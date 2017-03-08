#ifndef MANAGER_DATA_H
#define MANAGER_DATA_H
#include "../Entity/Task.h"

//here should be transforming data
class Data {
public:
    void write_to_file();

    Task write_from_file();

    friend istream& operator >> (istream& is, Task& temp);
};


#endif
