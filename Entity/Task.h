#ifndef MANAGER_TASKS_TASK_H
#define MANAGER_TASKS_TASK_H
#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "../DTO/DTODate.h"


using namespace std;

class Task
{
private:
    short id;
    string name;
    string state;
    string description;
    short assignment;
    DTODate create_date;
    short counter; //to check status upgrading
public:
    Task(): state(""), name(""), counter(0), description(""), assignment(0){}

    Task(string name, string state, string des, short as)
    {
        this->name = name;
        this->state = state;
        this->description = des;
        this->assignment = as;
    }

    void set_create_date(DTODate& obj);

    const char* get_create_date();

    void set_assignment(short val);

    short get_assignment();

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
