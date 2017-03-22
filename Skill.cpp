#include "Skill.h"

#include <iostream>
using std::cout;
using std::endl;

//Default constructor
Skill::Skill()
{
	this->skillName = ""; 
	this->maxLevel = 0;
	this->type = "";
}

//Copy constructor
Skill::Skill(const Skill &skillCopy)
{
	this->skillName = skillCopy.skillName;
	this->maxLevel = skillCopy.maxLevel;
	this->type = skillCopy.type;
}

//Constructor
Skill::Skill(const string &name, const string &type, int maxLevel)
{
	this->skillName = name;
	this->maxLevel = maxLevel;
	this->type = type;
}

//Destructor
Skill::~Skill()
{
//	cout << "~Skill() called" << endl;
}

// Overload << operator
ostream &operator<<(ostream &output, const Skill &skill)
{
	output << "\t" <<skill.skillName << "\nLevels:\t\t" << skill.maxLevel << "\nType:\t\t" << skill.type  << endl;
	return output;
}

// Overload == operator
bool Skill::operator== (const Skill &skill) const
{
	if (this->skillName == skill.skillName)
		return false;
	if (this->maxLevel == skill.maxLevel)
		return false;
	if (this->type == skill.type)
		return false;
	
	return true;
}


// Overload = operator
const Skill &Skill::operator= (const Skill &skill)
{
	this->skillName = skill.skillName;
	this->maxLevel = skill.maxLevel;
	this->type = skill.type;
	
	return *this;
}
