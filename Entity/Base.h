#ifndef MANAGER_TASKS_BASE_H
#define MANAGER_TASKS_BASE_H

#include <iostream>


using namespace std;

class Base
{
protected:
    short id;
public:
    Base():id(0){};

    short getBaseId();

    virtual ~Base() = 0;
};



#endif //MANAGER_TASKS_BASE_H
