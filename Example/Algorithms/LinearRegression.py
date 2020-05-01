from Algorithms.MachineLearningAlgorithms.LinearRegression import LinearRegression

X = [12, 24, 36]
y  = [25,49,73]

lr = LinearRegression()
lr.fit(X,y)

y_predict = lr.predict(12)
print(y_predict)