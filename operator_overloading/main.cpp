/*
REFERENCE: 
1. https://www.geeksforgeeks.org/operator-overloading-c/
*/

#include <iostream>

using namespace std;

class complex
{
    private:
    int real, imag;

    public:
    complex(int a=0, int b=0)
    {
        real=a;
        imag=b;
    }

    // This is automatically called when '+' is used with 
    // between two Complex objects 
    complex operator + (complex const &obj)
    {
        complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }

    void print_complex_number(void) 
    { 
        cout << real << " + i" << imag << endl; 
    } 
};

/*
NOTE:
1. In the above example the operator ‘+’ is overloaded. The operator ‘+’ is an addition operator 
and can add two numbers(integers or floating point) but here the operator is made to perform 
addition of two imaginary or complex numbers.

2. What is the difference between operator functions and normal functions?
Operator functions are same as normal functions. The only differences are, name of an operator 
function is always operator keyword followed by symbol of operator and operator functions are 
called when the corresponding operator is used.
*/

class complex2
{
    private:
    int real, imag;

    public:
    complex2(int a=0, int b=0)
    {
        real=a;
        imag=b;
    }

    void print_complex_number(void) 
    { 
        cout << real << " + i" << imag << endl; 
    } 

    // The global operator function is made friend of this class so 
    // that it can access private members 
    friend complex2 operator + (complex2 const &, complex2 const &);
};

complex2 operator + (complex2 const &c1, complex2 const &c2)
{
    complex2 res;
    res.real = c1.real + c2.real;
    res.imag = c1.imag + c2.imag;
    return res;
}

int main() 
{
    cout << "Operator overloading \n";
    complex2 c1(10, 5), c2(2, 3);
    complex2 c3 = c1 + c2;          // An example call to "operator+" 
    c3.print_complex_number(); 

    return 0;
}
