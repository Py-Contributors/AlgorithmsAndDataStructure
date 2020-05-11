#  __Date__     : 1/5/2020.
#  __Author__   :  CodePerfectPlus
#  __Package__  :  Python 3
#  __GitHub__   : https://www.github.com/codeperfectplus
#
from Algorithms import LogisticRegression

lr = LogisticRegression()

X = [2, 3, 5]
y = [3, 5, 3]
lr.fit(X, y)
