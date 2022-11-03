#ifndef INTERVENANT_H
#define INTERVENANT_H

#include "Personne.h"
#include <iostream> 
#include <string.h> 
using namespace std;

class Intervenant : public Personne
{
    protected:

        int numero;
    
    public:

        int getNumero()const;
        void setNumero(int);

        Intervenant();
        Intervenant(string, string, int);
        Intervenant(const Intervenant &);
        ~Intervenant();


        virtual string Tuple()const;
        virtual string ToString()const;

        Intervenant& operator=(const Intervenant&);


};

#endif