/*
REFERENCE: 
1. https://www.programiz.com/cpp-programming
*/

#include <iostream>

using namespace std;

class base
{
    private:
    int height, width;

    public:
    void display(void)
    {
        cout << "This is base class" << endl;
    }

};

//Function overriding
class derived: public base
{
    public: 
    void display(void)
    {
        cout << "This is derived class" << endl;
        base::display();
    }
};

//Multilevel inheritance
class A: public base
{

};

class B: public A
{
    
};

class C: public B
{
    
};

//Multiple inheritance 
class Mammal {
  public:
    Mammal()
    {
      cout << "Mammals can give direct birth." << endl;
    }
};

class WingedAnimal {
  public:
    WingedAnimal()
    {
      cout << "Winged animal can flap." << endl;
    }
};

class Bat: public Mammal, public WingedAnimal 
{
    public:
    Bat()
    {
        cout << "Bat class" << endl;
    }
};


int main(void) 
{
    cout << "Function overriding, Multilevel & Multiple Inheritance \n";
    //Function overriding
    derived obj;
    obj.display();

    //Multilevel inheritance
    C objc;
    objc.display();

    //Multiple inheritance 
    Bat b1;

    return 0;
}
