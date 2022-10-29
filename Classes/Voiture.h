#ifndef VOITURE_H
#define VOITURE_H
#include "Modele.h"
#include "Option.h"

#include <iostream> 
#include <string> 
using namespace std;

class Voiture 
{
    friend Voiture operator+(const Option &o, Voiture &v);
    friend ostream& operator<<(ostream& s, const Voiture& v);


    private:
        string nom;
        Modele modele;
        Option* options[5];

    public:

        void setModele(Modele m);
        void setNom(string n);
        string getNom()const;
        Modele getModele()const;


        Voiture();
        Voiture(string nom, Modele modele);
        Voiture(const Voiture &source);
        ~Voiture();

        void Affiche()const;
        
        void AjouteOption(const Option &option);
        void RetireOption(string);
        float getPrix()const;


        Voiture& operator=(const Voiture &);
        Voiture operator+(const Option &)const;
        Voiture operator-(const Option &);
        Voiture operator-(const string &);
        int operator<(const Voiture &)const;
        int operator>(const Voiture &)const;
        int operator==(const Voiture &)const;
        Option* operator[](const int)const;
        
};

#endif