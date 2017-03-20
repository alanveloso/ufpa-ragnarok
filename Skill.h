#ifndef _SKILL_H_
#define	_SKILL_H_

#include <ostream>
#include <string>
using std::string;
using std::ostream;

class Skill 
{
	friend ostream &operator<<(ostream &, const Skill &);
public:
	Skill();
	Skill(const string &, const string &, int);
	Skill(const Skill &);
	~Skill();
	bool operator== (const Skill &) const;
	bool operator!= (const Skill &skill) const
	{
		return ! (*this == skill);
	}
	const Skill &operator= (const Skill &);
private:
	string skillName;
	string type;
	int maxLevel;	
};

#endif	/* SKILL_H */
