#ifndef MANAGER_TASKS_DTOTASK_H
#define MANAGER_TASKS_DTOTASK_H
#pragma once
#include <fstream>
#include <iostream>
#include "../Entity/Task.h"


using namespace std;

class DTOTask{
public:
    //reading data from file
    static vector<Task> write_from_file();
    //write task to file ../data/Task.txt
    void write_to_file(Task obj);
};

#endif
