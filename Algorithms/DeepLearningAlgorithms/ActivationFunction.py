import numpy as np

class Sigmoid():
    ''' Softmax gives the probability of output function 
        Range : 0 to 1
    '''
    def __call__(self,x):
        return 1.0/(1.0 + np.exp(-x))
    
    def gradient(self,x):
        return self.__call__(x) * (1-self.__call__(x))

class tanH():
    ''' '''
    pass

class ReLU():
    pass

class LeakyReLU():
    pass

class Softmax():
    pass

class BinaryStepFunction():
    pass

class IdentityFunction():
    pass