import numpy as np
import math


class Regression:
    """ Base model :
    n_iterations : float
        The number of training iterations the algorithm will tune the weights
        for learning_rate : float
        The step length that will be used when updating the weights.
    """

    def __init__(self, n_iterations, learning_rate):
        self.n_interations = n_iterations
        self.learning_rate = learning_rate

    def initialize_weights(self, n_features):
        """ initialize weight randomly """
        limit = 1 / math.sqrt(n_features)
        self.w = np.random.uniform(-limit, limit, (n_features,))

    def fit(self, X, y):
        """ Insert constant one for bias weights """
        X = np.insert(X, 0, 1, axis=1)
        self.training_errors = []
        self.initialize_weights(n_features=X.shape[1])

        """ Gradient descent for n_iterations """
        for i in range(self.n_interations):
            y_pred = X.dot(self.w)
            mse = np.mean(0.5 * (y - y_pred) ** 2)
            self.training_errors.append(mse)
            grad_w = -(y - y_pred).dot(X)
            # update the weight
            self.w -= self.learning_rate * grad_w

    def predict(self, X):
        """insert constant ones for bias weights"""
        X = np.insert(X, 0, 1, axis=1)
        y_pred = X.dot(self.w)
        return y_pred


class LinearRegression(Regression):
    """ Linear Regression Model Parameter
    n_iterations : float
        The number of training iterations the algorithm will tune the weights
    for learning rate : float

    gradient_descent : boolean
        True : Gradient Descent
        False : batch optimization by least squares
    """

    def __init__(self, n_iterations=100, learning_rate=0.001, gradient_descent=True):
        self.gradient_descent = gradient_descent
        super(LinearRegression, self).__init__(
            n_iterations=n_iterations, learning_rate=learning_rate
        )

    def fit(self, X, y):
        """ If Gradient Descent is False """
        if not self.gradient_descent:
            pass
        else:
            super(LinearRegression, self).fit(X, y)
