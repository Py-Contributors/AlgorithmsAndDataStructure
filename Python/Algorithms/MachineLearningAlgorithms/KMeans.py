import random
import itertools
import numpy as np
from sklearn.datasets import make_blobs

class KMeans:
	def __init__(self,k):
		self.k = k
		self.means = None
	
	def form_clusters(self,data,indexes):
		#assigning clusters to points

		clusters = [[] for i in range(self.k)]
		means = []
		for point,index in zip(data,indexes):
			clusters[index].append(point)
		for cluster in clusters:
			if cluster:
				means.append(np.mean(cluster,axis=0).tolist())
			else:
				means.append(random.choice(data))
		return means	

	def classify(self,vector):
		
		diff = []
		#calculating euclidean distance for each point from each center
		for mean in self.means:
			diff.append(np.linalg.norm(mean - vector))
		return np.argmin(diff)

	@property
	def centers(self):
		return self.means	
				
	def fit(self,data):

		#random initialization of means
		cluster_index = [random.randrange(self.k) for _ in data]
		for i in itertools.count():
			#computing means and reassigning centers
			self.means = self.form_clusters(data,cluster_index)
			new_cluster_index = [self.classify(val) for val in data]
			
			#if difference between old centers and new centers is 0 then break the loop
			differences = 0
			for ind,new_ind in zip(cluster_index,new_cluster_index):
				if ind != new_ind:
					differences = differences + 1

			if differences == 0:
			 	return

			#calculating means for new cluster centers
			cluster_index = new_cluster_index
			self.means = self.form_clusters(data,cluster_index)

#generating random dataset
X,y= make_blobs(n_samples=150,n_features=2,centers=3)
clustering = KMeans(k=3)
clustering.fit(X)
print(clustering.centers)

