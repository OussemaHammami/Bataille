#include "Player.h"



Player::Player():prenom("")
{
	
}



void Player::setPrenom(string prenom)
{
	this->prenom = prenom; 
}

string Player::getPrenom()
{
	return prenom;
}

Hand& Player::getHand()
{
	return hand;
}

void Player::setHand(Hand& h)
{
	hand = h;
}

Player::~Player(void)
{
}
