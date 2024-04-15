#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<math.h>
#include<string>

using namespace std;

#define ull unsigned long long
#define ll long long
#define MOD 1000000007

            //CHÚ CỪU XA CÁCH
int m_h[4] = {-1,0,1,0};
int m_c[4] = {0,1,0,-1};
void dfs_sheep(int a[][105], int mask[][105], int h, int c, int &cnt,int n,   
 map<pair<int,int>,set<pair<int,int>> > &mp)
{
    //cout << h <<" " << c << "-> ";
    if(a[h][c] == 1) {
        cnt += 1;
    }
    mask[h][c] = 1;
    for(int i=0;i<4;i++)
    {
        int hh = h + m_h[i];
        int cc = c + m_c[i];
        if(mask[hh][cc] == 0  && hh>=1 && hh<=n && cc >= 1 && cc <=n
           && mp[{h,c}].count({hh,cc}) == 0  ) 
        {
            dfs_sheep(a,mask,hh,cc,cnt,n,mp);
        }
    }
}
void distance_sheep()
{
    int a[105][105] = {};
    int mask[105][105] = {};

    int n,k,m;
    cin >> n >> k >> m;

    // for(int i = 0;i<=n+1;i+=n)
    // {
    //     for(int j =0;j<=n+1;j+=n)
    //     {
    //         a[i][j] = -1;
    //         mask[i][j] = -1;
    //     }
    // }

    map<pair<int,int>,set<pair<int,int>> > mp;
    for(int i=0;i<m;i++)
    {
        pair<int,int> b;
        pair<int,int> c;
        cin >> b.first >> b.second >> c.first >> c.second;
        mp[b].insert(c);
        mp[c].insert(b);
        
        
    }
    vector<pair<int,int>> vt;
    for(int i =0;i<k;i++)
    {
        pair<int,int> te;
        cin >> te.first >> te.second;
        a[te.first][te.second] = 1;
        vt.push_back(te);
    }
    int ans = 0;
    for(int i = 0;i<vt.size();i++)
    {
        int cnt = 0;
        int  h = vt[i].first;
        int  c = vt[i].second;
        if(mask[h][c] == 0)
        {
            dfs_sheep(a,mask,h,c,cnt,n,mp);
            //cout << endl;
            ans += (k-cnt)*cnt;
            k-=cnt;
        }

        
    }
    cout << ans << endl;
}
            //CHÚ CỪU XA CÁCH

            //ĐẾM SỐ AO
void count_lakes()
{
    char a[105][105] = {};
    int h,c;
    cin >> h >> c;
    for(int i = 1;i<=h;i++)
    {
        for(int j= 1;j<=c;j++)
        {
            cin >> a[i][j];
        }
    }
    int mh[8] = {1,1,1,0,-1,-1,-1,0};
    int mc[8] = {-1,0,1,1,1,0,-1,-1};
    int ans = 0;

    for(int i = 1;i<=h;i++)
    {
        for(int j= 1;j<=c;j++)
        {
            if(a[i][j] == 'W')
            {

                ans++;
                queue<pair<int,int>> q;
                q.push({i,j});
                a[i][j] = '.';

                while (q.empty() == false)
                {
                    int hh = q.front().first;
                    int cc = q.front().second;
                    q.pop();

                    for(int jj =0;jj<8;jj++)
                    {
                        int ha = hh + mh[jj];
                        int co = cc + mc[jj];
                        if(a[ha][co] == 'W' && ha >=1 && ha<=h && co >=1 && co <=c)
                        {
                            q.push({ha,co});
                            a[ha][co] = '.';
                        }

                    }

                }

                
            }
        }
    }
    cout << ans << endl;

}
            //ĐẾM SỐ AO

int main()
{
    count_lakes();
    return 0;
}
