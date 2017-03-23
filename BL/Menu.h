#pragma once
#include"../Entity/Task.h"
#include"../DTO/DTOTask.h"

int first_menu();

void menu(DTOTask& d, Task& t);

void add_new_task(Task& t, DTOTask& d);

void show_all_task();

void erase_task();

void update();

