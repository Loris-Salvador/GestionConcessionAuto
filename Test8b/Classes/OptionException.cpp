#include "Exception.h"
#include "OptionException.h"

#include <iostream>
#include <string.h>
#include <new>
using namespace std;


/***********************************************************************************/
/*****************Constructeur***********************************************/
/***********************************************************************************/

OptionException::OptionException()
{  
    #ifdef DEBUG
        cout<<"constructeur de OptionException"<<endl;
	#endif
    
}
OptionException::OptionException(string m) : Exception(m)
{
    #ifdef DEBUG
        cout<<"constructeur d'initialisation d' OptionException"<<endl;
	#endif
    //message = m;
}
OptionException::OptionException(const OptionException &source) : Exception(source)
{
    // setMessage(source.getMessage());
}
OptionException::~OptionException()
{
    //cout<<"Destructeur de OptionException"<<endl;
}
