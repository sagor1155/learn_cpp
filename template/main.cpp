/*
Templates in C++
----------------
A template is a simple and yet very powerful tool in C++. The simple idea is to pass data type as a parameter 
so that we don’t need to write the same code for different data types. For example, a software company may 
need sort() for different data types. Rather than writing and maintaining the multiple codes, we can write 
one sort() and pass data type as a parameter.

C++ adds two new keywords to support templates: ‘template’ and ‘typename’. 
The second keyword can always be replaced by keyword ‘class’.

How templates work?
-------------------
Templates are expanded at compiler time. This is like macros. 
The difference is, compiler does type checking before template expansion. 
The idea is simple, source code contains only function/class, but compiled 
code may contain multiple copies of same function/class.

REF: https://www.geeksforgeeks.org/templates-cpp/
*/

#include <iostream>
#include <vector>

using namespace std;

//example 1: function template
template <typename T>
T getmax(T x, T y)
{
    return ((x > y)? x : y);
}

//example 2
template <class T>
void bubbleSort(T arr[], int n)
{
    for(int i=0; i<(n-1); i++)
    {
        for(int k=0; k<(n-i-1); k++)
        {
            if(arr[k] > arr[k+1])
            {
                swap(arr[k], arr[k+1]);
            }
        }
    }
}

//example 3: Class Templates    

template<typename T>
class Array
{
private:
    T *ptr;
    int arrSize;
public:
    Array(T arg[], int size);
    void print();
    ~Array(){}
};

template<typename T>
Array<T>::Array(T arg[], int size)
{
    this->ptr = new T(size);
    this->arrSize = size;
    if(this->ptr){
        for(int i=0; i<this->arrSize; i++){
            this->ptr[i] = arg[i];
        }
    }
}

template<typename T>
void Array<T>::print()
{
    for(int i=0; i < this->arrSize; i++){
        cout << this->ptr[i] << " ";
    }
    cout << endl;
}


int main()
{
    cout << "templates in c++" << endl;
    //example 1
    cout << getmax<int>(3, 7) << endl;
    cout << getmax<float>(3.5, 7.6) << endl;
    cout << getmax<char>('g', 'e') << endl;

    //example 2
    int a[] = {10, 5, 3, 70, 50, 30, 40, 20, 80, 1}; 
    int n = sizeof(a) / sizeof(a[0]); 
    bubbleSort<int>(a, n);
    cout << "sorted array (ascending order) : "; 
    for (int i = 0; i < n; i++) 
        cout << a[i] << " "; 
    cout << endl; 

    //example 3
    int arr[5] = {1, 2, 3, 4, 5}; 
    Array<int> arrobj(arr, 5);
    arrobj.print();

    return 0;
}
