import numpy as np
from collections import Counter
class KNN:
    
  #setting k = 5 as default value
  def __init__(self,k=5):
    self.k = k

  def euclid_distance(self,x1,x2):
      return np.sqrt(np.sum((x1-x2)**2))
    
  def fit(self,X,Y):
    self.X_train = X
    self.Y_train = Y
  
  def predict(self,X):
    y_pred = [self._predict(x) for x in X]
    return np.array(y_pred)

  def _predict(self,x):
      
    #distance
    distance = [self.euclid_distance(x,x_train) for x_train in self.X_train]
    
    # k nearest samples
    k_indices = np.argsort(distance)[:self.k]
    k_nearest_labels = [self.Y_train[i] for i in k_indices]
    
    # most common class label
    labels = Counter(k_nearest_labels).most_common(1)
    return labels[0][0]
