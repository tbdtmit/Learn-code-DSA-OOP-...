#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<math.h>
#include<algorithm>
#include<string>

#define ull unsigned long long
#define ll long long

using namespace std;

#define bit( a, b) (a & (1<<b))

unsigned int mask[(1<<20)+1][21] = {};
int cost[22][22] = {};

void bai_tap()
{
    int n,m;
    cin >> n >> m;
    vector<int> vt;
    for(int i=0;i<n;i++)
    {
        int te;
        cin >> te;
        vt.push_back(te);
    }
    sort(vt.begin(),vt.end());
    multiset<int> s;

    if(n > m)
    {
        int ans = INT32_MAX;
        for(int i = 1;i<m;i++)
        {
            s.insert(vt[i] - vt[i-1]);
        }
        auto en = s.end();
        --en;
        if(*en < ans) ans = *en;

        for(int i = m;i<n;i++)
        {
            s.erase(s.find(vt[i-m+1] - vt[i-m]));
            s.insert(vt[i] - vt[i-1]);
            en = s.end();
            --en;
            if(*en < ans ) ans = *en;
            cout << s.size() << " n > m" << endl;
        }
        cout << ans;
    }
    else{
        map<int,int> mp;
        for(int i = 1;i<n;i++)
        {
            mp[vt[i] - vt[i-1]]++;
        }
        if(mp.size() == 1)
        {
            cout << 0 ;return;
        }

        int i = m -n;
        while(i)
        {
            auto en = mp.end();
            --en;
            int key_mx = (*en).first;
            int num_mx = (*en).second;

            auto en2 = en--;en++;

            int devide = 2;
            while(key_mx/devide > (*en2).first && devide - 1 <= i && i - (devide)*num_mx >= 0)
            {
                devide++;
            }
            int du = key_mx%devide;
            key_mx /= devide;
            i-= (devide - 1)*num_mx;
            if(i>=0){
                mp.erase(en);
                for(int j = 0; j<du;j++)
                {
                    mp[key_mx+1] += num_mx;
                }
                for(int j =0;j< devide - du;j++)
                {
                    mp[key_mx] += num_mx;
                }
            }
            else break;


        }


            auto en = mp.end();
            --en;
            cout << (*en).first;

    }

}


void swap_games()
{
    int tc;cin >>tc;
    for(int ii=0;ii<tc;ii++)
    {
        set<int> s;
        int n;cin >>n;
        int st = 0;
        for(int i=0;i<n;i++)
        {
            int te;cin >> te;
            s.insert(te);
            if(i == 0) st = te;
        }

        st = st-1;
        if(s.find(st) != s.end())
        {
            cout << "Alice" << endl;
        }
        else{
            s.insert(st);
            if(s.find(st) == s.begin())
            {
                cout << "Bob" << endl;
            }
            else cout << "Alice" << endl;
        }
    }
}

int reverse_int(int x)
{
    ll te = 0;
    ll n = x;

    n = abs(n);
    while(n)
    {
        te = te*10 + n%10;
        n/=10;
    }
    if( te > INT32_MAX)
    cout << 0;
    else{
        if(x < 0) cout << -te;
        else cout << te;
    }
}

class Basic {
    public:
        int data = 5;
        string str = "";
        void func() const
        {
            data = 100;
        }
};

int main()
{
    Basic basic;
    Basic *basicptr = &basic;
    basicptr->data = 10;
    basicptr->str = "hello";
    cout << basicptr->data << endl;
    auto ptr2 = basicptr;
    ptr2->data = 15;
    cout << basicptr->data << endl;
    ptr2 = new Basic;
    return 0;
}