#include <iostream>
using namespace std;

#include "Garage.h"

int main()
{
  // Creation du Garage
  Garage g;
  
  // Ajout de modeles disponibles
  cout << "//***** Modeles disponibles ***********************" << endl;
  g.ajouteModele(Modele("208 Active 1.5 BlueHDi 5P",100,Diesel,21800.0f));
  g.ajouteModele(Modele("308 Allure 1.6 Hybrid 5P",150,Hybride,38650.0f));
  g.ajouteModele(Modele("2008 GT 1.2 PureTech 130 Man.6",130,Essence,31400.0f));
  g.afficheModelesDisponibles();

  // Ajout d'options disponibles
  cout << "//***** Options disponibles ***********************" << endl;
  g.ajouteOption(Option("0MM0","Peinture metallisee",450.0f));
  g.ajouteOption(Option("ZH75","Jante alliage leger 15 pouces",450.0f));
  g.ajouteOption(Option("UB01","Detecteur obstacles arriere",250.0f));
  g.afficheOptionsDisponibles();

  // Ajout de clients
  g.ajouteClient("Wagner","Jean-Marc","0498.25.36.23");
  g.ajouteClient("Leonard","Anne","0478/11.23.65");
  g.ajouteClient("Quettier","Patrick","0476/78.45.12");
  g.ajouteClient("Vilvens","Claude","0477/45.29.98");
  g.ajouteClient("Charlet","Christophe","0475/71.31.89");

  // Ajout d'employes
  g.ajouteEmploye("Issier","Paul","issipaul",Employe::VENDEUR);
  g.ajouteEmploye("Coptere","Elie","coptelie",Employe::ADMINISTRATIF);
  g.ajouteEmploye("Duviver","Isabelle","duviisab",Employe::ADMINISTRATIF);
  g.ajouteEmploye("Cadabras","Habras","cadahabr",Employe::VENDEUR);
  
  // Affichage
  cout << "////////// Avant ///////////////////////////////////////////////////////////////////////" << endl;
  g.afficheClients();
  g.afficheEmployes();

  // Suppression par indice
  cout<<"Supression par indice"<<endl;
  g.supprimeClientParIndice(1);
  g.supprimeEmployeParIndice(1);
  
  // Affichage
  cout << "////////// Apres suppression par indice (1) ////////////////////////////////////////////" << endl;
  g.afficheClients();
  g.afficheEmployes();

  // Suppression par numero
  g.supprimeClientParNumero(4);
  g.supprimeEmployeParNumero(9);

  // Affichage
  cout << "////////// Apres suppression par id (C4 et V9) /////////////////////////////////////////" << endl;
  g.afficheClients();
  g.afficheEmployes();

  return 0;
}

