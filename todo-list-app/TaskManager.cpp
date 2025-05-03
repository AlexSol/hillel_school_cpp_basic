#include "TaskManager.hpp"
#include "Task.hpp"

#include <iostream>

void TaskManager::addTask(const std::string& aTaskTitle, bool aCompleted)
{
    const int newIdTask = mTasks.size() + 1; 
    Task task{newIdTask, aTaskTitle, aCompleted};
    
    mTasks[task.id] = task;
}

std::vector<Task> TaskManager::listTasks() const
{
    std::vector<Task> tasks;
    for (const auto& pair : mTasks)
    {
        tasks.push_back(pair.second);
    }
    
    return tasks;
}

bool TaskManager::completeTask(int aId)
{
    auto it = mTasks.find(aId);
    if (it != mTasks.end())
    {
        it->second.completed = true;
        return true;
    }
    else
    {
        return false;
    }
}

bool TaskManager::deleteTask(int aId)
{
    auto it = mTasks.find(aId);
    if (it != mTasks.end())
    {
        mTasks.erase(it);
        return true;
    }
    else
    {
        return false;
    }
}