#include<bits/stdc++.h>
using namespace std;


            //CLEANRBT - Cleaning Robot UN FN
void clean_robot()
{
while(1)
{
    int h,c;
    cin>>h>>c;
    if(h ==0 && c == 0) break;
    char a[30][30] ={};
    int cnt =0;
    pair<int,int> st;
    for(int i=1;i<=h;i++)
    {
        for(int j =1;j<=c;j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 'o')
            {
                st.first = i;
                st.second = j;
            }
            if(a[i][j] == '*')
                cnt++;
        }
    }
    int mask[30][30] ={};
    queue<pair<int,int>> q;
    q.push(st);
    mask[st.first][st.second] = 1;

    int step =0;
    int check =0;
    int move_h[4] = {0,1,0,-1};
    int move_c[4] = {1,0,-1,0};
    int ans =0;
    while(q.empty() == false)
    {
        int sz = q.size();
        step++;
        check = 0;
        for(int i =0;i<sz;i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int j=0;j<4;j++)
            {
                int hh  = x+ move_h[j];
                int cc  = y+ move_c[j];
                if(a[hh][cc] == '.' && mask[hh][cc] == 0)
                {
                    q.push({hh,cc});
                    mask[hh][cc] = 1;
                }
                else if(a[hh][cc] == '*' && mask[hh][cc] == 0)
                {
                    a[hh][cc] ='.';
                    for(int ii =0;ii<30;ii++)
                        for(int jj =0;jj<30;jj++)
                            mask[ii][jj] = 0;;;
                    ans += step;
                    step =0;
                    while(q.empty() == false) q.pop();
                    q.push({hh,cc});
                    mask[hh][cc] = 1;  
                    cnt--;
                    if(cnt == 0)
                    {
                        check = 2;
                        break;
                    }  
                    else
                    {
                        check =1;break;
                    }
                    
                }

            }
            if(check) break;
        }
        if(check == 2) break;
    }
    if(cnt == 0)
    {
        cout << ans << endl;
    }
    else
        cout << -1 << endl;
}




}
            //CLEANRBT - Cleaning Robot UN FN

            //ELEVTRBL - Elevator Trouble

void elevator_trouble()
{
    int f,s,g,u,d;
    cin >>f >>s>>g>>u>>d;

    vector<int> mask(1000005,0);
    queue<int> q;
    mask[s] = 1;
    q.push(s);
    if(s != g)
    while(q.empty() == false)
    {
        int temp = q.front();
        q.pop();
        int a = temp + u;
        int b = temp - d;
        if(a >=1 && a<=f && mask[a] == 0)
        {
            mask[a] = mask[temp] +1;
            q.push(a);
        }
        if(b >=1 && b<=f && mask[b] == 0)
        {
            mask[b] = mask[temp] +1;
            q.push(b);
        }
    }

    if(mask[g] == 0)
    {
        cout << "use the stairs" <<endl;
    }
    else
    cout << mask[g] -1 << endl;

}
            //ELEVTRBL - Elevator Trouble

            //HERDING - Herding
int herd_map[1005][1005] = {};
int herd_mask[1005][1005] = {};

void herding()
{   
    int h,c;
    cin >>h>>c;
    int mv_h[5] = {0,-1,0,1,0};
    int mv_c[5] = {0,0,1,0,-1};
    for(int i=1;i<=h;i++)
    {
        for(int j =1;j<=c;j++)
        {
            char t;cin >>t;
            if(t == 'N')
            {
                herd_map[i][j] = 1;
            }
            else if(t == 'W')
            {
                herd_map[i][j] = 4;
            }
            else if(t == 'E')
            {
                herd_map[i][j] = 2;
            }
            else if(t == 'S')
            {
                herd_map[i][j] = 3;
            }
        }
    }


    queue<pair<int,int>> q;
    int cnt = 0;
    for(int i =1;i<=h;i++)
    {
        for(int j =1;j<=c;j++)
        {
            //cout << herd_mask[i][j] <<" ";
            if(herd_map[i][j] != 0 && herd_mask[i][j] == 0)
            {
                cnt++;
                q.push({i,j});
                herd_mask[i][j] = cnt;
                    int hh = q.front().first;
                    int cc = q.front().second;
                    int x = hh;
                    int y = cc;
                    while( herd_map[x + mv_h[herd_map[x][y]]][y + mv_c[herd_map[x][y]]] != 0 &&
                     herd_mask[x + mv_h[herd_map[x][y]]][y + mv_c[herd_map[x][y]]] == 0)
                    {
                        int xx = x + mv_h[herd_map[x][y]];
                        int yy = y + mv_c[herd_map[x][y]];
                        herd_mask[xx][yy] = cnt;
                        q.push({xx,yy});
                        x = xx;
                        y = yy;
                       // cout << x << " " << y << endl;
                    }
                while(q.empty() == false)
                {
                    hh = q.front().first;
                    cc = q.front().second;
                    q.pop();
                    for(int ii = 1;ii<=4;ii++)
                    {

                        x = hh + mv_h[ii];
                        y = cc + mv_c[ii];
                        int dr = herd_map[x][y];
                        if( herd_mask[x][y] == 0 && x+mv_h[dr] ==hh && y+mv_c[dr] == cc )
                        {
                            q.push({x,y});
                            herd_mask[x][y] = cnt;
                            //break;
                        }
                    }
                }
            }
        }
        //cout << endl;
    }
    // for(int i =1;i<=h;i++)
    // {
    //     for(int j =1;j<=c;j++)
        
    //         cout << herd_mask[i][j] << " ";
    //         cout << endl;
    // }

            cout << cnt << endl;

}
            //HERDING - Herding

            //LABYR1 - Labyrinth
        int mv_h[4] = {0,1,0,-1};
        int mv_c[4] = {1,0,-1,0};
void herd_bfs(int i, int j, int &max, int &x, int &y )
{
    x =-1;y=-1;
    queue<pair<int,int>> q;
                    herd_mask[i][j] = 1;
                    q.push({i,j});
                    while(q.empty() == false)
                    {
                        int hh = q.front().first;
                        int cc = q.front().second;
                        q.pop();
                        if(herd_mask[hh][cc] > max)
                        {
                            max = herd_mask[hh][cc];
                            x = hh;
                            y =cc ;
                        }
                        for(int jj =0;jj<4;jj++)
                        {
                            int x = hh + mv_h[jj];
                            int y = cc + mv_c[jj];
                            if( herd_map[x][y] == 1 && herd_mask[x][y] == 0)
                            {
                                herd_mask[x][y] = herd_mask[hh][cc] + 1;
                                q.push({x,y});
                            }
                        }
                    }
}
void labyrinth()
{
    int tc;
    cin >> tc;
    for(int ii =1 ;ii<= tc;ii++)
    {
        int h,c;
        cin >> c >> h;

            for(int i =1;i<=h;i++)
    {
        for(int j =1;j<=c;j++)
        
           {herd_mask[i][j] = 0;
            herd_map[i][j] = 0;}
    }
        for(int i =1;i<=h;i++)
        {
            for(int j = 1;j<=c;j++)
            {
                char t;
                cin >>t;
                if(t == '#')
                {
                    herd_map[i][j] = 2;
                }
                else if(t == '.')
                {
                    herd_map[i][j] = 1;
                }
            }
        }
        queue<pair<int,int>> q;
        int cnt = 0;
        int max = 0;
        int x;int y;
        for(int i=1;i<=h;i++)
        {
            for(int j =1;j<=c;j++)
            {
                if(herd_map[i][j] == 1 && herd_mask[i][j] == 0)
                {
                    herd_bfs(i,j,max,x,y);
                    if(x != -1)
                    {
                        for(int i =1;i<=h;i++)
                            {
                                for(int j =1;j<=c;j++)
                                    herd_mask[i][j] = 0;            
                            }
                        herd_bfs(x,y,max,x,y);
                    }

                }
            }
        }
for(int i =1;i<=h;i++)
    {
        for(int j =1;j<=c;j++)
           { herd_map[i][j] = 0;
            herd_mask[i][j] = 0;}
    }

        cout << "Maximum rope length is " << max - 1 << "."<< endl;
    }
}
            //LABYR1 - Labyrinth

            //SERGRID - Grid
void grid()
{
    int h,c;
    cin >> h>> c;
    for(int i = 1;i<=h;i++)
    {
        for(int j =1;j<=c;j++)
        {
            char c;cin >>c;
            int t = c - '0';
            herd_map[i][j] = t;
            //herd_mask[i][j]= 1;
        }
    }
    queue<pair<int,int>> q;
    q.push({1,1});
    herd_mask[1][1] = 1;
    while(q.empty() == false)
    {
        int hh = q.front().first;
        int cc = q.front().second;
        //cout << hh<<" "<<cc<<endl;
        q.pop();

        for(int i =0;i<4;i++)
        {
            int x = hh + mv_h[i] *  herd_map[hh][cc];
            int y = cc + mv_c[i] * herd_map[hh][cc];
            if(herd_mask[x][y] ==  0 && x>=1 && x<=h&& y>=1&&y<=c)
            {
                herd_mask[x][y] = herd_mask[hh][cc] + 1;
                q.push({x,y});
            }
        }

    }
    if(herd_mask[h][c] == 0) cout << -1 << endl;
    else
    cout << herd_mask[h][c] - 1 << endl;


}
            //SERGRID - Grid

            //PT07Y - Is it a tree
void is_tree_recursive(vector<vector<int>> &vt , int mask[], int st, int &cnt,int &check, int par)
{
    if(check) return;
    mask[st] = 1;
    for(int i =0;i<vt[st].size();i++ )
    {
        if(mask[vt[st][i]] == 0)
        {
            cnt = cnt + 1;
            is_tree_recursive(vt,mask,vt[st][i], cnt,check,st);
        }
        else
        {
            if(vt[st][i] !=  par)
            {
                check =1;
                return;
            }

        }
    }
}
void is_tree()
{
    int n,e;
    cin >> n >>e;
    vector<vector<int>> vt(10005);
    int mask[100005] ={};
    for(int i = 0;i<e;i++)
    {
        int a,b;
        cin >> a>> b;
        vt[a].push_back(b);
        vt[b].push_back(a);
    }
    int cnt = 1;
    int check = 0;
    is_tree_recursive(vt,mask,1,cnt,check,0);
    if( cnt == n && check == 0 && n == e+1) cout << "YES" << endl;
    else cout << "NO" << endl;

}
            //PT07Y - Is it a tree

            //BUGLIFE - A Bug’s Life
void bug_life_recursive(vector<vector<int>> &vt, int mask[], int st, int gen, int &check)
{
    if(check) return;
    if(gen == 1)
    {
        mask[st] = 1;
    }
    else if( gen == 2)
    {
        mask[st] = 2;
    }

    for(int i =0;i<vt[st].size();i++)
    {
        if(mask[vt[st][i]] == 0)
        {
            if(gen == 1)
                bug_life_recursive(vt,mask,vt[st][i],2,check);
            else if( gen == 2)
                bug_life_recursive(vt,mask,vt[st][i],1,check);
        }
        else{
            if(gen == 1 && mask[vt[st][i]] == 1)
            {
                check = 1;
                return;
            }
            if(gen == 2 &&mask[vt[st][i]] == 2)
            {
                check = 1;return;
            }

        }
    }
}
void bug_life()
{
    int tc ;
    cin >>  tc;
    for(int ii =1;ii<=tc;ii++)
    {
        int n, e;
        cin >> n >> e;
        vector<vector<int>> vt(2005);
        int mask[2005] = {};
        for(int i =0;i<e;i++)
        {
            int a,b;
            cin >> a >> b;
            vt[a].push_back(b);
            vt[b].push_back(a);
        }
        int check = 0;
        for(int i =1;i<=n;i++)
        {
            if(mask[i]==0)
            {
                bug_life_recursive(vt,mask,i,1,check);
                        if(check){
                cout << "Scenario #" << ii <<":" << endl;
                cout << "Suspicious bugs found!" << endl;
                break;
                                } 
            }
        }
        if(check == 0)
        {
                cout << "Scenario #" << ii <<":" << endl;
                cout << "No suspicious bugs found!" << endl;
        }





    }
}
            //BUGLIFE - A Bug’s Life

            //BENEFACT - The Benefactor //luu y: bai toan danh cho do thi k co chu trinh hoac 
                                        //do thi co so canh luon nho hon so dinh 1 don vi
void bene_recursive(vector<vector<pair<int,int>>> &vt , int mask[], int st, int &max, int sum, int &p)
{
    if(max < sum)
    {
        max = sum;
        p = st;
    }
    mask[st] = 1;
    for(int i =0;i<vt[st].size();i++)
    {
        if(mask[vt[st][i].first] == 0)
        {
            bene_recursive(vt,mask,vt[st][i].first,max,sum +vt[st][i].second,p );
        }
    }
}
void benefactor()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n;cin >> n;
        vector<vector<pair<int,int>>> vt(50005);
        int mask[50005] = {};
        for(int i =1;i<n;i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            vt[a].push_back({b,c});
            vt[b].push_back({a,c});
        }


    int max =0;
    int p = 0;
    for(int i =1;i<=n;i++)
    {
        if(mask[i] == 0)
        {
            p = 0;
            bene_recursive(vt,mask,i,max,0,p);
            if(p!=0)
        {
            for(int j = 1;j<=n;j++)
            {
                mask[j] = 0;
            }
            bene_recursive(vt,mask,p,max,0,p);
        }


        }

    }
    cout << max << endl;
    }

}
            //BENEFACT - The Benefactor // 

int main()
{
    benefactor();
    return 0;
}