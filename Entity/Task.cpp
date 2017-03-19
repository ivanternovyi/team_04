#include "Task.h"
#include "../DTO/DTOTask.h"

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

istream& operator >> (istream& is, Task &task) //overload operator
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
