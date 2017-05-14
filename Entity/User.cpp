#include "User.h"


User::User()
{
    this->username = "";
    this->login = "";
    this->password = "";
}

User::User(string username, string login, string password)
{
    this->username = username;
    this->login = login;
    this->password = password;
}

User::User(const User &obj)
{
    this->username = obj.username;
    this->login = obj.login;
    this->password = obj.password;
}

string User::get_username()
{
    return this->username;
}

void User::set_username(string username)
{
    this->username = username;
}

string User::return_login()
{
    return this->login;
}

void User::set_login(string login)
{
    this->login = login;
}

string User::return_password()
{
    return this->password;
}

void User::set_password(string groupname)
{
    this->password = password;
}