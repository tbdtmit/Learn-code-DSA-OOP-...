#include<iostream>
//#include<string.h>
using namespace std ;
bool is_prime(int a)
{   
    if(a>2)
    {  
        for(int i=2;i*i<=a;i++)
        {
            if(a%i == 0)
            return 0;
        }
        return 1;
    }
    else if(a==2)
    return 1;
    else
    return 0;
}
void ex1()
{
    int arr[100];
    int i =0;
    int status =1;
    while(status)
    {  
        int a;
        cin >> a;
        if(a != 42)
        {   
            arr[i] = a;
            i++;
        }
        else
        for(int j =0;j<i;j++)
        {   
            cout << arr[j] << endl;
            status =0;
        }
    }

}
void palin()
{   
    int tcc;
    cin >>tcc;
    for(int tc =0; tc<tcc;tc++)
    {
        int m;
        cin >>m ;
        m++;
        
        while(1)
        {
        string n = to_string(m);
        int l = n.length();
        if( l %2 ==0)
        {
            int j=0;
            while(n[l/2-1-j] == n[l/2+j] && l/2+j < l)
            {   
                j++;
            }
            if(2*j == l)
            {
                cout << n << endl;
                break;
            }
            else m++;

        }
        else
        {
            int j=1;
            while(n[l/2-j] == n[l/2+j] && l/2+j < l)
            {   
                j++;
            }
            if(2*j -1== l)
            {
                cout << n << endl;
                break;
            }
            else m++;
        }

        }


    }
}



int main()
{ 
    string str;
    cin >> str;
    string s[100];
    char dau[100];
    int so[100];
    int fi = 0;
    int la = 0;
    int index =0;
    
    for(int i =0; i<str.length();i++)
    {   
        if(str[i] == '+' || str[i] == '-' || i == str.length()-1)
        {   la = i;
            if(i == str.length()-1)
                la = i+1;
            for(int j =fi;j<la;j++)
            {   
                s[index] += str[j];
            }
            so[index] = atoi((s[index].c_str()));
            if(str[i] == '+')
                dau[index] = '+';
            else if(str[i] == '-')
                dau[index] = '-';
            index++;
            fi = i+1;
        }

    }

   int ans = so[0];
   for(int i =0;i<index-1;i++)
   {    
    if(dau[i] == '+')
        ans += so[i+1];
    else 
        ans -= so[i+1];
   }

   cout << ans <<endl;
    return 0;
}
