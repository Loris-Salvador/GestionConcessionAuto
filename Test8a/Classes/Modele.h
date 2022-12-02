#ifndef MODELE_H
#define MODELE_H
#include <stdlib.h>
#include <iostream>
using namespace std;

enum Moteur { Essence, Diesel, Electrique, Hybride };

class Modele
{

friend istream& operator>>(istream& s, Modele& m);
friend ostream& operator<<(ostream& s, const Modele& m);

private:
	char * nom;
	int puissance;
	Moteur moteur;
	float PrixDeBase;

public:
	Modele();
	Modele(const char *, int, Moteur, float);
	Modele(const Modele &);
	~Modele();

	const char *getNom()const; 
	int getPuissance()const;
	Moteur getMoteur()const;
	float getPrixDeBase()const;

	Modele& operator=(const Modele&);

	void setNom(const char* n);
	void setPuissance(int);
	void setMoteur(Moteur);
	void setPrixDeBase(float);
	void Affiche()const;
};

#endif


