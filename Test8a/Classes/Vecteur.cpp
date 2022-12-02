#include "Vecteur.h"
#include "Iterateur.h"

#include <iostream>
#include <string.h>
#include <new>
using namespace std;

/***********************************************************************************/
/*****************Constructeurs et destructeur**************************************/
/***********************************************************************************/

template <class T>
Vecteur<T>::Vecteur()
{
    v = new T[10];
    _sizeMax=10;
    _size = 0;
}
template <class T>
Vecteur<T>::Vecteur(int sizeMax)
{
    v = new T[sizeMax];
    _sizeMax = sizeMax;

    _size = 0;
}
template <class T>
Vecteur<T>::Vecteur(const Vecteur<T> &source)
{
    v = new T[source.sizeMax()];

    for(int i=0;i<source.size();i++)
    {
        // cout<<"yo"<< "    "<<source.size();
        v[i] = source.v[i];
    }

    _sizeMax = source._sizeMax;

    _size = source._size;
}
template <class T>
Vecteur<T>::~Vecteur()
{
    #ifdef DEBUG
		cout<<"Destructeur de Vecteur"<<endl;
	#endif
    delete []v;
}

template <class T>
int Vecteur<T>::size()const
{
    return _size;
}

template <class T>
int Vecteur<T>::sizeMax()const
{
    return _sizeMax;
}

template <class T>
void Vecteur<T>::Affiche()const
{
    for(int i=0;i<size();i++)
    {
        cout<<i<<" : "<<v[i]<<" \n";
    }
}
template <class T>
void Vecteur<T>::insere(const T & val)
{
    if(size()==sizeMax())
    {
        printf("Plus de place dans le vecteur");
        return;
    }
    (v[_size])=val;
    _size++;
}

template <class T>
T Vecteur<T>::retire(int ind)
{
    int i=ind;
    T tmp;
    tmp=v[ind];

    while(i<size())
    {
        v[i]=v[i+1];
        i++;
    }

    _size--;

    return tmp;
}

template <class T>
Vecteur<T>& Vecteur<T>::operator=(const Vecteur<T>& vec)
{

    delete []v;

    v = new T[vec.sizeMax()];

    _size=vec.size();
    _sizeMax=vec.sizeMax();

    for(int i=0;i<vec.size();i++)
    {
        v[i]=vec[i];
    }

    return (*this);
}

template <class T>
const T& Vecteur<T>::operator[](int i)const
{
    return v[i];
}


template class Vecteur<int>;
#include "Client.h"
template class Vecteur<Client>;
#include "Modele.h"
template class Vecteur<Modele>;
#include "Option.h"
template class Vecteur<Option>;
#include "Employe.h"
template class Vecteur<Employe>;

