#pragma once
#include"../Entity/Task.h"
#include"../DTO/DTOTask.h"
using namespace std;

int first_menu();
void menu(DTOTask &d, Task &t);
void add_new_task(Task &t, DTOTask &d);

