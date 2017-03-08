#ifndef MANAGER_TASK_H
#define MANAGER_TASK_H
#include <string>

using namespace std;

class Task {
private:
    string name;
    string state;
public:
    Task():name(""), state(""){};

    Task(string n, string s):name(n), state(s){};

    void set_name(string s);

    void set_state(string st);

    string get_name();

    string get_state();
};


#endif
