#include "Personne.h"

#include <iostream>
#include <string.h>
#include <new>
using namespace std;


/***********************************************************************************/
/*****************Constructeurs et destructeur**************************************/
/***********************************************************************************/

Personne::Personne()
{
    #ifdef DEBUG
		cout<<"Constructeur par initialisation de Personne["<<nom<<" "<<prenom<<endl;
	#endif

    nom = "sans Nom";
    prenom = "sans Prenom";
    
}

Personne::Personne(string n, string pr)
{
    #ifdef DEBUG
		cout<<"Constructeur par initialisation de Personne["<<nom<<" "<<prenom<<endl;
	#endif

    // nom = n;
    // prenom = pr;

    setNom(n);
    setPrenom(pr);


    
}

Personne::Personne(const Personne &source)
{
    #ifdef DEBUG
		cout<<"Constructeur de copie de Personne["<<source.getNom()<<"-"<<source.getPrenom()<<"]"<<endl;
	#endif

    setNom(source.getNom());
    setPrenom(source.getPrenom());
}

Personne::~Personne()
{
    #ifdef DEBUG
		cout<<"Destructeur de Personne"<<getNom()<<"-"<<getPrenom()<<endl;
	#endif
}

/***********************************************************************************/
/*****************Getters et Setters ***********************************************/
/***********************************************************************************/


string Personne::getNom()const
{
    return nom;
}

string Personne::getPrenom()const
{
    return prenom;
}

void Personne::setNom(string n)
{
    nom = n;
}
void Personne::setPrenom(string pr)
{
    prenom = pr;
}

/***********************************************************************************/
/*****************Surcharge Operateur***********************************************/
/***********************************************************************************/

istream& operator>>(istream& s, Personne& p)
{
    string n, pr;

    cout<<"Nom : "<<endl;
    getline(cin, n);
    cout<<"Prenom : "<<endl;
    getline(cin, pr);

    p.setNom(n);
    p.setPrenom(pr);

    return s;
}

ostream& operator<<(ostream& s, const Personne& p)
{
    s<<p.nom<<" "<<p.prenom<<endl;

    return s;
}

Personne& Personne::operator=(const Personne& p)
{
    setNom(p.getNom());
    setPrenom(p.getPrenom());

    return (*this);
}


bool Personne::operator<(const Personne &c)const
{
    string p1, p2;

    p1=this->getNom()+this->getPrenom();
    p2=c.getNom()+c.getPrenom();

    if(p1<p2)
        return true;
    else 
        return false;
}
bool Personne::operator>(const Personne &c)const
{
    string p1, p2;

    p1=this->getNom()+this->getPrenom();
    p2=c.getNom()+c.getPrenom();

    if(p1>p2)
        return true;
    else 
        return false;
}
bool Personne::operator==(const Personne &c)const
{
    string p1, p2;

    p1=this->getNom()+this->getPrenom();
    p2=c.getNom()+c.getPrenom();

    if(p1==p2)
        return true;
    else 
        return false;
}