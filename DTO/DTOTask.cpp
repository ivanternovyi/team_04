#include "DTOTask.h"


using namespace std;

vector<Task> DTOTask::write_from_file()
{
    ifstream file("../data/Task.csv");
    string line;
    vector<Task> tasks;
    if (file.is_open())
    {
        while (getline(file,line))
        {
            Task task;
            task.parse_line(line);
            tasks.push_back(task);
        }
        file.close();
        return tasks;
    }
    else
    {
        cout << "File not found!" << endl;
    }
    return tasks;
}

void DTOTask::write_to_file(Task obj){
    ofstream file("../data/Task.csv", ios::app);
    if (file)
    {
        file << obj;
    }
    else
    {
        cout << "File not found!" << endl;
    }
    file.close();
}

void DTOTask::delete_task(short id)
{
    ifstream file("../data/Task.csv");
    ofstream out("../data/outfile.csv", ios::app);
    string line;
    int k = 0;
    while(getline(file, line))
    {
        if(k != id)
        {
            out << line << "\n";
        }
        k++;
    }
    file.close();
    out.close();
    remove("../data/Task.csv");
    rename("../data/outfile.csv","../data/Task.csv");
}

void DTOTask::update_task(short id)
{
    vector<Task>  tasks;
    tasks = write_from_file();
    Task t = tasks[id];
    if(t.get_counter() < 3 && t.get_counter() != -1)
    {
        delete_task(id);
        if(t.get_counter() + 1 == 1)
        {
            t.set_state("in_progress");
        }
        else if(t.get_counter() + 1 == 2)
        {
            t.set_state("varificate");
        }
        else if(t.get_counter()  + 1 == 3)
        {
            t.set_state("done!");
        }
        write_to_file(t);
    }
    else
    {
        cout << "It`s impossible to update current task!\n";
    }
}