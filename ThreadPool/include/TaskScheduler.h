#pragma once
#include <string>
#include "Common.h"
#include "WorkerManager.h"
#include "Task.h"
using namespace std;

class Task;

class TaskScheduler{
public:
    TaskScheduler();
    ~TaskScheduler();

public:
    void createScheduler(int taskNum, Task* taskList);
    void destroyScheduler();

public:
    void addTask(Task* pTask);
    Task* getFreeTask();
    void taskFinished(Task* pTask);
    void waitForEmpytQueue();

public:
    void lock();
    void unLock();

private:
    static DWORD WINAPI ThreadProc(TaskScheduler* pScheduler);
    void schedule();

private:
    WorkerManager mManager;
    TaskLock mFullLock;
    TaskLock mFreeLock;
    Task** mFreeTasks;
    Task** mFullTasks;
    HANDLE mScheduleHandle;
    HANDLE mWorkerEvent;
    HANDLE mFullTaskEvent;
    HANDLE mFreeTaskEvent;
    HANDLE mExitEvent;
    DWORD mScheduleId;
    int mTaskNum;
    int mExceedNum;
    
};