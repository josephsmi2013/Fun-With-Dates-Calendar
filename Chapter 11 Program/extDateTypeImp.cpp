#include <iostream>
#include "extDateType.h"

using namespace std;

extDateType::extDateType(int month, int day, int year)
	: dateType()
{
	setDate(month, day, year);
}

void extDateType::setDate(int month, int day, int year)
{
	dateType::setDate(month, day, year);
}

bool extDateType::isDateValid(int month, int day, int year) const
{
	return dateType::isDateValid(month, day, year);
}

bool extDateType::isLeapYear(int year) const
{
	return dateType::isLeapYear(year);
}

int extDateType::getDay() const
{
	return dateType::getDay();
}

int extDateType::getMonth() const
{
	return dateType::getMonth();
}
int extDateType::getYear() const
{
	return dateType::getYear();
}

void extDateType::printDate() const
{
	dateType::printDate();
}

int extDateType::getMonthDays() const
{
	return dateType::getMonthDays();
}

int extDateType::getDaysPast() const
{
	return dateType::getDaysPast();
}

int extDateType::getDaysRemain() const
{
	return dateType::getDaysRemain();
}

string extDateType::getOffsetDate(int days)
{
	return dateType::getOffsetDate(days);
}

void extDateType::getDateString() const
{
	string months[13] = {"NA", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	int month;
	int year;

	month = getMonth();
	year = getYear();

	for (int i = 0; i <= 12; i++)
	{
		if (i == month)
		{
			cout << months[i] << ' ' << year << '\n';
			break;
		}
	}
}
