#ifndef OptionException_H
#define OptionException_H


#include "Exception.h"
#include <iostream> 
#include <string.h> 
using namespace std;

class OptionException : public Exception
{
    public:

        OptionException();
        OptionException(string);
        OptionException(const OptionException &);
        ~OptionException();
};

#endif

