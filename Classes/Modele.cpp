#include "Modele.h"

#include <iostream>
#include <string.h>
using namespace std;
/***********************************************************************************/
/*****************Constructeurs et destructeur**************************************/
/***********************************************************************************/

Modele::Modele()
{
	#ifdef DEBUG
	cout<<"Constructeur par défaut de Modele"<<endl;
	#endif

	puissance=0;
	PrixDeBase=0;
	moteur=Essence;  
	//nom=NULL;
	//nom=new char[50];
	//strcpy(nom,"Modele sans nom");
	nom=NULL;
	setNom("Modele sans nom");

}


Modele::Modele(const char * n, int p, Moteur m, float pdb)
{
	#ifdef DEBUG
		cout<<"Constructeur par initialisation de Modele["<<n<<"-"<<m<<"-"<<pdb<<"]"<<endl;
	#endif
	nom=NULL;
	setNom(n);
	setPuissance(p);
	setMoteur(m);
	setPrixDeBase(pdb);
}


Modele::Modele(const Modele &source)
{
	#ifdef DEBUG
		cout<<"Constructeur de copie de Modele["<<source.getNom()<<"-"<<source.getPuissance()<<"-"<<source.getNom()<<"]"<<endl;
	#endif
	nom=NULL;
	setNom(source.getNom());
	setPuissance(source.getPuissance());
	setMoteur(source.getMoteur());
	setPrixDeBase(source.getPrixDeBase());
}
Modele::~Modele()
{
	#ifdef DEBUG
		cout<<"Destructeur de Modele"<<getNom()<<"-"<<getPuissance()<<"-"<<getNom()<<"]"<<endl;
	#endif
	if(nom)
		delete[]nom;
}
/***********************************************************************************/
/*****************Getters et Setters ***********************************************/
/***********************************************************************************/
const char * Modele::getNom()const
{
	return nom;
}
int Modele::getPuissance()const
{
	return puissance;
}
Moteur Modele::getMoteur()const
{
	return moteur;
}
float Modele::getPrixDeBase()const
{
	return PrixDeBase;
}


void Modele::setPuissance(int p)
{
	if(p>=0)
		puissance=p;
}
void Modele::setMoteur(Moteur m)
{
	moteur=m;
}
void Modele::setPrixDeBase(float pdb)
{
	if(pdb>=0)
		PrixDeBase=pdb;
}
void Modele::setNom(const char *n)
{
	if(nom!=NULL)
		delete [] nom;
	nom=new char[strlen(n)+1];
	strcpy(nom,n);
}


void Modele::Affiche()const
{
	cout<<nom<<" "<<puissance<<" "<<moteur<<" "<<PrixDeBase<<endl;

}



istream& operator>>(istream& s, Modele& m)
{
	int p;
	float prix;
	char* n;
	int choix;
	n=new char[50];
	Moteur moteur;

	cout << "Nom du modele : "<<endl;
	do
    {
        cin.ignore();
        fgets(n, 50, stdin);
        n[strlen(n)-1]=0;

    } while (n[0]=='\0');
	//ignore();
	cout << "Puissance : "<<endl;
	cin >> p;
	cout <<"Moteur?"<<endl;
	cout << "1 : Essence, 2 : Diesel, 3 Electrique, 4 Hybride"<<endl;
	cin >> choix;
	cout << "PrixDeBase : "<<endl;
	cin >> prix;

	m.setNom(n);
	m.setPuissance(p);
	if(choix==1)
		m.setMoteur(Essence);
	else if(choix==2)
		m.setMoteur(Diesel);
	else if(choix==3)
		m.setMoteur(Electrique);
	else if(choix == 4)
		m.setMoteur(Hybride);
	m.setPrixDeBase(prix);

	return s;
}

ostream& operator<<(ostream& s, const Modele& m)
{
	//m.Affiche();

	s << m.nom <<endl<< m.puissance<<"  "<<m.moteur <<"  "<<m.PrixDeBase<<endl;

	return s;
}
