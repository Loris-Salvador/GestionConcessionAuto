#include "Voiture.h"
#include "Modele.h"
#include "Option.h"
#include "OptionException.h"

#include <iostream>
#include <fstream>
#include <string.h>
#include <new>
using namespace std;


/***********************************************************************************/
/*****************Constructeurs et destructeur**************************************/
/***********************************************************************************/

Voiture::Voiture()
{
	#ifdef DEBUG
		cout<<"Constructeur par défaut de Voiture"<<endl;
	#endif

    setNom("Voiture sans nom");

	for(int i=0;i<5;i++)
	{
		options[i]=NULL;
	}
	
	
}

Voiture::Voiture(string nom, Modele modele)
{

	#ifdef DEBUG
		cout<<"Constructeur par initialisation de Voiture"<<endl;
	#endif

	setNom(nom);
	setModele(modele);

	for(int i=0;i<5;i++)
	{
		options[i]=NULL;
	}
}


Voiture::Voiture(const Voiture &source)
{
	#ifdef DEBUG
		cout<<"Constructeur de copie de Voiture["<<source.getNom()<<"]"<<endl;
	#endif
	setNom(source.getNom());
	setModele(source.getModele());

    for (int i=0;i<5;i++)
    {
        if(source.options[i] != NULL)
            options[i]=new Option(*(source.options[i]));
        else
            options[i]=NULL;
    }
}


Voiture::~Voiture()
{
	#ifdef DEBUG
		cout<<"Destructeur de Voiture"<<getNom()<<"-"<<getModele()<<endl;
	#endif

	for(int i=0;i<5;i++)
    {
        if(options[i]!= NULL)
        {
            delete options[i];
            //options[i]=NULL;
        }
    }



}


/***********************************************************************************/
/*****************Getters et Setters ***********************************************/
/***********************************************************************************/


string Voiture::getNom()const
{
	return nom;
}
Modele Voiture::getModele()const
{
	return modele;
}
void Voiture::setModele(Modele m)
{
	modele.setNom(m.getNom());
    modele.setPuissance(m.getPuissance());
    modele.setMoteur(m.getMoteur());      
    modele.setPrixDeBase(m.getPrixDeBase());
}
void Voiture::setNom(string n)
{
	nom = n;
}

//Affiche objet

void Voiture::Affiche()const 
{

	cout<<nom<<"    "<<endl;
	modele.Affiche();

	for(int i=0;i<5;i++)
	{
		if(options[i]!=NULL)
		{
			options[i]->Affiche();
		}
	}
} 

//FONCTIONS OPTION

void Voiture::AjouteOption(const Option &option)
{
	int i=0;

	while(i<5)
	{
		if(options[i]!=NULL)
		{
			if(options[i]->getCode()==option.getCode())
				throw OptionException("Cette option existe deja");
		}

		i++;
	}

	i=0;
	

	while(i<5 && options[i]!=NULL)
	{
		
		// if(options[i]->getCode()==option.getCode())
		// 	throw OptionException("Cette option existe deja");

		i++;
	}
	if(i>=5)
	{
		throw OptionException("La voiture ne peut avoir plus de 5 options");
	}
	else
		options[i] = new Option(option); 
}

void Voiture::RetireOption(string code)
{

    int i=0;

    while(i<5)
    {
		if(options[i]!=NULL)
		{
			if( options[i]->getCode()==code)
			{
				delete options[i];
				options[i]= NULL;
				return;

			}
		}
        i++;
    }
	if(i<=5)
		throw OptionException("L'option n'existe pas");
    return;
}

float Voiture::getPrix()const
{
	int i=0;

	float prixM=0,prix=0;

	prixM=modele.getPrixDeBase();


	while(i<5)
	{
		if(options[i]!=NULL)
			prix=prix+((options[i])->getPrix());
		i++;
	}

	return prix;

}


//SURCHARGE OPERATEUR

Voiture& Voiture::operator=(const Voiture& v)
{
	int i;

	setNom(v.getNom());
	setModele(v.getModele());

	//boucle delete options au cas ou options avant d'assigner au nv

	for(i=0;i<5;i++)
	{
		if(options[i]!=NULL)
			delete options[i];
	}

	for(i=0;i<5;i++)
    {
        if(v.options[i] != NULL)
            options[i]=new Option(*(v.options[i]));
        else
            options[i]=NULL;
    }

	return (*this);
}

Voiture Voiture::operator+(const Option &o)const
{
	Voiture v(*this);

	for (int i=0;i<5;i++)
    {
        if(v.options[i] == NULL)
		{
			v.options[i]=new Option(o);
			i=5;
		}
            
    }

	return v;
}

Voiture operator+(const Option &o, Voiture &v)
{

	return v + o;
}

Voiture Voiture::operator-(const Option &o)
{
	RetireOption(o.getCode());

	return (*this);
}

Voiture Voiture::operator-(const string &c)
{
	RetireOption(c);

	return (*this);
}

int Voiture::operator<(const Voiture &v)const
{
	if(getPrix()<v.getPrix())
		return 1;
	else
		return 0;
}
int Voiture::operator>(const Voiture &v)const
{
	if(getPrix()>v.getPrix())
		return -1;
	else
		return 0;
}
int Voiture::operator==(const Voiture &v)const
{
	if(getPrix()==v.getPrix())
		return 1;
	else
		return 0;
}

ostream& operator<<(ostream& s, const Voiture& v)
{

	s << v.nom <<endl<< " "<<v.modele<<" "<<endl;

	for(int i=0;i<5;i++)
	{
		if(v.options[i]!=NULL)
		{
			s << *(v.options[i])<<endl;
		}
	}
	return  s;
}

Option* Voiture::operator[](int i)const 
{
	return options[i];
}

/***********************************************************************************/
/*****************FLUX***********************************************/
/***********************************************************************************/

void Voiture::Save()const
{
	string NomFichier;
	int taille, nbre=0;

	NomFichier=nom+".car";

	ofstream fichier(NomFichier, ios::out);

	//nom

	taille=nom.size();

	fichier.write((char*)&taille, sizeof(int));
	fichier.write((char*)nom.data(),taille*sizeof(char));

	//modele

	modele.Save(fichier);

	//option

	for(int i=0;i<5;i++)
	{
		if(options[i]!=NULL)
		{
			nbre++;
		}
	}


	//ecrire le nbre d'option(semble plus facile??)

	fichier.write((char*)&nbre, sizeof(int));

	for(int i=0;i<5;i++)
	{
		if(options[i]!=NULL)
		{
			options[i]->Save(fichier);
		}
	}

	fichier.close();

}
void Voiture::Load(string NomFichier)
{
	int taille, i=0, nbre=0;

	ifstream fichier(NomFichier, ios::in);


	//nom

	fichier.read((char*)&taille,sizeof(int));
    nom.resize(taille);
    fichier.read((char*)nom.data(),taille*sizeof(char));

	//modele

	modele.Load(fichier);

	//option

	for(int i=0;i<5;i++)
    {
        if(options[i]!= NULL)
        {
			delete options[i];
            options[i]=NULL;
        }
    }

	fichier.read((char*)&nbre,sizeof(int));


	for(int i=0;i<nbre;i++)
	{
		options[i] = new Option;
		options[i]->Load(fichier);
	}

	fichier.close();
}




