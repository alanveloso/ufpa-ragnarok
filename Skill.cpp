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
Skill::Skill(const User &skillCopy)
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
ostream &operator<<(ostream &output, const Skill &user)
{
	output << "\t" << user.skillName << "\nLevels:\t" << user.maxLevel << "\nType:\t" << user.type  << endl;
	return output;
}

// Overload == operator
bool Skill::operator== (const Skill &user) const
{
	if (this->skillName == user.skillName)
		return false;
	if (this->maxLevel == user.maxLevel)
		return false;
	if (this->type == user.type)
		return false;
	
	return true;
}


// Overload = operator
const Skill &Skill::operator= (const User &user)
{
	this->skillName = user.skillName;
	this->maxLevel = user.maxLevel;
	this->type = user.type;
	
	return *this;
}
