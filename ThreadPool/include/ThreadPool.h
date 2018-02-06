#pragma once
#include <vector>
#include "Common.h"
#include "TaskScheduler.h"

class THREADPOOL_EXPORT ThreadPool {
public:
    ThreadPool(int threadNum);
    ~ThreadPool();
public:
    void start();
    void addTask(Task* pTask);
private:
    TaskScheduler *mTaskScheduler;
    vector<Task*> mTaskList;
};
