import numpy as np


class GradientDescent:
    """ Base Model:
    X: array_like
       The input dataset of shape (m x n+1), where m is the number of examples,
        and n is the number of features. We assume a vector of one's already
        appended to the features so we have n+1 columns.

    y: array_like
       The values of the function at each data point. This is a vector of
        shape (m, ).

    theta: array_like
        The parameters for the regression function. This is a vector of
        shape (n+1, ).

    """

    def __init__(self, X, y, theta):
        self.X = X
        self.y = y
        self.theta = theta

    def compute_cost(self):
        """
        calculates cost after each iteration
        """

        # initializing values

        # number of training examples
        m = self.y.size

        J = 0

        # hypothesis function
        h = self.X.dot(self.theta)

        # calculating cost function
        J = (1 / (2 * m)) * np.sum(np.square(h - self.y))

        # returning cost of that iteration
        return J

    def gradient_descent(self, alpha, n_iterations):
        """ Gradient Descent Function
        alpha: float
            The learning rate.

        n_iterations: int
            The number of itterations for gradient descent.

        Returns
            optimized theta vector and cost value after each iteration.
        """

        # initializing values

        # number of training examples
        m = self.y.size

        # making original copy of theta
        theta = self.theta

        # creating cost function history list
        J_history = []

        for _ in range(n_iterations):
            self.theta = self.theta - (alpha / m) * \
                (np.dot(self.X, self.theta) - self.y).dot(self.X)

            # save the cost J in every iteration
            J_history.append(self.compute_cost())

        # returning new theta vector, cost history list and original theta
        return self.theta, J_history, theta
