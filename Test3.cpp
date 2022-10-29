#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Voiture.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();
void Essai6();
void Essai7();
void Essai8();
void Essai9();

int main(int argc,char* argv[])
{
  int choix;
  bool fini = false;
  
  while(!fini)
  {
    if (argc == 2) { choix = atoi(argv[1]); fini = true; }
    else choix = Menu();
    switch(choix)
    {
      case 1 : Essai1(); break;
      case 2 : Essai2(); break;
      case 3 : Essai3(); break;
      case 4 : Essai4(); break;
      case 5 : Essai5(); break;
      case 6 : Essai6(); break;
      case 7 : Essai7(); break;
      case 8 : Essai8(); break;
      case 9 : Essai9(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

/*******************************************************************************************************/
int Menu()
{
  cout << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TESTS 3 -------------------------------------------------------------------" << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << " 1. Tests de l'operateur = de la classe Voiture" << endl;
  cout << " 2. Tests des operateurs + de la classe Voiture" << endl;
  cout << " 3. Tests des operateurs - de la classe Voiture" << endl;
  cout << " 4. Tests des operateurs < > == de la classe Voiture" << endl;
  cout << " 5. Tests des operateurs << et >> de la classe Option" << endl;
  cout << " 6. Tests des operateurs << et >> de la classe Modele" << endl;
  cout << " 7. Tests de l'operateur << de la classe Voiture" << endl;
  cout << " 8. Tests des operateurs de pre/post decrementation de la classe Option" << endl;
  cout << " 9. Tests de l'opérateur [] de Voiture" << endl;
  cout << "10. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

/*******************************************************************************************************/
/*** Tests des operateurs = de la classe Voiture *******************************************************/
/*******************************************************************************************************/
void Essai1()
{
  cout << "********************************************************************" << endl;
  cout << "(1) ***** Tests de l'operateur d'affectation de Voiture ************" << endl;
  cout << "********************************************************************" << endl;
  {
    Voiture v1("Projet_208_MrDugenou",Modele("208 Access 1.0",68,Essence,12500.0f));
    v1.AjouteOption(Option("0MM0","Peinture metallisee",450.0f));
    v1.AjouteOption(Option("ZH75","Jante alliage leger 15 pouces",450.0f));
    cout << "---- v1 (avant affectation) --------------------" << endl;
    v1.Affiche();
    {
      Voiture v2;
      cout << ">>>>> v2 = v1;  (+ on retire une option)" << endl;
      v2 = v1;
      v2.RetireOption("0MM0");
      cout << "---- v2 ----------------------------" << endl;
      v2.Affiche();
      // Destruction de v2
    }
    cout << "---- v1 (apres affectation) -------------------------" << endl;
    v1.Affiche();
  }
}

/*******************************************************************************************************/
/*** Tests des operateurs + de la classe Voiture *******************************************************/
/*******************************************************************************************************/
void Essai2()
{
  cout << endl << "********************************************************************" << endl;
  cout <<         "(2) ***** Tests des operateurs + de Voiture ************************" << endl;
  cout <<         "********************************************************************" << endl;
  
  Voiture v("Projet_208_MrDugenou",Modele("208 Access 1.0",68,Essence,12500.0f)),v2;
  cout << "---- v (avant) --------------------------" << endl;
  v.Affiche();
  {
    Option op1("VD09","Vitres laterales arriere surteintees",150.0f);
    Option op2("0MM0","Peinture metallisee",450.0f);
    cout << ">>>>> v2 = v + op1;" << endl;
    v2 = v + op1;
    cout << ">>>>> v2 = v2 + Option(...Pack Cuir...);" << endl;
    v2 = v2 + Option("0P3U","Pack Cuir ambiance Mistral",1100.0f);
    cout << ">>>>> v2 = op2 + v2;" << endl;
    v2 = op2 + v2;
  }
  cout << "---- v (apres) --------------------------" << endl; // v ne doit pas etre modifie !!!!
  v.Affiche();
  cout << "---- v2 (v + 3 options) ------------------------" << endl;
  v2.Affiche();
}

/*******************************************************************************************************/
/*** Tests des opérateurs - de la classe Voiture *******************************************************/
/*******************************************************************************************************/
void Essai3()
{
  cout << endl << "********************************************************************" << endl;
  cout <<         "(3) ***** Tests des operateurs - de Voiture ************************" << endl;
  cout <<         "********************************************************************" << endl;

  Voiture v3("Projet_3008_MrLegrand",Modele("3008 Acces 1.6",120,Essence,25030.0f));
  v3 = v3 + Option("ZV02","Vision tete haute",350.0f);
  v3 = v3 + Option("OK01","Toit panoramique vitre",500.0f);
  v3 = v3 + Option("0MM0","Peinture metallisee",570.0f);
  cout << "----- v3 (avant) -----------------" << endl;
  v3.Affiche();
  v3 = v3 - Option("ZV02","Vision tete haute",350.0f);  // !!!
  v3 = v3 - "0MM0";                                     // !!!
  cout << "----- v3 (apres) ------------------" << endl;
  v3.Affiche();
}

/*******************************************************************************************************/
/*** Test des opérateurs < > == de la classe Voiture ***************************************************/
/*******************************************************************************************************/
void Essai4()
{
  cout << "**********************************************************************" << endl;
  cout << "(4) Tests des opérateurs < > == de Voiture ***************************" << endl;
  cout << "**********************************************************************" << endl;

  Voiture v1("Projet1_208_MrDugenou",Modele("208 Access 1.0",68,Essence,12500.0f));
  v1.AjouteOption(Option("0MM0","Peinture metallisee",450.0f));
  cout << "---- Projet 1 --------------------" << endl;
  v1.Affiche();
  cout << "Prix du projet 1 = " << v1.getPrix() << " euros" << endl << endl;

  Voiture v2("Projet2_208_MrDugenou",Modele("208 Access 1.0",68,Essence,12500.0f));
  v2 = v2 + Option("0MM0","Peinture metallisee",450.0f);
  v2 = v2 + Option("ZH75","Jante alliage leger 15 pouces",450.0f);
  cout << "---- Projet 2 --------------------" << endl;
  v2.Affiche();
  cout << "Prix du projet 2 = " << v2.getPrix() << " euros" << endl << endl;

  cout << "---- Comparaison des projets -------------------" << endl;
  if (v1 < v2) cout << "Le projet 1 est moins cher" << endl;
  if (v1 > v2) cout << "Le projet 1 est plus cher" << endl;
  if (v1 == v2) cout << "Les deux projets ont le meme prix" << endl;
}

/*******************************************************************************************************/
/*** Test des opérateurs << et >> de la classe Option **************************************************/
/*******************************************************************************************************/
void Essai5()
{
  cout << "**********************************************************************" << endl;
  cout << "(5) ***** Tests des opérateurs << et >> de Option ********************" << endl;
  cout << "**********************************************************************" << endl;
  Option o;
  cout << "Saisissez une nouvelle option :" << endl;
  cin >> o;
  cout << endl << "Voici l'option que vous avez encodee :" << endl;
  cout << o << endl << endl;
}

/*******************************************************************************************************/
/*** Test des opérateurs << et >> de la classe Modele **************************************************/
/*******************************************************************************************************/
void Essai6()
{
  cout << "**********************************************************************" << endl;
  cout << "(6) ***** Tests des opérateurs << et >> de Modele ********************" << endl;
  cout << "**********************************************************************" << endl;
  Modele m;
  cout << "Saisissez un nouveau modele :" << endl;
  cin >> m;
  cout << endl << "Voici le modele que vous avez encode :" << endl;
  cout << m << endl << endl;
}

/*******************************************************************************************************/
/*** Test de l'opérateur << de la classe Voiture *******************************************************/
/*******************************************************************************************************/
void Essai7()
{
  cout << "**********************************************************************" << endl;
  cout << "(7) ***** Tests de l'opérateur << de Voiture *************************" << endl;
  cout << "**********************************************************************" << endl;
  Voiture v("Projet_208_MrLagalere",Modele("208 Access 1.0",68,Essence,12500.0f));
  cout << endl << "Voici le projet de Voiture (sans option) :" << endl;
  cout << v << endl;

  v.AjouteOption(Option("0MM0","Peinture metallisee",450.0f));
  v.AjouteOption(Option("ZH75","Jante alliage leger 15 pouces",450.0f));
  v.AjouteOption(Option("UB01","Detecteur obstacles arriere",250.0f));

  cout << endl << "Voici le projet de Voiture (avec options) :" << endl;
  cout << v << endl;
}

/*******************************************************************************************************/
/*** Tests des operateurs de pre/post decrementation de la classe Option *******************************/
/*******************************************************************************************************/
void Essai8()
{
  cout << "**********************************************************************" << endl;
  cout << "(8.a) ***** Test de l'operateur de pre-decrementation ****************" << endl;
  cout << "**********************************************************************" << endl;
  Option op1("0MM0","Peinture metallisee",450.0f);
  cout << "Affichons d'abord op1 : " << op1 << endl;
  cout << "Resultat de cout << --op1 << endl; :" << endl;  
  cout << --op1 << endl;        // Si tout va bien, op1 est decremente avant d'etre affiche !
  cout << "et on reaffiche op1 : " << op1 << endl << endl;

  cout << "**********************************************************************" << endl;
  cout << "(8.b) ***** Test de l'operateur de post-decrementation ***************" << endl;
  cout << "**********************************************************************" << endl;
  Option op2("ZH75","Jantes alliage 15 pouces",350.0f);
  cout << "Affichons d'abord op2 : " << op2 << endl;
  cout << "Resultat de cout << op2-- << endl; :" << endl;  
  cout << op2-- << endl;        // Si tout va bien, op2 est decremente apres avoir ete affiche !
  cout << "et on reaffiche op2 : " << op2 << endl << endl;
}

/*******************************************************************************************************/
/*** Tests de l'opérateur [] de la classe Voiture ******************************************************/
/*******************************************************************************************************/
void Essai9()
{
  cout << "**********************************************************************" << endl;
  cout << "(9) ***** Tests de l'opérateur [] de Voiture *************************" << endl;
  cout << "**********************************************************************" << endl;
  Voiture v("Projet_208_MrLagalere",Modele("208 Access 1.0",68,Essence,12500.0f));
  cout << endl << "Voici le projet de Voiture (sans option) :" << endl;
  cout << v << endl;

  v.AjouteOption(Option("0MM0","Peinture metallisee",450.0f));
  v.AjouteOption(Option("ZH75","Jante alliage leger 15 pouces",450.0f));
  v.AjouteOption(Option("UB01","Detecteur obstacles arriere",250.0f));
  v.AjouteOption(Option("OK01","Toit panoramique vitre",500.0f));
  v = v - "ZH75";

  cout << endl << "Voici le projet de Voiture (avec options) :" << endl;
  cout << v << endl;

  cout << endl << "Voici les options affichées une à une :" << endl;
  for (int i=0 ; i<5 ; i++)
  {
    cout << i << " : ";
    if (v[i] != NULL) cout << *(v[i]) << endl;
    else cout << "---" << endl;
  }
}
