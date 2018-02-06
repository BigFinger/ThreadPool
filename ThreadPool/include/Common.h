#pragma once

#define THREADPOOL_EXPORT _declspec(dllexport) 
typedef void* (*CreateObject)(void);

#include <Windows.h>