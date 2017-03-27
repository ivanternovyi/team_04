#include "Task.h"
#include "../DTO/DTOTask.h"

short Task::get_id()
{
    DTOTask d;
    vector<Task>  tasks;
    tasks = d.write_from_file();
    this->id = tasks.size();
    for(int i = 0; i < tasks.size(); i++)
    {
        if(this->name == tasks[i].get_name())
        {
            this->id = i;
        }
    }
    return this->id;
}

void Task::set_state(string state)
{
    this->state = state;
}

string Task::get_state()
{
    return this->state;
}

void Task::set_name(string name)
{
    this->name = name;
}

string Task::get_name()
{
    return this->name;
}

void Task::set_counter(short temp)
{
    this->counter = temp;
}

short Task::get_counter()
{
    if(state == "to_do")
    {
        counter = 0;
    }
    else if(state == "in_progress")
    {
        counter = 1;
    }
    else if(state == "varificate")
    {
        counter = 2;
    }
    else if(state == "done!")
    {
        counter = 3;
    }
    else
    {
        counter = -1; //means that task does not consists of mentioned states
    }
    return this->counter;
}

//overload operator to parse line into task
istream& operator >> (istream& is, Task &task)
{
    //temporary variable strTask to read from stream is
    string strTask;
    getline(is, strTask);
    string name;
    string state;
    int pos = strTask.find(',');
    int iterator = 0;
    while (iterator < strTask.size())   //parsing line into task
    {
        if (iterator < pos)
        {
            name += strTask[iterator];
        }
        else if(iterator > pos)
        {
            state += strTask[iterator];
        }
        iterator += 1;
    }
    task.set_name(name);
    task.set_state(state);
    return is;
}

ostream& operator << (ostream& os, Task& task)
{
    os << task.get_name ();
    os << ",";
    os << task.get_state ();
    os <<"\n";
    return os;
}
