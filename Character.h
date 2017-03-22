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
	// Constructor
	Character(const string & = "unknown", const string & = "MALE");
	// Copy constructor
	Character(const Character &);
	// Destructor
	virtual ~Character();
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
	virtual void printInfo() const = 0;
	// Use mount
	virtual void useMount() const = 0;
	// List additive skill 
	virtual void listAvailableSkill() const = 0;
private:
	string name;
	const string sex;
	static const string RACE;
	static int numberChars;
};

#endif	/* CHARACTER_H */


