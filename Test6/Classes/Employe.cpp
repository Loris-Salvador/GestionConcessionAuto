#include "Employe.h"
#include "PasswordException.h"

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
    if(motDePasse!=NULL)
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
        throw PasswordException("ERREUR : Pas de mot de passe assigne", PasswordException::NO_PASSSWORD);
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
    int i=0, testLettre=0, testChiffre=0;

    ResetMotDePasse();

    if(mdp.length()<6)
        throw PasswordException("Le mot de passe doit contenir minimum 6 caracteres", PasswordException::INVALID_LENGTH);
   
    while(i<mdp.length())
    {
        if((mdp[i]>='A' && mdp[i]<='Z') || (mdp[i]>='a' && mdp[i]<='z'))
            testLettre=1;
        else if(mdp[i]>='0' && mdp[i]<='9')
            testChiffre=1;
        i++;
    }
    if(testLettre==0)
        throw PasswordException("Le mot de passe doit contenir au moins une lettre", PasswordException::ALPHA_MISSING);
    if(testChiffre==0)//PROBLEME
        throw PasswordException("Le mot de passe doit contenir au moins un chiffre", PasswordException::DIGIT_MISSING);

    motDePasse = new string(mdp);
}
void Employe::ResetMotDePasse()
{
    if(motDePasse!=NULL)
    {
        delete motDePasse;
        motDePasse=NULL;
    }
    
    
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
    // setNom(e.getNom());
    // setPrenom(e.getPrenom());
    // setNumero(e.getNumero());
    Intervenant::operator=(e);
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

    if(getFonction()=="Administratif")
        c = "[A";
    else if(getFonction()=="Vendeur")
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

