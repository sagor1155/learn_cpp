
#include <iostream>

using namespace std;

class myclass
{
    public:
    myclass(int *intptr)
    {
        var = intptr;
        cout << "constructor invoked \n";
    }
    ~myclass()
    {
        cout << "destructor invoked \n";
    }

    int *var;
    void execute(void);
    // {
    //     cout << "Execute Method: " << *var << "\n";   
    // }

};
