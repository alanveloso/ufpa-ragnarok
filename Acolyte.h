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
	Acolyte(const string &, const string &, const Date &, const Skill &, int, int, const Skill &);
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
	void addSkill(const Skill &);
	// User acolyte mount
	void useMount() const;
	// List additive skill 
	void listAvailableSkill() const;
private:
	int skillNumber;
	Skill *yourAcolyteSkillList;
	static const string AVAILABLE_ACOLYTE_SKILLS[2];
};

#endif /* _ACOLYTE_H__*/
