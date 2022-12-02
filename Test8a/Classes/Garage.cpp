#include "Option.h"
#include "Modele.h"
#include "VecteurTrie.h"
#include "Vecteur.h"
#include "Garage.h"
#include "Employe.h"
#include "Client.h"

#include <iostream>
#include <string.h>
#include <new>
using namespace std;

/***********************************************************************************/
/*****************Constructeurs et destructeur**************************************/
/***********************************************************************************/
Garage::Garage()
{
    
}

void Garage::ajouteModele(const Modele &m)
{
    modeles.insere(m);
}

void Garage::ajouteOption(const Option &o)
{
    options.insere(o);
}

void Garage::afficheOptionsDisponibles()const
{
    options.Affiche();
}

void Garage::afficheModelesDisponibles()const
{
    modeles.Affiche();
}

Modele Garage::getModele(int indice)
{
    return modeles[indice];
}

Option Garage::getOption(int indice)
{
    return  options[indice];
}

void Garage::ajouteClient(string nom, string prenom, string gsm)
{
    
    Intervenant::NumCourant++;
    Client c(nom, prenom, Intervenant::NumCourant, gsm);


    clients.insere(c);
}

void Garage::ajouteEmploye(string nom,string prenom,string login,string fonction)
{   
    Intervenant::NumCourant++;
    Employe e(nom, prenom,Intervenant::NumCourant,  login, fonction);
    //e.setMotDePasse("hqdsjfdsfj333");
    employes.insere(e);
}

void Garage::afficheClients()const
{
    clients.Affiche();
}

void Garage::afficheEmployes()const
{
    employes.Affiche();
}

void Garage::supprimeClientParIndice(int ind)
{
    clients.retire(ind);
}

void Garage::supprimeClientParNumero(int num)
{
    int i=0;

    while(clients[i].getNumero()!=num && i<clients.size())
    {
        i++;
    }
    if(i==clients.size())
    {
        cout<<"Client pas trouve"<<endl;
    }
    else
    {
        clients.retire(i);
    }
    
}

void Garage::supprimeEmployeParIndice(int ind)
{
    employes.retire(ind);
}

void Garage::supprimeEmployeParNumero(int num)
{
    int i=0;

    while(employes[i].getNumero()!=num && i<employes.size())
    {
        i++;
    }
    if(i==employes.size())
    {
        cout<<"Employe pas trouve"<<endl;
    }
    else
    {
        employes.retire(i);
    }
    
}