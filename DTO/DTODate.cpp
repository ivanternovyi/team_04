#include"DTODate.h"
DTODate::DTODate() {};

istream& operator>>(istream& is, DTODate&d)
{
	cout << "Enter date (format - dd mm yyyy hh mm ss - spaces in between)\n";
	char** arr = new char*[6];
	for (int i = 0; i < 6; i++)
	{
		if (i == 2)
		{
			arr[i] = new char[4];
		}
		else
		{
			arr[i] = new char[2];
		}
	}
		
	for (int i = 0; i < 6; i++)
	{
		if (i == 2)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> arr[i][j];
			}

		}
		else
		{
			for (int j = 0; j < 2; j++)
			{
				cin >> arr[i][j];
			}
		}
		
	}
	d.format(arr);



	//      Check if entered date is correct
	bool check=false, b;
	if (d.date.get_year() % 4 == 0)
	{	
		b = 1;
		if (d.date.get_year() % 100 == 0) 
		{
			if (d.date.get_year() % 400 == 0) 
			{
				b = 1;
			}
			else
			{
				b = 0;
			}
		}
	}
	else
	{
		b = 0;
	};
	switch (d.date.get_month())
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (d.date.get_day() <= 31)
		{
			check = true;
		}

		break;

	case 4:
	case 6:
	case 9:
	case 11:
		if (d.date.get_day() <= 30)
		{
			check = true;
		}
		break;
	case 2:
		switch (b)
		{
		case 1:
			if (d.date.get_day() <= 29)
			{
				check = true;
			}
			break;
		case 0:
			if (d.date.get_day() <= 28)
			{
				check = true;
			}
			break;

		}
		break;
	default: check = false;
		break;
	}
	if ((d.date.get_hour() >= 24) || (d.date.get_minute() >= 60)|| (d.date.get_second()>=60))
	{
		check = false;
	}
	if (check == 0)
	{
		cout << "Date format is incorrect\n";
	}

	return is;
};
ostream&  operator<<(ostream& os, DTODate&d)
{
	if (d.date.get_day() < 10)
	{
		os << "0" << d.date.get_day();
	}
	else
	{
		os << d.date.get_day();
	}
	os << ".";
	if (d.date.get_month() < 10)
	{
		os << "0" << d.date.get_month();
	}
	else
	{
		os << d.date.get_month();
	}
	os << "." << d.date.get_year() << " " << d.date.get_hour() << ":";
	if (d.date.get_minute() < 10)
	{
		os << "0" << d.date.get_minute();
	}
	else
	{
		os <<  d.date.get_minute();
	}
	if (d.date.get_second() < 10)
	{
		os << "0" << d.date.get_second();
	}
	else
	{
		os << d.date.get_second();
	}
	return os;
};
void DTODate::format(char** string_date)
{
	this->date.set_day(atoi(string_date[0]));
	this->date.set_month(atoi(string_date[1]));
	this->date.set_year(atoi(string_date[2]));
	this->date.set_hour(atoi(string_date[3]));
	this->date.set_minute(atoi(string_date[4]));
};


bool operator<(Date left, Date right)
{
	if (left.get_year() < right.get_year())
	{
		return true;
	}
	if (left.get_month() < right.get_month())
	{
		return true;
	}
	if (left.get_day() < right.get_day())
	{
		return true;
	}
	if (left.get_hour() < right.get_hour())
	{
		return true;
	}
	if (left.get_minute() < right.get_minute())
	{
		return true;
	}
	if (left.get_second() < right.get_second())
	{
		return true;
	}
	return false;
};
bool operator>(Date left, Date right)
{
	return !(left < right);

};
bool operator==(Date left, Date right)
{
	if ((left.get_day() == right.get_day()) &&
		(left.get_hour() == right.get_hour()) &&
		(left.get_minute() == right.get_minute()) &&
		(left.get_month() == right.get_month()) &&
		(left.get_year() == right.get_year())&&
		(left.get_second() == right.get_second()))
	{
		return true;
	}
	else
	{
		return false;
	}
};
bool operator!=(Date left, Date right)
{
	
	if ((left.get_day() != right.get_day()) ||
		(left.get_hour() != right.get_hour()) ||
		(left.get_minute() != right.get_minute()) ||
		(left.get_month() != right.get_month()) ||
		(left.get_year() != right.get_year()) ||
		(left.get_second() != right.get_second()))
	{
		return true;
	}
	else
	{
		return false;
	}

};

