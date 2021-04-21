#pragma once
#include <iostream>

#include"Card.h"
#include<stack>
using namespace std;


class Hand
{
	stack <Card> handPlayer;
public : 

	
	Hand(void); 

	void setHandPlayer(stack<Card>); // Modifier HandPlayer

	stack<Card> getHandPlayer(); // retourner HandPlayer

	void tirerCard(); // depiler << handPlayer >> 

	~Hand(void); 


};

