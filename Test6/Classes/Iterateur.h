#ifndef ITERATEUR_H
#define ITERATEUR_H
#include "Vecteur.h"

#include <iostream> 
using namespace std;

template<class T> class Vecteur;

template<class T> 

class Iterateur
{
    private:

        Vecteur<T> &vec;
        T *pCur;

    public:

        Iterateur(Vecteur<T>&);

        void reset();
        bool end();


        void operator++();
        void operator++(int);
        operator T()const;
        

};


// template class Iterateur<int>;
// #include "Client.h"
// template class Iterateur<Client>;



#endif