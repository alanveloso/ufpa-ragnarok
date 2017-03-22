#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "Character.h"
#include "Skill.h"
#include "Date.h"
#include "Acolyte.h"
#include "Merchant.h"
#include "Mage.h"
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;

int main()
{
	Date yesterday(19, 03, 2017);
	Date today(20, 03, 2017);
	Skill firstAid("First Aid", "Supportive", 1);
	Skill cure("Cure", "Supportive", 1);
	Skill fireWall("Fire Wall", "Offensive" , 10);
	Skill vending("Vending", "Active", 10);

	vector < Character * > characters( 4 );

	characters[ 0 ] = new Acolyte("Chen Lio", "Male", today, firstAid, 1, 1, cure); 
	characters[ 1 ] = new Mage("Kathryne Keyron", "Female", yesterday, firstAid, 1, 1, fireWall);
	characters[ 2 ] = new Merchant("Howard Alt-Eisen", "Male",today, firstAid, 1, 1, vending); 
	characters[ 3 ] = new Merchant("Al Alt-Eisen", "Male",yesterday, firstAid, 1, 1, vending);

	for ( size_t i = 0; i < characters.size(); i++ )
	{
 		characters[i]->printInfo();

		Merchant *derivedPtr = dynamic_cast<Merchant *>(characters[i]); 

		if ( derivedPtr !=0 )
		{
			cout << endl;
			cout << "You need to rent Pushcart" << endl;
			cout << endl;

		} 
		cout << "----------------------------------------------------------------" << endl; 
	} 

	
	for ( size_t j = 0; j < characters.size(); j++ )
	{
		
		cout << "Deleting objects " << typeid(*characters[j]).name() << "..." <<endl ;
		delete characters[ j ];
		cout << endl;
	}

	return 0;
}
