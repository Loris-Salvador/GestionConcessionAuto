#ifndef VECTEUR_H
#define VECTEUR_H
#include "Iterateur.h"

#include <iostream> 
using namespace std;

template<class T>class Iterateur;


template<class T>
class Vecteur
{

    protected :
        T * v;
        int _sizeMax;
        int _size;

    public:

        Vecteur();
        Vecteur(/*const T*, int,*/ int);
        Vecteur(const Vecteur<T>&);
        ~Vecteur();

        int size()const;
        int sizeMax()const;
        void Affiche()const;

        void insere(const T &);
        T retire(int);

        Vecteur<T>& operator=(const Vecteur<T>&);
        const T& operator[](int)const;

        friend class Iterateur<T>;



};

// template class Vecteur<int>;
// #include "Client.h"
// template class Vecteur<Client>;


#endif