#ifndef extDateType_H
#define extDateType_H

#include "dateType.h"

class extDateType: dateType
{
public:
	extDateType(int month = 1, int day = 1, int year = 1500);
	void setDate(int, int, int);
	bool isDateValid(int, int, int) const;
	bool isLeapYear(int) const;
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void printDate() const;
	int getMonthDays() const;
	int getDaysPast() const;
	int getDaysRemain() const;
	string getOffsetDate(int);
	void getDateString() const;


private:
	string monthString;
};

#endif