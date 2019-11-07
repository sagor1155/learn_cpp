/*
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
template <typename T>
class Array
{
    private:
        T *ptr; 
        int size;

    public:
        Array(T arr[], int s);
        void print(void);
};

template <typename T>
Array<T>::Array(T arr[], int s)
{
    ptr = new T[s];
    size = s;
    for(int i=0; i<s; i++)
    {
        ptr[i] = arr[i];
    }
}

template <typename T>
void Array<T>::print(void)
{
    for(int i=0; i<size; i++)
    {
        cout << ptr[i] << " ";
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
    bubbleSort(a, n);
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
