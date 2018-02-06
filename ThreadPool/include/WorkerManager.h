#pragma once
#include "Task.h"
#include "TaskLock.h"

class TaskWorker;

class WorkerManager{
public:
    WorkerManager();
    ~WorkerManager();
public:
    void createWorkers(int workerNum);
    void destroyWorkers();

    void dispatchTask(Task* pTask);
    void taskFinished(TaskWorker* pWorker);

    HANDLE getFreeEvent();

private:
    TaskWorker **mWorkers;
    TaskWorker **mFreeWorkers;
    TaskLock mWorkerLock;
    HANDLE* mWorkerHandles;
    HANDLE mFreeEvent;
    int mWorkerNum;
    int mFreeWorkerNum;
};