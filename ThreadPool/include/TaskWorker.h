#pragma once
#include "Common.h"
#include "Task.h"

class WorkerManager;

class TaskWorker{
public:
    TaskWorker(WorkerManager *pManager);
    ~TaskWorker();
public:
    HANDLE createWorker();
    void destroyWorker();
    void startWork(Task* pTask);
private:
    static DWORD WINAPI ThreadProc(TaskWorker* pWorker);

private:
    WorkerManager* mManger;
    Task* mTask;
    HANDLE mThreadHandle;
    DWORD mThreadId;
    HANDLE mEvents[2];
};