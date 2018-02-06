#pragma once
#include "Common.h"

class Task{
public:
    Task();
    virtual ~Task();
public:
    virtual void execute() = 0;

private:
    int mTaskId;
};