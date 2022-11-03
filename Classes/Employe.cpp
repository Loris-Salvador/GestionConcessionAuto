#include "Employe.h"

#include <iostream>
#include <string.h>
#include <new>
using namespace std;

/***********************************************************************************/
/*****************Constructeurs et destructeur**************************************/
/***********************************************************************************/

Employe::Employe()
{
    login = "Pas de login";
    motDePasse=NULL;
    fonction="aucune fonction";
}
Employe::Employe(string n, string pr, int num, string log, string fct) : Intervenant(n, pr, num)
{
    motDePasse=NULL;

    setLogin(log);
    setFonction(fct);
}
Employe::Employe(const Employe &source) : Intervenant(source)
{
    setMotDePasse(source.getMotDePasse());
    setLogin(source.getLogin());
    setFonction(source.getFonction());
}
Employe::~Employe()
{
    delete motDePasse;
}

/***********************************************************************************/
/*****************Getters et Setters ***********************************************/
/***********************************************************************************/

string Employe::getLogin()const
{
    return login;
}
//const avant string*???

string Employe::getMotDePasse()const
{
    if(motDePasse!=NULL)
        return *motDePasse;
    else
        return "Pas de mdp";
}
string Employe::getFonction()const
{
    return fonction;
}

void Employe::setLogin(string log)
{
    login = log;
}
void Employe::setMotDePasse(string mdp)
{
    motDePasse = new string(mdp);
}
void Employe::ResetMotDePasse()
{
    delete motDePasse;
    //*motDePasse=NULL;
}
void Employe::setFonction(string fct)
{
    if(fct != "Vendeur" && fct != "Administratif")
    {
        do
        {
            cout<<"Veuillez entrer Vendeur ou Administratif comme fct"<<endl;
            cin>>fct;
        }
        while(fct != "Vendeur" && fct != "Administratif");
    }
    fonction = fct;
}

/***********************************************************************************/
/*****************Surcharge Operateur***********************************************/
/***********************************************************************************/


//ATTENTION SUREMENT METTRE + CAR C'EST UNE PERSONNE/Intervenant



Employe& Employe::operator=(const Employe& e)
{
    setNom(e.getNom());
    setPrenom(e.getPrenom());
    setNumero(e.getNumero());
    setLogin(e.getLogin());
    setMotDePasse(e.getMotDePasse());
    setFonction(e.getFonction());

    return (*this);
}

ostream& operator<<(ostream& s, const Employe &e)
{
    s<<e.getNom()<<endl<<e.getPrenom()<< endl<<e.getNumero()<<endl<<e.getLogin()<<endl<<e.getFonction()<<endl;

    return s;
}



string Employe::ToString()const
{
    string c;

    c = "[V";
    c +=std::to_string(getNumero());
    c = c+"] "+getNom()+" "+getPrenom();

    return c;
}

string Employe::Tuple()const
{
    string c;

    c +=std::to_string(getNumero());
    c = c+";"+getNom()+";"+getPrenom()+";"+getFonction();

    return c;
}

const string Employe::ADMINISTRATIF = "Administratif";

const string Employe::VENDEUR = "Vendeur";

