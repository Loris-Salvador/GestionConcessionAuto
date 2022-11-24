#ifndef EMPLOYE_H
#define EMPLOYE_H

#include "Intervenant.h"
#include <iostream> 
#include <string.h> 
using namespace std;

class Employe : public Intervenant
{
    friend ostream& operator<<(ostream&, const Employe&);

    private:

        string login;
        string* motDePasse;
        string fonction;

    public:

        static const string ADMINISTRATIF;
        static const string VENDEUR;

        Employe();
        Employe(string, string, int, string, string);
        Employe(const Employe &);
        ~Employe();

        string getLogin()const;
        string getMotDePasse()const;
        string getFonction()const;

        void setLogin(string);
        void setMotDePasse(string);
        void setFonction(string);
        void ResetMotDePasse();


        Employe& operator=(const Employe&);


        string ToString()const;
        string Tuple()const;

        // string ADMINISTRATIF();
        // string VENDEUR();

};

#endif