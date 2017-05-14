#include "Date.h"


Date::Date():day(0), month(0), year(0), hour(0), minute(0){}

unsigned short Date::get_day()
{
	return this->day;
}

unsigned short Date::get_month()
{
	return this->month;
}

unsigned short Date::get_year()
{
	return this->year;
}

unsigned short Date::get_hour()
{
	return this->hour;
}

unsigned short Date::get_minute()
{
	return this->minute;
}

unsigned short Date::get_second()
{
	return this->second;
}

void Date:: set_day(unsigned short x)
{
	this->day = x;
}

void Date::set_month(unsigned short x)
{
	this->month = x;
}

void Date::set_year(unsigned short x)
{
	this->year = x;
}

void Date::set_hour(unsigned short x)
{
	this->hour = x;
}

void Date:: set_minute(unsigned short x)
{
	this->minute = x;
}

void Date:: set_second(unsigned short x)
{
	this->second = x;
}