#include "Date.h"

#include <iostream>
using std::cout;
using std::endl;

// Overload output operator
ostream &operator<< (ostream &output, const Date &date)
{
	switch (date.month){
	case 1:
		cout << "Jan";
		break;
	case 2:
		cout << "Fev";
		break;
	case 3:
		cout << "Mar";
		break;
	case 4:
		cout << "Apr";
		break;
	case 5:
		cout << "May";
		break;
	case 6:
		cout << "Jun";
		break;
	case 7:
		cout << "Jul";
		break;
	case 8:
		cout << "Aug";
		break;
	case 9:
		cout << "Sep";
		break;
	case 10:
		cout << "Ouc";
		break;
	case 11:
		cout << "Nov";
		break;
	case 12:
		cout << "Dec";
		break;
	}
	cout << " "<<date.day << ", ";
	cout << date.year << endl;

	return output;

}

// Overload operator ==
bool Date::operator== (const Date &date) const
{
	if (this->day == date.day)
		return false;
	if (this->month == date.month)
		return false;
	if (this->year == date.year)
		return false;
	
	return true;
}

// Overload assignment operator
const Date &Date::operator= (const Date &date)
{
	this->day = date.day;
	this->month = date.month;
	this->year = date.year;
	
	return *this;
}

// Constructor of Date class
Date::Date(int d, int m, int y) 
{
	if ( m > 0 && m <= 12 ) // validate the month
		month = m;
	
	if ( y < 0 )
		year = 1900;
	else
		year = y;
   
	day = CheckDay(d);

}

//Copy constructor
Date::Date(const Date &dateCopy)
{
	this->day = dateCopy.day;
	this->month = dateCopy.month;
	this->year = dateCopy.year;
}

// Destructor
Date::~Date()
{
//	cout << "~Date() called" << endl;
}

// Check date
int Date::CheckDay(int dayTest) const
{
	static const int daysForMonth[ 13 ] = 
	   { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	if ( dayTest > 0 && dayTest <= daysForMonth[ month ] )
		return dayTest;
	
	if ( month == 2 && dayTest == 29 && ( year % 400 == 0 ||
			( year % 4 == 0 && year % 100 != 0 ) ) )
		return dayTest;
	
	cout << "Invalid day (" << dayTest << ") configured for 1.\n";
	return 1; 
}

