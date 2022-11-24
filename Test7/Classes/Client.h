#ifndef CLIENT_H
#define CLIENT_H

#include "Intervenant.h"
#include "Personne.h"
#include <iostream> 
#include <string.h> 
using namespace std;

class Client : public Intervenant
{
    friend ostream& operator<<(ostream&, const Client &);

    private:

        string gsm;

    public:

        string getGsm()const;
        void setGsm(string);


        Client& operator=(const Client&);

        Client();
        Client(string, string, int, string);  
        Client(const Client&);
        ~Client();

        virtual string ToString()const;
        virtual string Tuple()const;


};

#endif