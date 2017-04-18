#include <iostream>
#include "../Entity/Task.h"
#include "../DTO/DTOTask.h"
#include "Menu.h"
#include <sstream>

#if (_WIN32 || _WIN64)
    const char* CLR = "cls";
#elif (__unix || __unix__ || __APPLE__ || __MACH__ || __linux__)
    const char* CLR = "clear";
#endif


using namespace std;

enum state_task {to_do = 1, in_progress, varificate, done};


int first_menu()
{
    string choice;
    cout << "***************************" << endl;
    cout << "1) Show tasks" << endl;
    cout << "2) New task" << endl;
    cout << "3) Update" << endl;
    cout << "4) Delete" << endl;
    cout << "5) Exit" << endl;
    cout << "***************************" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    while(true)
    {
        if(choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5")
        {
            break;
        }
        else
        {
            cout << "Retry! Choice should be in range (1..5)!\n";
            choice.clear();
            cin >> choice;
        }
    }
    return stoi(choice);
}

void menu(DTOTask &dto, Task &task)
{
    int your_choice = 0;
    while(your_choice != 5){
        your_choice = first_menu();
        switch (your_choice){
            case 1:
            {
                show_menu();
                system(CLR);
                break;
            }

            case 2:
            {
                add_new_task(task, dto);
                system(CLR);
                break;
            }

            case 3:
            {
                update();
                system(CLR);
                break;
            }
            case 4:
            {
                system(CLR);
                erase_task();
                cin.get();
                break;
            }
            default:
            {
                cout << "Exit success!\n";
                break;
            }
        }
    }
}


void show_menu()
{
    string choice;
    cout << "***************************" << endl;
    cout << "1) To_do tasks" << endl;
    cout << "2) Tasks in progress" << endl;
    cout << "3) Varificate tasks" << endl;
    cout << "4) Done tasks" << endl;
    cout << "5) All tasks" << endl;
    cout << "6) Show by assignment" << endl;
    cout << "q - to return to main menu" << endl;
    cout << "***************************" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    while(true)
    {
        if(choice == "q")
        {
            return;
        }
        else if(choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5" || choice == "6")
        {
            switch (stoi(choice))
            {
                case to_do: show_by("to_do", -1);
                    break;
                case in_progress: show_by("in_progress", -1);
                    break;
                case varificate: show_by("varificate", -1);
                    break;
                case done: show_by("done!", -1);
                    break;
                case 5: show_by("all", -1);
                    break;
                case 6: assignment_menu();
                    break;
            }
            break;
        }
        else
        {
            cout << "Retry! Choice should be in range (1..6)!\n";
            choice.clear();
            cin >> choice;
        }
    }
}

void assignment_menu()
{
    vector<Task> tasks(DTOTask::write_from_file());
    string assignment;
    short assign_temp;
    cout << "Input assignment of the task, which should be shown: ";
    while(true)
    {
        locale loc;
        cin >> assignment;
        if (isdigit(assignment[0], loc))
        {
            stringstream(assignment) >> assign_temp;
            break;
        }
        else
        {
            cout << "Retry! Assignment should be a digit greater than zero or equal!\n";
        }
    }
    show_by("all", assign_temp);
}

//show by state and assignment: if state = "all" and assign = -1, all tasks will be shown
void show_by(string state, int assign)
{
    vector<Task> tasks(DTOTask::write_from_file());
    printf("%-5s%-20s%-20s%-20s%-15s\n", "Id", "Name", "State", "Description", "Assignment");
    int counter = 0;
    for (int i = 0; i < tasks.size() - 1; i++) {
        if((tasks[i].get_state() == state && tasks[i].get_assignment() == assign)
            || (state == "all" && tasks[i].get_assignment() == assign)
                || (assign == -1 && tasks[i].get_state() == state)
                    || (assign == -1 && state == "all"))
        {
            counter++;
            printf("%-5i%-20s%-20s%-20s%-15i\n", i, tasks[i].get_name().c_str(),
                   tasks[i].get_state().c_str(), tasks[i].get_description().c_str(),
                   tasks[i].get_assignment());
        }
        else if(i == tasks.size() - 2 && counter == 0)
        {
            cout << "\t\t\tThere are no any tasks with given state or assignment...\n";
        }
    }
}

void add_new_task(Task& task, DTOTask& dto)
{
    string state;
    string name;
    string description;
    string assignment;
    cout << "Enter name: ";
    cin >> name;
    task.set_name(name);
    cin.get();
    cout << "Enter state(1 - 'to_do', 2 - 'in_progress', 3 - 'varificate', 4 - 'done!'): ";
    while(true)
    {
        getline(cin, state);
        if(state == "1" || state == "2" || state == "3" || state == "4")
        {
            switch(stoi(state))
            {
                case to_do: task.set_state("to_do");
                    break;
                case in_progress: task.set_state("in_progress");
                    break;
                case varificate: task.set_state("varificate");
                    break;
                case done: task.set_state("done!");
                    break;
            }
            break;
        }
        else
        {
            cout << "Retry!\n";
        }
    }
    cout << "Enter description: ";
    getline(cin, description);
    task.set_description(description);
    cout << "Input assignment: ";
    while(true)
    {
        locale loc;
        cin >> assignment;
        if (isdigit(assignment[0], loc))
        {
            short assign_temp;
            stringstream(assignment) >> assign_temp;
            task.set_assignment(assign_temp);
            break;
        }
        else
        {
            cout << "Retry! Assignment should be a digit greater than zero or equal!\n";
        }
    }
    dto.write_to_file(task);
}

void update()
{
    DTOTask d;
    vector<Task>  tasks;
    tasks = d.write_from_file();
    string id;
    cout << "Input id of the task, which you want to update: ";
    cin >> id;
    int counter = 0;
    while(true)
    {
        for(int i = 0; i < tasks.size() - 1; i++)
        {
            if(id == to_string(i))
            {
                d.update_task(stoi(id));
                counter++;
                break;
            }
        }
        if(counter != 0)
        {
            break;
        }
        cout << "Retry! Id should be <= number of lines in file!\n";
        id.clear();
        cin >> id;
    }
}

void erase_task()
{
    DTOTask d;
    vector<Task>  tasks;
    tasks = d.write_from_file();
    string id;
    cout << "Input id of the task, which you want to delete: ";
    cin >> id;
    int counter = 0;
    while(true)
    {
        for(int i = 0; i < tasks.size(); i++)
        {
            if(id == to_string(i))
            {
                d.delete_task(stoi(id));
                counter++;
                break;
            }
        }
        if(counter != 0)
        {
            break;
        }
        cout << "Retry! Id should be <= number of lines in file!\n";
        id.clear();
        cin >> id;
    }
}