/*
Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, 
with their storage being handled automatically by the container. Vector elements are placed in contiguous storage so that 
they can be accessed and traversed using iterators. In vectors, data is inserted at the end. Inserting at the end takes 
differential time, as sometimes there may be a need of extending the array. Removing the last element takes only constant 
time because no resizing happens. Inserting and erasing at the beginning or in the middle is linear in time.

REF: https://www.geeksforgeeks.org/vector-in-cpp-stl/
*/

#include <iostream>
#include <vector>

using namespace std;


int main()
{
    cout << "vector in c++" << endl;
    vector<int> vec;
    
    /////////////////////////
    cout << "size of vector after init: " << vec.size() << endl;
    for(int i=0; i<5; i++){
        vec.push_back(i);
    }

    for (int i = 0; i < vec.size(); i++){
        cout << "vec[" << i << "] = " << vec[i] << endl;
    }
    cout << "size of vector after assigning: " << vec.size() << endl;

    /* iterator */
    vector<int>::iterator it = vec.begin();
    cout << "value of iterator: ";
    while(it != vec.end()){
        cout << *it << " ";
        it++;
    }

    /* constant reverse iterator iterator */
    vector<int>::const_reverse_iterator cit = vec.crbegin();
    cout << "\nvalue of constant reverse iterator: ";
    while(cit != vec.crend()){
        cout << *cit << " ";
        cit++;
    }

    /////////////////////////
    cout << "\nOutput of begin and end: "; 
    for (auto i = vec.crbegin(); i != vec.crend(); i++) {
        cout << *i << " "; 
    }
    cout << endl;
    /////////////////////////

    cout << "vector size: " << vec.size() << endl;
    cout << "vector max size: " << vec.max_size() << endl;
    cout << "vector capacity: " << vec.capacity() << endl;

    vec.resize(4);
    cout << "vector size after resize: " << vec.size() << endl;

    if (vec.empty())
        cout << "vector is empty!" << endl;
    else
        cout << "vector is not empty." << endl;
    
    vec.shrink_to_fit();

    cout << "Output after resize and shrink: "; 
    for(vector<int>::iterator i = vec.begin(); i!=vec.end(); i++)
    {
        cout << *i << " "; 
    }
    cout << endl;
    /////////////////////////

    cout << "reference operator vec[2] = " << vec[2]  << endl;  //not exception safe 
    cout << "vec.at(3)   = " << vec.at(3) << endl;              //vector.at(index) is exception safe but vector[index] is not  
    cout << "vec.front() = " << vec.front() << endl;
    cout << "vec.back()  = " << vec.back() << endl;

    int* ptr = vec.data();
    cout << "2nd element is: " << *(ptr+1) << endl;
    /////////////////////////

    // Assign vector 
    vector<int> v; 

    // fill the array with 10 five times 
    v.assign(5, 10); 
    cout << "The vector elements are: "; 
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " "; 

    // inserts 15 to the last position 
    v.push_back(15); 
    int n = v.size(); 
    cout << "\nThe last element is: " << v[n - 1]; 
    
    // removes last element 
    v.pop_back(); 
  
    // prints the vector 
    cout << "\nThe vector elements are: "; 
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " ";     
    
    v.insert(v.cbegin(), 4);    // inserts 4 at the beginning
    v.erase(v.begin());         // removes the first element 
    cout << "\nThe first element is: " << v[0]; 

    v.emplace(v.cbegin(), 3);   // inserts at the beginning 
    cout << "\nThe first element is: " << v[0]; 

    v.emplace_back(9);          // Inserts 9 at the end 
    cout << "\nThe last element is: " << v[v.size() - 1];    
    
    // prints the vector    
    cout << "\nThe vector elements are: "; 
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " ";     

    // erases the vector 
    v.clear(); 
    cout << "\nVector size after erase(): " << v.size(); 

    // two vector to perform swap 
    vector<int> v1, v2; 
    v1.push_back(1); 
    v1.push_back(2); 
    v2.push_back(3); 
    v2.push_back(4); 
  
    cout << "\n\nVector 1: "; 
    for (int i = 0; i < v1.size(); i++) 
        cout << v1[i] << " "; 
  
    cout << "\nVector 2: "; 
    for (int i = 0; i < v2.size(); i++) 
        cout << v2[i] << " "; 
  
    // Swaps v1 and v2 
    v1.swap(v2); 
  
    cout << "\nAfter Swap \nVector 1: "; 
    for (int i = 0; i < v1.size(); i++) 
        cout << v1[i] << " "; 
  
    cout << "\nVector 2: "; 
    for (int i = 0; i < v2.size(); i++) 
        cout << v2[i] << " "; 

    cout << endl;
    return 0;
}

/*
Modifiers:
----------
assign()    – It assigns new value to the vector elements by replacing old ones
push_back() – It push the elements into a vector from the back
pop_back()  – It is used to pop or remove elements from a vector from the back.
insert()    – It inserts new elements before the element at the specified position
erase()     – It is used to remove elements from a container from the specified position or range.
swap()      – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
clear()     – It is used to remove all the elements of the vector container
emplace()   – It extends the container by inserting new element at position
emplace_back() – It is used to insert a new element into the vector container, the new element is added to the end of the vector
*/

/*
Element access:
---------------
reference operator [g] – Returns a reference to the element at position ‘g’ in the vector
at(g)   – Returns a reference to the element at position ‘g’ in the vector
front() – Returns a reference to the first element in the vector
back()  – Returns a reference to the last element in the vector
data()  – Returns a direct pointer to the memory array used internally by the vector to store its owned elements.
*/

/*
Capacity
--------
size()     – Returns the number of elements in the vector.
max_size() – Returns the maximum number of elements that the vector can hold.
capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
resize(n)  – Resizes the container so that it contains ‘n’ elements.
empty()    – Returns whether the container is empty.
shrink_to_fit() – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
reserve()       – Requests that the vector capacity be at least enough to contain n elements.
*/

/*
Iterators
---------
begin()     – Returns an iterator pointing to the first element in the vector
end()       – Returns an iterator pointing to the theoretical element that follows the last element in the vector
rbegin()    – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
rend()      – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
cbegin()    – Returns a constant iterator pointing to the first element in the vector.
cend()      – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
crbegin()   – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
crend()     – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
*/
