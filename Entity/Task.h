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
    string description;
    short counter; //to check status upgrading
public:
    Task(): state(""), name(""), counter(0), description(""){}

    Task(string name, string state, string des)
    {
        this->name = name;
        this->state = state;
        this->description =des;
    }

    void set_description(string temp);

    string get_description();

    short get_id();

    void set_state(string state);

    string get_state();

    void set_name(string name);

    string get_name();

    short get_counter();

    void parse_line(string line);

    friend istream& operator >> (istream& is, Task& task);

    friend ostream& operator << (ostream& os, Task& task);
};


#endif
