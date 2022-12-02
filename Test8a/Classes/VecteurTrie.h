#ifndef VECTEURTRIE_H
#define VECTEURTRIE_H

#include "Vecteur.h"
#include "Iterateur.h"

#include <iostream> 
using namespace std;

template<class T>class Iterateur;

template<class T>
class VecteurTrie : public Vecteur<T>
{
    public :

        VecteurTrie();
        VecteurTrie(int);

        void insere(const T &);

        friend class Iterateur<T>;
};

#endif