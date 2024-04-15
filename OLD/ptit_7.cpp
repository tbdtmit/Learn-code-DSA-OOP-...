#include<bits/stdc++.h>
using namespace std ;

            //KẾT BẠN
void make_friend()
{
    int tc; cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n,e;
        cin >> n >> e;
        vector<vector<int>> vt(100005);
        int mask[100005] = {};
        for(int i=0;i<e;i++)
        {
            int a,b;
            cin >> a >> b;
            vt[a].push_back(b);
            vt[b].push_back(a);
        }

        queue<int> q;
        int max = 0;

        for(int i =1;i<=n;i++)
        {
            if(mask[i] == 0)
            {
                q.push(i);
                mask[i] = 1;
                int cnt = 1;

                while(q.empty() == false)
                {
                    int temp = q.front();
                    q.pop();
                    for(int j=0;j<vt[temp].size();j++)
                    {
                        if(mask[vt[temp][j]] == 0)
                        {
                            mask[vt[temp][j]] = 1;
                            q.push(vt[temp][j]);
                            cnt++;
                            if(cnt > max) max = cnt;

                        }
                    }
                }
            }
        }

        cout << max << endl;
    }
}
            //KẾT BẠN 
            
            //TÌM ĐƯỜNG
int fw_check = 0;
void find_way_dfs(int mask[][600], char a[][600], pair<int,int> en, int pdr, int ndr ,int st, int cnt, int h, int c ) // pdr la huong trc do, ndr la huong hien tai
{
    if(cnt == 3 || fw_check == 1) return;
    int mvh[4] = {-1,0,1,0};
    int mvc[4] = {0,1,0,-1};
    if(h == en.first && c == en.second)
    {
        fw_check = 1;return;
    }
    else
    {
        for(int i =0;i<4;i++)
        {
            int hh = h + mvh[i];
            int cc = c + mvc[i];
            if(mask[hh][cc] == 0 && a[hh][cc] != 0 && a[hh][cc] != '*')
            {
                mask[hh][cc] = 1;
                if(st == 0)
                {
                    find_way_dfs(mask,a,en,i,i,st+1,cnt,hh,cc);
                }
                else{
                    if(i != ndr)
                    {
                        find_way_dfs(mask,a,en,ndr,i,st+1,cnt+1,hh,cc);
                    }
                    else
                    {
                        find_way_dfs(mask,a,en,ndr,i,st+1,cnt,hh,cc);
                    }
                }

                mask[hh][cc] =  0;
            }
        }
    }
}
void find_way()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int h,c;
        cin >> h >> c;
        char a[600][600] = {};
        int mask[600][600] = {};
        pair<int,int> st;
        pair<int,int> en;
        for(int i =1;i<=h;i++)
        {
            for(int j =1;j<=c;j++)
            {
                cin >> a[i][j];
                if(a[i][j] == 'S')
                {
                    st = {i,j};
                }
                else if(a[i][j] == 'T')
                {

                    en = {i,j};
                }
            }
        }

        mask[st.first][st.second] = 1;
        fw_check = 0;
        find_way_dfs(mask,a,en,0,0,0,0,st.first,st.second);
        if(fw_check) cout << "YES" << endl;
        else cout << "NO" << endl;
    } 
}
            //TÌM ĐƯỜNG

            //MẠNG XÃ HỘI
void social_net()
{
    int tc;cin >> tc;
    for(int ii= 0;ii<tc;ii++)
    {
        int n,e;
        cin >> n>> e;
        int grade[100005] = {};
        int mask[100005] = {};
        vector<vector<int>> vt(100005);
        for(int i=0;i<e;i++)
        {
            int a,b;
            cin >> a>> b;
            vt[a].push_back(b);
            vt[b].push_back(a);
            grade[a]++;
            grade[b]++;
        }
        int check = 0;
        for(int i= 1;i<=n;i++)
        {
            if(grade[i] > 1 && mask[i] == 0) 
            {
                mask[i] = 1;
                int sz =  vt[i].size();
                for(int j=0;j<sz;j++)
                {
                    mask[vt[i][j]] = 1;
                }
                
                for(auto j: vt[i])
                {
                    int cnt =0;
                    for(auto jj: vt[j])
                    {
                        
                        if(mask[jj] == 1)
                        {
                            cnt++;
                        }
                        else
                        {
                            check = 1;break;
                        }

                    }
                    if(cnt != sz)
                    {
                        check =1; break;
                    }

                    if(check) break;
                }


            }
            if(check) break;
        }
        if(check) cout << "NO" << endl;
        else cout << "YES" << endl;

    }
}
            //MẠNG XÃ HỘI

            //ĐỔI TIỀN
void change_cash_recursive(vector<int> &vt,int cnt, int index, int sum, int en, int &check)
{
    if(check || index == -1 || sum > en) return;
    if(sum == en)
    {
        check = cnt;
        return;
    }
    else{
        for(int i = index;i>=0;i--)
        {
            change_cash_recursive(vt,cnt+1,i-1,sum+vt[i],en,check);
        }
    }
}

void change_cash()
{
    int n, en;
    cin >> n>> en;
    vector<int> vt;
    for(int i =0;i<n;i++)
    {
        int t;cin >> t;
        vt.push_back(t);
    }
    sort(vt.begin(),vt.end());
    int check = 0;
    change_cash_recursive(vt,0,n-1,0,en,check);
    if(check) cout << check << endl;
    else cout <<  -1 << endl;
}
            //ĐỔI TIỀN

            //LIỆT KÊ ĐỈNH TRỤ &&  LIỆT KÊ CẠNH CẦU
void tarjan(vector<vector<int>> &vt, int num[], int low[], int &time, int st, int par, set<pair<int,int>> &s)
{
    num[st] = low[st] = ++time;
    int node = (par != 0);
    for(auto i : vt[st])
    {
        if(i == par) continue;
        if(num[i] == 0)
        {
            tarjan(vt,num,low,time,i,st,s);
            low[st] = min(low[st], low[i]);
            if(low[i] >= num[st])
            {
                node++;
            }
            // if(low[i] == num[i])
            // {
            //     if(st<i)
            //     s.insert({st,i});
            //     else
            //     s.insert({i,st});
            // }   
        }
        else if (num[i])
        {
            low[st] = min(low[st], num[i]);
        }
    }
    if(node >= 2) s.insert({st,0});
}
void list_articulation_point()
{
    int tc;
    cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n,e;
        cin >> n>>e;
        vector<vector<int>> vt(1005);
        int mask[1005] = {};
        for(int i=0;i<e;i++)
        {
            int a,b;
            cin >>  a >> b;
            vt[a].push_back(b);
            vt[b].push_back(a);

        }
        int low[1005] = {};
        int num[1005] = {};
        int time = 0;
        set<pair<int,int>> s;
        tarjan(vt,num,low,time,1,0,s);
        for(auto i : s)
        {
            //cout << i.first << " " << i.second << " ";
            cout << i.first << " ";

        }
        cout << endl;
        
    }
}
            //LIỆT KÊ ĐỈNH TRỤ && LIỆT KÊ CẠNH CẦU

            //ĐƯỜNG ĐI VÀ CHU TRÌNH EULER VỚI ĐỒ THỊ VÔ HƯỚNG &&  CÓ HƯỚNG
void euler_path_or_circle()
{
    int tc;cin >>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n,e;
        cin >> n >> e;
        vector<vector<int>> vt(1005);
        int grade[1005] = {};
        int g_out[1005] = {};
        int g_in[1005] = {};
        for(int i=0;i<e;i++)
        {
            int a,b;
            cin >> a >> b;
            //grade[a]++;
            //grade[b]++;
            g_out[a]++;
            g_in[b]++;
        }
        int cnt = 0;
        for(int i =1;i<=n;i++)
        {
            if(g_in[i] != g_out[i])
            {
                cnt++;
            }
        }
        if(cnt == 0) cout << 1 << endl;
        //else if(cnt == 2) cout << 1 << endl;
        else cout << 0 << endl;
    }
}
            //ĐƯỜNG ĐI VÀ CHU TRÌNH EULER VỚI ĐỒ THỊ VÔ HƯỚNG && CÓ HƯỚNG

            //Disjoin Set Union
vector<pair<int,int>> dfs_frame_tree_vt;
void dsu_make_set(int n, int par[], int siz[])
{
    for(int i = 1;i<=n;i++)
    {
        siz[i] = 1;
        par[i] = i;
    }

}

int dsu_find(int x, int par[])
{
    if(par[x] == x)
        return x;
    return par[x] = dsu_find(par[x],par);
}

void dsu_union(int a, int b, int par[] , int siz[] , int &check)
{
    int aa = a;
    int bb = b;
     a = dsu_find(a,par);
     b = dsu_find(b,par);
    if(a != b)
    {
        if(siz[a] <siz[b]) swap(a,b);
        par[b] = a ;
        siz[a] += siz[b];
        //dfs_frame_tree_vt.push_back({aa,bb});
    }
    else
    {
        check = 1;
    }

}

            
            //Disjoin Set Union


            //KIỂM TRA CHU TRÌNH SỬ DỤNG DISJOIN SET
void dsu_is_circle()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n,e;
        cin >> n >> e;
        vector<pair<int,int>> vt;
        int par[1005] = {};
        int siz[1005] = {};
        for(int i = 0;i<e;i++)
        {
            int a,b;
            cin >> a >> b;
            vt.push_back({a,b});
        }
        dsu_make_set(n,par,siz);
        int check = 0;
        for(int i=0;i<e;i++)
        {
            int a = vt.back().first;
            int b = vt.back().second;
            vt.pop_back();
            dsu_union(a,b,par,siz,check);
            if(check) break;
        }
        if(check == 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
            //KIỂM TRA CHU TRÌNH SỬ DỤNG DISJOIN SET

            //CÂY KHUNG CỦA ĐỒ THỊ THEO THUẬT TOÁN DFS && BFS
void dfs1(int par[], int siz[],int st, vector<vector<int>> &vt, int n)
{


    for(int i=0;i<vt[st].size();i++)
    {
        int check = 0;
        dsu_union(st,vt[st][i],par,siz,check);
        if(check == 0)
        {
            dfs_frame_tree_vt.push_back({st,vt[st][i]});
            dfs1(par,siz,vt[st][i],vt,n);
            
        }
        if(dfs_frame_tree_vt.size() == n-1) return;

    }
}
void dfs_frame_tree()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n,e,st;
        cin >> n >> e >> st;
        //queue<pair<int,int>> vt;
        vector<vector<int>> vt(1005);
        int par[1005] = {};
        int siz[1005] = {};
        int mask[1005] = {};
        for(int i = 0;i<e;i++)
        {
            int a,b;
            cin >> a >> b;
            vt[a].push_back(b);
            vt[b].push_back(a);
        }
        dfs_frame_tree_vt.clear();
        dsu_make_set(n,par,siz);


        // dfs1(par,siz,st,vt,n);
        // if(dfs_frame_tree_vt.size() != n-1)
        //     cout << "-1" << endl;
        // else{
        //     for(auto j : dfs_frame_tree_vt)
        //     {
        //         cout << j.first << " " << j.second  << endl;
        //     }
        // }

        queue<int> q;
        q.push(st);

        while(q.empty() == false)
        {
            int j = q.front();
            q.pop();
            for(int i =0;i<vt[j].size();i++)
            {
                int check = 0;
                dsu_union(j,vt[j][i],par,siz,check);
                if(check == 0)
                {
                    q.push(vt[j][i]);
                    dfs_frame_tree_vt.push_back({j,vt[j][i]});
                }
                if(dfs_frame_tree_vt.size() == n-1) break;
            }
            if(dfs_frame_tree_vt.size() == n-1) break;
        }
        if(dfs_frame_tree_vt.size() !=  n-1) cout << -1 << endl;
        else{
            for(auto i : dfs_frame_tree_vt)
            {
                cout << i.first << " " << i.second << endl;
            }
        }



    }   
}
            //CÂY KHUNG CỦA ĐỒ THỊ THEO THUẬT TOÁN DFS && BFS

            //
void traveler_recursive(int mask[], int a[][20],int n, int st,int sum, int &min,int cnt)
{
    if(sum > min) return;  // luu y : chi 1 thay doi nho co the bien btoan tu TLE => AC
    if(cnt == n-1)
    {
        //sum = sum + a[st][1];
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
    int tc;cin >>tc;
    for(int ii=0;ii<tc;ii++)
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
    for(int i=1;i<=n;i++)
    traveler_recursive(mask,a,n,i,0,min,0);
    cout << min << endl;
    }

    
}
            //

            //DÃY CON TĂNG DẦN BẬC K
void dctdbk_recursive(int a[], int n, int index, int te, int cnt, int &ans)
{
    if(cnt == 3)
    {
        ans++;
        return;
    }
    else{
        for(int i = index;i<n;i++)
        {
          if(a[i] > te)
          {
            dctdbk_recursive(a,n,i,a[i],cnt+1,ans);
          }  
        }
    }
}
void dctdbk()
{
    int n,k;
    cin >> n >> k;
    int a[1000] = {};
    for(int i =0;i<n;i++)
    {
        cin >> a[i];
    }
    int ans =0 ;
    dctdbk_recursive(a,n,0,-1000,0,ans);
    cout << ans << endl;
}
            //DÃY CON TĂNG DẦN BẬC K

int main()
{
    dctdbk();
    return 0;
}