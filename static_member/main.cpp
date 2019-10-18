#include <iostream>

using namespace std;

class box
{
    public:
    static int object_count;

    box()
    {
        object_count++;
    }

    static int get_object_count(void)
    {
        return object_count;
    }
};

int box::object_count = 0;

int main()
{
    cout << "static members of class" << endl;    
    box b1;
    box b2;
    box b3;
    cout << "total object instantiated: " << box::get_object_count() << endl;

    return 0;
}