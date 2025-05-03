#pragma once

#include <map>
#include <vector>
#include <string>

class Task;

class TaskManager
{
private:
    TaskManager() = default;
    TaskManager(const TaskManager&) = delete;
    TaskManager& operator=(const TaskManager&) = delete;

private:
    std::map<int, Task> mTasks;

public:
    static TaskManager& getInstance()
    {
        static TaskManager instance;
        return instance;
    }

    void addTask(const std::string& aTaskTitle, bool aCompleted = false);
    std::vector<Task> listTasks() const;
    bool completeTask(int aId);
    bool deleteTask(int aId);
};
