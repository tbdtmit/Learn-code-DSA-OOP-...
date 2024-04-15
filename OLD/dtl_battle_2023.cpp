#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<math.h>
#include<algorithm>
#include<string>
#include <unordered_map> 


#define ull unsigned long long
#define ll long long



using namespace std;
ll cnt = 0;
void pt(ll n, map<ll,ll> &m)
{
    for(ll i = 2;i*i <=n;i++)
    {
        cnt++;
        while(n%i == 0 && n > 1)
        {
            m[i]++;
            n/=i;
            cnt++;
        }
        if(n == 1) return;
    }
    if(n != 1)
    {
        m[n]++;
    }
}


bool nt(ll n)
{
    for(ll i = 2;i*i <=n;i++)
    {
        cnt++;
        if(n%i == 0)
        {
            return false;
        }
    }  
    return n > 1;  
}

bool le(ll n)
{
    for(ll i = 3;i*i <=n;i+=2)
    {
        cnt++;
        if(n % i == 0 )
        {
            return true;
        }
    }
    return false;
}
void bai1()
{
    ll tc;cin >> tc;
    for(ll ii =0;ii<tc;ii++)
    {
        ll n;cin >> n;
        ll n1 = abs(n);

        bool check = 0;
        if(n == 1 || n == -1 || n == 0)
            cout << "Piccolo" << endl;
        else{
            if(nt(n1))
            {
                cout << "Majin Buu" << endl;
                continue;
            }
            map<ll,ll> m;
            pt(n1,m);
            auto mi = m.begin();
            if(m.size() == 1 && (*mi).second == 1)
            {
                cout << "Majin Buu" << endl;
                continue;
            }
            else if(m.size() == 1 && (*mi).second > 1)
            {
                if(n > 0)
                {
                cout << "Piccolo" << endl;
                continue;
                }
                else{
                    if(le((*mi).second) || (*mi).second % 2 == 1|| (*mi).second == 6)
                    {
                    cout << "Piccolo" << endl;
                    continue;
                    }
                    else
                    {
                        cout << "Majin Buu" << endl;
                        continue;
                    }
                }

            }
            map<ll,ll> m1;

            for(auto x : m)
            {
                m1[x.second] = x.first;
                cnt++;
            }
             mi = m1.begin();
            auto min = (*mi).first;
            check = 0;
            auto en = m1.end();en--;
            for(auto x : m1)
            {
                cnt++;
                auto fi = x.first;
                if(fi % min != 0)
                {
                    cout << "Majin Buu" << endl;
                    break;
                }
                if(x == *en)
                {check = 1;}



            }
            if(check)
            {
                if(n > 0)
                {
                    cout << "Piccolo" << endl;

                }
                else{
                    if(le((*mi).second) || (*mi).second % 2 == 1 || (*mi).second == 6)
                    {
                        cout << "Piccolo" << endl;
                    }
                    else{
                        cout << "Majin Buu" << endl;
                    }
                }
            }

            }
    }
}


int snt[1000005] = {};

void sang_snt()
{
    snt[0] = snt[1] = 1;
    for(int i = 2;i*i<1000005;i++)
    {
        if(snt[i] == false)
        {
            for(int j = i;j*i<1000005;j++)
            {
                snt[i*j] = 1;
            }
        }
    }
}

void bai2()
{
    sang_snt();
    int tc;cin >> tc;
    for(int ii=0;ii<tc;ii++)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int st,en;
        int mi1,mi2;
        if(x1 < y1) 
        {
            st = x1;
            mi1 = y1;
        }
        else 
        {
            st = y1;
            mi1 = x1;
        }
        if(x2 < y2) 
        {
            en = y2;
            mi2 = x2;
        }
        else 
        {
            en = x2;
            mi2 = y2;
        }

        if(mi1 > mi2) 
        {
            int te = mi1;
            mi1 = mi2;
            mi2 = te;
        }
        int x = 0;
        int y = 0;
        int s = 0;
        int x11 = 0;
        int y11 = 0;
        if(x1 == 1 || y1 == 1) st = 1;
        unordered_map<long,int> m;
        for(int i = st;i<=en;i++)
        {
            if(snt[i] == 0)
            {
                if(i >= x1 && i <= x2) x++;
                if(i >= y1 && i <= y2) y++;
                if(i >= mi1 && i <= mi2) s++;
                if(x1 == 1 && i <= y2)
                {
                    x11++;
                }
                if(y1 == 1 && i <= x2)
                {
                    y11++;
                }
            }
        }

        if(x1 == 1)
        cout << (ll)x * y - (ll)s + x11 << endl;
        else if(y1 == 1)
        cout << (ll)x * y - (ll)s + y11 << endl;
        else if(x1 == 1 &&  y1 == 1)
        {
            cout << (ll)x * y - (ll)s + y11 + x11 << endl;
        }
        else{
            cout << (ll)x * y - (ll)s  << endl;
        }
    }
}
int main()
{
    bai2();
    return 0;
}