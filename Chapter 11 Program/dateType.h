#include <string>

using namespace std;

class dateType
{

public:
	dateType(int month = 1, int day = 1, int year = 1500);
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
	string getOffsetDate(int) const;

private:
	int dMonth;
	int dDay;
	int dYear;
};