#include "Iterateur.h"
#include "Vecteur.h"

#include <iostream>
#include <string.h>
#include <new>
using namespace std;

/***********************************************************************************/
/*****************Constructeurs et destructeur**************************************/
/***********************************************************************************/


template <class T>
Iterateur<T>::Iterateur(Vecteur<T> & V) : vec(V), pCur(V.v)
{
    // vec(V);
    // pCur(V.v);
}

template <class T>
void Iterateur<T>::reset()
{
    pCur = vec.v;
}

template <class T>
bool Iterateur<T>::end()
{
    if(pCur - vec.v >= vec.size())
        return true;
    return false;
}

template <class T>
void Iterateur<T>::operator++()
{
    if(end()==true)
    {
        printf("On est a la fin du vecteur");
        return;
    }
    else
    {
        // if(pCur)
        // {
            pCur++;
            //return true;
        // }
        // else
        //     return false;
    }
}
template <class T>
void Iterateur<T>::operator++(int)
{
    return operator++();
}



template <class T>
Iterateur<T>::operator T()const
{
    return *pCur;
}


template class Iterateur<int>;
#include "Client.h"
template class Iterateur<Client>;