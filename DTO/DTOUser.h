#ifndef TEAM_04_DTOUSER_H
#define TEAM_04_DTOUSER_H
#pragma once
#include <fstream>
#include <iostream>
#include "../Entity/User.h"
#include <vector>

class DTOUser
{
    //reading data from file
    static vector<User> write_from_file();
    //write user to file ../data/User.csv
    void write_to_file(User obj);;
    //deleting user from file by id
    void delete_user(short id);

    void change_user_data(short id);
};


#endif
