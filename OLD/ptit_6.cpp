#include<bits/stdc++.h>
using namespace std ;

            //ĐƯỜNG ĐI THEO DFS VỚI ĐỒ THỊ VÔ HƯỚNG &&  CHU TRÌNH THEO DFS
void dfs( int st ,int en , vector<set<int>> &vt, int mask[] ,vector<int> &ans , int &check)
{
    if(check) return;
    mask[st] = 1;
    ans.push_back(st);
    // if(st == en) {
    //     check = 1;
    //     return;
    // }
    for(auto i : vt[st])
    {
        if(mask[i] == 0)
        {
            dfs(i,st,vt,mask,ans,check);
            if(check) return;
        }
        else{
            if(i != en && i == 1)
            {
                
                check = 1;return;
            }

        }
    }
    //mask[st] = 0;
    ans.pop_back();
}
void dfs_path()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n,e,st,en;
        //cin >> n >>e >> st >> en;
        cin >> n >> e;
        st = 1;
        //vector<vector<int>> vt(1005);
        vector<set<int>> vt(1005);

        int mask[1005] = {};

        for(int i =0;i<e;i++)
        {
            int a,b;
            cin >> a >>b ;
            vt[a].insert(b);
            vt[b].insert(a);

        }
        vector<int> ans;
        int check =0;
        dfs(st,0,vt,mask,ans,check);
        //if(check  == 0) cout << "-1" << endl;
        if(check  == 0) cout << "NO" << endl;
        else{
            for(auto i : ans)
            {
                cout << i  << " ";
            }
            cout << 1;
            cout << endl;
        }


    }
}
            //ĐƯỜNG ĐI THEO DFS VỚI ĐỒ THỊ VÔ HƯỚNG && CHU TRÌNH THEO DFS

            //ĐƯỜNG ĐI THEO BFS TRÊN ĐỒ THỊ VÔ HƯỚNG 
void bfs_path()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n,e,st,en;
        cin >> n >>e >> st >> en;
        vector<vector<int>> vt(1005);
        int mask[1005] = {};

        for(int i =0;i<e;i++)
        {
            int a,b;
            cin >> a >>b ;
            vt[a].push_back(b);
            vt[b].push_back(a);

        }

        int par[1005] = {};
        int check =0;
        queue<int> q;
        q.push(st);
        mask[st] =1 ;
        par[st] = 0;

        while(q.empty() == false)
        {
            int temp = q.front();
            q.pop();
            for(int i =0;i< vt[temp].size();i++)
            {
                if(mask[vt[temp][i]] == 0)
                {
                    mask[vt[temp][i]] = 1;
                    par[vt[temp][i]] = temp;
                    q.push(vt[temp][i]);
                    if(vt[temp][i] == en)
                    {
                        check  =1;
                        break;
                    }
                }
            }
            if(check) break;
        }

        vector<int> ans;
        ans.push_back(en);
        
        if(check  == 0) cout << "-1" << endl;
        else{
            while(par[en] != 0)
            {
                ans.push_back(par[en]);
                en = par[en];
            }
            reverse(ans.begin(),ans.end());
            for(auto i : ans)
            {
                cout << i << " ";
            }
            cout << endl;
        }


    }    
}
            //ĐƯỜNG ĐI THEO BFS TRÊN ĐỒ THỊ VÔ HƯỚNG 

            //ĐẾM SỐ THÀNH PHẦN LIÊN THÔNG && KIỂM TRA TÍNH LIÊN THÔNG MẠNH
void count_connected_part()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n,e;
        cin >> n >>e ;
        vector<vector<int>> vt(1005);
        int mask[1005] = {};

        for(int i =0;i<e;i++)
        {
            int a,b;
            cin >> a >>b ;
            vt[a].push_back(b);
            //vt[b].push_back(a);

        }


        int check =0;
        queue<int> q;


        for(int jj = 1;jj<=n;jj++)
{
            if(mask[jj] == 0)
    {

        q.push(jj);
        mask[jj] =1 ;
        while(q.empty() == false)
        {
            int temp = q.front();
            q.pop();
            for(int i =0;i< vt[temp].size();i++)
            {
                if(mask[vt[temp][i]] == 0)
                {
                    mask[vt[temp][i]] = 1;
                    q.push(vt[temp][i]);
 
                }
            }

        }

        for(int i = 1;i<=n;i++)
        {
            if(mask[i] == 0)
            {
                check = 1;
                break;
            }
            else{
                mask[i] = 0;
            }
        }
        if(check) break;


    }
}


    if(check == 1) cout << "NO" << endl;
    else cout << "YES" << endl;
        



    }
}
            //ĐẾM SỐ THÀNH PHẦN LIÊN THÔNG && KIỂM TRA TÍNH LIÊN THÔNG MẠNH

            //SỐ LƯỢNG HÒN ĐẢO
void count_island()
{
    int tc;cin >>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int h,c;
        cin >> h >> c ;
        int a[600][600]  = {};
        for(int  i=1;i<=h;i++)
        {
            for(int j=1;j<=c;j++)
            {
                cin >> a[i][j];
            }
        }
        int mvh[8] = {-1,-1,-1,0,1,1,1,0};
        int mvc[8] = {-1,0,1,1,1,0,-1,-1};
        int ans = 0;
        for(int i = 1;i<=h;i++)
        {
            for(int j =1;j<=c;j++)
            {
                if(a[i][j] == 1)
                {
                    ans++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    a[i][j] = 0;

                    while(q.empty() == false)
                    {
                        int hh = q.front().first;
                        int cc = q.front().second;
                        q.pop();

                        for(int jj =0;jj<8;jj++)
                        {
                            int x = hh + mvh[jj];
                            int y = cc + mvc[jj];
                            if(a[x][y] == 1)
                            {
                                a[x][y] = 0;
                                q.push({x,y});
                            }
                        }
                    }
                    
                }
            }
        }

        cout << ans << endl;
    }
}
            //SỐ LƯỢNG HÒN ĐẢO

            //KIỂM TRA CHU TRÌNH TRÊN ĐỒ THỊ VÔ HƯỚNG
void is_circle()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n,e;
        cin >> n >>e ;
        vector<vector<int>> vt(1005);
        int mask[1005] = {};

        for(int i =0;i<e;i++)
        {
            int a,b;
            cin >> a >>b ;
            vt[a].push_back(b);
            vt[b].push_back(a);

        }


        int check =0;
        queue<int> q;
        int par[1005] ={};


        for(int jj = 1;jj<=n;jj++)
{
            if(mask[jj] == 0)
    {

        q.push(jj);
        mask[jj] =1 ;
        par[jj] = 0;
        while(q.empty() == false)
        {
            int temp = q.front();
            q.pop();
            for(int i =0;i< vt[temp].size();i++)
            {
                if(mask[vt[temp][i]] == 0)
                {
                    mask[vt[temp][i]] = 1;
                    par[vt[temp][i]] = temp;
                    q.push(vt[temp][i]);
                    
 
                }
                else{
                    if(vt[temp][i] != par[temp])
                    {
                        check = 1;
                        break;
                    }
                }
            }

            if(check) break;   
        }

        if(check) break;


    }
}


    if(check == 0) cout << "NO" << endl;
    else cout << "YES" << endl;
        



    }
}
            //KIỂM TRA CHU TRÌNH TRÊN ĐỒ THỊ VÔ HƯỚNG

            //KIỂM TRA CHU TRÌNH TRÊN ĐỒ THỊ CÓ HƯỚNG
void dfs_check_circle(vector<vector<int>> &vt, int st , int par, int mask[], int &check)
{   
    if(check) return;
    mask[st] = 1;
    for(int i = 0;i<vt[st].size();i++)
    {
        if(mask[vt[st][i]] == 0)
        {
            mask[vt[st][i]] = 1;
            dfs_check_circle(vt,vt[st][i],st,mask,check);

        }
        else{
            if(mask[vt[st][i]] == 1)
            {
                if(vt[st][i] != par)
                {
                    check = 1;
                    return;
                }

            }
        }
    }
    mask[st] = 2;

}   
void is_circle_dfs()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n,e;
        cin >> n >>e ;
        vector<vector<int>> vt(1005);
        int mask[1005] = {};

        for(int i =0;i<e;i++)
        {
            int a,b;
            cin >> a >>b ;
            vt[a].push_back(b);
            //vt[b].push_back(a);

        }
        int check =0;
        for(int i=1;i<=n;i++)
        {
            if(mask[i] == 0)
            {
                dfs_check_circle(vt,i,0,mask,check);
                if(check) break;
            }
        }
        if(check) cout << "YES" << endl;
        else cout << "NO" << endl;



    }

}
            //KIỂM TRA CHU TRÌNH TRÊN ĐỒ THỊ CÓ HƯỚNG

            //KIỂM TRA ĐỒ THỊ CÓ PHẢI LÀ CÂY HAY KHÔNG
void is_tree()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n,e;
        cin >> n ;
        vector<vector<int>> vt(1005);
        int mask[1005] = {};

        for(int i =0;i<n-1;i++)
        {
            int a,b;
            cin >> a >>b ;
            vt[a].push_back(b);
            vt[b].push_back(a);

        }


        int check =0;
        queue<int> q;
        int par[1005] ={};



        q.push(1);
        mask[1] =1 ;
        par[1] = 0;
        while(q.empty() == false)
        {
            int temp = q.front();
            q.pop();
            for(int i =0;i< vt[temp].size();i++)
            {
                if(mask[vt[temp][i]] == 0)
                {
                    mask[vt[temp][i]] = 1;
                    par[vt[temp][i]] = temp;
                    q.push(vt[temp][i]);
                    
 
                }
                else{
                    if(vt[temp][i] != par[temp])
                    {
                        check = 1;
                        break;
                    }
                }
            }

            if(check) break;   
        }

        for(int i =1;i<=n;i++)
        {
            if(mask[i] == 0)
            {
                check = 1;
                break;
            }
        }




    if(check == 1) cout << "NO" << endl;
    else cout << "YES" << endl;
        



    }   
}
            //KIỂM TRA ĐỒ THỊ CÓ PHẢI LÀ CÂY HAY KHÔNG

            //TÔ MÀU ĐỒ THỊ && ĐỒ THỊ HAI PHÍA
void paint_graph_dfs(int st, vector<vector<int>> &vt, int mask[], int color, int mask1[])
{
    mask1[st] = 1;
    int pnt = 0;
    for(int i =0;i<vt[st].size();i++)
    {
        if(mask[vt[st][i]] == color)
        {
            pnt = 1;
            break;
        }
    }
    if(pnt == 0 && mask[st] == 0)  mask[st] = color;
    for(int i=0;i<vt[st].size();i++)
    {
        if(mask1[vt[st][i]] == 0 )
        {
            paint_graph_dfs(vt[st][i],vt,mask,color,mask1);
        }
    }
}
void paint_graph()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n,e, m;
        //cin >> n >>e >> m;    //TÔ MÀU ĐỒ THỊ
        cin >> n >>e ;  // ĐỒ THỊ HAI PHÍA
        m = 2;          // ĐỒ THỊ HAI PHÍA
        vector<vector<int>> vt(1005);
        int mask[1005] = {};
        int mask1[1005] = {};

        for(int i =0;i<e;i++)
        {
            int a,b;
            cin >> a >>b ;
            vt[a].push_back(b);
            vt[b].push_back(a);

        }
        int color = 0;
        int check =0;
        for(int i =1;i<=n;i++)
        {
            if(mask[i] == 0)
            {
                color++;
                if(color > m)
                {
                    check = 1;break;
                }

                for(int jj=i;jj<=n;jj++)
                {
                    if(mask1[jj] == 0)
                    {
                        paint_graph_dfs(jj,vt,mask,color,mask1);
                    }
                }



                for(int j=0;j<1005;j++)
                {
                    mask1[j] = 0;
                }



            }
        }
        if(check == 1)
        cout << "NO" << endl;
        else
        cout << "YES" << endl;



    }    
}
            //TÔ MÀU ĐỒ THỊ && ĐỒ THỊ HAI PHÍA

            //ĐƯỜNG ĐI HAMILTON
            // luu y day la bai toan tim con duong dai nhat giua hai diem chu k phai tim
            // khoang cach xa nhat(khach quan) giua 2 diem nen k the su dung bfs double hoac dfs double.
            // Vi vay phai xet duong di tu tung diem de tim ra con duong dai nhat
void hamilton_dfs1(int st, vector<vector<int>> &vt, int mask[], int &x, int &max, int cnt, int &check, int n)
{
    if(check) return;
    // if(cnt > max)
    // {
    //     max = cnt;
    //     x = st;
    // }
    if(cnt == n-1)
    {
        check = 1;return;
    }
    mask[st] = 1;
    for(int i=0;i<vt[st].size();i++)
    {
        if(mask[vt[st][i]] == 0)
        {
            hamilton_dfs1(vt[st][i],vt,mask,x,max,cnt+1,check,n);
        }
    }
    mask[st] = 0;
}



void hamilton()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n,e, m;
        cin >> n >>e ;
        vector<vector<int>> vt(1005);
        int mask[1005] = {};
        int mask1[1005] = {};

        for(int i =0;i<e;i++)
        {
            int a,b;
            cin >> a >>b ;
            vt[a].push_back(b);
            vt[b].push_back(a);

        }
        int max = 0;
        int check = 0;
        int x = 0;
        // hamilton_dfs1(1,vt,mask,x,max,0,check,n);
        // //cout << " x =  " << x  << endl;
        // hamilton_dfs1(x,vt,mask,x,max,0,check,n);

        for(int i =1;i<=n;i++)
        {
            if(mask[i] == 0)
            {
                hamilton_dfs1(i,vt,mask,x,max,0,check,n);
                if(check) break;
            }
        }

        if(check) cout << 1 << endl;
        else cout << 0 << endl;



    }   
}
            //ĐƯỜNG ĐI HAMILTON



int main()
{
    
    return 0;

}