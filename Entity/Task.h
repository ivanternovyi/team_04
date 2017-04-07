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
private:
    short id;
    string name;
    string state;
    short counter; //to check status upgrading
public:
    Task(): state(""), name(""), counter(0){}

    Task(string name, string state)
    {
        this->name = name;
        this->state = state;
    }

    short get_id();

    void set_state(string state);

    string get_state();

    void set_name(string name);

    string get_name();

    void set_counter(short temp);

    short get_counter();

    void parse_line(string line);

    friend istream& operator >> (istream& is, Task& task);

    friend ostream& operator << (ostream& os, Task& task);
};


#endif
