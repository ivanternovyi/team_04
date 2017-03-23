#include <iostream>
#include "../Entity/Task.h"
#include "../DTO/DTOTask.h"
#include "Menu.h"


using namespace std;

int first_menu()
{
    int choose;
    cout << "***************************" << endl;
    cout << "1) Show all tasks" << endl;
    cout << "2) New task" << endl;
    cout << "3) Update" << endl;
    cout << "4) Delete" << endl;
    cout << "5) Exit" << endl;
    cout << "***************************" << endl;
    cout << "Enter your choice: ";
    cin >> choose;
    return choose;
}

void menu (DTOTask &d, Task &t)
{
    int your_choice = 0;
    while(your_choice != 5){
        your_choice = first_menu();
        switch (your_choice){
            case 1:
            {
                show_all_task();
                system("pause>null");
                //system("cls");
                break;
            }


            case 2:
            {
                add_new_task(t, d);
                system("cls");
                break;
            }

            case 3:
            {
                update();
                system("cls");
                break;
            }
            case 4:
            {
                erase_task();
                cin.get();
                system("cls");
                break;
            }
            default:
            {
                system("cls");
                break;
            }
        }
    }
}

void add_new_task(Task& t, DTOTask& d)
{
    string state;
    string name;
    cout << "Enter name: " << endl;
    cin >> name;
    cout << "Enter state('to_do', 'in_progress', 'varificate', 'done!'): " << endl;
    cin >> state;
    t.set_name(name);
    t.set_state(state);
    d.write_to_file(t);

}

void show_all_task()
{
    vector<Task> tasks(DTOTask::write_from_file());
    cout << "Name: " << "\t" << "State: " << endl;
    for(int i = 0 ; i < tasks.size(); i++)
    {
        cout << tasks[i].get_name() << "\t" << tasks[i].get_state() << endl;
    }
}

void erase_task()
{
    short id;
    cout << "Input id of the task, which you want to delete: ";
    cin >> id;
    DTOTask d;
    d.delete_task(id);
}

void update()
{
    short id;
    cout << "Input id of the task, which you want to update: ";
    cin >> id;
    DTOTask d;
    d.update_task(id);
}
