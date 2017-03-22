#include <iostream>
#include <ostream>
#include <string>
#include "Character.h"
using std::cout;
using std::endl;
using std::string;

int Character::numberChars = 0;
const string Character::RACE = "Human";

// Default constructor

// Constructor
Character::Character(const string &nam, const string &gen)
:sex(gen), name(nam)
{
	numberChars++;
}

// Copy Constructor
Character::Character(const Character &character)
:sex(character.sex), name(character.name)
{
	numberChars++;
}

// Destructor
Character::~Character()
{
	//cout << "~Character() called" << endl;
}

// Overload << opperator
ostream &operator<< (ostream &output, const Character &character)
{
	output << "Name:\t\t" << character.name << "\nGender:\t\t" <<character.sex << endl; 
	return output;
}

// Overload == operator 
bool Character::operator== (const Character &character) const
{
	if (this->name == character.name)
		return false;
	else if (this->sex == character.sex)
		return false;
	
	return true;
}

// Overload = operator 
const Character &Character::operator= (const Character &character)
{
	this->name = character.name;

	return *this;
}
void Character::printInfo() const
{}

void Character::useMount() const
{}
	
void Character::listAvailableSkill() 
{}
