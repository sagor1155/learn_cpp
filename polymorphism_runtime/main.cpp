#include <iostream>

using namespace std;

class shape
{
    protected:
    int height, width;

    public:
    shape(int a=0, int b=0)
    {
        height = a; 
        width = b;
    }

    virtual int get_area(void)
    {
        cout << "within shape class" << "\n";
        return (height * width);
    }
};

class rectangle: public shape
{
    public:
    rectangle(int a=0, int b=0):shape(a, b){}

    int get_area(void)
    {
        cout << "within rectangle class" << "\n";
        return (height * width);
    }
};

class triangle: public shape
{
    public:
    triangle(int a=0, int b=0):shape(a, b){}

    int get_area(void)
    {
        cout << "within triangle class" << "\n";
        return (height * width);
    }
};

int main() 
{
    cout << "Runtime Polymorphism \n";
    shape *shape_obj = new shape(10, 2);
    rectangle rect(10, 7);
    triangle  tri(10, 5);

    int area = shape_obj->get_area();
    cout << "area: " << area << "\n";

    shape_obj = &rect;
    area = shape_obj->get_area();
    cout << "area: " << area << "\n";

    shape_obj = &tri;
    area = shape_obj->get_area();
    cout << "area: " << area << "\n";       

    return 0;
}
