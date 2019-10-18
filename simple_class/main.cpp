#include <iostream>
#include "main.h"

using namespace std;

void myclass::execute(void)
{
    cout << "Execute Method: " << *var << "\n";  
    cout << "is everything okay? \n" ; 
}

int main() 
{
    cout << "Hello, World! \n";
    int localvar = 45;
    myclass *myobj = new myclass(&localvar);
    myobj->execute();
    delete(myobj);
    return 0;
}
