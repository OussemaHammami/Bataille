#include "Game.h"
#include "Hand.h"
#include <windows.h> 
#include <iostream>
using namespace std;


Game::Game(const Package& pq):P(pq)
{
}



void Game::Jeux(Player &j1, Player& j2)
{

	
	Hand h1=j1.getHand(); 
	Hand h2=j2.getHand(); 
	string nom1 = j1.getPrenom();
	string nom2 = j2.getPrenom();

	int index = 1; // Nombre de manche

	
	string choix;
	
	

	do {

		do
		{
			cout << endl;
			cout << "1- tirer carte" << endl;
			cin >> choix;
		} while (choix != "1" );

		Card ct1, ct2;
		bool testBataille = false; 
		stack <Card> aux; //table 


		cout << "                 " << endl;
		cout << "joueur 1: " << h1.getHandPlayer().size() << endl;
		cout << "joueur 2: " << h2.getHandPlayer().size() << endl;
		cout << "____________________" << endl;
		cout << "             " << endl;


		ct1 = h1.getHandPlayer().top(); //sommet 
		cout <<nom1 <<":"<<"  "<< ct1.getValeur()<<ct1.getSymbole()<< endl;
		h1.tirerCard();
		ct2 = h2.getHandPlayer().top();
		cout <<nom2<<":"<<"  " << ct2.getValeur()<<ct2.getSymbole()<< endl;
		h2.tirerCard();
		aux.push(ct1);
		aux.push(ct2);


			if (ct1.comparer(ct2) == 1) // premier joueur remporte la manche
			{
				h1.setHandPlayer(aux);
				cout << nom1 << " a emporte la manche" << "  " << index<< endl;
				index++;
			}

			else if (ct1.comparer(ct2) ==2) // 2éme joueur remporte la manche
			{
				h2.setHandPlayer(aux);
				cout << nom2 << " a emporte la manche" << "  " << index <<endl;
				index++;
			}

		//Egalite
		else {
			cout << "             " << endl;
			cout << "BATTAILE" << endl;
			cout << "             " << endl;
			
			// Si un de joueurs ne possede plus de carte 
			if (h1.getHandPlayer().size() == 0 || h2.getHandPlayer().size() == 0) { 

				if (h1.getHandPlayer().size() == 0) {
					h2.setHandPlayer(aux);
					
				}
				else {
					h1.setHandPlayer(aux);
					
				}
			}

			// Si un de joueurs possede une seule carte qui ne le permete pas de continuer la bataille
			else if (h1.getHandPlayer().size() == 1 || h2.getHandPlayer().size() == 1) { 

					if (h1.getHandPlayer().size() == 1) {
						aux.push(h1.getHandPlayer().top());
						h1.tirerCard();
						h2.setHandPlayer(aux);
						
					}
					else {
						aux.push(h2.getHandPlayer().top());
						h2.tirerCard();
						h1.setHandPlayer(aux);
			
					}
			}


			
			else {
			do { 
				Card ct3, ct4, ct5, ct6;
				ct3 = h1.getHandPlayer().top();
				h1.tirerCard();
				ct4 = h2.getHandPlayer().top();
				h2.tirerCard();
				aux.push(ct3);
				aux.push(ct4);

				// si un de joueurs ne possede plus de carte
				if (h1.getHandPlayer().size() == 0 || h2.getHandPlayer().size() == 0)
				{ 
					if (h1.getHandPlayer().size() == 0) 
					{
						h2.setHandPlayer(aux);
						cout << nom2 << " a emporte la manche" << "  " << index << endl;
						testBataille = true;
					}
					else 
					{
						h1.setHandPlayer(aux);
						cout << nom1 << " a emporte la manche" << "  " << index << endl;
						testBataille = true;
					}
				}


				else 
				{
					ct5 = h1.getHandPlayer().top();
					h1.tirerCard();
					ct6 = h2.getHandPlayer().top();
					h2.tirerCard();
					aux.push(ct5);
					aux.push(ct6);
					cout << nom1 << ":" << "  " << ct1.getValeur() <<ct1.getSymbole() << "  " << "*" << "  " << ct5.getValeur() << ct5.getSymbole() << endl;
					cout << nom2 << ":" << "  " << ct2.getValeur() <<ct2.getSymbole() << "  " << "*" << "  " << ct6.getValeur() << ct6.getSymbole() << endl;


					// premier joueur remporte la manche
					if (ct5.comparer(ct6) == 1)
					{
						h1.setHandPlayer(aux);
				
						cout << nom1 << " a emporte la manche" << index << endl;
						index++;
						
						testBataille = true;
					}

					// 2éme joueur remporte la manche
					else if (ct5.comparer(ct6) == 2) {
						h2.setHandPlayer(aux);
						cout << nom2 << " a emporte la manche" << index << endl;
						index++;
						
						testBataille = true;
					}

					//égalite
					else 
					{ 
						cout << "BATTAILE" << endl;
						cout << "             "<< endl;
					}
				
				}

			} while (testBataille == false);}
			}

		

	}while (h1.getHandPlayer().empty()==false && h2.getHandPlayer().empty()==false);
	Beep(523, 500); //sonorie 
	
	j1.setHand(h1); 
	j2.setHand(h2); 

	cout << "             " << endl;

	cout << "              " << endl;
	if (h1.getHandPlayer().empty()==true) { cout << nom2 << " a ganger" << endl; }
	else { cout << nom1 << " a gange" << endl; }
	
} 

Game::~Game(void)
{
}
