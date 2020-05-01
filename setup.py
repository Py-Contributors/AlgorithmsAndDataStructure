#  Date   1/5/2020.
#   __Author__   :  CodePerfectPlus
#  __Package__  :  Python 3
#  __GitHub__  : https://www.github.com/codeperfectplus
#

from setuptools import setup

with open("README.md", "r") as fh:
    long_description = fh.read()

setup(
    name='AlgorithmsAndDataStructure',
    version='0.0.1',
    packages=['utils', 'Algorithms', 'Algorithms.BackTracking', 'Algorithms.DivideAndConquer',
              'Algorithms.GreedyAlgorithms', 'Algorithms.DynamicPrograming', 'Algorithms.SortingAlgorithms',
              'Algorithms.RecursionAlgorithms', 'Algorithms.SearchingAlgorithms', 'Algorithms.PathFindingAlgorithms',
              'Algorithms.DeepLearningAlgorithms', 'Algorithms.MachineLearningAlgorithms', 'DataStructure',
              'DataStructure.LinkedListDS'],
    url='https://www.github.com/codeperfectplus',
    license='MIT Licence',
    author='DeepakRaj',
    author_email='codeperfectplus@gmail.com',
    description='Python DataStructure and Algorithm',
    long_description =long_description,
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
)
