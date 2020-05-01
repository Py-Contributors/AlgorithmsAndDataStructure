class LogisticRegression:
    def __init__(self,lr=0.01,num_iter=100000,fit_intercept=True,verbose=False):
        self.lr = lr 
        self.num_iter = num_iter
        self.fit_intercept = fit_intercept

    def __add_intercept(self,X):
        intercept = np.ones((X.shape[0],1))
        return np.concatenate((intercept,X),axis=1)

    def __sigmoid(self,z):
        return 1/(1+np.exp(-z))
    
    def __loss(self,h, y):
        return(-y * np.log(h) - (1 - y) *np.log(1-h)).mean()

    def fit(self,X,y):
        '''
        lr.fit(X,y)
        '''
        if self.fit_intercept:
            X = self.__add_intercept(X)

        #weights Initializaation
        self.theta = np.zeros(X.shape[1])

        for i in range(self.num_iter):
            z = np.dot(X, self.theta)
            h = self.__sigmoid(z)
            gradient = np.dot (X.T, (h-y))/y.size 
            self.theta -= self.lr * gradient

            if(self.verbose == True and i % 10000 == 0):
                z = np.dot(X,self.theta)
                h = self.__sigmoid(z)
                print(f'Loss :{self.__loss(h,y)} \t')
    
    def predict_prob(self,X):
        if self.fit_intercept:
            x = self.__add_intercept(X)
        
        return self.__sigmoid(np.dot(X, self.theta))
    
    def predict(self, X, threshold):
        '''
        lr.predict(X,y)
        '''
        return self.predict_prob(X) >= threshold
