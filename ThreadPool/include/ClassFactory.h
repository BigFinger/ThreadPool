#pragma once
#include <map>
#include <string>
#include "Common.h"
using namespace std;

class ClassFactory{
public:

private:
    map<string, CreateObject> mClassMap;
};