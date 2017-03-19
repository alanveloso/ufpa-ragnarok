#include <iostream>
#include <ostream>
#include <string>
#include "Novice.h"
#include "Date.h"
#include "Skill.h"
using std::cout;
using std::endl;
using std::string;

// Default Constructor
Novice::Novice()
:Character(), creationDate()
{
	this->skillPoints = 0;
	this->noviceSkillList;
}

// Constructor
Novice::Novice(const string &name, const string &sex, const Date &created, const Skill &skill, int points)
:Character(name, sex), creationDate(created)
{
	if (points <= 9)
		this->skillPoints = points;
	else
	{
		cout << "Skill points setted for 9" << endl;
		this->skillPoints = 9;
	}
	this->noviceSkillList.push_back (skill);
}

// Copy Constructor
Novice::Novice(const Novice &novice)
:Character(static_cast<Character> (novice)), creationDate(novice.creationDate)
{
	this->skillPoints = novice.skillPoints;
	this->noviceSkillList = novice.noviceSkillList;
}

// Destructor
Novice::~Novice()
{
	//cout << "~Novice() called" << endl;
}

// Overload << opperator
ostream &operator<< (ostream &output, const Novice &novice)
{
	output << static_cast< Character> (novice) << endl;
	cout << endl;
	output << "Skill list" << endl;
	for (int i = 0; i < novice.noviceSkillList.size(); i++)
		output << novice.noviceSkillList[i] << " ";
	cout << endl;
	output << "Skill points " << novice.skillPoints << endl;

	return output;
}

// Overload == operator 
bool Novice::operator== (const Novice &novice) const
{
	if (static_cast< Character >(*this) != static_cast<Character> (novice))	
		return false;
	if (this->skillPoints == novice.skillPoints)
		return false;
	for (int i = 0; i < novice.noviceSkillList.size(); i++)
		if (this->noviceSkillList[i] == novice.noviceSkillList[i])
			return false;
	return true;
}

// Overload = operator 
const Novice &Novice::operator= (const Novice &novice)
{
	static_cast< Character> (*this) = static_cast< Character > (novice);
	this->skillPoints = novice.skillPoints;
	this->noviceSkillList = novice.noviceSkillList;

	return *this;
}

// Print novice info
void Novice::printInfo() const
{
	cout << "Job Type:\tNovice" << endl;
	cout << "Race:\t" << Novice::getRace << endl;
	cout << "Changer At:\tTraning Grounds" << endl;
	cout << "Total Skill Points:\t9" << endl;
	cout << "Total Quest Skills: 2" << endl;
	cout << "\tJob Bonues" << endl;
	cout << "STR\tAGI\tVIT\tINT\tDEX\tLUK" << endl;
	cout << "+0\t+0\t+0\t+0\t\t+0\t+0" << endl;
	cout << "\tWeapons" << endl;
	cout << "Dagger • One Handed Sword" << endl;
}

// Skill first Aid
void Novice::firstAid() const
{
	cout << "First Aid !!" << endl;
}

// Skill play dead
void Novice::playDead() const
{
	cout << "Play Dead !!" << endl;
}

// Add skill of skill list
void Novice::addSkill(const Skill &skill) 
{
	this->noviceSkillList.push_back(skill);
}

// Return skill points
int Novice::getSkillPoints() const
{
	return this->skillPoints;
}

// Set skill points
void Novice::setSkillPoints(int points)
{
	this->skillPoints = points;
}
