#include <string>

using namespace std;

class dayType
{
public:
	dayType();
	dayType(int);
	void setDay(int);
	void printDay() const;
	int getDay() const;
	int getNextDay() const;
	int getPreviousDay() const;
	string getOffsetDay(int) const;
	string cDays[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

private:
	int cDay;

};