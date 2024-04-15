#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<math.h>
#include<algorithm>
#include<string>
#include<unordered_map>

#define ull unsigned long long
#define ll long long

using namespace std;

bool binary_search(ll begin, ll end, vector<ll> &v, ll target)
{
    ll m = (begin + end)/2;   
    if(begin < end)
    {
        if(v[m] == target)
        {
            return true;
        }
        else if(v[m] > target)
        {
            binary_search(begin,m-1,v,target);
        }
        else{
            binary_search(m+1,end,v,target);
        }
    }
    else
        false;
    

}

void gameWithMultiset()
{
    vector<ll> v;
    set<ll> s;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        ll a,b;
        cin >> a >> b;
        if(a == 1)
        {
            v.push_back(b);
            auto sz = s.size();
            if(sz > 1)
            {
                auto be = (s.begin());
                for(auto j=0; j++; j < sz)
                {
                    s.insert(b + *be);
                    be++;
                }
            }
            else
                s.insert(b);

        }
    }
}
int main()
{

}