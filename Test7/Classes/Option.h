#ifndef OPTION_H
#define OPTION_H

#include <string>
using namespace std;

class Option
{
    friend istream& operator>>(istream& s, Option& o);
    friend ostream& operator<<(ostream& s, const Option& o);

    private:
        string code;
        string intitule;
        float prix;
    public:

        Option();
        Option(string, string, float);
        Option(const Option&);
        ~Option();

        void setCode(string);
        void setIntitule(string);
        void setPrix(float);
        
        string getCode()const;
        string getIntitule()const;
        float getPrix()const;

        void Affiche()const;

        Option operator--();
        Option operator--(int);

        	
        void Save(ofstream &)const;
	    void Load(ifstream &);

};

#endif