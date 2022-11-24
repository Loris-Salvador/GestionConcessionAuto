#include "Exception.h"

#include <iostream>
#include <string.h>
#include <new>
using namespace std;


/***********************************************************************************/
/*****************Constructeur***********************************************/
/***********************************************************************************/
Exception::Exception()
{
   //cout<<"Constructeur d'Exception"<<endl;
    #ifdef DEBUG
        cout<<"constructeur par defaut d'Exception"<<endl;
	#endif
   message = "";
}
Exception::Exception(string m)
{
    #ifdef DEBUG
        cout<<"constructeur d'initialisation d'Exception"<<endl;
	#endif
    message = m;
}
Exception::Exception(const Exception &source)
{
    setMessage(source.getMessage());
}
Exception::~Exception()
{
    // cout<<"Destructeur de Exception"<<endl;
}

/***********************************************************************************/
/*****************Getter***********************************************/
/***********************************************************************************/

string Exception::getMessage()const
{
    return message;
}

void Exception::setMessage(string m)
{
    message = m;
}

