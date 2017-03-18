#ifndef _ACOLYTE_H_
#define _ACOLYTE_H_

#include <ostream>
#include <string>
#include "Skill.h"
#include "Novice.h"
using std::string;
using std::ostream;

class Acolyte : public Novice
{
	//Defined operator output
	friend ostream &operator<<(ostream &, const Acolyte &);
public:
	// Default constructor
	Acolyte();
	// Constructor
	Acolyte(const string &, char, const Data &, const Skill &, int, int, const Skill &);
	// Copy constructor
	Acolyte(const Acolyte &);
	// Destructor
	~Acolyte();
	// Defined operator ==
	bool operator== (const Acolyte &) const;
	// Defined operator !=
	bool operator!= (const Acolyte &acolyte) const
	{
		return ! (*this == acolyte);
	}
	// Defined = operator
	const Acolyte &operator= (const Acolyte &);
	// Print acolyte info
	void printInfo() const;
	// Skill cure
	void cure() const;
	// Skill blessing
	void blessing() const;
	// Add skill of acolyte skill list
	void addSkill();
private:
	int skillNumber;
	Skill yourAcolyteSkillList[];
	string availableAcolyteSkills;
};

#endif /* _ACOLYTE_H__*/
