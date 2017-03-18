#ifndef _DATE_H_
#define	_DATE_H_

#include <ostream>
using std::ostream;

class Date 
{
	//Overload output operator
	friend ostream &operator<<(ostream &, const Date &);
public:
	const Date &operator=(const Date &);
	bool operator== (const Date &) const;
	// Defined operator !=
	bool operator!= (const Date &date) const
	{
		return ! (*this == date);
	}
	Date( int = 1, int = 1, int = 1900);
	Date(const Date &);
	~Date();
	void print() const;
	 
private:
	 
	int month;
	int day;
	int year;
	 
	int CheckDay( int ) const;


};

#endif	/* DATE_H */

