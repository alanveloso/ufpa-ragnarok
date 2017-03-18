#ifndef _NOVICE_H_
#define _NOVICE_H_

#include <ostream>
#include <string>
#include <vector>
#include "Date.h"
#include "Skill.h"
#include "Character.h"
using std::string;
using std::ostream;
using std::vector;

class Novice : public Character
{
	//Defined operator output
	friend ostream &operator<<(ostream &, const Novice &);
public:
	// Default constructor
	Novice();
	// Constructor
	Novice(const string &, char, const Date &, const Skill &, int points);
	// Copy constructor
	Novice(const Novice &);
	// Destructor
	~Novice();
	// Defined operator ==
	bool operator== (const Novice &) const;
	// Defined operator !=
	bool operator!= (const Novice &novice) const
	{
		return ! (*this == novice);
	}
	// Defined = operator
	const Novice &operator= (const Novice &);
	// Print Novice Info
	void printInfo() const;
	// Skill first Aid
	void firstAid() const;
	// Skill play dead
	void playDead() const;
	// Add skill of skill list
	void addSkill();
private:
	static int numberOfSkills;
	int skillPoints;
	const Date creationDate;
	vector<Skill> noviceSkillList;
};
#endif
