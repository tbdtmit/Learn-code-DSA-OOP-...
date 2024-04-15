#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

            //[C++ Final Test 1]. Problem A. Số đẹp
void so_dep()
{
    int n;cin >> n;
    for(int ii =0;ii<n;ii++)
    {
        ll a;cin >> a;
        if( a < 0) a = -a;
        string s = to_string(a);
        int check = 0;
        for(int i=0;i<s.length();i++)
        {
            if( (s[i] - '0')% 2 == 0 && i%2 == 0)  //luu y
                {cout << "NO" <<endl;check =1;break;}
            else if((s[i] - '0')% 2 == 1 && i%2 == 1)  // luu y
                {cout << "NO" << endl;check =1;break;}
        }
        if(check==0) cout << "YES" << endl;

    }
}
            //[C++ Final Test 1]. Problem A. Số đẹp

            //[C++ Final Test 1]. Problem B. Truy vấn trên mảng
void tvtm()
{
    int n;
    cin >> n;
    int a[100005];
    multiset<int> s;
    for(int i=0;i<n;i++)
    {cin >> a[i];s.insert(a[i]);}
    int q;cin >> q;
    for(int ii =0;ii<q;ii++)
    {
        int a, b;
        cin >> a >> b;
        switch (a)
        {
        case 1:
            s.insert(b);
            break;
        case 2:
            if(s.count(b) != 0)   // luu y
            s.erase(s.find(b));
            break;
        case 3:
            if(s.count(b)) cout << "YES" <<endl;
            else cout << "NO" << endl;
            break;    
        default:
            break;
        }
    }
}
            //[C++ Final Test 1]. Problem B. Truy vấn trên mảng

            //[C++ Final Test 1]. Problem C. Flood fill
void flood_fill()
{
    int h,c;
    cin >> h >> c;
    int a[100][100] = {1000};
    for(int i=0;i<h;i++)
    {
        for(int j =0;j<c;j++)
        {
            cin >> a[i][j];
        }
    }
    map<int,multiset<int>> mp;
    int move_h[8] = {-1,-1,-1,0,1,1,1,0};
    int move_c[8] = {-1,0,1,1,1,0,-1,-1};
    for(int i=0;i<h;i++)
    {
        for(int j =0;j<c;j++)
        {
            if(a[i][j] != 1000)
            {
                queue<pair<int,int>> q;
                q.push({i,j});
                int x = a[i][j];
                int cnt = 0;
                while(q.empty() == false)
                {
                    int sz = q.size();
                    for(int ii =0;ii<sz;ii++)
                    {
                        pair<int,int> p = q.front();
                        q.pop();
                        if(a[p.first][p.second] == x) cnt++;  //luu y
                        a[p.first][p.second] = 1000;
                        for(int iii =0;iii<8;iii++)
                        {
                            if(a[p.first + move_h[iii]][p.second + move_c[iii]] == x
                                &&p.first + move_h[iii] >= 0 && p.first + move_h[iii] <=h-1
                                &&  p.second + move_c[iii] >=0 && p.second + move_c[iii] <=c-1 )
                                {
                                    q.push({p.first + move_h[iii],p.second + move_c[iii]});
                                }
                        }
                    }

                }
                mp[x].insert(cnt);

            }
        }
    }


    for(auto i:mp)
    {
        cout << i.first << " : ";
        for(auto j: i.second)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    
}
            //[C++ Final Test 1]. Problem C. Flood fill

            //[C++ Final Test 1]. Problem D. Xử lý gian lận 
void xlgl()
{
    int n;cin>> n;
    map<string, string> mp1;
    for(int i=0;i<n;i++)
    {
        string a,b;
        cin >> a;     // luu y
        cin.ignore();  // luu y
        getline(cin,b);  //luu y
        mp1[a] = b;
    }
    int m;cin >>m;
    map<string,set<string>> mp;
    for(int i =0;i<m;i++)
    {
        string a,b,c,d;
        cin >> a>> b>> c >>d;
        mp[c].insert(d);

    }
    for(auto i : mp1)
    {
        cout <<   i.first << " " << i.second << " ";
        if(mp[i.first].size() !=1)
            cout << "FAIL" << endl;
        else
        {
            if(mp[i.first].count("code.ptit.edu.vn") == 1)
                cout << "OK" << endl;
            else
                cout << "FAIL" <<endl;
        } 
    }
}
            //[C++ Final Test 1]. Problem D. Xử lý gian lận 

            //[C++ Final Test 1]. Problem E. Quản lý kho hàng 
struct mh{
    string ten, hang, dv,nhap,xuat;
    string ma;
    int ln()
    {
        return (stoi(xuat) - stoi(nhap));
    }
    string tao_ma()
    {
        string s = "";
        stringstream ss(ten);
        string temp;
        while(ss >> temp)
        {
            s += toupper(temp[0]);
        }
        return s;
    }
};

void qlkh()
{
    int n;cin >>n;

    map<string,int> mp1;  // mang luu ma(raw) cung voi so thu tu, de ghep lai thanh ma chuan
    map<string,mh> mp;    // mang luu ma cung voi bien theo cau truc mh de truy suat mat hang theo ma
    map<int,set<string>> mpp;  // mang sap xep theo loi nhuan, sau do la sap xep theo ma sp

    for(int ii =0;ii<n;ii++)
    {
        cin.ignore();  // luu y
        mh sp;
        string a;
        getline(cin,a);
        sp.ten = a;
        getline(cin,a);
        sp.hang = a;
        getline(cin,a);
        sp.dv = a;
        cin >> a;
        sp.xuat = a;
        cin >> a;
        sp.nhap = a;
        mp1[sp.tao_ma()]++;
        string maa = sp.tao_ma();
        string so = to_string(mp1[sp.tao_ma()]);
        for(int i=0;i<4-so.length();i++)
        {
            maa += '0';
        }
        maa+=so;
        sp.ma = maa;
        mpp[sp.ln()].insert(sp.ma);
        mp[sp.ma] = sp;

        


    }

    for(auto i : mpp)
    {
        for(auto j:i.second)
        {
            cout << j <<" ";
            cout << mp[j].ten << " "<< mp[j].hang<<" " << mp[j].dv 
            << " "<< mp[j].xuat << " "<< mp[j].nhap <<endl;

        }
    }
}
            //[C++ Final Test 1]. Problem E. Quản lý kho hàng 


int main()
{
    qlkh();
}