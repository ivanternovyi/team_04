#include "DTOTask.h"


vector<Task> DTOTask::write_from_file()
{
    ifstream file("../data/Task.txt");
    vector<Task> tasks;
    if (file.is_open())
    {
        while (!file.eof())
        {
            Task task;
            file >> task;
            tasks.push_back(task);
        }
        file.close();
        return tasks;
    }
    else
    {
        cout << "File not found!" <<endl;
    }
    return tasks;
}

void DTOTask::write_to_file(Task obj){
    ofstream file("../data/Task.txt", ios::app);
    if (file)
    {
        file << obj.get_name ();
        file << ",";
        file << obj.get_state ();
        file <<"\n";
    }
    else
    {
        cout << "File not found!" << endl;
    }
    file.close();
}