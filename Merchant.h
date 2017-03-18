#ifndef _MERCHANT_H_
#define _MERCHANT_H_

#include <ostream>
#include <string>
#include "Skill.h"
#include "Novice.h"
using std::string;
using std::ostream;

class Merchant : public Novice
{
	//Defined operator output
	friend ostream &operator<<(ostream &, const Merchant &);
public:
	// Default constructor
	Merchant();
	// Constructor
	Merchant(const string &, char, const Data &, const Skill &, int, int, const Skill &);
	// Copy constructor
	Merchant(const Merchant &);
	// Destructor
	~Merchant();
	// Defined operator ==
	bool operator== (const Merchant &) const;
	// Defined operator !=
	bool operator!= (const Merchant &merchant) const
	{
		return ! (*this == merchant);
	}
	// Defined = operator
	const Merchant &operator= (const Merchant &);
	// Print merchant info
	void printInfo() const;
	// Skill mammonite
	void mammonite() const;
	// Skill vending
	void vending() const;
	// Add skill of merchant skill list
	void addSkill();
private:
	int skillNumber;
	Skill yourMerchantSkillList[];
	string availableMerchantSkills;
};

#endif /* _MERCHANT_H__*/
