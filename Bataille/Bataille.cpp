#include "Package.h"
#include"Hand.h"
#include"Player.h"
#include"Game.h"
#include <ostream>




// Une partie du jeu
void bataille() {
    
    Package pq;
    Game P(pq); 
    Player p1, p2;
    string a, b;
    cout << "taper nom joueur 1" << endl;
    cin >> a;
    p1.setPrenom(a);
    cout << "taper nom joueur 2" << endl;
    cin >> b;
    p2.setPrenom(b);
    Hand hand1, hand2;
    pq.distribuer(hand1, hand2);
    p1.setHand(hand1);
    p2.setHand(hand2);
    cout << "***************Bataille****************" << endl;
    P.Jeux(p1, p2);
}


//menu du jeu
void Menu() {
    cout << "*******************************Bataille*******************************" << endl;
    cout <<"                                 " <<"MENU" <<"                            "<<endl; 
    cout << "-1- Jouer" << endl;
    cout << "-2- Quitter" << endl; 
    cout<< ""<<endl;
}



int main()
{
    string choix;

    do {
       
        srand((int)time(0));
        Menu();
        cout << " taper votre choix " << endl;
        cin >> choix;

        if (choix == "1")
        {
        bataille();
        }
    
    
    } while (choix!="2");
   


   
    return 0;
}

