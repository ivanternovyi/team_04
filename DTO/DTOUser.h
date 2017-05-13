//
// Created by nazar on 09.05.17.
//

#ifndef TEAM_04_DTOUSER_H
#define TEAM_04_DTOUSER_H
#pragma once
#include <fstream>
#include <iostream>
#include "../Entity/User.h"
#include <vector>

class DTOUser {
    //reading data from file
    static vector<User> write_from_file();
    //write task to file ../data/Task.csv
    void write_to_file(User obj);;
    //deleting task in file by given name
    void delete_user(short id);
    //upgrading task by reassigning state if necessary
    void change_user_data(short id);
};


#endif //TEAM_04_DTOUSER_H
