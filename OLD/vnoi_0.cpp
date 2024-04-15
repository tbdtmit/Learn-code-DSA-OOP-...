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

void tach_tu_try(string &s, int l,string &ans, int id
                    , string te, bool &check
                    , unordered_map<string,int> &um)// te = s[0], id = 0
{
    if(check) return;
    if(id == l)
    {
        ans = te;
        check = 1;
        return;
    }
    else{
        string res = "";
        for(int i =id;i<l;i++)
        {
            res += s[i];
            if(um[res] != 0)
            {
                tach_tu_try(s,l,ans,i+1,te + res + " ",check,um);
            }
        }



        
    }
}
void tach_tu()
{
    int n; cin >> n;
    unordered_map<string,int> um;
    for(int i=0;i<n;i++)
    {
        string te;cin >> te;
        um[te]++;
    }
    int q; cin >> q;
    for(int i =0;i<q;i++)
    {
        string s;
        cin >> s;
        int l = s.length();
        string ans = "";
        bool check = 0;
        tach_tu_try(s,l,ans,0,"",check,um);
        if(check)
            cout << ans << endl;
        else   
            cout << -1 << endl;


    }
}
int main()
{
    tach_tu();
    return 0;
}