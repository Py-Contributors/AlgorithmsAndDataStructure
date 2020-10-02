"""
__FileCreationDate__  :  //2020
__Author__           :  CodePerfectPlus
__Package__         :  Python 3
__GitHub__         : https://www.github.com/codeperfectplus
"""
import numpy as np


class GradientDescent:
    """
    Gradient Descent Algorithm Implementation
    """

    def __init__(self, w, x, b, y):
        self.w = w
        self.b = b
        self.x = x
        self.y = y
        self.z = self.w * self.x + self.b

    def sigmoid(self, w, b, x):
        return 1.0 / (1.0 + np.exp(-w * self.x + self.b))

    def grad_w(self, w, b, x, y):
        fx = self.sigmoid(w, x, b)
        return (fx - y) * fx * (1 - fx) * x

    def grad_b(self, w, b, x, y):
        fx = self.sigmoid(w, b, x)
        return (fx - y) * fx * (1 - fx)

    def Compute(self):
        w, b, eta = -2, -2, 1.0
        epochs = 1000
        for i in range(epochs):
            dw = db = 0
            for x, y in zip(self.x, self.y):
                dw = dw + self.grad_w(w, b, x, y)
                db = db + self.grad_b(w, b, x, y)
            w = w - eta * dw
            b = b - eta * db


class Adam:
    def __init__(self, learning_rate=0.001, b1=0.9, b2=0.999):
        self.learning_rate = learning_rate
        self.eps = 1e-8
        self.m = None
        self.v = None

        self.b1 = b1
        self.b2 = b2

    def update(self, w, grad_wrt_w):
        if self.m is None:
            self.m = np.zeros(np.shape(grad_wrt_w))
            self.v = np.zeros(np.shape(grad_wrt_w))

        self.m = self.b1 * self.m + (1 - self.b1) * grad_wrt_w
        self.v = self.b2 * self.m + (1 - self.b2) * np.power(grad_wrt_w, 2)

        m_hat = self.m / (1 - self.b1)
        v_hat = self.m / (1 - self.b2)

        self.w_updt = self.learning_rate * m_hat / (np.sqrt(v_hat) + self.eps)
        return w - self.w_updt
