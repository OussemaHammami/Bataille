#pragma once
#include <iostream>
#include <string>
using namespace std;


class Card
{
	int valeur; 
	string symbole; 
public : 

	Card(void); 


	int getValeur()const;  // retourner la valeur de la carte
	
	string getSymbole()const; // retourner la symbole de la carte

	void setValeur(int);  //Affectuer la valeur de la carte

	void setSymbole(string);  // Affectuer le symbole de la carte

	int comparer(Card&); //comparer les valeurs de deux cartes

	void operator=(const Card&); 

	~Card(void); 
};

