#include <iostream>
#include "oop_2.cpp"
using namespace std;




class B {

    public:
    static A a;
    string z;
    static bool check(string te)
    {
        return te == a.get_b();
    }

    bool check1(string te)
    {
        return te == a.get_b();
    }

};


A te("hello");
A B :: a = te;
int main()
{

    B b;
    B :: check("abc");
    for(int i =0;i<5;i++)
    {
        string str;cin >> str;
        B :: a.set_b(str);
        cout << b.check("hello") << endl;

    }


    return 0;
}