#include "Exception.h"
#include "PasswordException.h"

#include <iostream>
#include <string.h>
#include <new>
using namespace std;


/***********************************************************************************/
/*****************Constructeur***********************************************/
/***********************************************************************************/

PasswordException::PasswordException()
{
    code = 0;
}
PasswordException::PasswordException(string m, int c) : Exception(m)
{
    setCode(c);
}
PasswordException::PasswordException(const PasswordException &source) : Exception(source)
{
    setCode(source.getCode());
}
PasswordException::~PasswordException()
{

}


void PasswordException::setCode(int c)
{
    code = c;
}
int PasswordException::getCode()const
{
    return code;
}

const int PasswordException::INVALID_LENGTH = 1;
const int PasswordException::ALPHA_MISSING = 2;
const int PasswordException::DIGIT_MISSING = 3;
const int PasswordException::NO_PASSSWORD = 4;