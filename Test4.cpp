#include <iostream>
using namespace std;

#include "Personne.h"
#include "Client.h"
#include "Employe.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();
void Essai6();

int main()
{
  int choix;
  bool fini = false;
  srand((unsigned)time(NULL));

  while(!fini)
  {
    choix = Menu();
    switch(choix)
    {
      case 1 : Essai1(); break;
      case 2 : Essai2(); break;
      case 3 : Essai3(); break;
      case 4 : Essai4(); break;
      case 5 : Essai5(); break;
      case 6 : Essai6(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 4 ----------------------------------------------------------" << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << " 1. Test de la classe Personne" << endl;
  cout << " 2. Test de la classe Client" << endl;
  cout << " 3. Test de la classe Employe" << endl;
  cout << " 4. Heritage et virtualite : Test des methodes virtuelles" << endl;
  cout << " 5. Test du downcasting et du dynamic-cast" << endl;
  cout << " 6. Test des variables statiques de la classe Employe" << endl;
  cout << " 7. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

/***********************************************************************************************/
// A FAIRE : la classe Persone qui contient le nom (string) et le prenom (string) d'une personne  
//           les methodes << et >> de Personne
//           l'operateur d'affectation (=) de Personne
void Essai1()
{
  cout << "----- 1.1 Test du constructeur par defaut de Personne ------------------------" << endl;
  Personne p1;
  cout << "--> Voici p1 : " << p1 << endl;
  cout << endl;
 
  cout << "----- 1.2 Test du constructeur d'initialisation de Personne ------------------" << endl;
  Personne p2("Wagner","Jean-Marc");
  cout << "--> Voici p2 : " << p2 << endl;
  cout << endl;

  cout << "----- 1.3 Test du constructeur de copie de Personne --------------------------" << endl;
  Personne p3(p2);
  cout << "--> Voici p3 : " << p3 << endl;
  cout << endl;

  cout << "----- 1.4 Test des getXXX et setXXX de Personne ------------------------------" << endl;
  p3.setNom("Quettier");
  p3.setPrenom("Patrick");
  cout << "Nom : " << p3.getNom() << endl;
  cout << "Prenom : " << p3.getPrenom() << endl;
  cout << endl;

  cout << "----- 1.5 Test de l'operateur >> de Personne ---------------------------------" << endl;
  cout << "Encodez une personne : " << endl;
  cin >> p3;
  cout << "Voici la personne encodee : " << p3 << endl;
  cout << endl;

  cout << "----- 1.6 Test de l'operateur = de Personne -----------------------------------" << endl;
  p1 = p3;
  cout << "Voici p1 apres affectation : " << p1 << endl;
}

/***********************************************************************************************/
// A FAIRE : la classe abstraite Intervenant qui h�rite de Personne et qui poss�de un numero (int)
//           et les deux m�thodes virtuelles pures Tuple() et ToString()
//           la classe Client qui herite de Intervenant, contenant en plus un numero de gsm (string)
void Essai2()
{
  cout << "----- 2.1 Test du constructeur par defaut ----------------------------------" << endl;
  Client c1;
  cout << "--> Voici c1 : " <<endl<< c1 << endl;
  cout << endl;

  cout << "----- 2.2 Test des setters -------------------------------------------------" << endl;
  c1.setNom("Lagalere");
  c1.setPrenom("Pierre");
  c1.setNumero(17);
  c1.setGsm("0498/15.23.69");
  cout << "--> Voici c1 (apres les setters) : " << c1 << endl;
  cout << endl;
  
  cout << "----- 2.3 Test des getters -------------------------------------------------" << endl;
  cout << "Nom    : " << c1.getNom() << endl;
  cout << "Prenom : " << c1.getPrenom() << endl;
  cout << "Numero : " << c1.getNumero() << endl;
  cout << "GSM    : " << c1.getGsm() << endl;
  cout << endl;

  cout << "----- 2.4 Test du constructeur d'initialisation ----------------------------" << endl;
  Client c2("Issier","Pol",41,"0485/12.12.23");
  cout << "--> Voici c2 : " << c2 << endl; 
  cout << endl;

  cout << "----- 2.5 Test des methodes Tuple() et ToString()  -------------------------" << endl;
  cout << "--> Pour c2 : " << endl;
  cout << "ToString() : --" << c2.ToString() << "--" << endl;
  cout << "Tuple()    : --" << c2.Tuple() << "--" << endl; 
  cout << endl;

  cout << "----- 2.6 Allocation dynamique de Client avec pointeur de type Client + test du constructeur de copie ------" << endl;
  cout << "--> Copie de c2..." << endl;
  Client *p1 = new Client(c2); // Vive le constructeur de copie !
  cout << "--> Voici la copie de c2 : " << *p1 << endl;
  cout << "--> Destruction de la copie..." << endl;
  delete p1;
  cout << "--> Revoici c2 : " << c2 << endl;
  cout << endl;

  cout << "----- 2.7 Test de l'operateur d'affectation --------------------------------" << endl;
  Client c3;
  cout << "--> Execution du code c3 = c2; :" << endl;
  c3 = c2;
  cout << "--> c3 = " << c3 << endl;
}

// /***********************************************************************************************/
// // A FAIRE : la classe Employe qui herite de Intervenant
// //           contenant en plus une fonction (string), un login (string) et un mot de passe (string)
// //           deux variables statiques constantes VENDEUR et ADMINISTRATIF
void Essai3()
{
  cout << "----- 3.1 Test du constructeur par defaut ----------------------------------" << endl;
  Employe e1;
  cout << "--> Voici e1 : " << e1 << endl;
  cout << endl;

  cout << "----- 3.2 Test des setters -------------------------------------------------" << endl;
  e1.setNom("Tombale");
  e1.setPrenom("Pierre");
  e1.setNumero(4);
  e1.setLogin("tombpier");
  e1.setMotDePasse("azerty34");
  e1.setFonction("Vendeur");
  cout << "--> Voici e1 (apres les setters) :" << e1 << endl;
  cout << endl;

  cout << "----- 3.3 Test des getters -------------------------------------------------" << endl;
  cout << "Nom          : " << e1.getNom() << endl;
  cout << "Prenom       : " << e1.getPrenom() << endl;
  cout << "Numero       : " << e1.getNumero() << endl;
  cout << "Login        : " << e1.getLogin() << endl;
  cout << "Mot de passe : " << e1.getMotDePasse() << endl;
  cout << "Fonction     : " << e1.getFonction() << endl;
  cout << endl;

  cout << "----- 3.4 Test du constructeur d'initialisation ----------------------------" << endl;
  Employe e2("Dugenou","Jean-Paul",2,"dugejean","Administratif");
  // Le pointeur motDePasse est initialise a NULL. Le mot de passe ne peut etre modifie (intialise)
  // qu'avec la methode setMotDePasse ou ResetMotDePasse (qui remet le pointeur a NULL).
  e2.setMotDePasse("qsdf1234");
  cout << "--> Voici e2 : " << e2 << endl; 
  cout << "Son mot de passe est : " << e2.getMotDePasse() << endl;
  cout << endl;

  cout << "----- 3.5 Test des methodes Tuple() et ToString()  -------------------------" << endl;
  cout << "--> Pour e2 : " << endl;
  cout << "ToString() : --" << e2.ToString() << "--" << endl;
  cout << "Tuple()    : --" << e2.Tuple() << "--" << endl; 
  cout << endl;

  cout << "----- 3.6 Allocation dynamique de Employe + test du constructeur de copie ------" << endl;
  cout << "--> Copie de e2..." << endl;
  Employe *p1 = new Employe(e2); // Vive le constructeur de copie !
  // Le constructeur de copie copie tout, y compris le mot de passe
  cout << "--> Voici la copie de e2 : " << *p1 << endl;
  cout << "Son mot de passe est : " << p1->getMotDePasse() << endl;
  cout << "--> Destruction de la copie..." << endl;
  delete p1;
  cout << "--> Revoici e2 :" << e2 << endl;
  cout << "Son mot de passe est : " << e2.getMotDePasse() << endl;
  cout << endl;

  cout << "----- 3.7 Test de l'operateur d'affectation --------------------------------" << endl;
  Employe e3;
  cout << "--> Execution du code e3 = e2; :" << endl;
  e3 = e2;
  cout << "--> e3 = " << e3 << endl;
}

// // /******************************************************************************************/
// // // A FAIRE : normalement rien dans vos classes...
// // //           juste comprendre et tester le code ci-dessous
void Essai4()
{
  srand((unsigned)time(NULL));

  cout << "----- 4.1 Allocation dynamique d'intervenants --------------------------------" << endl;
  Intervenant* intervenants[10];

  for (int i=0 ; i<10 ; i++)   // Tracez vos constructeurs !!!
  {
    cout << endl << "intervenants[" << i << "] : ";
    int n = rand()%3;
    switch(n)
    {
      case 0 : intervenants[i] = new Client("Issier","Pol",41,"0485/12.12.23");
               cout << "Client" << endl;
               break;

      case 1 : intervenants[i] = new Employe("Dugenou","Jean-Paul",2,"dugejean","Administratif");
               cout << "Employe (Administratif)" << endl;
               break;

      case 2 : intervenants[i] = new Employe("Coptere","Eli",7,"copteeli","Vendeur");
               cout << "Employe (Vendeur)" << endl;
               break;
    }
  }
  cout << endl;

  cout << "----- 4.2 Test des methodes VIRTUELLE ToString() et Tuple() ---------------------------------------------" << endl;
  for (int i=0 ; i<10 ; i++)
  {
    cout << endl << "intervenants[" << i << "] : " << intervenants[i]->ToString();
    cout << endl << "intervenants[" << i << "] : " << intervenants[i]->Tuple() << endl;
  }
  cout << endl;
  
  cout << "----- 4.3 Liberation memoire ----------------------------------------------------------------------------" << endl;
  for (int i=0 ; i<10 ; i++) delete intervenants[i];  // Tout se passe-t-il comme vous voulez ?
  // Pour etre plus precis, quid des destructeurs et de la virtualite ?
}

// /*********************************************************************************************/
// // A FAIRE : normalement rien dans vos classes...
// //           juste comprendre et tester le code ci-dessous
void Essai5()
{
  srand((unsigned)time(NULL));

  cout << "----- 5.1 Allocation dynamique d'intervenants --------------------------------" << endl;
  Intervenant* intervenants[10];

  for (int i=0 ; i<10 ; i++)   // Tracez vos constructeurs !!!
  {
    cout << endl << "intervenants[" << i << "] : ";
    int n = rand()%2;
    switch(n)
    {
      case 0 : intervenants[i] = new Client("Issier","Pol",41,"0485/12.12.23");
               cout << "Client" << endl;
               break;

      case 1 : intervenants[i] = new Employe("Coptere","Eli",7,"copteeli","Vendeur");
               cout << "Employe" << endl;
               break;
    }
  }
  cout << endl;

  cout << "----- 5.2 Test du downcasting et dynamic-cast ------------------------------" << endl;
  for (int i=0 ; i<10 ; i++)
  {
    cout << "intervenants[" << i << "] ";
    Client* pClient = dynamic_cast<Client*>(intervenants[i]);
    if (pClient != NULL) 
    {
      cout << "est un Client" << endl;
      cout << "--> GSM = " << pClient->getGsm() << endl;
    }
    Employe* pEmploye = dynamic_cast<Employe*>(intervenants[i]);
    if (pEmploye != NULL) 
    {
      cout << "est un Employe" << endl;
      cout << "--> fonction = " << pEmploye->getFonction() << endl;
    }
  }
  cout << endl;

  cout << "----- 5.3 Liberation memoire ----------------------------------------------------------------------------" << endl;
  for (int i=0 ; i<10 ; i++) delete intervenants[i];
}

// /******************************************************************************************/
// // A FAIRE : Les deux variables statiques ADMINISTRATIF et VENDEUR (const string) de la classe Employe
void Essai6()
{
  cout << "Les deux fonctions possibles pour un employe sont :" << endl;
  cout << " - " << Employe::ADMINISTRATIF << endl;
  cout << " - " << Employe::VENDEUR << endl << endl;

  Employe e("Dugenou","Jean-Paul",2,"dugejean",Employe::ADMINISTRATIF);
  cout << e << endl;
  e.setFonction(Employe::VENDEUR);
  cout << e << endl;
}
