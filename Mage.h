#ifndef _MAGE_H_
#define _MAGE_H_

#include <ostream>
#include <string>
#include "Skill.h"
#include "Novice.h"
using std::string;
using std::ostream;

class Mage : public Novice
{
	//Defined operator output
	friend ostream &operator<<(ostream &, const Mage &);
public:
	// Default constructor
	Mage();
	// Constructor
	Mage(const string &, char, const Data &, const Skill &, int, int, const Skill &);
	// Copy constructor
	Mage(const Mage &);
	// Destructor
	~Mage();
	// Defined operator ==
	bool operator== (const Mage &) const;
	// Defined operator !=
	bool operator!= (const Mage &mage) const
	{
		return ! (*this == mage);
	}
	// Defined = operator
	const Mage &operator= (const Mage &);
	// Print mage info
	void printInfo() const;
	// Skill fire wall
	void fireWall() const;
	// Skill thunderstorm
	void thunderstorm() const;
	// Add skill of mage skill list
	void addSkill();
private:
	int skillNumber;
	Skill yourMageSkillList[];
	string availableMageSkills;
};

#endif /* _MAGE_H__*/
