#include <iostream>
using namespace std;
#include "Modele.h"
#include <string>

// Quelques conseils avant de commencer...
// * N'oubliez pas de tracer (cout << ...) tous les constructeurs et le destructeur !!! Ca, c'est pas un conseil,
//   c'est obligatoire :-)
// * N'essayez pas de compiler ce programme entierement immediatement. Mettez tout en commentaires
//   sauf le point (1) et creez votre classe (dans ce fichier pour commencer) afin de compiler et tester 
//   le point (1). Une fois que cela fonctionne, decommentez le point (2) et modifier votre classe en 
//   consequence. Vous developpez, compilez et testez donc etape par etape. N'attendez pas d'avoir encode 
//   300 lignes pour compiler...
// * Une fois que tout le programme compile et fonctionne correctement, creez le .h contenant la declaration
//   de la classe, le .cpp contenant la definition des methodes, et ensuite le makefile permettant de compiler
//   le tout grace a la commande make 

int main()
{
  cout << endl << "(1) ***** Test constructeur par defaut + Affiche ************************" << endl;
  {
    Modele modele;
    modele.Affiche();
  } // La presence des accolades assure que le destructeur de Modele sera appele --> a tracer !

  cout << endl << "(2) ***** Test des setters et getters ***********************************" << endl;
  {
    Modele modele;
    modele.setNom("208 Active 1.5 BlueHDi 5P");
    modele.setPuissance(100);
    modele.setMoteur(Diesel);
    modele.setPrixDeBase(21800.0f);
    modele.Affiche();
    cout << "Nom          = " << modele.getNom() << endl;
    cout << "Puissance    = " << modele.getPuissance() << " Ch" << endl;
    cout << "Moteur       = " << modele.getMoteur() << endl;
    cout << "Prix de base = " << modele.getPrixDeBase() << " euros" << endl;
  }

  cout << endl << "(3) ***** Test du constructeur d'initialisation *************************" << endl;
  {
    Modele modele("308 Allure 1.6 Hybrid 5P",150,Hybride,38650.0f);
    modele.Affiche();
  }

  cout << endl << "(4) ***** Test du constructeur de copie *********************************" << endl;
  {
    Modele modele1("2008 GT 1.2 PureTech 130 Man.6",130,Essence,31400.0f);
    cout << "modele1 (AVANT) :" << endl;
    modele1.Affiche();
    {   
      Modele modele2(modele1);
      cout << "modele2 :" << endl;
      modele2.Affiche();
      modele2.setNom("2008 GT 1.2 PureTech 130 EAT8");
      modele2.Affiche();
    } // de nouveau, les {} assurent que modele2 sera detruit avant la suite
    cout << "modele1 (APRES) :" << endl;
    modele1.Affiche();
  }

  cout << endl << "(5) ***** Test d'allocation dynamique (constructeur par defaut) *********" << endl;
  {
    Modele *p = new Modele();
    p->setNom("308 Allure 1.5 BlueHDi 5P");
    p->setPuissance(130);
    p->setMoteur(Diesel);
    p->setPrixDeBase(31650.0f);
    p->Affiche();
    cout << "Le prix de base de ce modele est : " << p->getPrixDeBase() << " euros" << endl;
    delete p;
  }

  cout << endl << "(6) ***** Test d'allocation dynamique (constructeur de copie) ***********" << endl;
  {
    Modele modele1("508 GT 1.6 Hybrid 225 EAT8",225,Hybride,50100.0f);
    cout << "modele1 (AVANT) :" << endl;
    modele1.Affiche();
    Modele* p = new Modele(modele1);
    cout << "La copie :" << endl;
    p->Affiche();
    cout << "Destruction de la copie..." << endl; 
    delete p;
    cout << "modele1 (APRES) :" << endl;
    modele1.Affiche();
  }

  return 0;
}


