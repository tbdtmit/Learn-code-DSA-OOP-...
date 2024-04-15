
#include<iostream>
using namespace std;
class BixTeam
{
    int x, y;
    public:
    BixTeam(int xx)
    {
        x = ++xx;
    }
    void Display()
    {   cout << x << " ";
        cout<< --x  << " ";

    }
};
int main()
{
    BixTeam objBT(45);
    objBT.Display();
    BixTeam *p = &objBT;
    p->Display();
    *p = 27;
    objBT.Display();

    cout << sizeof(objBT);
    return 0;
}
