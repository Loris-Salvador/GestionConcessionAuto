#ifndef PasswordException_H
#define PasswordException_H


#include "Exception.h"
#include <iostream> 
#include <string.h> 
using namespace std;

class PasswordException : public Exception
{
    private:

        int code;

    public:

        PasswordException();
        PasswordException(string, int);
        PasswordException(const PasswordException &);
        ~PasswordException();

        void setCode(int);
        int getCode()const;

        static const int INVALID_LENGTH;
        static const int ALPHA_MISSING;
        static const int DIGIT_MISSING;
        static const int NO_PASSSWORD;
        
};

#endif