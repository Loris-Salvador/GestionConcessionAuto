#include "Vecteur.h"
#include "Iterateur.h"
#include "VecteurTrie.h"

#include <iostream>
#include <string.h>
#include <new>
using namespace std;

/***********************************************************************************/
/*****************Constructeurs et destructeur**************************************/
/***********************************************************************************/
template <class T>
VecteurTrie<T>::VecteurTrie()
{
    //cout<<"Constructeur par defaut Vecteur trie"<<endl;
}

template <class T>
VecteurTrie<T>::VecteurTrie(int sizeMax) : Vecteur<T>(sizeMax)
{
    #ifdef DEBUG
		cout<<"Destructeur de VecteurTrie"<<endl;
	#endif
    //cout<<"Constructeur d'initilisation Vecteur trie"<<endl;
}

template <class T>
void VecteurTrie<T>::insere(const T & val)
{
    int i=0,j=0;

    if(this->size()==this->sizeMax())
    {
        printf("Plus de place dans le vecteur");
        return;
    }
    if(this->size()!=0)
    {
        //trouver ou le mettre
        while(this->v[i]<val)
        {
            i++;
        }
        //decaler
        for(j=(this->size());j>i;j--)
        {
            this->v[j]=this->v[j-1];
        }
    }

    this->v[j]=val;
    (this->_size)++;

}

template class VecteurTrie<int>;
#include "Client.h"
template class VecteurTrie<Client>;
#include "Employe.h"
template class VecteurTrie<Employe>;