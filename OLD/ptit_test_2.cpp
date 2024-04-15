#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long


            //
int snt[300005] = {};
void sang_nt(int n)
{
    for(int i= 2 ; i*i<=n;i++)
    {
        if(snt[i] == 0)
        {
            for(int j =i;j*i <= n;j++)
            {
                snt[i*j] = 1;
            }
        }
    }
}
void prba()
{
    ull n;
    cin >> n;

    sang_nt(300000);
    for(int i=2;i*i*i<=n;i++)
    {
        if(snt[i] == 0 && n%i == 0 && n % (i*i*i) == 0)
        {
            cout << "YES" << endl;return;
        }
    }
    cout << "NO" << endl;
}
            //

            //
void prbb()
{
    int n;
    cin >> n;
    set<int> s;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int t;cin >> t;
        a.push_back(t);
        s.insert(t);

    }

    for(int i=0;i<n;i++)
    {
        if(s.find(a[i]) == s.begin())
        {
            cout << "#" <<" ";
        }
        else
        {
            auto j = s.find(a[i]);
            j--;
            cout << *j << " ";
        }
        //cout <<*(s.begin());
    }


}
            //

            //
ull map_maze[1005][1005] = {0};
ull map_maze_h[1005][1005] ={0};
ull map_maze_c[1005][1005] ={0};
ull cal(int x,int y,int z, int xx)
{
    ull sum =0;
    if(xx == 1)
    {
        sum = map_maze_h[x][z] - map_maze_h[x][y-1];
    }
    else{
        sum = map_maze_c[z][x] - map_maze_c[y-1][x];
    }
    return sum;
}


void prbc()
{   
    int n,m;
    cin >>n>>m;
    for(int i =1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> map_maze[i][j];
            map_maze_c[i][j] = map_maze[i][j];
            map_maze_h[i][j] = map_maze[i][j];
        }
    }

    for(int i =1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            map_maze_h[i][j] += map_maze_h[i][j-1];

        }
    }

    for(int i =1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            map_maze_c[j][i] += map_maze_c[j-1][i];
        }
    }

    int q;cin >> q;
    for(int i =0;i<q;i++)
    {
        int xx;
        cin >>xx;
        int x,y,z;
        cin>>x>>y>>z;
        cout << cal(x,y,z,xx) << endl;
    }
}
            //

            //
struct db{
    int diem = 0 ; int hieu_so = 0;
    string ten;

    bool operator < (db a)
    {
        if(diem != a.diem)
            return diem > a.diem;
        if(hieu_so != a.hieu_so)
            return hieu_so > a.hieu_so;
        return ten < a.ten;
    }

};

pair<pair<string,int>,pair<string,int>> p_tich(string s)
{
    pair<pair<string,int>,pair<string,int>> ans;
    stringstream ss(s);
    string tem;
    int check = 0;
    string str = "";
    while(ss >> tem)
    {
        if(tem == "-") continue;
        if(tem[0] == '[' || isdigit(tem[0]))
        {
            check++;
        }
        if(check == 1 || check == 4)
        {   str+=tem;
            if(tem[tem.length()-1] != ']')
            while(ss >> tem)
            {   str += tem;
                if(tem[tem.length() - 1] == ']')
                    break;
            }
            str = str.substr(1,str.length()-2);
            if(check == 1)
            {
                ans.first.first =str;
                str = "";
            }
            else{
                ans.second.first = str;
                str = "";
            }

        }
        else{
            //cout << tem << endl;
            if(check == 2) ans.first.second = stoi(tem);
            else ans.second.second = stoi(tem);
        }
    }
    return ans;
}
void gbd()
{
    map<string,db> mp;
    string s;
    do
    {

        getline(cin,s);
        if(s == "") break;
        auto tem = p_tich(s);
        db d1;
        db d2;
        d1.ten = tem.first.first;
        d2.ten = tem.second.first;
        int s1 = tem.first.second;
        int s2 = tem.second.second;
        mp[d1.ten].hieu_so += (s1 - s2);
        mp[d2.ten].hieu_so += (s2 - s1);
        if(s1 == s2)
        {
            mp[d1.ten].diem++;
            mp[d2.ten].diem++;
        }
        else if(s1 > s2)
        {
            mp[d1.ten].diem += 3;
        }
        else{
            mp[d2.ten].diem += 3;
        }


    } while (s != "");
    vector<db> vt;
    for(auto i : mp)
    {
        db a;
        a.diem = i.second.diem;
        a.hieu_so = i.second.hieu_so;
        a.ten = i.first;
        vt.push_back(a);
    }
    sort(vt.begin(),vt.end());
    for(auto i : vt)
    {
        cout << i.ten << " " << i.diem << " " << i.hieu_so<< endl;
    }


}


    
    

            //

            //
struct CT{
    string id;
    string cap;
    string ten;
    string dob;
    int cong;
    int ba_salary;
    int phu_cap;
    int thuong ;
    int luong;
    bool operator  < ( CT ct)
    {
        if(ct.luong != luong)
            return luong > ct.luong;
        return id < ct.id;
    }

};

string create_grade(string id)
{
    string tem = "";
    for(int i=0;i<id.length();i++)
    {
        if(id[i] == '-')break;
        tem += id[i];

    }
    return tem;
}
int create_phu_cap(string grade)
{
    if(grade == "GD") return 2000000;
    else if(grade == "PGD") return  1000000;
    else if(grade == "TP" ) return 500000;
    else return 200000;
}
int create_thuong(CT ct)
{
    //cout << "cong  ============= " << ct.cong << " " << ct.ba_salary << endl;
    if(ct.cong >= 27) return 2 * ct.ba_salary* ct.cong / 10;
    else if(ct.cong >= 25) return  ct.ba_salary * ct.cong / 10;
    else  return 0;
}

void create_luong(CT &ct)
{
    ct.luong = ct.cong * ct.ba_salary + ct.phu_cap + ct.thuong;
}

string fix_grade(string grade)
{
    if(grade == "TP") return "Truong phong";
    else if(grade == "PGD") return "Pho giam doc";
    else if(grade == "GD") return "Giam doc";
    else return "Nhan vien";
}

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
void cong_ty()
{
    int n;cin >> n;
    vector<CT> vt;
    for(int i =0;i<n;i++)
    {
        CT ct;
        cin >> ct.id;
        ct.cap = create_grade(ct.id);
        cin.ignore();
        getline(cin,ct.ten);
        cin >> ct.dob;
        cin >> ct.cong;
        cin >> ct.ba_salary;
        ct.phu_cap = create_phu_cap(ct.cap);
        ct.thuong =  create_thuong(ct);
        //cout << "                                                     "<<ct.cap << " " << ct.thuong << endl;
        create_luong(ct);

        vt.push_back(ct);
    }
    sort(vt.begin(),vt.end());
    for(auto i : vt)
    {
        cout << i.id << " " << i.ten << " " << fix_grade(i.cap) << " " << fix_dob(i.dob) << 
        " " << i.cong << " " << i.ba_salary << " "<<i.luong << endl;
    }
}
            //
int main()
{
    
    cong_ty();
    // auto a = p_tich("[South Korea] 6 - 6 [Netherlands]");\
    // cout << a.first.first << " " << a.first.second << " " << a.second.first << " " << a.second.second;

    // stringstream ss(a);
    // string te;
    // string str = "";
    // while(ss >> te)
    // {
    //     if(te[0] == '[')
    //     {
    //         str += te;
    //         if(te[te.length()- 1] != ']')
    //         while(ss >> te)
    //         {   
    //             str+= te;
    //             if(te[te.length()- 1] == ']')break;
    //         }
    //     }
    //     cout << str << " ";
    //     str = "";
    // }
    
    return 0;
}