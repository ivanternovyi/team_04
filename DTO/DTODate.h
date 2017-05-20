#include <iostream>
#include <string>
#include "../Entity/Date.h"
#pragma once


using namespace std;

class DTODate
{
private:
	Date date;
public:
	DTODate(){};

    DTODate(const DTODate& obj)
    {
        this->date = obj.date;
    }

    DTODate(string line);

    string get_string_date();

    friend istream& operator>>(istream& is, DTODate&d);

	friend ostream& operator<<(ostream& os, DTODate&d);

	void format(char** string_date);

	friend bool operator<(Date left, Date right);

	friend bool operator>(Date left, Date right);

	friend bool operator==(Date left, Date right);

	friend bool operator!=(Date left, Date right);
};
