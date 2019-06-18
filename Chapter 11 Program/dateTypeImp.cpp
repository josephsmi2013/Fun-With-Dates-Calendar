#include <iostream>
#include "dateType.h"

using namespace std;

dateType::dateType(int month, int day, int year)
{
	setDate(month, day, year);
}

void dateType::setDate(int month, int day, int year) 
{

	if (isDateValid(month, day, year))
	{
		dMonth = month;
		dDay = day;
		dYear = year;
	}
}

bool dateType::isDateValid(int month, int day, int year) const
{
	if (year < 1000 || year > 9999) return false;
	if (month < 1 || month > 12) return false;
	if (day < 1 || day > 31) return false;

	if (month == 2)
	{
		if (isLeapYear(year)) return (day <= 29);
		else return (day <= 28);
	}

	if (month == 4 || month == 6 || month == 9 || month == 11) return (day <= 30);

	return true;
}

bool dateType::isLeapYear(int year) const
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

int dateType::getDay() const
{
	return dDay;
}

int dateType::getMonth() const
{
	return dMonth;
}

int dateType::getYear() const
{
	return dYear;
}

void dateType::printDate() const
{
	cout << dMonth << "-" << dDay << "-" << dYear;
}

int dateType::getMonthDays() const
{
	if (dMonth == 2) return 28;
	if (dMonth == 4 || dMonth == 6 || dMonth == 9 || dMonth == 11) return 30;
	else return 31;
}

int dateType::getDaysPast() const
{
	int months[13] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int monthDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	int days = 0;
	for (int i = 1; i <= 12; i++)
	{
		if (dMonth == i)
		{
			return days + dDay;
		}

		days = days + monthDays[i];
	}

	return 0;
}

int dateType::getDaysRemain() const
{
	return 365 - getDaysPast();
}

string dateType::getOffsetDate(int x) const
{
	int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int offset = getDaysPast();
	int remDays = getDaysRemain();
	int day;
	int month;
	int year;

	if (x <= remDays)
	{
		year = dYear;
		offset = offset + x;
	}
	else
	{
		x = x - remDays;
		year = dYear + 1;

		int y2days = 365;
		while (x >= y2days)
		{
			x = x - y2days;
			year = year + 1;
			y2days = 365;
		}

		offset = x;
	}

	int i;
	for (i = 1; i <= 12; i++)
	{
		if (offset <= months[i]) break;
		offset = offset - months[i];
	}

	month = i;
	day = offset;

	return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}