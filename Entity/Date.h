#pragma once
using namespace std;

class Date
{
private:
	unsigned short  day;
	unsigned short  month;
	unsigned short  year;
	unsigned short  hour;
	unsigned short  minute;
	unsigned short second;
public:
	Date();
	Date(unsigned short d, unsigned short m, unsigned short y, unsigned short h, unsigned short mi, unsigned short s):
		day(d),
		month(m),
		year(y),
		hour(h),
		minute(mi), 
		second(s)
	{}
	unsigned short  get_day();
	unsigned short  get_month();
	unsigned short  get_year();
	unsigned short  get_hour();
	unsigned short  get_minute();
	unsigned short  get_second();
	void set_day(unsigned short x);
	void set_month(unsigned short x);
	void set_year(unsigned short x);
	void set_hour(unsigned short x);
	void set_minute(unsigned short x);
	void set_second(unsigned short x);
};
