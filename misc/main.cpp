
#include <iostream>

using namespace std;

//function pointer 
int (*function_pointer)(int, int);       

int my_function(int value, int anotherValue){
    return value*anotherValue;
}

void function_pointer_example(void){
    function_pointer = my_function;
    int value = (*function_pointer)(20, 20);
    cout << "value is: " << value << endl;
}

/*
Constant Pointers:
------------------
A constant pointer is a pointer that cannot change the address its holding. 
In other words, we can say that once a constant pointer points to a variable then it cannot point to any other variable.
*/

int a;
int* const ptr = &a;

/*
Pointer to Constant:
--------------------
A pointer through which one cannot change the value of variable it points is known as a pointer to constant. 
These type of pointers can change the address they point to but cannot change the value kept at those address.
*/

const int * ptr2;

int main()
{
    cout << "c++ miscellaneous" << endl;
    function_pointer_example();


    return 0;
}
