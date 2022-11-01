#include "Option.h"

#include <iostream>
#include <string.h>
using namespace std;



/***********************************************************************************/
/*****************Constructeurs et destructeur**************************************/
/***********************************************************************************/


Option::Option()
{
    #ifdef DEBUG
	    cout<<"Constructeur par défaut d'Option"<<endl;
	#endif


    setCode("sans code");
    setIntitule("sans intitule");
    setPrix(0);
}
Option::Option(string code, string intitule, float prix)
{
    #ifdef DEBUG
		cout<<"Constructeur par initialisation d'Option"<<code<<" "<<intitule<<" "<<prix<<endl;
	#endif

    setCode(code);
    setIntitule(intitule);
    setPrix(prix);
}
Option::Option(const Option &source)
{
    #ifdef DEBUG
		cout<<"Constructeur de copie d'option  "<<source.getCode()<<" "<<source.getIntitule()<<"  "<<source.getPrix<<endl;
	#endif

    setCode(source.getCode());
    setIntitule(source.getIntitule());
    setPrix(source.getPrix());
}
Option::~Option()
{
    #ifdef DEBUG
		cout<<"Destructeur d'Option"<<getCode()<<"-"<<getIntitule()<<" "<<getPrix()<<endl
	#endif
    


}


/***********************************************************************************/
/*****************Getters et Setters ***********************************************/
/***********************************************************************************/

void Option::setCode(string c)
{
    code=c;
}
void Option::setIntitule(string inti)
{
    intitule=inti;
}
void Option::setPrix(float p)
{
    prix=p;
}


string Option::getCode()const
{
    return code;
}
string Option::getIntitule()const
{
    return intitule;
}
float Option::getPrix()const
{
    return prix;
}


//////////FONCTION AFFICHE//////////////////

void Option::Affiche()const
{
    cout<<code<<"  "<<intitule<<"  "<<prix<<endl;
}




istream& operator>>(istream& s, Option& o)
{
    string c;
    string i;
    float p;

    cout << "Code : "<<endl;
    getline(cin, c);
    cout << "intitule"<<endl;
    getline(cin, i);
    cout <<"Prix : "<<endl;
    cin >> p;


    o.setCode(c);
    o.setIntitule(i);
    o.setPrix(p);

    return s;

}

ostream& operator<<(ostream& s, const Option& o)
{

    s << o.code <<"  "<<o.intitule<< "  "<<o.prix<<endl;

    return s;
}

Option Option::operator--()
{
    prix = prix - 50;
    return (*this);
}

Option Option::operator--(int)
{ 
    Option temp(*this);

    this->prix=this->prix-50;
    
    return temp;
}