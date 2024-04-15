#include <iostream>
#include <cmath>
#include <string>
#include "test.cpp"
using namespace std;

void timm(int32_t n)
{
    int32_t i = 1;
    int32_t t = 0 ;

    while (n - t > 0)
    {
        
       i = ++i ;
        t = t + i;
        
        
        
        
       

    }
    cout << i-1 ;
    
}

void sortdown()
{
    int16_t a ;
    int16_t index;
    
    int32_t c ;
    int16_t t;
    
    cout << "nhap so luong so can sap xep: " << endl ;
    cin >> a ;
    int32_t b[a];
    cout << "nhap " << a << " so: " << endl ;
    for ( t=0;t < a;t++)
    {
        cin >> b[t] ;
    }
    for ( t =0;t < a;t++)
    {
    for (int16_t z = t;z < a;z++)
    {
        
        if (z==t)
        {
            c = b[z] ;

        }
        else if (z>t)
        {
            if(b[z] > c)
            {
                c = b[z];
                index = z ;
            }
        }
    }

   
    b[index] = b[t];
    b[t] = c ;
    cout << b[t] <<" " ;

    }
}
int rac(int8_t a, int b, int c)
{
    cout << sizeof a <<endl;
    
    //cout << a+b <<endl;
    return a+b+c;
}
int main()
{
    cout<< add(4,5) << endl;
    cout<< rac(33,5,229);
    return 0;
}




