#ifndef MANAGER_TASKS_TASK_H
#define MANAGER_TASKS_TASK_H
#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Task
{
    string state;
    string name;
public:
    Task(): state(""), name(""){}

    Task(string name, string state)
    {
        this->name = name;
        this->state = state;
    }

    void set_state(string state);

    string get_state();

    void set_name(string name);

    string get_name();

    friend istream& operator >> (istream& is, Task& task);

    friend ostream& operator << (ostream& os, Task& task);
};


#endif
