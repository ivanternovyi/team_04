#include "Entity/Task.h"
#include "DTO/DTOTask.h"
#include "BL/Menu.cpp" //there should be changes


int main()
{
    DTOTask d;
    Task tasks;
    tasks.set_name ("Name_temp");
    tasks.set_state ("State_temp");
    d.write_to_file(tasks);
    tasks.show_all_task();
    return 0;
}

