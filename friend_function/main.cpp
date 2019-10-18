/*
REFERENCE: 
1. 
*/

#include <iostream>

using namespace std;

class myclass
{
    private:
    int height, width;

    public:
    // myclass(int a=0, int b=0): height(a), width(b)
    // {
    // }

    myclass(): height(2), width(2)
    {
    }
    friend int get_area(myclass myobj);
};

int get_area(myclass myobj)
{
    return (myobj.height * myobj.width);
}

int main(void) 
{
    cout << "Friend Function \n";
    myclass myobj;
    int area = get_area(myobj);
    cout << "area: " << area << endl;
    return 0;
}

/*
NOTE:
Following are the characteristics of a friend function:
-------------------------------------------------------
1. The friend function is not in the scope of the class in which it has been declared.
2. Since it is not in the scope of the class, so it cannot be called by using the object of the class. 
3. Therefore, friend function can be invoked like a normal function.
4. A friend function cannot access the private members directly, it has to use an object name and dot operator with each member name.
5. Friend function uses objects as arguments.
*/