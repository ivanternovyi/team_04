#include "DTOTask.h"
#include <string>
#include <cstdio>


using namespace std;

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

void DTOTask::delete_task(string given_name)
{
    ifstream file("../data/Task.txt");
    ofstream out("../data/outfile.txt", ios::app);
    string line, name;
    int k = 0;
    while(getline(file, line))
    {
        int pos = line.find(',');
        while(k < pos)
        {
            name += line[k];
            k++;
        }
        if(given_name == name)
        {
            continue;
        }
        else
        {
            out << line << "\n";
        }
        name.clear();
        k = 0;
    }
    file.close();
    out.close();
    remove("../data/Task.txt");
    rename("../data/outfile.txt","../data/Task.txt");
}
