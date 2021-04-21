#pragma once
#include <iostream>
#include <string>
#include "Hand.h"
using namespace std;

class Player
{
	string prenom; 
	Hand hand;
public :
	Player(void);


	void setPrenom(string); // affectuer prénom du joueur


	string getPrenom(); // retoruner prénom du joueur


	Hand& getHand(); // retourner "hand" du joueur


	void setHand(Hand& h); //modifier "hand" 


	~Player(void); 
};


