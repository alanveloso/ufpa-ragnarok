#include <iostream>
#include <ostream>
#include <string>
#include "Mage.h"
#include "Date.h"
#include "Skill.h"
using std::cout;
using std::endl;
using std::string;

const string Mage::AVAILABLE_MAGE_SKILLS[2] = {"Fire Wall","Thunderstorm"};

// Default Constructor
Mage::Mage()
:Novice()
{
	this->skillNumber = 0;
	this->yourMageSkillList = new Skill[1];
}

// Constructor
Mage::Mage(const string &name, const string &sex, const Date &created, const Skill &skill, int points, int number, const Skill &mageSkill)
:Novice(name, sex, created, skill, points)
{
	if (number < 0)
	{
		cout << "Skill Number setted for 1" << endl;
		this->skillNumber = 1;
	}
	else
		this->skillNumber = number;
	this->yourMageSkillList = new Skill[this->skillNumber];
	this->yourMageSkillList[0] = mageSkill;
}

// Copy Constructor
Mage::Mage(const Mage &mage)
:Novice(static_cast<Novice> (mage))
{
	this->skillNumber = mage.skillNumber;
	for (int i = 0; i < this->skillNumber; i++)
		this->yourMageSkillList[i] = mage.yourMageSkillList[i];
}

// Destructor
Mage::~Mage()
{
	//cout << "~Mage() called" << endl;
	delete [] this->yourMageSkillList;
}

// Overload << opperator
ostream &operator<< (ostream &output, const Mage &mage)
{
	output << static_cast< Novice> (mage) << endl;
	cout << endl;
	output << "Skill list" << endl;
	for (int i = 0; i < mage.skillNumber; i++)
		output << mage.yourMageSkillList[i] << " ";
	cout << endl;
	output << "Skill number " << mage.skillNumber << endl;

	return output;
}

// Overload == operator 
bool Mage::operator== (const Mage &mage) const
{
	if (static_cast< Novice >(*this) != static_cast<Novice> (mage))
		return false;
	if (this->skillNumber == mage.skillNumber)
		return false;
	for (int i = 0; i < mage.skillNumber; i++)
		if (this->yourMageSkillList[i] == mage.yourMageSkillList[i])
			return false;
	return true;
}

// Overload = operator 
const Mage &Mage::operator= (const Mage &mage)
{
	static_cast< Novice> (*this) = static_cast< Novice > (mage);
	this->skillNumber = mage.skillNumber;
	delete [] this->yourMageSkillList;
	for (int i = 0; i < this->skillNumber; i++)
		this->yourMageSkillList[i] = mage.yourMageSkillList[i];

	return *this;
}

// Print mage info
void Mage::printInfo() const
{
	cout << "Job Type:\t\tMage" << endl;
	cout << "Race:\t\t\tHuman" << endl;
	cout << "Changer At:\t\tGaffen" << endl;
	cout << "Total Skill Points:\t121" << endl;
	cout << "Total Quest Skills:\t1" << endl;
	cout << "\t\tJob Bonues" << endl;
	cout << "STR\tAGI\tVIT\tINT\tDEX\tLUK" << endl;
	cout << "+0\t+4\t+0\t+8\t+3\t+3" << endl;
	cout << "\t\tWeapons" << endl;
	cout << "Dagger • Rod" << endl;
}

// Skill first Aid
void Mage::thunderstorm() const
{
	cout << "Cure !!" << endl;
}

// Skill play dead
void Mage::fireWall() const
{
	cout << "Blessing !!" << endl;
}

// Add skill of skill list
void Mage::addSkill(const Skill &skill) 
{
	int skillPoints = (*this).getSkillPoints();
	if (skillPoints > 0)
	{
		Skill *aux = new Skill[this->skillNumber];
		for(int i = 0; i < this->skillNumber; i++)
			aux[i] = this->yourMageSkillList[i];

		delete [] this->yourMageSkillList;
		this->skillNumber++;
		this->yourMageSkillList = new Skill[this->skillNumber];
		for(int i = 0; i < this->skillNumber--; i++)
			this->yourMageSkillList[i] = aux[i];

		this->yourMageSkillList[skillNumber--] = skill;
		(*this).setSkillPoints(skillPoints--);

		delete [] aux;
	}
	else
	{
		cout << "I don't have points for distribute" << endl;
	}
}
