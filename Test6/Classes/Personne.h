#ifndef PERSONNE_H
#define PERSONNE_H


#include <iostream> 
#include <string.h> 
using namespace std;

class Personne
{

    friend istream& operator>>(istream& , Personne&);
    friend ostream& operator<<(ostream&, const Personne&);

    protected:

        string nom;
        string prenom;

    public:

        Personne();
        Personne(string, string);
        Personne(const Personne&);
        ~Personne();

        string getNom()const;
        string getPrenom()const;
        void setNom(string);
        void setPrenom(string);

        Personne& operator=(const Personne&);

};




#endif