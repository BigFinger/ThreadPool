#pragma once
#include "Common.h"

class TaskLock{
public:
    TaskLock();
    ~TaskLock();
public:
    void lock();
    void unLock();

private:
    CRITICAL_SECTION mSection;
};