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
        virtual ~Intervenant();


        virtual string Tuple()const=0;
        virtual string ToString()const=0;

        Intervenant& operator=(const Intervenant&);

        static int NumCourant;


};

#endif