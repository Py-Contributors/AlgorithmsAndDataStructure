#  __Date__     : 1/5/2020.
#  __Author__   :  CodePerfectPlus
#  __Package__  :  Python 3
#  __GitHub__   : https://www.github.com/codeperfectplus
#
from Algorithms import LinearRegression

X = [12, 24, 36]
y = [25, 49, 73]

lr = LinearRegression()
lr.fit(X, y)

y_predict = lr.predict(12)
print(y_predict)
