#include "Task.h"


void Task::set_name(string s)
{
    this->name = s;
}

void Task::set_state(string st)
{
    this->state = st;
}

string Task::get_name()
{
    return this->name;
}

string Task::get_state()
{
    return this->state;
}
