#include <iostream>
#include "../Entity/Task.h"
#include "../DTO/DTOTask.h"
#include "Menu.h"


using namespace std;

int first_menu()
{
    string choose;
    cout << "***************************" << endl;
    cout << "1) Show all tasks" << endl;
    cout << "2) New task" << endl;
    cout << "3) Update" << endl;
    cout << "4) Delete" << endl;
    cout << "5) Exit" << endl;
    cout << "***************************" << endl;
    cout << "Enter your choice: ";
    cin >> choose;
    while(true)
    {
        if(choose == "1" || choose == "2" || choose == "3" || choose == "4" || choose == "5")
        {
            break;
        }
        else
        {
            cout << "Retry! Choice should be in range (1..5)!\n";
            choose.clear();
            cin >> choose;
        }
    }
    return stoi(choose);
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
                system("clear");
                break;
            }


            case 2:
            {
                add_new_task(t, d);
                system("clear");
                break;
            }

            case 3:
            {
                update();
                system("clear");
                break;
            }
            case 4:
            {
                system("clear");
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

void add_new_task(Task& t, DTOTask& d)
{
    string state;
    string name;
    cout << "Enter name: " << endl;
    cin >> name;
    cout << "Enter state('to_do', 'in_progress', 'varificate', 'done!'): " << endl;
    while(true)
    {
        getline(cin, state);
        if(state == "to_do" || state == "in_progress" || state == "varificate" || state == "done!")
        {
            break;
        }
        else
        {
            cout << "Retry!\n";
        }
    }
    t.set_name(name);
    t.set_state(state);
    d.write_to_file(t);

}

void show_all_task()
{
    vector<Task> tasks(DTOTask::write_from_file());
    cout << "Name: " << "\t" << "State: " << endl;
    for(int i = 0 ; i < tasks.size() - 1; i++)
    {
        cout << "Id: " << i << "\t"<< tasks[i].get_name() << "\t" << tasks[i].get_state() << endl;
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
        for(int i = 0; i < tasks.size(); i++)
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
