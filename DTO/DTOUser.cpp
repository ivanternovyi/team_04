//
// Created by nazar on 09.05.17.
//

#include "DTOUser.h"

vector<User> DTOUser::write_from_file() {
    ifstream file("../data/User.csv");
    vector<User> users;
    if (file.is_open())
    {
        while (!file.eof())
        {
            User user;
            file >> user;
            users.push_back(user);
        }
        file.close();
        return users;
    }
    else
    {
        cout << "File not found!" <<endl;
    }
    return users;
}

void DTOUser::write_to_file(User obj) {
    ofstream file("../data/User.csv", ios::app);
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

void DTOUser::delete_user(short id) {
    ifstream file("../data/User.csv");
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
    remove("../data/User.csv");
    rename("../data/outfile.csv","../data/User.csv");
}

void DTOUser::change_user_data(short id) {
    vector<User> users;
    users = write_from_file();
    User t = users[id];
}

bool DTOUser::is_unique_user(string username) {
    bool result = true;
    vector<User> users;
    users = write_from_file();
    for (int i = 0; i < users.size() ; ++i) {
        if(users[i].get_username() == username){
            result = false;
        }
    }
    return result;
}
