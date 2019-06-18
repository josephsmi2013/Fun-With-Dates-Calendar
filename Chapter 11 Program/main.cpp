/****************************************************
Author: Joe Smith
Last Modified: June 13, 2019
Purpose: Manipulates date and calendar objects
****************************************************/

//includes here
#include <iostream>
#include <string>
#include "extDateType.h"
#include "calendarType.h"

//namespace here
using namespace std;

//prototypes here
void showMenu();
void setDate(extDateType&);
void getDate(extDateType&);
void checkYear(extDateType&);
void getMonthDays(extDateType&);
void getDaysPast(extDateType&);
void getDaysRemain(extDateType&);
void getOffsetDate(extDateType&);
void getCalendar();

//main program here
int main() 
{
	//declare variables
	extDateType yourDate;
	int userChoice;

	//initial user message
	cout << "Welcome to Fun With Dates!\n";

	//show menu/decision loop
	showMenu();
	cin >> userChoice;

	while (userChoice != 0)
	{
		switch (userChoice)
		{
			case 1:
				setDate(yourDate);
				break;
			case 2:
				getDate(yourDate);
				break;
			case 3:
				checkYear(yourDate);
				break;
			case 4:
				getMonthDays(yourDate);
				break;
			case 5:
				getDaysPast(yourDate);
				break;
			case 6:
				getDaysRemain(yourDate);
				break;
			case 7:
				getOffsetDate(yourDate);
				break;
			case 8:
				getCalendar();
				break;
			default:
				cout << "invalid selection\n";
		}

		showMenu();
		cin >> userChoice;
	}

	return 0;

}

//displays the main menu
void showMenu()
{
	cout << '\n';
	cout << "Make a selection by choosing a number below\n";
	cout << "1. Set a new date\n";
	cout << "2. Return the month, day and, year entered\n";
	cout << "3. Check if the date is in a leap year\n";
	cout << "4. Return the number of days in month\n";
	cout << "5. Return the number of days past in year\n";
	cout << "6. Return the number of days remaining in year\n";
	cout << "7. Return the date with some days added\n";
	cout << "8. Print a monthly calendar\n";
	cout << "0. Exit the program\n";
}

//Collects user date, parses the date string and sends it for validation
void setDate(extDateType& yourDate)
{
	string userDate;
	char delimiter;
	int month;
	int day;
	int year;

	cout << "Please provide a date in mm/dd/yyyy format\n";
	cin >> userDate;

	delimiter = '/';

	month = stoi(userDate.substr(0, userDate.find(delimiter)));
	day = stoi(userDate.substr(3, userDate.find(delimiter)));
	year = stoi(userDate.substr(6, userDate.find(delimiter) + 2));

	yourDate.setDate(month, day, year);
}

//Outputs the Month, Day and Year variables
void getDate(extDateType& yourDate)
{
	int userChoice;

	cout << "Pick a date format\n";
	cout << "1. mmm yyyy\n";
	cout << "2. mm-dd-yyyy\n";

	cin >> userChoice;

	if (userChoice == 1) yourDate.getDateString();
	else cout << "Your date is " << yourDate.getMonth() << "-" << yourDate.getDay() << "-" << yourDate.getYear() << '\n';
}

//Outputs Yes or No if year is a leap year
void checkYear(extDateType& yourDate)
{
	bool isLeap;
	int year;

	year = yourDate.getYear();
	isLeap = yourDate.isLeapYear(year);

	if (isLeap) cout << "Yes. Your date is in a leap year\n";
	else cout << "No. Your date is not in a leap year\n";
	
}

//Outputs the number of days in the month entered
//Doesn't consider leap years
void getMonthDays(extDateType& yourDate)
{
	cout << "The number of days in your month is " << yourDate.getMonthDays() << '\n';
}

//Outputs the number of days passed for a given date
//Doesn't considered the year entered
void getDaysPast(extDateType& yourDate)
{
	cout << "The number of days passed is " << yourDate.getDaysPast() << '\n';
}

//Outputs the number of days passed for a given date
//Doesn't considered the year entered
void getDaysRemain(extDateType& yourDate)
{
	cout << "The number of days remaining is " << yourDate.getDaysRemain() << '\n';
}

//Outputs a new date based on days input
//Doesn't alter the date stored in our object
//Doesn't consider lear years
void getOffsetDate(extDateType& yourDate)
{
	int days;

	cout << "How many days should we add on?\n";
	cin >> days;
	cout << "The new date is " << yourDate.getOffsetDate(days) << "\n";
}

//Prints a monthly calendar
void getCalendar()
{
	calendarType yourCalendar;
	int month;
	int year;


	cout << "Enter the month and year of the calendar to display\n";
	cin >> month >> year;

	yourCalendar.getCalendar(month, year);
}