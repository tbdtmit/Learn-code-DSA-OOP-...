#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

            // Prime 2
bool snt[1000005] = {};
int ssnt[1000005] = {};
void sang_nt(int n)
{
    snt[0] = snt[1] = 1;
    for(int i=2;i*i<=n;i++)
    {
        if(snt[i] == 0)
        {
            for(int j =i;j*i <= n;j++)
            {
                snt[i*j] = 1;
            }
        }
    }
    int cnt = 0;
    for(int i =0;i<=n;i++)
    {
        if(snt[i] == 0)
        {
            ssnt[i] = ++cnt;
        }
        else{
            ssnt[i] = cnt;
        }
    }
}
void prime_2()
{
    int tc; cin >> tc;
    sang_nt(1000000);
    for(int ii =0;ii<tc;ii++)
    {
        int cnt = 0;
        int a,b;
        cin >> a >> b;
        if(snt[a] == 0)
        cnt = ssnt[b] - ssnt[a] +1;
        else
        cnt = ssnt[b] - ssnt[a];
        cout << cnt << endl;

    }
}
            // Prime 2

            //
bool is_prime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i == 0) return false;
    }
    return n > 1;
}

void matrix_prime()
{
    int n;cin >> n;
    int a[300][300] = {};
    set<int> s;
    for(int i =1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> a[i][j];
            if(i == j) s.insert(a[i][j]);
            if(i +j == n+1) s.insert(a[i][j]);
        }
    }
    int cnt = 0;
    for(auto i : s)
    {
        if(is_prime(i)) cnt ++ ;
    }
    cout << cnt << endl;
}
            //

            //
string to_lower(string s)
{
    string tem = "";
    for(int i =0;i<s.length();i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            tem += char( s[i]  + 32);
        }
        else 
            tem += s[i];
    }
    return tem;
}
void unique_str()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);

    stringstream aa(a);
    string ai;
    set<string> s;
    while(aa >> ai)
    {
        string bi;
        stringstream bb(b);
        int check = 0;
        while(bb >> bi)
        {
            if(to_lower(ai) == to_lower(bi)) {
                check = 1;break;
            }
        }
        if(check == 0)
        {
            s.insert(to_lower(ai));
        }
    }
    for(auto i : s) 
    cout << i << " ";
    cout << endl;

}
            //

            //
struct net{
    string user;
    string pass;
    string name;
    string in;
    string out;
    int h_play;
    int m_play;
    int timee;
    bool operator < (net n)
    {
        if(timee != n.timee)
            return timee > n.timee;
        return user < n.user;
    }
};

void create_time_play(net &n)
{
    int inn = stoi(n.in.substr(0,2)) * 60 + stoi(n.in.substr(3,2));
    int outt = stoi(n.out.substr(0,2)) * 60 + stoi(n.out.substr(3,2));
    int time = outt - inn;
    n.timee = time;
    n.h_play = time/60;
    n.m_play = time%60;
}

void net_service()
{
    int n;cin >> n;
    vector<net> vt;
    for(int i=0;i<n;i++)
    {
        net ne;
        cin >> ne.user;
        cin >> ne.pass;
        cin.ignore();
        getline(cin,ne.name);
        cin >> ne.in;
        cin >> ne.out;
        create_time_play(ne);
        vt.push_back(ne);
    }
    sort(vt.begin(),vt.end());
    for(auto i : vt)
    {
        cout << i.user << " " << i.pass << " " << i.name << " "<< i.h_play <<" gio "
        << i.m_play << " phut " << endl;
    }

}
            //

            //
int bin_search(int l, int r, int val, vector<int> &arr)
{
    while(l<r)
    {
        int m = (l+r)/2;
        if(arr[m] <= val) l = m+1;
        else r = m;
    }
    return r;
}
void bigger_k()
{
    int n,k;
    cin >> n >> k;
    vector<int> vt;
    for(int i =1;i<=n;i++)
    {
        int te;
        cin >> te;
        vt.push_back(te);
    }
    sort(vt.begin(), vt.end());

    ull ans =0;
    for(int i=0;i<n-1;i++)
    {

        int te = bin_search(i+1,n-1,k-vt[i],vt);
        //cout << "te = " << te << endl;
        if(vt[te] + vt[i] > k)
        ans += (ull)n - te ;
        
    }
    cout << ans << endl;
}
            //
int main()
{
    bigger_k();
    return 0;
}