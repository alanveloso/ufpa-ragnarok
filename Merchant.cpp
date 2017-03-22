#include <iostream>
#include <ostream>
#include <string>
#include "Merchant.h"
#include "Date.h"
#include "Skill.h"
using std::cout;
using std::endl;
using std::string;

const string Merchant::AVAILABLE_MERCHANT_SKILLS[2] = {"Mammonite","Vending"};

// Default Constructor
Merchant::Merchant()
:Novice() 
{
	this->skillNumber = 0;
	this->yourMerchantSkillList = new Skill[1];
}

// Constructor
Merchant::Merchant(const string &name, const string &sex, const Date &created, const Skill &skill, int points, int number, const Skill &acolyteSkill)
:Novice(name, sex, created, skill, points) 
{
	if (number < 0)
	{
		cout << "Skill Number setted for 1" << endl;
		this->skillNumber = 1;
	}
	else
		this->skillNumber = number;
	this->yourMerchantSkillList = new Skill[this->skillNumber];
	this->yourMerchantSkillList[0] = acolyteSkill;
}

// Copy Constructor
Merchant::Merchant(const Merchant &acolyte)
:Novice(static_cast<Novice> (acolyte)) 
{
	this->skillNumber = acolyte.skillNumber;
	for (int i = 0; i < this->skillNumber; i++)
		this->yourMerchantSkillList[i] = acolyte.yourMerchantSkillList[i];
}

// Destructor
Merchant::~Merchant()
{
	//cout << "~Merchant() called" << endl;
	delete [] this->yourMerchantSkillList;
}

// Overload << opperator
ostream &operator<< (ostream &output, const Merchant &acolyte)
{
	output << static_cast< Novice> (acolyte) << endl;
	cout << endl;
	output << "Skill list" << endl;
	for (int i = 0; i < acolyte.skillNumber; i++)
		output << acolyte.yourMerchantSkillList[i] << " ";
	cout << endl;
	output << "Skill number " << acolyte.skillNumber << endl;

	return output;
}

// Overload == operator 
bool Merchant::operator== (const Merchant &acolyte) const
{
	if (static_cast< Novice >(*this) != static_cast<Novice> (acolyte))	
		return false;
	if (this->skillNumber == acolyte.skillNumber)
		return false;
	for (int i = 0; i < acolyte.skillNumber; i++)
		if (this->yourMerchantSkillList[i] == acolyte.yourMerchantSkillList[i])
			return false;
	return true;
}

// Overload = operator 
const Merchant &Merchant::operator= (const Merchant &acolyte)
{
	static_cast< Novice> (*this) = static_cast< Novice > (acolyte);
	this->skillNumber = acolyte.skillNumber;
	delete [] this->yourMerchantSkillList;
	for (int i = 0; i < this->skillNumber; i++)
		this->yourMerchantSkillList[i] = acolyte.yourMerchantSkillList[i];

	return *this;
}

// Print acolyte info
void Merchant::printInfo() const
{
	cout << *this << endl;
	cout << "Job Type:\t\tMerchant" << endl;
	cout << "Race:\t\t\tHuman" << endl;
	cout << "Changer At:\t\tAlberta" << endl;
	cout << "Total Skill Points:\t61" << endl;
	cout << "Total Quest Skills:\t3" << endl;
	cout << "\t\tJob Bonues" << endl;
	cout << "STR\tAGI\tVIT\tINT\tDEX\tLUK" << endl;
	cout << "+5\t+1\t+4\t+1\t+5\t+2" << endl;
	cout << "\t\tWeapons" << endl;
	cout << "Axe • Dagger • Mace • One Handed Sword" << endl;
}

// Skill first Aid
void Merchant::mammonite() const
{
	cout << "Mammonite !!" << endl;
}

// Skill play dead
void Merchant::vending() const
{
	cout << "Vending !!" << endl;
}

// Add skill of skill list
void Merchant::addSkill(const Skill &skill) 
{
	int skillPoints = (*this).getSkillPoints();
	if (skillPoints > 0)
	{
		Skill *aux = new Skill[this->skillNumber];
		for(int i = 0; i < this->skillNumber; i++)
			aux[i] = this->yourMerchantSkillList[i];

		delete [] this->yourMerchantSkillList;
		this->skillNumber++;
		this->yourMerchantSkillList = new Skill[this->skillNumber];
		
		for(int i = 0; i < this->skillNumber--; i++)
			this->yourMerchantSkillList[i] = aux[i];

		this->yourMerchantSkillList[skillNumber--] = skill;
		
		(*this).setSkillPoints(skillPoints--);

		delete [] aux;
	}
	else
	{
		cout << "I don't have points for distribute" << endl;
	}
}

// User merchant mount
void Merchant::useMount() const
{
	cout << "Savage equiped" << endl;
}

// List Available Skills
void Merchant::listAvailableSkill() const 
{
	cout << "\tAvailable Skills" << endl;
	for(int i = 0; i < 2; i++)
		cout << AVAILABLE_MERCHANT_SKILLS[i] << endl;
}
