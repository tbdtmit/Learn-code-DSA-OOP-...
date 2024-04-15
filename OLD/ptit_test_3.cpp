#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
            //[Hàm, Lý Thuyết Số]. Bài 30. Chữ số cuối cùng lớn nhất
int snt[10000005] = {};

void sang_nt( int n)
{
    snt[0] = snt[1] = 1;
    for(int i=2;i*i<=n;i++)
    {
        if(snt[i] == 0)
        {
            for(int j = i;j*i<=n;j++)
            {
                snt[j*i] = 1;
            }
        }

    }
}

bool check_max_last_digit(int a)
{
    int max = a%10;
    while(a != 0)
    {
        a/=10;
        if(a%10 > max) return false;

    }
    return 1;
}

void prb_a()
{
    int n;cin >> n;
    sang_nt(n);
    int cnt = 0;
    for(int i =2;i<=n;i++)
    {
        if(snt[i] == 0 && check_max_last_digit(i))
        {
            cnt++;
            cout << i << " ";
        }

    }
    cout << endl;
    cout << cnt << endl;

}
            //[Hàm, Lý Thuyết Số]. Bài 30. Chữ số cuối cùng lớn nhất

            //[Sắp xếp - Tìm Kiếm]. Bài 31. Dragon

void dragon()
{
    ll s;ll n;
    cin >> n >> s;
    pair<ll,ll> pa[n];
    bool check = 1;
    for(int i =0;i<n;i++)
    {
        ll a,b;
        cin >> a>> b;
        pa[i] = {a,b};
    }
    sort(pa,pa+n);
    for(int i=0;i<n;i++)
    {
        if(s <= pa[i].first)
        {
                cout << "NO" << endl;
            check = 0;break;
            
        }

            s+= pa[i].second;
        
    }
    if(check) cout << "YES" << endl;

}
            //[Sắp xếp - Tìm Kiếm]. Bài 31. Dragon

            //Maximum path sum
void max_path_recursive(int a[][200], int mvh[], int c,int h, int sum, int &max, int n){
    if(c == n)
    {
        if(sum > max) max =sum;
        return;
    }
    else{
        for(int i= 0;i<3;i++)
        {
            int cc = c+1;
            int hh = h + mvh[i];
            if(hh >=1 && hh <=n && cc >=1 && cc<=n)
            {
                max_path_recursive(a,mvh,cc,hh,sum+a[hh][cc],max,n);
            }
        }
    }
}
void max_path()
{
    int n ;cin >> n;
    int a[200][200] = {};
    int mask[200][200] = {};
    int mvh[3] = {-1,0,1};
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            cin >> a[i][j];
            mask[i][j] = a[i][j];
        }
    }
    int max = 0;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int z =0;z<3;z++)
            {
                int c = i+1;
                int h = j + mvh[z];
                if(h>=1 && h<=n)
                {
                    if(mask[h][c] < a[h][c] + mask[j][i])
                    {
                        mask[h][c] = a[h][c] +  mask[j][i];
                    }
                }
            }
        }
    }
    // cout << endl << endl;
    // for(int i =1;i<= n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cout << mask[i][j] <<  " ";
    //     }
    //     cout << endl;
    // }
    //     cout << endl << endl;
    for(int i=1;i<=n;i++)
    {
        if(mask[i][n] > max) max = mask[i][n];
    }
    cout << max << endl;
}    

            //Maximum path sum

            //
string create_pass(string s){
    string tem = "";
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '/') continue;
        if(i == 3 && s[i] == '0') continue;
        if(i == 0 && s[i] == '0') continue;
        tem += s[i];
    }
    return tem;
}
string to_lower(string s)
{
    string tem = "";
    for(int i =0;i<s.length();i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            tem+= char(s[i] + 32);
        }
        else{
            tem += s[i];
        }
    }
    string ans ="";
    stringstream ss(tem);
    string t;
    while (ss>> t)
    {
        t[0] = char(t[0] -32);
        ans += t + " ";
    }
    
    return ans;
}
void create_email()
{
    int n;cin >>n;
    cin.ignore();
    multiset<string> ms;
    for(int i=1;i<=n;i++)
    {
        string s;
        getline(cin,s);
        stringstream ss(s);
        string tem;
        string tt ="";
        string tem1;
        string num;
        while (ss >> tem)
        {
            if(isdigit(tem[0])) {
                num = tem;break;
            }
            tem1 = tem;
            tt += tem1[0];
        }
        tt = tt.substr(0,tt.length()-1);
        tt = tem1 + tt;
        tt =  to_lower(tt);
        ms.insert(tt);
        int in = ms.count(tt);
        if(in>1)
        {
            tt = tt + to_string(in) + "@xyz.edu.vn";
        }
        else{
            tt = tt + "@xyz.edu.vn";
        }

        cout << tt << endl;
        cout << create_pass(num) << endl;

        
    }
}
            // 

            //
class SV{
    public:
    string lop;
    string dob;
    float gpa;
    string name;
    string id;

    static int cnt ;
    SV()
    {
        ++cnt;
    }
    SV(float a )
    {
        this->gpa = a;
    }

    bool operator < (SV sv){
        if(gpa != sv.gpa)
            return gpa > sv.gpa;
        return id < sv.id;
    }


};

string fix_dob(string s)
{
    string tem ="";
    string te ="";
    for(int i =0 ;i<s.length();i++)
    {
        tem += s[i];
        if(s[i] == '/' || i == s.length() -1 )
        {
            if(tem.length() == 2)
                tem = '0'+ tem;
            te += tem ;
            tem = "";
        }
        

    }
    return te;
}
int SV :: cnt = 0 ;
string create_id()
{
    string te = "SV0";
    if(SV :: cnt <10)
    {
        te += '0' + to_string(SV :: cnt);
    }
    else
    {
        te += to_string(SV :: cnt);
    }
    
    return te;

}

void list_sv()
{
    int n;cin>>n;
    vector<SV> st;
    for(int i=0;i<n;i++)
    {
        SV sv;
        cin.ignore();

        getline(cin,sv.name);
        cin >> sv.lop;
        cin >> sv.dob;
        cin >> sv.gpa;
        string idd = create_id();
        sv.id = idd;
        //cout << idd << endl;
        st.push_back(sv);

    }
    sort(st.begin(),st.end());
    for(auto i : st)
    {
        cout << i.id + " " + to_lower(i.name) + i.lop + " " + fix_dob(i.dob) << " " <<
         fixed << setprecision(2) << i.gpa << endl;
    }
}

            //

union A{
    int a;
    char b;
};
int main()
{
    // A z;
    // cout << &z << endl;
    // cout << &z.a << " " << &z.b << endl;
    // z.a =1089;
    // cout << z.b << endl;
    // char *aa  = &z.b;
    // cout << (int*)aa << endl;
    // z.b = 65;


    // float a =3.0;
    // cout <<  setprecision(2) << fixed << a;

    list_sv();


    return 0;
}