#include <string>
#include <iostream>
#include <iomanip>
#include "calendarType.h"

using namespace std;

calendarType::calendarType()
{

}

void calendarType::getCalendar(int month, int year) const
{
	string months[13] = { "NA", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	int monthDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	string calendar;
	int yOffset;
	int mOffset;
	int dOffset;
	int i;
	int j;
	string monthName;
	int monthDay;


	yOffset = year - calendarDate.getYear();
	mOffset = month - calendarDate.getMonth();
	dOffset = 0;

	for (i = 0; i < yOffset; i++)
	{
		dOffset = dOffset + 365;
	}

	for (i = 0; i <= mOffset; i++)
	{
		dOffset = dOffset + monthDays[i];
	}



	for (i = 0; i <= 12; i++)
	{
		if (i == month)
		{
			monthName = months[i];
			monthDay = monthDays[i];
		}
	}



	cout << '\n' << monthName << ' ' << year << '\n';
	
	i = 1;
	j = 0;
	int rowCounter = 0;
	int colCounter = 0;

	while (rowCounter < 7)
	{
		while (colCounter < 7)
		{
			if (rowCounter == 0)
			{
				cout << left << setw(10) << setfill(' ') << calendarDay.cDays[colCounter];
			}
			else if(calendarDay.getOffsetDay(dOffset) == calendarDay.cDays[colCounter])
			{
				if (rowCounter == 1)
				{
					while (j < colCounter)
					{
						cout << left << setw(10) << setfill(' ') << ' ';
						j = j + 1;
					}

					cout << left << setw(10) << setfill(' ') << 1;
					i = i + 1;
				}
			}
			else if (i > 1 && i <= monthDay)
			{
				cout << left << setw(10) << setfill(' ') << i;
				i = i + 1;
			}

			colCounter = colCounter + 1;
		}

		cout << endl;

		colCounter = -1;
		rowCounter = rowCounter + 1;
	}

}