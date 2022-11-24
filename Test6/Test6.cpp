#include <iostream>
using namespace std;

#include "Vecteur.h"
#include "Iterateur.h"
#include "Client.h"


//#include "VecteurTrie.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();
void Essai6();
void Essai7();
void Essai8();

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
      // case 5 : Essai5(); break;
      // case 6 : Essai6(); break;
      // case 7 : Essai7(); break;
      // case 8 : Essai8(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 6 ---------------------------------------------------------" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << " 1. Test du template Vecteur avec des entiers" << endl;
  cout << " 2. Test du template Vecteur avec des objets de la classe Client" << endl;
  cout << " 3. Test de l'iterateur avec un Vecteur d'entiers" << endl;
  cout << " 4. Test de l'iterateur avec un Vecteur de Clients" << endl;
  cout << "***** BONUS **********************************************" << endl;
  cout << " 5. Test du template VecteurTrie avec des entiers" << endl;
  cout << " 6. Test du template VecteurTrie avec des objets de la classe Client" << endl;
  cout << " 7. Test de l'iterateur avec un VecteurTrie d'entiers" << endl;
  cout << " 8. Test de l'iterateur avec un VecteurTrie de Clients" << endl;
  cout << " 9. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

/*******************************************************************************************************/
void Essai1()
{
  cout << "----- 1. Test du template Vecteur avec des entiers ------------------------------------------" << endl;
  cout << "----- 1.1 Creation et gestion d'un Vecteur --------------------------------------------------" << endl;

  Vecteur<int> vec(10);  // Capacité maximale de 10
  vec.Affiche();                                         // --> ()
  cout << endl;

  cout << "On insere 3,-2,5,-1,0 et 17..." << endl;
  vec.insere(3);
  vec.insere(-2);
  vec.insere(5);
  vec.insere(-1);
  vec.insere(0);
  vec.insere(17);
  vec.Affiche();        // --> (3 -2 5 -1 0 17)
  cout << "Capacite du vecteur = " << vec.sizeMax() << endl;
  cout << "Le vecteur contient " << vec.size() << " elements." << endl << endl;

  cout << "----- 1.2 On retire des elements du vecteur -------------------------------------------------" << endl;
  cout << "On retire l'element d'indice 4 (0)  : " << vec.retire(4) << endl;
  vec.Affiche();
  cout << "On retire l'element d'indice 0 (3)  : " << vec.retire(0) << endl;
  vec.Affiche();
  cout << "On retire l'element d'indice 3 (17) : " << vec.retire(3) << endl;
  vec.Affiche();

  cout << "----- 1.3 Test du constructeur de copie -----------------------------------------------------" << endl;
  {
    Vecteur<int> vec2(vec);
    cout << "----> Voici la copie :" << endl;
    vec2.Affiche();
    cout << "----> On insere 50 dans la copie :" << endl; 
    vec2.insere(50);
    vec2.Affiche();
    cout << "----> Destruction de la copie..." << endl;
  }
  cout << endl << "Et revoici le vecteur de depart : " << endl;
  vec.Affiche();
  cout << endl;

  cout << "----- 1.4 Test de l'operateur = -------------------------------------------------------------" << endl;
  {
    Vecteur<int> vec3;
    vec3 = vec;
    cout << "----> Voici le resultat de l'operateur = :" << endl;
    vec3.Affiche();
    cout << "----> On insere 50 dans le nouveau vecteur :" << endl; 
    vec3.insere(50);
    vec3.Affiche();
    cout << "----> Destruction du nouveau vecteur..." << endl;
  }
  cout << endl << "Et revoici le vecteur de depart : " << endl;
  vec.Affiche();
  cout << endl;

  cout << "----- 1.5 Test de l'operateur [] -------------------------------------------------------------" << endl;
  for (int i=0 ; i<vec.size() ; i++)
    cout << "vec[" << i << "] = " << vec[i] << endl;
}

/*********************************************************************************************/
void Essai2()
{
  cout << "----- 2. Test du template Vecteur avec des objets de la classe Client --------------" << endl;
  cout << "Creation  d'un vecteur..." << endl;
  Vecteur<Client> vec;
  vec.Affiche();                                    
  cout << endl;

  cout << "On insere Client(\"Wagner\",\"Jean-Marc\",1,\"0498.25.36.23\")..." << endl;
  vec.insere(Client("Wagner","Jean-Marc",1,"0498.25.36.23"));
  vec.Affiche();

  cout << "On insere c(\"Leonard\",\"Anne\",2,\"0478/11.23.65\")..." << endl;
  Client c("Leonard","Anne",2,"0478/11.23.65");
  vec.insere(c);
  vec.Affiche();

  cout << "On insere new Client(\"Quettier\",\"Patrick\",3,\"0476/78.45.12\")..." << endl;
  Client *ptr = new Client("Quettier","Patrick",3,"0476/78.45.12");
  vec.insere(*ptr);
  delete ptr;
  vec.Affiche();
  cout << "Le vecteur contient " << vec.size() << " elements." << endl << endl;

  cout << "vec[1] = " << vec[1] << endl << endl;

  cout << endl;
}

/*******************************************************************************************************/
void Essai3()
{
  cout << "----- 3. Test de l'iterateur avec un vecteur d'entiers ------------------------" << endl;
  cout << "Creation  d'un vecteur..." << endl;
  Vecteur<int> vec;

  cout << "On insere 3,-2,5,-1 et 0..." << endl;
  vec.insere(3);
  vec.insere(-2);
  vec.insere(5);
  vec.insere(-1);
  vec.insere(0);



  cout << "On affiche grace a un iterateur..." << endl;
  Iterateur<int> it(vec);
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (int)it << endl;
  cout << endl;

  cout << "On supprime l'element d'indice 1 et on re-affiche grace a l'iterateur..." << endl;
  vec.retire(1);
  it.reset();
  while (!it.end())
  {
    cout << " " << (int)it << endl;
    it++;
  }
}

/*******************************************************************************************************/
void Essai4()
{
  cout << "----- 4. Test de l'iterateur avec un Vecteur de Clients ---------------------" << endl;
  cout << "Creation  d'un vecteur..." << endl;
  Vecteur<Client> vec(8);
  
  cout << "On insere quelques clients..." << endl;
  vec.insere(Client("Wagner","Jean-Marc",1,"0498.25.36.23"));
  vec.insere(Client("Leonard","Anne",2,"0478/11.23.65"));
  vec.insere(Client("Quettier","Patrick",3,"0476/78.45.12"));
  vec.insere(Client("Vilvens","Claude",4,"0477/45.29.98"));
  vec.insere(Client("Charlet","Christophe",5,"0475/71.31.89"));
  
  cout << "On affiche grace a un iterateur..." << endl;
  Iterateur<Client> it(vec);
  for (it.reset() ; !it.end() ; it++)
  {
    Client c = (Client)it;
    cout << " " << c << " >> Tuple = " << c.Tuple() << endl;
  }
  cout << endl;

  cout << "On supprime l'element d'indice 1 et on re-affiche grace a l'iterateur..." << endl;
  vec.retire(1);
  it.reset();
  while (!it.end())
  {
    cout << " " << (Client)it << endl;
    it++;
  }
}

// /*******************************************************************************************************/
// void Essai5()
// {
//   cout << "----- 5. Test du template Vecteur avec des entiers ------------------------------------------" << endl;
//   cout << "----- 5.1 Creation et gestion d'un Vecteur --------------------------------------------------" << endl;

//   VecteurTrie<int> vec(10);  // Capacité maximale de 10
//   vec.Affiche();                                         // --> ()
//   cout << endl;

//   cout << "On insere 3,-2,5,-1,0 et 17..." << endl;
//   vec.insere(3);
//   vec.insere(-2);
//   vec.insere(5);
//   vec.insere(-1);
//   vec.insere(0);
//   vec.insere(17);
//   vec.Affiche();        // --> (-2 -1 0 3 5 17)
//   cout << "Capacite du vecteur = " << vec.sizeMax() << endl;
//   cout << "Le vecteur contient " << vec.size() << " elements." << endl << endl;

//   cout << "----- 5.2 On retire des elements du vecteur -------------------------------------------------" << endl;
//   cout << "On retire l'element d'indice 4 (5)  : " << vec.retire(4) << endl;
//   vec.Affiche();
//   cout << "On retire l'element d'indice 0 (-2)  : " << vec.retire(0) << endl;
//   vec.Affiche();
//   cout << "On retire l'element d'indice 3 (3) : " << vec.retire(3) << endl;
//   vec.Affiche();
// }

// /*******************************************************************************************************/
// void Essai6()
// {
//   cout << "----- 6. Test du template VecteurTrie avec des objets de la classe Client ---------------" << endl;
//   cout << "Creation  d'un vecteur trie..." << endl;
//   VecteurTrie<Client> vec;
//   vec.Affiche();                                       
//   cout << endl;

//   cout << "On insere quelques clients..." << endl;
//   vec.insere(Client("Wagner","Jean-Marc",1,"0498.25.36.23"));
//   vec.insere(Client("Leonard","Anne",2,"0478/11.23.65"));
//   vec.insere(Client("Quettier","Patrick",3,"0476/78.45.12"));
//   vec.insere(Client("Vilvens","Claude",4,"0477/45.29.98"));
//   vec.insere(Client("Charlet","Christophe",5,"0475/71.31.89"));
//   vec.insere(Client("Quettier","Sophie",6,"0475/48.65.92"));
//   vec.Affiche();
//   cout << "Le vecteur contient " << vec.size() << " elements." << endl;
//   cout << endl;
// }

// /*******************************************************************************************************/
// void Essai7()
// {
//   cout << "----- 7. Test de l'iterateur avec un VecteurTrie d'entiers ------------------------" << endl;
//   cout << "Creation  d'un vecteur trie..." << endl;
//   VecteurTrie<int> vec;

//   cout << "On insere 3,-2,5,-1 et 0..." << endl;
//   vec.insere(3);
//   vec.insere(-2);
//   vec.insere(5);
//   vec.insere(-1);
//   vec.insere(0);

//   cout << "On affiche grace a un iterateur..." << endl;
//   Iterateur<int> it(vec);
//   for (it.reset() ; !it.end() ; it++)
//     cout << " " << (int)it << endl;
//   cout << endl;

//   cout << "On supprime l'element d'indice 1 et on re-affiche grace a l'iterateur..." << endl;
//   vec.retire(1);
//   it.reset();
//   while (!it.end())
//   {
//     cout << " " << (int)it << endl;
//     it++;
//   }
// }

// /*******************************************************************************************************/
// void Essai8()
// {
//   cout << "----- 8. Test de l'iterateur avec un VecteurTrie de Clients ---------------------" << endl;
//   cout << "Creation  d'un vecteur..." << endl;
//   VecteurTrie<Client> vec(8);
  
//   cout << "On insere quelques clients..." << endl;
//   vec.insere(Client("Wagner","Jean-Marc",1,"0498.25.36.23"));
//   vec.insere(Client("Leonard","Anne",2,"0478/11.23.65"));
//   vec.insere(Client("Quettier","Patrick",3,"0476/78.45.12"));
//   vec.insere(Client("Vilvens","Claude",4,"0477/45.29.98"));
//   vec.insere(Client("Charlet","Christophe",5,"0475/71.31.89"));
  
//   cout << "On affiche grace a un iterateur..." << endl;
//   Iterateur<Client> it(vec);
//   for (it.reset() ; !it.end() ; it++)
//   {
//     Client c = (Client)it;
//     cout << " " << c << " >> Tuple = " << c.Tuple() << endl;
//   }
//   cout << endl;

//   cout << "On supprime l'element d'indice 1 et on re-affiche grace a l'iterateur..." << endl;
//   vec.retire(1);
//   it.reset();
//   while (!it.end())
//   {
//     cout << " " << (Client)it << endl;
//     it++;
//   }
// }
