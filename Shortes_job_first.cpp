#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Task {
public:
    int arrivalTime;
    int processingTime;
    int index;

    Task(int arrTime, int procTime, int idx) : arrivalTime(arrTime), processingTime(procTime), index(idx) {}

    bool operator<(const Task& other) const {
        return processingTime > other.processingTime;  // Min-heap based on processing time
    }
};

vector<int> shortestJobFirst(vector<vector<int>>& tasks) {
    int n = tasks.size();

    // Create Task objects and store them in a priority queue (min-heap) based on processing time
    priority_queue<Task> taskQueue;
    for (int i = 0; i < n; ++i) {
        Task task(tasks[i][0], tasks[i][1], i);
        taskQueue.push(task);
    }

    vector<int> orderedTasks;
    int currentTime = 0;

    while (!taskQueue.empty()) {
        Task currentTask = taskQueue.top();
        taskQueue.pop();

        // If the arrival time is later than the current time, update the current time
        if (currentTask.arrivalTime > currentTime)
            currentTime = currentTask.arrivalTime;

        // Execute the current task
        currentTime += currentTask.processingTime;
        orderedTasks.push_back(currentTask.index);
    }

    return orderedTasks;
}

int main() {
    vector<vector<int>> tasks = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
    vector<int> orderedTasks = shortestJobFirst(tasks);

    cout << "Order of Tasks: ";
    for (int i : orderedTasks)
        cout << i << " ";
    cout << endl;

    return 0;
}