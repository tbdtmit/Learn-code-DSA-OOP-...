#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class A{
    int a;
    string b;
    public:
    A(string te) : b(te){}
    int get_a()
    {
        return a;
    }
    string get_b()
    {
        return b;
    }
    void set_b(string te)
    {
        b = te;
    }

};