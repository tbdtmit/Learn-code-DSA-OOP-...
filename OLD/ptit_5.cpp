#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

            //CHUYỂN DANH SÁCH KỀ SANG MA TRẬN KỀ
int mmap[1005][1005];  
void to_matrix()
{
    int n;cin >> n;
    cin.ignore();
    for(int i =1;i<=n;i++)
    {
        string s;
        getline(cin,s);
        stringstream ss(s);
        string temp;
        while(ss >> temp)
        {
            int t = stoi(temp); 
            mmap[i][t] = 1;
        }

    }
    for(int i =1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout << mmap[i][j] <<" ";
        }
        cout << endl;
    }

}
            //CHUYỂN DANH SÁCH KỀ SANG MA TRẬN KỀ

            //CHUYỂN MA TRẬN KỀ SANG DANH SÁCH KỀ
void matrix_to_list()
{
    int n;cin >> n;
    for(int i =1;i<=n;i++)
    {
        for(int j =1;j<=n;j++)
        {
            int t;
            cin >> t;
            mmap[i][j] = t;
            if(t == 1)
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}
            //CHUYỂN MA TRẬN KỀ SANG DANH SÁCH KỀ

            //NHỊP CHỨNG KHOÁN
void stonk()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n;cin>> n;
        stack<pair<int,int>> st;
        int a[100005] ={};
        int mask[100005] = {};
        for(int i = 0;i<n;i++)
        {
            cin >> a[i];
        }
        
        mask[0] = 1;
        st.push({a[0],mask[0]});
        cout << 1 <<" ";
        for(int i =1;i<n;i++)
        {
            int t = st.top().first;
            if( a[i] < t)
            {
                mask[i] = 1;
                st.push({a[i],mask[i]});
            }
            else{
                mask[i] = 1;
                while(a[i] >= st.top().first )
                {
                    mask[i] += st.top().second;
                    st.pop();
                    if(st.empty() == true) break;
                }
                st.push({a[i],mask[i]});


            }
            cout << mask[i] << " ";
            
        }
        cout << endl;


    }
}
            //NHỊP CHỨNG KHOÁN

            //CHIA ĐỀU
int chia_deu_ans  =0;
void chia_deu_recursive(int k , int x, int index ,int n, int a[],int sum, int cnt, int check) // index = 0,sum = a[0]
{
    if(index == n || cnt > k )
    {

        //if(cnt == k)
       // {       // cout << check<< " " << cnt << endl; dung trong viec debug, day la 1 bai toan can luu y
          //  chia_deu_ans++;
       // }
        return;

    } 
    //if(cnt == k) return;
    if( sum == x)
    {
        // sum = 0 ;
         cnt++;
        chia_deu_recursive(k,x,index+1,n,a,0+a[index+1],cnt,111); // so 111 la bien check de debug
         if(cnt == k)
         {
             if(index == n-1)
            { 
                 chia_deu_ans++;
            }
         }
         cnt--;
        // sum = x;
    }
    //if(cnt < k)
    chia_deu_recursive(k,x,index+1,n,a,sum+ a[index+1],cnt,0);
}
void chia_deu()
{
    int n;int k;
    cin >> n >>k ;
    int a[20];
    int sum = 0;

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int cnt = 0;
    if( sum%k != 0 )
    {
        cout << cnt << endl;
    }
    else{
        int x = sum/k;
        chia_deu_recursive(k,x,0,n,a,a[0],0,0);
        cout << chia_deu_ans << endl;
    }
}
            //CHIA ĐỀU

            //NGƯỜI DU LỊCH
void traveler_recursive(int mask[], int a[][20],int n, int st,int sum, int &min,int cnt)
{
    if(sum > min) return;  // luu y : chi 1 thay doi nho co the bien btoan tu TLE => AC
    if(cnt == n-1)
    {
        sum = sum + a[st][1];
        if(min > sum)
        {
            min = sum;

        }
        return;
    }
    mask[st]= 1;
    for(int i =1;i<=n;i++)
    {
        if(mask[i] == 0)
        {
            traveler_recursive(mask,a,n,i,sum+a[st][i],min,cnt+1);
        }
    }
    mask[st] = 0;
}
void traveler()
{
    int n ;cin>>n;
    int a[20][20];
    int mask[20] = {};
        for(int i= 1;i<=n;i++)
        {
            for(int j =1;j<=n;j++)
            {
                cin >> a[i][j];
            }
        }
    int min = 1000000000 ;
    traveler_recursive(mask,a,n,1,0,min,0);
    cout << min << endl;
    
}
            //NGƯỜI DU LỊCH

            //BIỂU THỨC ĐÚNG DÀI NHẤT
void dau_ngoac()
{
    int tc; cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        stack<int> st;
        st.push(0);
        string s;
        cin >> s;
        int n =s.length();
        int max = 0;
        int tt = 0;
        for(int i =0;i<n;i++)
        {
            if(s[i] == '(')
            {
                st.push(i+1);

            }
            else{
                if(st.size() >1)
                {
                    st.pop();
                    tt = (i+1) - st.top(); // dung de tim chuoi dung dai nhat trong day string
                    max+=2;

                }
                else{
                    st.pop();
                    st.push(i+1);
                   // max+=tt;
                    //tt = 0;
                }
            }
        }
       // max += tt;
        cout << max  << endl;
    }

}
            //BIỂU THỨC ĐÚNG DÀI NHẤT

            //GIÁ TRỊ NHỎ NHẤT CỦA XÂU
void min_of_string()
{
    int tc;cin>>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int k;cin >> k;
        string s;
        multiset<int> ms;
        cin >> s;
        int n = s.length();
        int a[1000] = {};
        for(int i=0;i<n;i++)
        {
            a[s[i]]++;
        }
        for(int i = 'A';i<='Z';i++)
        {
            //cout << a[i] << " ";
            ms.insert(a[i]);
        }
        //cout << endl;
        for(int i=0;i<k;i++)
        {
            auto j = ms.end();
            j--;
            int temp = *j;
            temp--;
            if(temp <0) temp =0;
            ms.erase(j);
            ms.insert(temp);
        }
        ll ans = 0;
        for(auto i: ms)
        {
            //cout << i <<" ";
            ans += (ll)i * i;
        }
        //cout << endl;
        cout <<ans << endl;
    }

}
            //GIÁ TRỊ NHỎ NHẤT CỦA XÂU
            
            //TỪ ĐIỂN
bool dic_check = 0;
int mv_h[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int mv_c[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void dic_recursive(set<string> &x , int mask[][10], string a[][10], string s, int index,int h, int c,int mh,int mc)
{
    if(x.find(s) != x.end())
    {
        cout << s << " ";
        dic_check = 1;
        return;
    }
    else{
        for(int i=0;i<8;i++)
        {
            int hh = h +mv_h[i];
            int cc = c + mv_c[i];
            if(hh>=1 && hh <= mh && cc>=1 && cc <=mc&&mask[hh][cc] == 0)
            {
                mask[hh][cc] = 1;
                dic_recursive(x,mask,a,s+a[hh][cc][0],index+1,hh,cc,mh,mc);
                mask[hh][cc] = 0;
            }
        }
    }
}
void dictionary()
{
    int tc;cin>>tc;
    for(int ii=0;ii<tc;ii++)
    {
        int n , h ,c ;
        cin  >> n>>h>>c;
        string a[10][10] ={};
        int mask[10][10]= {};
        set<string> s;
        for(int i =0;i<n;i++)
        {
            string str;
            cin >> str;
            s.insert(str);
        }
        for(int i =1;i<=h;i++)
        {
            for(int j =1;j<=c;j++)
            {
                cin >> a[i][j];
            }
        }
        dic_check = 0;

            for(int i = 1;i<=h;i++)
            {
                for(int j =1;j<=c;j++)
                {
                    for(auto temp : s)
                    {
                        if(temp[0] == a[i][j][0])
                        {

                       
                        mask[i][j] = 1;
                        dic_recursive(s,mask,a,a[i][j],0,i,j,h,c);
                        mask[i][j] = 0;
                        break;


                        }
                    }

                }
            
        } 
        if(dic_check == 0)  
        {
            cout << "-1";
        }
        cout << endl;
    }
}
            //TỪ ĐIỂN

            //BIỂU THỨC TOÁN HỌC
int math_check = 0;

void math_fun_recursive1(int  st[], int index,char ch[], char dau[])
{
    if(math_check) return;
    if(index == 4)
    {
        int res = st[0];
        int cnt = 0;
        for(int i=0;i<4;i++)
        {
            if(ch[i] == '*')
            {
                cnt++;
                res *= st[cnt];

            }
            else if(ch[i] == '+')
            {
                cnt++;
                res += st[cnt];

            }
            else if(ch[i] == '-')
            {
                cnt++;
                res -= st[cnt];

            }

        }

        if(res == 23)
        {
            math_check = 1;
        }
        return;

    }
    else{
        for(int i=0;i<3;i++)
        {
            ch[index] = dau[i];
            math_fun_recursive1(st,index+1,ch,dau);
        }
    }
}
void math_fun_recursive2(int  st[], int index,char ch[], int a[], char dau[], int mask[])
{
    if(math_check) return;
    if(index == 5)
    {
        math_fun_recursive1(st,0,ch,dau);


        return;

    }
    else{
        for(int i=0;i<5;i++)
        {
            if(mask[i] == 0)
            {
                mask[i] = 1;
                st[index] = a[i];
                math_fun_recursive2(st,index+1,ch,a,dau,mask);
                mask[i] = 0;
            }

        }
    }
}


void math_fun()
{
    int tc;cin >>tc;
    for(int ii =0;ii<tc;ii++){
        int a[10];
        char ch[5] = {};
        int mask[10] = {};
        int st[10];
        for(int i =0;i<5;i++)
        {
            cin >> a[i];
        }

        char dau[3] = {'+','-','*'};
        math_check = 0;
        math_fun_recursive2(st,0,ch,a,dau,mask);
        if(math_check) cout << "YES" << endl;
        else cout << "NO" << endl;


    }
}
            //BIỂU THỨC TOÁN HỌC

            //ĐƯỜNG ĐI DÀI NHẤT
multiset<pair<int,int>> long_s;
void longest_path_dfs(int &max, int &x, int st, int mask[][30] ,vector<vector<int>> &vt,int sum)
{
    if(max < sum)
    {
        max = sum;
        x = st;
        //long_s.insert({max,x});
        
    }

    for(int i=0;i<vt[st].size();i++)
    {
        if(mask[st][vt[st][i]]  == 0 &&  mask[vt[st][i]][st] == 0)
        {
            mask[st][vt[st][i]] = 1;
            mask[vt[st][i]][st] = 1;
            longest_path_dfs(max,x,vt[st][i],mask,vt,sum+1);
            mask[st][vt[st][i]] = 0;
            mask[vt[st][i]][st] = 0;
        }
    }

}
void longest_path()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        vector<vector<int>> vt(30);
        int mask[30][30] = {};
        int n, e;
        cin >> n >> e;
        for(int i =0;i<e;i++)
        {
            int a,b;
            cin >> a >> b;
            vt[a].push_back(b);
            vt[b].push_back(a);
           // mask[a][b] = 1;
           // mask[b][a] = 1;
        }
        int max = 0;
        int x = -1;
        for(int i =0;i<n;i++)
        {
        longest_path_dfs(max,x,i,mask,vt,0);
        //longest_path_dfs(max,x,x,mask,vt,0);
        }

        // auto j = long_s.end();
        // j--;
        // int temp = (*j).first;
        // vector<int> vc;
        // while((*j).first == temp)
        // {
        //     vc.push_back((*j).second);
        //     long_s.erase(j);
        //     j--;
        // }
        // for(auto i : vc)
        // {
        //     if(vt[i].size() >1)
        //     {
        //     longest_path_dfs(max,x,i,mask,vt,1);

        //     }
        //     else{
        //     longest_path_dfs(max,x,i,mask,vt,0);
        //     }
        // }

        //cout << " x : " << x << endl;

        cout << max << endl;

    }
}
            //ĐƯỜNG ĐI DÀI NHẤT

            //KÝ TỰ ĐẶC BIỆT
void special_char()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        string s;
        cin >> s;
        ull k;cin >>k;
        ull n = s.length();
        ull nn = n;
        while(nn < k)
        {
            nn = nn*2;
        }
        while(k > n)
        {
            while( k <= nn)
            {
                nn /=2;
            }
            k = k -nn - 1;
        }
        if( k == 0)
        {
            cout << s[s.length()-1] <<endl;
        }
        else{
            cout << s[k-1] << endl;
        }
    }
}
            //KÝ TỰ ĐẶC BIỆT

            //BIẾN ĐỔI S – T
void convert_s_t()
{
    int tc;cin >>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int s ,t ;
        cin >> s >> t;
        int a[100000] = {};
        a[s] = 1;
        queue<int> q;
        q.push(s);
        while(q.empty() == false)
        {
            int temp = q.front();
            //cout << temp << " ";
            q.pop();
            int x = temp *2;
            int y = temp -1;
            if(  x > 0 && x <= 10000  && a[x] == 0)
            {
            
                a[x] = a[temp] + 1;
                q.push(x);
                

            }

            if(y > 0  &&  y <=10000 && a[y] == 0 )
            {
     
                a[y] = a[temp] + 1;
                q.push(y);
                

            }

            if(a[t] != 0)
            break;
            

        }
        cout << a[t] -1 << endl;
    }
}
            //BIẾN ĐỔI S – T
            
            //QUÂN MÃ
void knight()
{
    int tc; cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        char h,c;
        cin >> c >> h;
        pair<int,int> st, en;
        st = { 9 - (h - '0') ,c-'a' +1};
        cin >> c >> h ;
        en = {9 - (h - '0') ,c-'a' +1};
        int a[10][10] = {};

        queue<pair<int,int>> q;
        q.push(st);
        a[st.first][st.second] = 1;

        int mvh[8] = {-1,-2,-2,-1,1,2,2,1};
        int mvc[8] = {-2,-1,1,2,2,1,-1,-2};
        while(q.empty() == false)
        {
            int hh = q.front().first;
            int cc = q.front().second;
            q.pop();
            for(int i =0;i<8;i++)
            {
                int x = hh + mvh[i];
                int y = cc + mvc[i];
                if(a[x][y] == 0 && x >=1 && x<=8 && y>=1 && y<=8)
                {
                    a[x][y] = a[hh][cc] +1 ;
                    q.push({x,y});
                    if(x == en.first &&  y == en.second) break;
                }
            }
            int x = q.front().first;
            int y = q.front().second;
            if(x == en.first &&  y == en.second) break;
        }
        cout << a[en.first][en.second] - a[st.first][st.second] << endl;

    }
}
            //QUÂN MÃ



int main()
{

    knight();
    return 0;
}