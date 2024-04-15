#include<bits/stdc++.h>
using namespace std;

            //EASUDOKU - Easy sudoku
bool check_sudoku(int h, int c, int a[][20])
{
    for(int i=1;i<=9;i++)
    {
        if(a[h][i] == a[h][c] && i !=c)
            return false;
        if(a[i][c] == a[h][c] && i !=h)
            return false;
    }
    return true;
}

bool check_block_3x3(int x, int y, int a[][20])
{
	int start_x = (x-1)/3;
	int start_y = (y-1)/3;
	int i=start_x*3+1, end_x = i+3, j = start_y*3+1, end_y = j+3;
	for(i=start_x*3+1; i<end_x; i++)
		for(j = start_y*3+1; j<end_y; j++)
			if(a[x][y]==a[i][j] && i!=x && j!=y)return 0;
	return 1;
}
void sudoku_recursive(int &check, int a[][20], int mask[][20], int n,int h, int c)
{
    if(check) return;
    if(h >= 10)
    {
        check = 1;
        return;
    }
    else{
        for(int i=9;i>=1;i--)
        {
            if(check == 0)
            {
            a[h][c] = i;
            if(check_sudoku(h,c,a) ==true && check_block_3x3(h,c,a) == true)
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
        int h,c;
        if(vt.empty() == false)
        {
         h = vt[0].first;
         c = vt[0].second;
        }
        else
        {
            h =10;
            c= 1;
        }

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

            //MKJUMPS - Making Jumps
int move_h[8] ={-1,-2,-2,-1,1,2,2,1};
int move_c[8] ={-2,-1,1,2,2,1,-1,-2};
void making_jumps_recursive(int a[][20], int h, int c, int cnt, int &max)
{
    if(max<cnt)
    {
       max =cnt; 
    }

        for(int i =0;i<8;i++)
        {
            int hh = h+move_h[i];
            int cc = c+move_c[i];
            if(a[hh][cc] == 1 )
            {
                a[hh][cc] = 2;
                making_jumps_recursive(a,hh,cc, cnt+1,max);
                a[hh][cc] = 1;
            }
        }
    }

void making_jumps()
{
    int tc =0;
    while(1)
    {
        tc++;
        int n;cin >>n;
        if(n == 0) break;
        int a[20][20] = {0};
        int mask[20][20] = {0};
        pair<int,int> st;
        int sum = 0;
        for(int i = 1;i<=n;i++)
        {
            int aa,b;
            cin >> aa>> b;
            sum +=b;
            if(i == 1)
            {
                st.first = 1;
                st.second = aa+1;
            }
            for(int j = aa+1;j<aa+1+b;j++)
            {
                a[i][j] = 1;
            }
        }



        a[st.first][st.second] = 2;
        mask[st.first][st.second] =1;
        int max = 1;
        making_jumps_recursive(a,st.first,st.second,1,max);
        int cnt = sum - max;
        if(cnt != 1)
        cout <<     "Case " << tc <<", " << cnt << " squares can not be reached." <<endl;
        else
        cout <<     "Case " << tc <<", " << cnt << " square can not be reached." <<endl;        
    }
}
            //MKJUMPS - Making Jumps 

            //Dijkstra

            //Dijkstra

            //MICEMAZE - Mice and Maze 
void mice_maze()
{
    int a[200][200] = {0};
    int mask[200] = {0};
    vector<int> d(200,1000000000);
    //memset(d,1000000000,sizeof(d));

    vector<vector<int>> vt(200);
    int n, e, t,m;
    cin >> n>>e>>t>>m;
    for(int i=0;i<m;i++)
    {
        int x, y,z;
        cin >> x >>y >>z;
        vt[y].push_back(x);
        a[y][x] = z;

    }
    d[e] = 0;
    multiset<pair<int,int>> s;
    s.insert({0,e});

    while(s.empty() == false)
    {
        auto aa = s.begin();
        int tg = (*aa).second;
        s.erase(s.begin());
        if(mask[tg] == 0)
        for(auto i : vt[tg])
        {
            //cout << tg << ">>" << i<<endl;
            int temp = d[tg] + a[tg][i];
            //cout << temp << endl;
            //cout << d[i] << endl;
            d[i] = min(d[i],temp);
            //cout << d[i] << endl;
            s.insert({d[i],i});
        }
        mask[tg] = 1;
    }
    int cnt = 0;
    for(int i= 1;i<=n;i++)
    {
        //cout << d[i] <<" ";
        if(d[i] <= t)
            cnt++;
    }
    cout << cnt << endl;
    


}
            //MICEMAZE - Mice and Maze 

            //SPIKES - Spiky Mazes
int spike_mv_h[4] = {-1,0,1,0};
int spike_mv_c[4] = {0,1,0,-1};
void spike_recursive(char a[][50],int check, int h, int c, int mask[][50], int av, int &rcheck)
{
    if(av == -1) return;
    if(rcheck == 1)
    {
        return;

    }
    else
    {
        for(int i=0;i<4;i++)
        {
            int hh = h+ spike_mv_h[i];
            int cc = c+ spike_mv_c[i];
            if(a[hh][cc] != '#' && a[hh][cc] != 0 && mask[hh][cc] == 0 && rcheck != 1)
            {
                if(a[hh][cc] == 's')
                {
                    mask[hh][cc] = 1;
                    spike_recursive(a,check,hh,cc,mask,av-1,rcheck);
                    mask[hh][cc] = 0;
                }
                else if(a[hh][cc] == '.')
                {
                    mask[hh][cc] = 1;
                    spike_recursive(a,check,hh,cc,mask,av,rcheck);
                    mask[hh][cc] = 0;                    
                }
                else if(a[hh][cc] == 'x')
                {

                    for(int r=0;r<50;r++)
                    {
                        for(int c =0 ;c<50;c++)
                            mask[r][c] = 0;
                    }
                    mask[hh][cc] = 1;
                    check =1;
                    spike_recursive(a,check,hh,cc,mask,av,rcheck);
                    //cout << "av : " << av <<endl;
                    //cout << "check : " << check << endl;
                 
                }
                else if(a[hh][cc] == '@')
                {
                    if(check == 1 && av >= 0)
                        {
                            rcheck = 1;
                            //cout << "av : " << av << endl;
                            return;
                        }
                    else{
                        return;
                    }                  
                }
            }
        }
    }
}
void spike()
{
    int h,c,av;
    cin >> h >>c >>av;
    char a[50][50] = {};

    vector<pair<int,int>> vt;
    for(int i =1;i<=h;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cin >> a[i][j];
            if(a[i][j] == '@')
            {
                vt.push_back({i,j});
            }
        }
    }
            int check =0;
    for(auto i : vt)
    {
        check = 0;
        int mask[50][50] = {};
        mask[i.first][i.second] = 1;
        spike_recursive(a,0,i.first,i.second,mask,av,check);
        if(check == 1) break;
    }
    if(check ==1) cout <<"SUCCESS" << endl;
    else
    cout << "IMPOSSIBLE" <<endl;




}
            //SPIKES - Spiky Mazes

            //VONNY - Vonny and her dominos
int domino_mv_h[2] ={0,1};
int domino_mv_c[2] ={1,0};
void domino_recursive(int h, int c, int a[][10], int mask[][10], int bone[][10], int cnt, int &check)
{
    //cout << "cnt " << cnt <<endl;
    if(h == 8)
    {
        //if(cnt == 28 )
        check++;
        return;
    }
    else{

        mask[h][c] = 1;

        for(int i=0;i<2;i++)
        {
            int hh = h + domino_mv_h[i];
            int cc = c + domino_mv_c[i];
            if(a[hh][cc] != -1 && mask[hh][cc] == 0)
            {
                int f,s;
                if(a[hh][cc] <= a[h][c])
                {
                    f = a[hh][cc];
                    s = a[h][c];
                }
                else
                {
                    f = a[h][c];
                    s = a[hh][cc];

                }
                if(bone[f][s] == 1)
                {
                    bone[f][s] =0;
                    mask[hh][cc] = 1;

                    int r  = h, cl =c;
                    if(mask[h][c] == 1)
                    {
                        while(mask[r][cl] == 1)
                        {
                            cl++;
                            if(cl==9)
                            {
                                r++;
                                cl=1;
                            }    
                        }
                    }
                    domino_recursive(r,cl,a,mask,bone,cnt+1,check);
                    mask[hh][cc] = 0;
                    bone[f][s] = 1;

                }
            }

            
        }
        mask[h][c] =0;

    }
}
void domino()
{

    int tc;cin >>tc;
    for(int ii=0;ii<tc;ii++)
    {
        int a[10][10];
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
                a[i][j] = -1;
        }
        int mask[10][10] = {};
        int bone[10][10] = {};
        for(int i= 0;i<=6;i++)
        {  
            for(int j =i;j<=6;j++)
            {
                bone[i][j] = 1;
            }
        }
        for(int i = 1;i<=7;i++)
        {
            for(int j =1;j<=8;j++)
            {
                cin >> a[i][j];
            }
        }
        int check = 0;
        domino_recursive(1,1,a,mask,bone,0,check);
        cout << check << endl;




    }
}
            //VONNY - Vonny and her dominos

            //EZSUDOKU - Easy modified sudoku
bool check_r_c(int h, int c, int a[][10])
{
    for(int i =1;i<=8;i++)
    {
        if(a[h][i] == a[h][c] &&  i!=c)
            return 0;
        if(a[i][c] == a[h][c] &&  i!=h)
            return 0;
    }
    return 1;
}
bool check_r_c_f(int h, int c, int a[][10])
{
    int cnt_h[9] = {};
    int cnt_c[9] = {};
    for(int i =1;i<=8;i++)
    {
        cnt_h[a[h][i]]++;
        if(cnt_h[a[h][i]] == 2 && a[h][i] !=0 ) return 0;
        cnt_c[a[i][c]]++;
        if(cnt_c[a[i][c]] == 2 && a[i][c] !=0 ) return 0;
    }
    return 1;
}

bool check_full(int a[][10])
{
    for(int i =1;i<=8;i++)
    {
        if(check_r_c_f(i,i,a) == 0) return 0;
    }
    return 1;
}
bool check_4x4(int h, int c , int a[][10])
{
    int x = (h-1)/4;
    int y = (c-1)/4;
    int stx = x*4+1;
    int ex = x*4+1+4;
    int sty = y*4+1;
    int ey = y*4 +1 +4;
    int cnt = 0;
    for(stx = x*4+1;stx<ex;stx++)
    {
        for(sty = y*4+1;sty<ey;sty++)
        {
            if(a[h][c] == a[stx][sty] && h != stx && c != sty)
            {
                cnt++;
                if(cnt == 2)
                    return 0;
            }
        }
    }
    return 1;
}


bool check_4x4_f(int h,int c,int a[][10])
{
    int x = (h-1)/4;
    int y = (c-1)/4;
    int stx = x*4+1;
    int ex = x*4+1+4;
    int sty = y*4+1;
    int ey = y*4 +1 +4;
    int cnt[9] = {};
    for(stx = x*4+1;stx<ex;stx++)
    {
        for(sty = y*4+1;sty<ey;sty++)
        {
            cnt[a[stx][sty]]++;
            if(cnt[a[stx][sty]] == 3 && a[stx][sty] != 0) return 0;
        }
    }
    return 1;
}
void ez_mod_su_recursive(int &check,int index,int n,vector<pair<int,int>> &vt,int a[][10], int mask[][10], int h ,int c)
{
    if(index == n)
    {
        check =1;
        return;
    }
    else{
        for(int i=1;i<=8;i++)
        {
            if(check !=1)
            {
                int hh = vt[index].first;
                int cc = vt[index].second;
                a[hh][cc] = i;
                if(check_4x4(hh,cc,a) && check_r_c(hh,cc,a) )
                {
                    //cout << hh << " " <<cc <<endl;
                    ez_mod_su_recursive(check,index+1,n,vt,a,mask,h,c);

                }
                if(check == 1) return;
                a[hh][cc] =0;
            }

        }
    }
}
void ez_mod_sudoku()

{
    int tc;cin>>tc;
    for(int ii=0;ii<tc;ii++)
    {
        int a[10][10];
        int mask[10][10] ={};
        vector<pair<int,int>> vt;
        int n =0;
        for(int i =1;i<=8;i++)
        {
            for(int j=1;j<=8;j++)
            {   
                cin >> a[i][j];
                if(a[i][j] == 0)
                {
                    vt.push_back({i,j});
                    n++;
                }
            }
        }
        int check =0;
        if( check_full(a) &&check_4x4_f(1,1,a) && check_4x4_f(5,5,a) && check_4x4_f(1,5,a) && check_4x4_f(5,1,a))
        {
        if(vt.empty() == false)
        ez_mod_su_recursive(check,0,n,vt,a,mask,0,0);
        }

        cout << "Test case #" << ii+1 <<": " ;
        if(check)
        {
            cout << "YES" << endl;
            for(int i=1;i<=8;i++)
            {
                for(int j=1;j<=8;j++)
                    cout << a[i][j] << " ";
                    cout << endl;
            }
        }
        else
        cout <<"NO" <<endl;
    }
}
            //EZSUDOKU - Easy modified sudoku

int main()
{
    //multimap<pair<int,int>, int> ms;

    ez_mod_sudoku();
    return 0;

}