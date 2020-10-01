// SVM, which stands for Support Vector Machine, is a classifier. 
// Classifiers perform classification, predicting discrete categorical labels. 
// SVR, which stands for Support Vector Regressor, is a regressor. Regressors perform regression, predicting continuous ordered variables. 
// Both use very similar algorithms, but predict different types of variables.

// In simple regression we try to minimize the error rate. While in SVR we try to fit the error within a certain threshold.

// There are 4 main basics of SVR, they are :-

// 1. Kernel :- The function used to map lower dimensional data into a higher dimensional data.
// 2. HyperPlane :- In SVM this is basically the separation line between the data classes. Although in SVR we are going to define it as the line that will will help us predict the continuous value or target value.
// 3. Boundary line :- In SVM there are two lines other than Hyper Plane which creates a margin . The support vectors can be on the Boundary lines or outside it. This boundary line separates the two classes. In SVR the concept is same.
// 4. Support vectors :- This are the data points which are closest to the boundary. The distance of the points is minimum or least.


// Importing the libraries

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

// Importing the dataset

dataset = pd.read_csv('Position_Salaries.csv')
dataset.head()

X = dataset.iloc[:, 1:2].values
y = dataset.iloc[:, 2].values

// Splitting the dataset into the Training set and Test set
"""from sklearn.model_selection import train_test_split
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.2,random_state=0)"""


// Feature Scaling
from sklearn.preprocessing import StandardScaler
sc_X = StandardScaler()
sc_y = StandardScaler()
X = sc_X.fit_transform(X)
y = sc_y.fit_transform(y.reshape(-1,1))


// Fitting SVR to the dataset

from sklearn.svm import SVR
regressor = SVR(kernel='rbf') #RBF(Radial Basis Function) :- It is a general-purpose kernel; used when there is no prior knowledge about the data.
regressor.fit(X,y)


// Predicting a new result
print(regressor.predict(np.reshape(6.5,(1,1))))
y_pred = sc_y.inverse_transform(regressor.predict(sc_X.transform(np.array([[6.5]]))))
y_pred


// Visualising the SVR results
plt.scatter(X,y,color='red')
plt.plot(X,regressor.predict(X),color='blue')
plt.title('Truth or Bluff (SVR)')
plt.xlabel('Position level')
plt.ylabel('Salary')
plt.show()


// Visualising the SVR results (for higher resolution and smoother curve)

X_grid = np.arange(min(X), max(X), 0.01) # choice of 0.01 instead of 0.1 step because the data is feature scaled
X_grid = X_grid.reshape((len(X_grid), 1))
plt.scatter(X, y, color = 'red')
plt.plot(X_grid, regressor.predict(X_grid), color = 'blue')
plt.title('Truth or Bluff (SVR)')
plt.xlabel('Position level')
plt.ylabel('Salary')
plt.show()


plt.scatter(X, y, color = 'red')
plt.plot(X_grid, regressor.predict(X_grid), color = 'blue')
plt.title('Truth or Bluff (SVR)')
plt.xlabel('Position level')
plt.ylabel('Salary')
plt.show()
