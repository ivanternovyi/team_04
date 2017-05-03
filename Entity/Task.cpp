#include "Task.h"
#include "../DTO/DTOTask.h"


short Task::get_id()
{
    DTOTask d;
    vector<Task>  tasks;
    tasks = d.write_from_file();
    this->id = tasks.size();
    for(int i = 0; i < tasks.size() - 1; i++)
    {
        if(this->name == tasks[i].get_name())
        {
            this->id = i;
        }
    }
    return this->id;
}

void Task::set_assignment(short val)
{
    this->assignment = val;
}

short Task::get_assignment()
{
    return this->assignment;
}

void Task::set_description(string temp)
{
    this->description = temp;
}

string Task::get_description()
{
    return this->description;
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

//parse method
void Task::parse_line(string line)
{
    size_t found1 = line.find(",");
    this->name = line.substr(0, found1);
    size_t found2 = line.find(",", found1 + 1, 1);
    this->state = line.substr(found1+1, found2 - found1 - 1);
    found1 = line.find(",", found2 + 1, 1);
    this->description = line.substr(found2 + 1, found1 - found2 - 1);
    this->assignment = atoi(line.substr(found1 + 1).c_str());
}

//overload operator to read line to task
istream& operator >> (istream& is, Task& task)
{
    string line;
    getline(is, line);
    task.parse_line(line);
    return is;
}

ostream& operator << (ostream& os, Task& task)
{
    os << task.get_name();
    os << ",";
    os << task.get_state();
    os << ",";
    os << task.get_description();
    os << ",";
    os << task.get_assignment();
    os <<"\n";
    return os;
}
