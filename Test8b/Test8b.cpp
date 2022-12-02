#include <iostream>
using namespace std;

#include "Garage.h"

int main()
{
  // Creation du Garage
  // implicite !!! (variable statique)

  // Ajout de modeles disponibles
  cout << "//***** Modeles disponibles ***********************" << endl;
  Garage::getInstance().ajouteModele(Modele("208 Active 1.5 BlueHDi 5P",100,Diesel,21800.0f));
  Garage::getInstance().ajouteModele(Modele("308 Allure 1.6 Hybrid 5P",150,Hybride,38650.0f));
  Garage::getInstance().ajouteModele(Modele("2008 GT 1.2 PureTech 130 Man.6",130,Essence,31400.0f));
  Garage::getInstance().afficheModelesDisponibles();

  // Ajout d'options disponibles
  cout << "//***** Options disponibles ***********************" << endl;
  Garage::getInstance().ajouteOption(Option("0MM0","Peinture metallisee",450.0f));
  Garage::getInstance().ajouteOption(Option("ZH75","Jante alliage leger 15 pouces",450.0f));
  Garage::getInstance().ajouteOption(Option("UB01","Detecteur obstacles arriere",250.0f));
  Garage::getInstance().afficheOptionsDisponibles();

  // Ajout de clients
  Garage::getInstance().ajouteClient("Wagner","Jean-Marc","0498.25.36.23");
  Garage::getInstance().ajouteClient("Leonard","Anne","0478/11.23.65");
  Garage::getInstance().ajouteClient("Quettier","Patrick","0476/78.45.12");
  Garage::getInstance().ajouteClient("Vilvens","Claude","0477/45.29.98");
  Garage::getInstance().ajouteClient("Charlet","Christophe","0475/71.31.89");

  // Ajout d'employes
  Garage::getInstance().ajouteEmploye("Issier","Paul","issipaul",Employe::VENDEUR);
  Garage::getInstance().ajouteEmploye("Coptere","Elie","coptelie",Employe::ADMINISTRATIF);
  Garage::getInstance().ajouteEmploye("Duviver","Isabelle","duviisab",Employe::ADMINISTRATIF);
  Garage::getInstance().ajouteEmploye("Cadabras","Habras","cadahabr",Employe::VENDEUR);
  
  // Affichage
  cout << "////////// Avant ///////////////////////////////////////////////////////////////////////" << endl;
  Garage::getInstance().afficheClients();
  Garage::getInstance().afficheEmployes();

  // Suppression par indice
  Garage::getInstance().supprimeClientParIndice(1);
  Garage::getInstance().supprimeEmployeParIndice(1);
  
  // Affichage
  cout << "////////// Apres suppression par indice (1) ////////////////////////////////////////////" << endl;
  Garage::getInstance().afficheClients();
  Garage::getInstance().afficheEmployes();

  // Suppression par numero
  Garage::getInstance().supprimeClientParNumero(4);
  Garage::getInstance().supprimeEmployeParNumero(9);

  // Affichage
  cout << "////////// Apres suppression par id (C4 et V9) /////////////////////////////////////////" << endl;
  Garage::getInstance().afficheClients();
  Garage::getInstance().afficheEmployes();

  // Manipulation du projet de voiture en cours
  cout << "////////// Projet en cours : Avant /////////////////////////////////////////////////////" << endl;
  Garage::getProjetEnCours().Affiche();

  Garage::getProjetEnCours().setNom("Projet_208_MrLagalere");
  Garage::getProjetEnCours().setModele(Garage::getInstance().getModele(0));
  Garage::getProjetEnCours().AjouteOption(Garage::getInstance().getOption(2));
  Garage::getProjetEnCours().AjouteOption(Garage::getInstance().getOption(0));

  cout << "////////// Projet en cours : Apres /////////////////////////////////////////////////////" << endl;
  Garage::getProjetEnCours().Affiche();

  cout << "////////// Projet en cours : Apres reset ///////////////////////////////////////////////" << endl;
  Garage::resetProjetEnCours();
  Garage::getProjetEnCours().Affiche();

  return 0;
}

