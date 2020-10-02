# Title - Gradient Descent

import numpy as np

# calculates cost function
def cost_compute(X, y, theta):
    # X is the design matrix of shape (m x n+1)
    # y is the actual output vector of shape (m)
    # theta is the vector of initial values of theta (n+1)

    # m is the number of training examples
    m = y.size

    # intializing J which is the cost function
    J = 0

    # h is the hypothesis function
    h = np.dot(X, theta)

    # calculating cost function J
    J = (1/(2 * m)) * np.sum(np.square(np.dot(X, theta) - y))

    # returning the cost function
    return J

# implements gradient descent
def minimize_batch(X, y, theta, alpha, epochs):
    # X is the design matrix of shape (m x n+1)
    # y is the actual output vector of shape (m)
    # theta is the vector of initial values of theta (n+1)
    # alpha is the learning rate
    # epochs is the number of iterations of gradient descent

    # m is the number of training examples
    m = y.shape[0]

    # python list to save cost in  every iteration
    J_histroy = []

    # performing gradient descent
    for i in range(epochs):
        theta = theta - (alpha / m) * (np.dot(X, theta) - y).dot(X)

        #saving cost of every itteration
        J_histroy.append(cost_compute(X, y, theta))

    # returning new theta and J_history
    return theta, J_histroy
