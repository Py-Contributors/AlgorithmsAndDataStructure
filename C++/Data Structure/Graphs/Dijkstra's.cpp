#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <unordered_map>
#include <unordered_set> 
#include <climits>
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::unordered_set;

class Graph {
    int size;
    
    unordered_map<int, unordered_map<int, int>> adjList;
public:
    Graph(int size) {
        this->size = size;
    }
    void insert(int x, int y) {
        
        std::random_device ran;
        std::mt19937 rng(ran());
        std::uniform_int_distribution<int> range(1, 10);
        adjList[x][y] = range(rng); 
        adjList[y];
    }
    void printGraph() {
        for (int i = 0; i < adjList.size(); i++) {
            cout << "Current Node " << i <<  ":" << endl;
            for (auto j : adjList[i]) {
                cout << "Node: " << j.first << " Weight = " << j.second << endl;
            }
        }
    }
    void dijkstra(int src) {
        unordered_set<int> visited = { src }, unvisited;
        vector<int> distances(size, INT_MAX);
        vector<int>predecessor(size);
        for (int i = 0; i < adjList.size(); i++)
            if (i != src) {
                unvisited.insert(i);
                for (auto v : adjList[src])
                    if (v.first == i) {
                        distances[i] = v.second;
                        break;
                    }
            }
        distances[src] = 0;
        while (!unvisited.empty()) {
            int i = src, smallestVal = INT_MAX;
            for (auto v : unvisited)
                if (distances[v] < smallestVal) {
                    i = v;
                    smallestVal = distances[v];
                }
            unvisited.erase(i);
            visited.insert(i);
            for (auto v : adjList[i])
                if (distances[i] + v.second < distances[v.first]) {
                    distances[v.first] = distances[i] + v.second;
                    predecessor[v.first] = i;
                }
        }
        int totalCost = 0;
        /*for (int i : distances) {
            totalCost += i;
        }
        cout << "Total Cost: " << totalCost << endl;*/
        vector<int> path;
        path.push_back(size - 1);
        int index = predecessor[size - 1];
        while(index != src) {
            path.push_back(index);
            index = predecessor[index];
        }
        path.push_back(src);
        std::reverse(path.begin(), path.end());
        cout << "Path";
        for (int i : path) {
            cout << " " << i;
        }
        totalCost += distances[path[path.size() - 1]];
        cout << " Total Cost: " << totalCost << endl;
    }
};

int main() {
    Graph g = Graph(5);
    g.insert(0, 1);
    g.insert(1, 2);
    g.insert(3, 2);
    g.insert(2, 3);
    g.insert(0, 3);
    g.insert(3, 4);
    g.insert(2, 4);
    g.printGraph();
    g.dijkstra(0);
    
}