#pragma once
#include"../Entity/Task.h"
#include"../DTO/DTOTask.h"

int first_menu();

void menu(DTOTask& d, Task& t);

void show_menu();

void assignment_menu();

void show_by(string state, int assign);

void add_new_task(Task& t, DTOTask& d);

void erase_task();

void update();
