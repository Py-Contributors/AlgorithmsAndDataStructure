import numpy as np
import nnfs
from nnfs.datasets import spiral_data
nnfs.init()
'''
inputs = [[1,2,3,2.5],
			[2,5,-1,2],
			[-1.5,2.7,3.3,-0.8]]
weights1 = [[0.2,0.8,-0.5,1],
			[0.5,-0.91,0.26,-0.5],
			[-0.26,-0.27,0.17,0.87]]
bias1=[2,3,0.5]
weights2 = [[0.1,-0.14,0.5],
			[-0.5,0.12,-0.33],
			[-0.44,0.73,-0.13]]
bias2=[-1,2,-0.5]
layer1_output = np.dot(inputs,np.array(weights1).T) + bias1
layer2_output = np.dot(layer1_output,np.array(weights2).T) + bias2
print(layer2_output)
'''
'''
output = []
for weights_,bias_ in zip(weights,bias):
	output_ =0
	for inputs_,weight_ in zip(inputs,weights_):
		output_ += weight_*inputs_
	output_+=bias_
	output.append(output_)
print(output) 
'''
'''
inputs = [[1,2,3,2.5],
			[2,5,-1,2],
			[-1.5,2.7,3.3,-0.8]]
weights1 = [[0.2,0.8,-0.5,1],
			[0.5,-0.91,0.26,-0.5],
			[-0.26,-0.27,0.17,0.87]]
bias1=[2,3,0.5]
weights2 = [[0.1,-0.14,0.5],
			[-0.5,0.12,-0.33],
			[-0.44,0.73,-0.13]]
bias2=[-1,2,-0.5]
class networks:
	def __init__(self,inputs,weights,bias):
		self.inputs = inputs
		self.weights = weights
		self.bias = bias
	def result(self):
		self.output = np.dot(self.inputs,np.array(self.weights).T) + self.bias
t1 = networks(inputs,weights1,bias1)
t1.result()
t2 = networks(t1.output,weights2,bias2)
t2.result()
print(t2.output)
'''
'''np.random.seed(0)
X = [[1,2,3,2.5],
	[2,5,-1,2],
	[-1.5,2.7,3.3,-0.8]]'''
X,Y = spiral_data(100,3)
class networks:
	def __init__(self,n_inputs,n_neurons):
		self.weights = 0.1*np.random.rand(n_inputs,n_neurons)
		self.bias = np.zeros((1,n_neurons))
	def forward(self,inputs):
		self.output = np.dot(inputs,self.weights) + self.bias
class Activateion_ReLU:
	def forward(self,x):
		self.output = np.maximum(0,x)

t = networks(2,5)
t.forward(X)
activation = Activateion_ReLU()
activation.forward(t.output)
print(activation.output)

	