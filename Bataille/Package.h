#pragma once
#include <iostream>


#include "Hand.h"  
using namespace std;

class Package
{
	Card Pack[52];
public : 

	Package(void); 


	void distribuer(Hand&, Hand&); // distribuer les cartes entre 2 joueurs


	~Package(void); 


};



