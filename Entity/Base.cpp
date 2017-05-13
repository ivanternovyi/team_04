#include "Base.h"
#include <fstream>
#include <iostream>


using namespace std;

short Base::readId()
{
    string line;
    ifstream file("../data/BaseID.txt");
    if(!file.is_open())
    {
        cout << "Can`t read id!\n";
        exit(0);
    }
    else
    {
        file >> line;
        if(line.empty())
        {
            id = 1;
        }
        else
        {
            id = stoi(line);
        }
    }
    file.close();
    renewId(id);
    return id;
}

void Base::renewId(short oldId)
{
    ofstream fileIn("../data/BaseID.txt", ios::trunc);
    string toFile = to_string(oldId + 1);
    fileIn << toFile;
    fileIn.close();
}

short Base::getBaseId()
{
    return id;
}

inline Base::~Base()
{
    id = 0;
}