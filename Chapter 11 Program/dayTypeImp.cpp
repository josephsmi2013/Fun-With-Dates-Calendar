#include <iostream>
#include "dayType.h"



dayType::dayType()
{
	cDay = 1;
}

dayType::dayType(int day)
{
	setDay(day);
}

void dayType::setDay(int day)
{
	cDay = day;
}

void dayType::printDay() const
{
	for (int i = 1; i <= 6; i++)
	{
		if (i = cDay)
		{
			cout << "Your day is " << cDays[i];
		}
	}
}

int dayType::getDay() const
{
	return cDay;
}

int dayType::getNextDay() const
{
	return cDay + 1;
}

int dayType::getPreviousDay() const
{
	return cDay - 1;
}

string dayType::getOffsetDay(int offset) const
{
	int day;
	string dayString;


	day = cDay + (offset % 7);

	for (int i = 1; i <= 6; i++)
	{
		if (i = day)
		{
			dayString = cDays[i];
			break;
		}
	}
	return dayString;
}