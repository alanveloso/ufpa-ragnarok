#ifndef _CHARACTER_H_
#define	_CHARACTER_H_

#include <ostream>
#include <string>
using std::ostream;
using std::string;

class Character 
{
	//Overload output operator
	friend ostream &operator<<(ostream &, const Character &);
public:
	// Default constructor
	Character();
	// Constructor
	Chatacter(const string &, char);
	// Copy constructor
	Character(const Character &);
	// Destructor
	~Character();
	// Defined = operator
	const Character &operator=(const Character &);
	// Defined == operator
	bool operator== (const Character &) const;
	// Defined operator !=
	bool operator!= (const Character &character) const
	{
		return ! (*this == character);
	}
	// Print character info
	void printInfo();
private:
	string name;
	const char sex;
	static const RACE = "Human";
	static int numberChars;
};

#endif	/* CHARACTER_H */


