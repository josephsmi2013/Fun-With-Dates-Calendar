#include "dayType.h"
#include "extDateType.h"

using namespace std;

class calendarType
{

public:
	calendarType();
	void getCalendar(int, int) const;
private:
	dayType calendarDay;
	extDateType calendarDate;
};