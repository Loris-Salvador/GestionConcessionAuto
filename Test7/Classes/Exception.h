#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream> 
#include <string.h> 
using namespace std;

class Exception
{
    protected:

        string message;

    public:

        Exception();
        Exception(string);
        Exception(const Exception &);
        ~Exception();

        string getMessage()const;
        void setMessage(string);

};

#endif