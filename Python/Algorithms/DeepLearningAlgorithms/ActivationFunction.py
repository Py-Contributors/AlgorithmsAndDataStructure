"""
__FileCreationDate__  :  4/5/2020
__Author__           :  CodePerfectPlus
__Package__         :  Python 3
__GitHub__         : https://www.github.com/codeperfectplus
"""
import numpy as np

# Call Method : https://www.geeksforgeeks.org/__call__-in-python/


class Sigmoid:
    """ Softmax gives the probability of output function
        Range : 0 to 1
    """

    def __call__(self, x):
        return 1.0 / (1.0 + np.exp(-x))

    def gradient(self, x):
        return self.__call__(x) * (1 - self.__call__(x))


class TanH:
    """TanH Gives the probability of output function
        Range : - 1 to 1
     """

    def __call__(self, x):
        pass


class ReLU:
    def __call__(self, x):
        pass


class LeakyReLU:
    def __call__(self, x):
        pass


class Softmax:
    def __call__(self, x):
        pass


class BinaryStepFunction:
    def __call__(self, x):
        pass


class IdentityFunction:
    def __call__(self, x):
        pass
