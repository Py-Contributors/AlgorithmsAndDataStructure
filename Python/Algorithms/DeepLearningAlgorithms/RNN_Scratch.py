#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Oct 11 11:38:32 2020

@author: anjalisingh
"""
import numpy as np
import random

def get_initial_loss(vocab_size, seq_length):
    return -np.log(1.0/vocab_size)*seq_length

def smooth(loss, cur_loss):
    return loss * 0.999 + cur_loss * 0.001

def print_sample(sample_ix, ix_to_char):
    txt = ''.join(ix_to_char[ix] for ix in sample_ix)
    txt = txt[0].upper() + txt[1:]  # capitalize first character
    print('%s' % (txt, ), end='')


def initialize_parameters(n_a, n_x, n_y):
    Wax = np.random.randn(n_a, n_x)*0.01  # input to hidden
    Waa = np.random.randn(n_a, n_a)*0.01  # hidden to hidden
    Wya = np.random.randn(n_y, n_a)*0.01  # hidden to output
    ba = np.zeros((n_a, 1))  # hidden bias
    by = np.zeros((n_y, 1))  # output bias

    parameters = {"Wax": Wax, "Waa": Waa, "Wya": Wya, "ba": ba, "by": by}

    return parameters


def update_parameters(parameters, gradients, lr):

    parameters['Wax'] += -lr * gradients['dWax']
    parameters['Waa'] += -lr * gradients['dWaa']
    parameters['Wya'] += -lr * gradients['dWya']
    parameters['ba'] += -lr * gradients['db']
    parameters['by'] += -lr * gradients['dby']

    return parameters

def rnn_cell_forward(xt, a_prev, parameters):

    Wax = parameters["Wax"]
    Waa = parameters["Waa"]
    Wya = parameters["Wya"]
    ba = parameters["ba"]
    by = parameters["by"]

    a_next = np.tanh(np.dot(Wax, xt) + np.dot(Waa, a_prev) + ba)
    yt_pred = softmax(np.dot(Wya, a_next) + by)

    cache = (a_next, a_prev, xt, parameters)

    return a_next, yt_pred, cache

def rnn_forward(X, Y, a0, parameters, vocab_size=27):
    x, a, y_hat = {}, {}, {}
    a[-1] = np.copy(a0)
    loss = 0
    for t in range(len(X)):
        x[t] = np.zeros((vocab_size, 1))
        if (X[t] != None):
            x[t][X[t]] = 1
        a[t], y_hat[t], _ = rnn_cell_forward(x[t], a[t-1],parameters)
        loss -= np.log(y_hat[t][Y[t], 0])
    cache = (y_hat, a, x)
    return loss, cache

def rnn_cell_backward(dy, gradients, parameters, x, a, a_prev):
    gradients['dWya'] += np.dot(dy, a.T)
    gradients['dby'] += dy
    da = np.dot(parameters['Wya'].T, dy) +         gradients['da_next']  # backprop into h
    daraw = (1 - a * a) * da  # backprop through tanh nonlinearity
    gradients['db'] += daraw
    gradients['dWax'] += np.dot(daraw, x.T)
    gradients['dWaa'] += np.dot(daraw, a_prev.T)
    gradients['da_next'] = np.dot(parameters['Waa'].T, daraw)
    return gradients


def rnn_backward(X, Y, parameters, cache):
    gradients = {}
    (y_hat, a, x) = cache
    Waa, Wax, Wya, by, ba = parameters['Waa'], parameters['Wax'], parameters['Wya'], parameters['by'], parameters['ba']
    gradients['dWax'], gradients['dWaa'], gradients['dWya'] = np.zeros_like(Wax), np.zeros_like(Waa), np.zeros_like(Wya)
    gradients['db'], gradients['dby'] = np.zeros_like(ba), np.zeros_like(by)
    gradients['da_next'] = np.zeros_like(a[0])

    for t in reversed(range(len(X))):
        dy = np.copy(y_hat[t])
        dy[Y[t]] -= 1
        gradients = rnn_cell_backward(
            dy, gradients, parameters, x[t], a[t], a[t-1])

    return gradients, a


def softmax(x):
    e_x = np.exp(x - np.max(x))
    return e_x / e_x.sum(axis=0)


def clip(gradients, maxValue):
    dWaa, dWax, dWya, db, dby = gradients['dWaa'], gradients['dWax'], gradients['dWya'], gradients['db'], gradients['dby']

    for gradient in [dWax, dWaa, dWya, db, dby]:
        np.clip(gradient, -maxValue, maxValue, out=gradient)

    gradients = {"dWaa": dWaa, "dWax": dWax, "dWya": dWya, "db": db, "dby": dby}

    return gradients


def sample(parameters, char_to_ix, seed):
    Waa, Wax, Wya, by, ba = parameters['Waa'], parameters['Wax'], parameters['Wya'], parameters['by'], parameters['ba']
    vocab_size = by.shape[0]
    n_a = Waa.shape[1]
    x = np.zeros((vocab_size, 1))
    a_prev = np.zeros((n_a, 1))
    indices = []

    idx = -1

    counter = 0
    newline_character = char_to_ix['\n']

    while (idx != newline_character and counter != 50):
        a = np.tanh(np.dot(Wax, x) + np.dot(Waa, a_prev) + ba)
        z = np.dot(Wya, a) + by
        y = softmax(z)

        idx = np.random.choice(list(range(vocab_size)), p=y.ravel())

        indices.append(idx)

        x = np.zeros((vocab_size, 1))
        x[idx] = 1

        a_prev = a

        counter +=1

    if (counter == 50):
        indices.append(char_to_ix['\n'])

    return indices


def optimize(X, Y, a_prev, parameters, learning_rate = 0.01):
    loss, cache = rnn_forward(X, Y, a_prev, parameters)

    gradients, a = rnn_backward(X, Y, parameters, cache)

    gradients = clip(gradients, 5)

    parameters = update_parameters(parameters, gradients, learning_rate)

    return loss, gradients, a[len(X)-1]


def model(data, ix_to_char, char_to_ix, num_iterations = 35000, n_a = 50, dino_names = 7, vocab_size = 27):

    n_x, n_y = vocab_size, vocab_size

    parameters = initialize_parameters(n_a, n_x, n_y)

    loss = get_initial_loss(vocab_size, dino_names)

    with open('dinos.txt') as f:
        examples = f.readlines()
    examples = [x.lower().strip() for x in examples]

    np.random.seed(0)
    np.random.shuffle(examples)

    a_prev = np.zeros((n_a, 1))

    for j in range(num_iterations):

        index = j % len(examples)
        X = [None] + [char_to_ix[ch] for ch in examples[index]]
        Y = X[1:] + [char_to_ix["\n"]]

        curr_loss, gradients, a_prev = optimize(X, Y, a_prev, parameters)

        loss = smooth(loss, curr_loss)

        if j % 2000 == 0:

            print('Iteration: {}, Loss: {}'.format(j, loss) + '\n')

            seed = 0
            for name in range(dino_names):

                sampled_indices = sample(parameters, char_to_ix, seed)
                txt = ''.join(ix_to_char[ix] for ix in sampled_indices)
                txt = txt[0].upper() + txt[1:]  # capitalize first character
                print('%s' % (txt, ), end='')

                seed += 1

            print('\n')

    return parameters

data = open('dinos.txt', 'r').read()
data= data.lower()
chars = list(set(data))
data_size, vocab_size = len(data), len(chars)
print('There are {} total characters and {} unique characters in your data.'.format(data_size, vocab_size))

char_to_ix = { ch:i for i,ch in enumerate(sorted(chars)) }
ix_to_char = { i:ch for i,ch in enumerate(sorted(chars)) }

model(data, ix_to_char, char_to_ix)
