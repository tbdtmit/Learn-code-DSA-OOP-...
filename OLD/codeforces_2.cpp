#include<bits/stdc++.h>
using namespace std;


            //Dorms War

bool check(char i ,char aa[], int k)
{
    for(int a=0;a<k;a++)
    {
        if(i == aa[a])
            return true;
    }
    return false;
}
void dorms_war()
{
    int tc;
    cin >>tc;
    for(int ii =0;ii<tc;ii++)
    {
        char special[30];
        int n;
        cin >> n;
        string s;
        cin >> s;
        int k;
        cin >>k;
        for(int i=0;i<k;i++)
        {
            cin >> special[i];
        }

        int status =1;
        int index_last =0;
        int cnt =0;
        int c = 0;
        while( s.length() != c)
        {
            string ss;
            for(int i =0;i<s.length()-1;i++)
            {
                if(check(s[i+1] , special,k))
                {

                    index_last = i+1;

                }
                else
                {
                    ss += s[i];
                }

            }
            if(status)
            {
                c = n - index_last;
                status = 0;
            }
            if(s.length() != c)
            cnt++;
            s = ss + s[s.length()-1];
           // cout << s.length() <<" "<< c << endl;



        }
        cout << cnt <<endl;

    }
}
            //Dorms War

            // ADD String
void add_string(string a, string b)
{
    int n = a.length();
    int m = b.length();

    if(n<m)
    {
        while(n<m)
        {
            a = '0' + a;
            n = a.length();
        }
    }
    else{
        while(m<n)
        {
            b = '0' + b;
            m = b.length();
        }
    }

    string ans = "";
    int remember = 0;
    for(int i=n-1;i>=0;i--)
    {
        int res = (a[i] - '0') + (b[i] - '0') +remember;
        char dv = (res%10) + '0' ;
        remember = res/10;
        ans = ans + dv;
        if( i == 0)
        {
            if(remember != 0)
                ans = ans + char(remember + '0');
        }

    }
    for(int i =0;i<= (ans.length()-1)/2;i++)
    {
        char temp = ans[i];
        ans[i] = ans[ans.length()-1-i];
        ans[ans.length()-1-i] = temp ;
        
    }
    cout << ans << endl;

}
            // ADD String

            //PT07Y - Is it a tree UN FN
void it_a_tree()
{
    int n,e;
    cin>>n>>e;
    vector<vector<int>>  vt(100000);
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin >>a>>b;
        vt[a].push_back(b);
        vt[b].push_back(a);
    }

}
            //PT07Y - Is it a tree UN FN

            //NAKANJ - Minimum Knight moves !!!
void mkm()
{
    int tc;
    cin >>tc;
    for(int ii=0;ii<tc;ii++)
    {
        int a[30][30] = {0};
        queue<pair<int, int>> q;
        string aa,b;
        cin >> aa >> b;
        q.push({ aa[1] - '0',aa[0] -'a'+1});

        int move_h[8] = {-1,-2,-2,-1,1,2,2,1};
        int move_c[8] = {-2,-1,1,2,2,1,-1,-2};
        int check = 0;
        int cnt =0;
        while(1)
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                int h = q.front().first;
                int c = q.front().second;
                q.pop();
                if( h == int(b[1] - '0')  && c == int(b[0] - 'a' + 1))
                {
                    cout << cnt <<endl ;
                    check = 1;
                    break;
                }
                a[h][c] = 1;
                for(int j =0;j<8;j++)
                {
                    if(h + move_h[j] >= 1 && h + move_h[j] <= 8 &&
                        c + move_c[j] >= 1 &&  c + move_c[j] <= 8 
                        && a[h + move_h[j]][c + move_c[j]] == 0)
                        {
                            q.push({h + move_h[j],c + move_c[j]});
                        }
                }

            }
            cnt++;
            if(check) break;
        }


    }
}
            //NAKANJ - Minimum Knight moves !!!




            //ABCPATH - ABC Path
int move_h[8] = {-1,-1,-1,0,1,1,1,0};
int move_c[8] = {-1,0,1,1,1,0,-1,-1};
void abc_path_recursive(char a[][60], char ch, int &max , int cnt, int h, int c, int mask[][60], int m, int n )
{
    if( cnt > max)
    {
        max = cnt;
    }

        for(int i=0;i<8;i++)
        {
            int hh = h + move_h[i];
            int cc = c + move_c[i];
            if(a[hh][cc] == ch +1 && hh >=1 &&hh<=m && cc >=1 && cc<=n && mask[hh][cc] == 0)
            {
                mask[hh][cc] = 1;
                abc_path_recursive(a,ch+1,max,cnt+1,hh,cc,mask,m,n);
                //mask[hh][cc] = 0;
            }
        }
    
}
void abc_path()
{
    int tc = 0;
    while(1)
{
    tc++;
    int m,n;
    char a[60][60] = {0};
    int mask[60][60] = {0};
    vector<pair<int,int>> vt;
    int max = 0;
    cin >>m>>n;
    if(m == 0 && n ==0) break;
    for(int i= 1;i<=m;i++)
    {
        for(int j =1;j<=n;j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 'A')
            {
                vt.push_back({i,j});
                mask[i][j] = 1;
            }

        }
    }
    for(auto i : vt)
    {
        int h = i.first;
        int c = i.second;
        abc_path_recursive(a,'A',max,1,h,c,mask,m,n);

    }
    cout << "Case " << tc <<": " << max <<endl;

}


}
            //ABCPATH - ABC Path

            //ALLIZWEL - ALL IZZ WELL
void aiw_recursive(char a[][200], int &check , int cnt, int h, int c, int mask[][200], int m, int n, string &str )
{
    if(check == 1) return;
    if( cnt == str.length() -1)
    {
        check = 1;
        return;
    }

        for(int i=0;i<8;i++)
        {
            int hh = h + move_h[i];
            int cc = c + move_c[i];
            if(a[hh][cc] == str[cnt+1] && hh >=1 &&hh<=m && cc >=1 && cc<=n && mask[hh][cc] == 0 )
            {
                mask[hh][cc] = 1;
                aiw_recursive(a,check,cnt+1,hh,cc,mask,m,n,str);
                mask[hh][cc] = 0;
            }
        }
    
}
void aiw()
{
    int tc;cin >>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int h,c;
        cin >> h >> c;
        char a[200][200] = {0};
        int mask[200][200] = {0};
        vector<pair<int, int>> vt;
        string str = "ALLIZZWELL";
        int n = str.length();
        for(int i=1;i<=h;i++)
        {
            for(int j= 1;j<=c;j++)
            {
                cin >> a[i][j];
                if(a[i][j] == 'A')
            {
                vt.push_back({i,j});
                mask[i][j] = 1;
            }
            }
        }
        int check = 0;
        for(auto i : vt)
        {
            aiw_recursive(a,check,0,i.first,i.second,mask,h,c,str);
            if(check)
            {
                cout <<"YES" << endl;
                break;
            }

        }
        if(check == 0) 
            cout <<"NO" << endl;

    }
}

            //ALLIZWEL - ALL IZZ WELL

            //EASUDOKU - Easy sudoku
bool check_sudoku(int h, int c, int a[][20])
{
    int mask[10] ={0};
    for(int i=1;i<=9;i++)
    {
        if(a[h][i] == a[h][c] && i!=c)
            return false;
        if(a[i][c] == a[h][c] && i !=h)
            return false;
    }
    return true;
}
void sudoku_recursive(int &check, int a[][20], int mask[][20], int n,int h, int c)
{
    if(check) return;
    if(h == 10)
    {
        check = 1;
        return;
    }
    else{
        for(int i=1;i<=9;i++)
        {
            if(check == 0)
            {
            a[h][c] = i;
            if(check_sudoku(h,c,a))
            {
            int cc = c+1;
            int hh = h;
            if(cc == 10)
            {
                hh = h+1;
                cc = 1;
            }
            while(mask[hh][cc] != 1)
            {
                cc +=1;
                if(cc ==10)
                    {
                        cc =1;
                        hh+=1;
                    }
            }
            
            if(check ==0)
            sudoku_recursive(check,a,mask,n,hh,cc); 
            }

              
            }

        }
        if(check==0)
        a[h][c]= 0;
    }
}
void sudoku()
{
    int tc;cin >>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int a[20][20] ={0};
        int mask[20][20] ={0};
        mask[10][1] =1;
        int n =9;
        vector<pair<int,int>> vt;
        for(int i =1;i<=n;i++)
        {
            for(int j= 1;j<=n;j++)
            {
                cin >> a[i][j];

                if(a[i][j] == 0)
                {
                    vt.push_back({i,j});
                    mask[i][j] = 1;
                }
            }
        }
        int h = vt[0].first;
        int c = vt[0].second;
        int check =0;
        sudoku_recursive(check,a,mask,n,h,c);

        //cout << endl;
        
        if(check)
        {
        for(int i =1;i<=n;i++)
        {
            for(int j= 1;j<=n;j++)
            {
                cout << a[i][j] <<" ";
            }
            cout <<endl;
        }
        }
        else
            cout << "No solution"  <<endl;
    }
}
            //EASUDOKU - Easy sudoku

int main()
{
    sudoku();

    return 0;

}