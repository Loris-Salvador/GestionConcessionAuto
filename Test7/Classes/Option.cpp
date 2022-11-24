#include "Option.h"
#include "OptionException.h"

#include <iostream>
#include <fstream>
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
    


    code="sans code";
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
		cout<<"Constructeur de copie d'option"<<endl;
	#endif

    setCode(source.getCode());
    setIntitule(source.getIntitule());
    setPrix(source.getPrix());
}
Option::~Option()
{
    #ifdef DEBUG
		cout<<"Destructeur d'Option"<<getCode()<<"-"<<getIntitule()<<" "<<getPrix()<<endl;
	#endif

}


/***********************************************************************************/
/*****************Getters et Setters ***********************************************/
/***********************************************************************************/

void Option::setCode(string c)
{
    if(c.length()!=4)
        throw OptionException("Le code doit contenir exactement 4 caracteres");
    
    code=c;
}
void Option::setIntitule(string inti)
{
    if(inti.length()==0)
        throw OptionException("L'intitule ne peut pas etre vide");
    intitule=inti;
}
void Option::setPrix(float p)
{
    if(p<0)
        throw OptionException("Le prix ne peut pas etre négatif");
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
    cin.ignore();


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
    if(prix-50<0)
        throw OptionException("Le Prix ne peut pas etre negatif");
    prix=prix-50;
    
    return temp;
}

/***********************************************************************************/
/*****************FLUX***********************************************/
/***********************************************************************************/

void Option::Save(ofstream & fichier)const
{
    int taille = code.size();

    //code

    fichier.write((char*)&taille,sizeof(int));
    fichier.write((char*)code.data(),taille*sizeof(char));

    //intitule

    taille = intitule.size();

    fichier.write((char*)&taille,sizeof(int));
    fichier.write((char*)intitule.data(),taille*sizeof(char));


    //prix

    fichier.write((char*)&prix,sizeof(float));

}
void Option::Load(ifstream & fichier)
{
    int taille;

    fichier.read((char*)&taille,sizeof(int));
    code.resize(taille);
    fichier.read((char*)code.data(),taille*sizeof(char));

    //intitule

    fichier.read((char*)&taille,sizeof(int));
    intitule.resize(taille);
    fichier.read((char*)intitule.data(),taille*sizeof(char));

    //prix

    fichier.read((char*)&prix,sizeof(float));

}