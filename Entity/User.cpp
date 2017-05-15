//
// Created by nazar on 03.05.17.
//

#include "User.h"

User::User() {
    this->username = "";
    this->login = "";
    this->password = "";
}

User::User(string username, string login, string password) {
    this->username = username;
    this->login = login;
    this->password = password;
}

User::User(const User &obj) {
    this->username = obj.username;
    this->login = obj.login;
    this->password = obj.password;
}

string User::get_username() {
    return this->username;
}

void User::set_username(string username) {
    this->username = username;
}

string User::get_login() {
    return this->login;
}

void User::set_login(string login) {
    this->login = login;
}

string User::get_password() {
    return this->password;
}

void User::set_password(string groupname) {
    this->password = password;
}

void User::parse_line(string line) {
    size_t found1 = line.find(",");
    this->username = line.substr(0, found1);
    size_t found2 = line.find(",", found1 + 1, 1);
    this->login = line.substr(found1+1, found2 - found1 - 1);
    found1 = line.find(",", found2 + 1, 1);
    this->password = line.substr(found2 + 1, found1 - found2 - 1);
}


istream &operator>>(istream &is, User &user) {
    string line;
    getline(is, line);
    user.parse_line(line);
    return is;
}

ostream &operator<<(ostream &os, User &user) {
    os << user.get_username();
    os << ",";
    os << user.get_login();
    os << ",";
    os << user.get_password();
    os <<"\n";
    return os;
}
