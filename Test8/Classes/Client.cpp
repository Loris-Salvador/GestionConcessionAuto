#include "Client.h"
#include "Personne.h"
#include "Intervenant.h"

#include <iostream>
#include <string.h>
#include <new>
using namespace std;

/***********************************************************************************/
/*****************Constructeurs et destructeur**************************************/
/***********************************************************************************/

Client::Client()
{
    gsm = "pas de gsm assigné";
}
Client::Client(string n, string pr, int num, string g) : Intervenant(n, pr, num)
{
    gsm = g;
}
Client::Client(const Client &source) : Intervenant(source)
{
    setGsm(source.getGsm());
}
Client::~Client()
{
    #ifdef DEBUG
		cout<<"Destructeur d'Employe"<<endl;
	#endif
   //cout<<"yo";
}

/***********************************************************************************/
/*****************Getters et Setters ***********************************************/
/***********************************************************************************/

string Client::getGsm()const
{
    return gsm;
}
void Client::setGsm(string g)
{
    gsm = g;
}

/***********************************************************************************/
/*****************Surcharge Operateur***********************************************/
/***********************************************************************************/


//ATTENTION SUREMENT METTRE + CAR C'EST UNE PERSONNE



Client& Client::operator=(const Client& c)
{
    Intervenant::operator=(c);
    // setNom(c.getNom());
    // setPrenom(c.getPrenom());
    // setNumero(c.getNumero());
    setGsm(c.getGsm());

    return (*this);
}

ostream& operator<<(ostream& s, const Client &c)
{


    s<<c.getNom()<<endl<<c.getPrenom()<< endl<<c.getNumero()<<endl<<c.getGsm()<<endl;

    return s;
}
bool Client::operator<(const Client &c)const
{
    // string c1, c2;

    // c1=this->getNom()+this->getPrenom();
    // c2=c.getNom()+c.getPrenom();

    // if(c1<c2)
    //     return true;
    // else 
    //     return false;

    return Personne::operator<(c);
}
bool Client::operator>(const Client &c)const
{
    // string c1, c2;

    // c1=this->getNom()+this->getPrenom();
    // c2=c.getNom()+c.getPrenom();

    // if(c1>c2)
    //     return true;
    // else 
    //     return false;

    return Personne::operator>(c);
}
bool Client::operator==(const Client &c)const
{
    // string c1, c2;

    // c1=this->getNom()+this->getPrenom();
    // c2=c.getNom()+c.getPrenom();

    // if(c1==c2)
    //     return true;
    // else 
    //     return false;

    return Personne::operator==(c);
}




string Client::ToString()const
{
    string c;

    // char* num;

    // sprintf(num, "%d", getNumero());

    c = "[C";//+=getNumero()+" "+getNom()+" "+getPrenom();
    c +=std::to_string(getNumero());
    c = c+"] "+getNom()+" "+getPrenom();

    return c;

    
}
string Client::Tuple()const
{
    string c;

    c +=std::to_string(getNumero());
    c = c+";"+getNom()+";"+getPrenom()+";"+getGsm();

    return c;
}