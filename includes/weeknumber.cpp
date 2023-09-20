#include <ctime>
#include <math.h>
#include "weeknumber.hpp"
#define ConvertNr 604800

int getWeekNumber()
{
	double seconds;
	
	time_t CurrentDate;
	time(&CurrentDate);

	struct tm StartDate {0};
	
	StartDate.tm_hour = 0;   StartDate.tm_min = 0; StartDate.tm_sec = 0;
  	StartDate.tm_year = 2023-1900; StartDate.tm_mon = 9; StartDate.tm_mday = 2;
	
	//get the difference in sec and make it positive 
	seconds = fabs(difftime(CurrentDate, mktime(&StartDate)));

	double weekNumber = seconds/ConvertNr;
	int weekNumberRounded = ceil(weekNumber);
	return weekNumberRounded;
}
