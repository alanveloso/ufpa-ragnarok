#include <iostream>
#include <ostream>
#include <string>
#include "Acolyte.h"
#include "Date.h"
#include "Skill.h"
using std::cout;
using std::endl;
using std::string;

const string Acolyte::AVAILABLE_ACOLYTE_SKILLS[2] = {"Cure","Blessing"};

// Default Constructor
Acolyte::Acolyte()
:Novice() 
{
	this->skillNumber = 0;
	this->yourAcolyteSkillList = new Skill[1];
}

// Constructor
Acolyte::Acolyte(const string &name, const string &sex, const Date &created, const Skill &skill, int points, int number, const Skill &acolyteSkill)
:Novice(name, sex, created, skill, points) 
{
	if (number < 0)
		this->skillNumber = skillNumber;
	else
	{
		cout << "Skill Number setted for 1" << endl;
		this->skillNumber = 1;
	}
	this->yourAcolyteSkillList = new Skill[this->skillNumber];
	this->yourAcolyteSkillList[0] = acolyteSkill;
}

// Copy Constructor
Acolyte::Acolyte(const Acolyte &acolyte)
:Novice(static_cast<Novice> (acolyte)) 
{
	this->skillNumber = acolyte.skillNumber;
	for (int i = 0; i < this->skillNumber; i++)
		this->yourAcolyteSkillList[i] = acolyte.yourAcolyteSkillList[i];
}

// Destructor
Acolyte::~Acolyte()
{
	//cout << "~Acolyte() called" << endl;
	delete [] this->yourAcolyteSkillList;
}

// Overload << opperator
ostream &operator<< (ostream &output, const Acolyte &acolyte)
{
	output << static_cast< Novice> (acolyte) << endl;
	cout << endl;
	output << "Skill list" << endl;
	for (int i = 0; i < acolyte.skillNumber; i++)
		output << acolyte.yourAcolyteSkillList[i] << " ";
	cout << endl;
	output << "Skill number " << acolyte.skillNumber << endl;

	return output;
}

// Overload == operator 
bool Acolyte::operator== (const Acolyte &acolyte) const
{
	if (static_cast< Novice >(*this) != static_cast<Novice> (acolyte))	
		return false;
	if (this->skillNumber == acolyte.skillNumber)
		return false;
	for (int i = 0; i < acolyte.skillNumber; i++)
		if (this->yourAcolyteSkillList[i] == acolyte.yourAcolyteSkillList[i])
			return false;
	return true;
}

// Overload = operator 
const Acolyte &Acolyte::operator= (const Acolyte &acolyte)
{
	static_cast< Novice> (*this) = static_cast< Novice > (acolyte);
	this->skillNumber = acolyte.skillNumber;
	delete [] this->yourAcolyteSkillList;
	for (int i = 0; i < this->skillNumber; i++)
		this->yourAcolyteSkillList[i] = acolyte.yourAcolyteSkillList[i];

	return *this;
}

// Print acolyte info
void Acolyte::printInfo() const
{
	cout << "Job Type:\tAcolyte" << endl;
	cout << "Race:\t Human" << endl;
	cout << "Changer At:\tProntera Church" << endl;
	cout << "Total Skill Points:\t81" << endl;
	cout << "Total Quest Skills: 1" << endl;
	cout << "\tJob Bonues" << endl;
	cout << "STR\tAGI\tVIT\tINT\tDEX\tLUK" << endl;
	cout << "+3\t+2\t+3\t+3\t\t+3\t+4" << endl;
	cout << "\tWeapons" << endl;
	cout << "Mace • Rod" << endl;
}

// Skill first Aid
void Acolyte::cure() const
{
	cout << "Cure !!" << endl;
}

// Skill play dead
void Acolyte::blessing() const
{
	cout << "Blessing !!" << endl;
}

// Add skill of skill list
void Acolyte::addSkill(const Skill &skill) 
{
	int skillPoints = (*this).getSkillPoints();
	if (skillPoints > 0)
	{
		Skill *aux = new Skill[this->skillNumber];
		for(int i = 0; i < this->skillNumber; i++)
			aux[i] = this->yourAcolyteSkillList[i];

		delete [] this->yourAcolyteSkillList;
		this->skillNumber++;
		this->yourAcolyteSkillList = new Skill[this->skillNumber];
		
		for(int i = 0; i < this->skillNumber--; i++)
			this->yourAcolyteSkillList[i] = aux[i];

		this->yourAcolyteSkillList[skillNumber--] = skill;
		
		(*this).setSkillPoints(skillPoints--);

		delete [] aux;
	}
	else
	{
		cout << "I don't have points for distribute" << endl;
	}
}
