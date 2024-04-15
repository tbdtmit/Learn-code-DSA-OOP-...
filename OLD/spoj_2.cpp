#include<iostream>
using namespace std;

            //QUE1E - Queue Rookie (Easy)
void queue_rookie()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n;cin >> n;
        int tall[1005] = {};
        int ahead[1005] = {};
        int count[1005] = {};
        for(int i =1;i<=n;i++)
        {
            cin >> tall[i];
            count[tall[i]]++;
        }
        for(int i =1;i<=n;i++)
        {
            cin >> ahead[i];
        }

        for(int i =1;i<=n;i++)
        {
            int min = tall[i];
            int index = i;
            int min1 = ahead[i];
    
            for(int j = i;j<=n;j++)
            {
                if(tall[j] < min)
                {
                    min = tall[j];
                    min1  = ahead[j];
                    index = j;

                }
                else if(tall[j] == min)
                {
                    if(ahead[j] < min1)
                    {
                        min1 = ahead[j];
                        index = j;
                    }
                }
            }
            int temp = tall[index];
            tall[index] = tall[i];
            tall[i] = temp;
            temp = ahead[index];
            ahead[index] = ahead[i];
            ahead[i] = temp;
        }
        // for(int i=1;i<=n;i++)
        // {
        //     cout << tall[i] << " " <<ahead[i] <<endl;
        // }
        int mask[1005] = {};
        int ans[1005] = {};

        for(int i=1;i<=n;i++)
        {
            int cnt = 0;
            int t = ahead[i];

            int j = 1;
            for(int jj =1;jj<=n;jj++)
            {
                if(cnt == t && ans[jj] == 0)
                {

                    j =jj;
                    break;
                }
                if(ans[jj] == 0)
                {
                    cnt++;
                }
            }
            ans[j] = tall[i];


        }
        for(int i =1;i<=n;i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;


    }
}
            //QUE1E - Queue Rookie (Easy)

            //PROB02 - Hệ thống phân tích rèm cửa
void ptdc()
{
    int tc;
    cin >>  tc;
    for(int ii=0;ii<tc;ii++)
    {
        int h,c;
        cin >> h >> c;
        char a[700][700] = {};
        int hh = h*5+1;
        int cc = c*5+1;

        for(int i =0;i<hh;i++)
        {
            for(int j=0;j<cc;j++)
            {
                cin >> a[i][j];
            }
        }
        
        int ans[6] = {};
        for(int i = 1;i<=h;i++)
        {
            for(int j =1;j<=c;j++)
            {
                int cnt = 0;
                int x = 5*i-4;
                int y = 5*j-4;
                while(a[x][y] == '*')
                {
                    cnt++;
                    x++;
                }
                ans[cnt]++;
            }
        }

        cout << "#" << ii+1<<" ";
        for(int i=0;i<5;i++)
        {
            cout << ans[i] << " ";

        }
        cout << endl;
    }
}
            //PROB02 - Hệ thống phân tích rèm cửa

            //SLTKNGHT - Quân mã được chọn
int map_chess[1005][1005] = {};
pair<int,int> kn[1000005];
void selected_knight()
{
    int tc ; cin >> tc;
    for(int ii=0;ii<tc;ii++)
    {

        int n, k, pa, un;
        cin >> n >> k>>pa>>un;
        
        for(int i = 0;i<k;i++)
        {
            int x,y;
            cin >> x>> y;
            map_chess[x][y] = 2;
            kn[i] = {x,y};
        
        }
        for(int i = 0;i<pa;i++)
        {
            int x,y;
            cin >> x>> y;
            map_chess[x][y] = 1;
        
        }
        for(int i = 0;i<un;i++)
        {
            int x,y;
            cin >> x>> y;
            map_chess[x][y] = 0;
        
        }
        int mvh[8] = {-1,-2,-2,-1,1,2,2,1};
        int mvc[8] = {-2,-1,1,2,2,1,-1,-2};
        int max =0;
        int xx,yy;
        for(int ij=0;ij<k;ij++)
        {
            int  i = kn[ij].first;
            int  j = kn[ij].second;
                    int cnt = 0;
                    for(int jj=0;jj<8;jj++)
                    {
                        int hh = i + mvh[jj];
                        int cc = j + mvc[jj];
                        if(hh>=0 && hh<n && cc>=0 && cc < n && map_chess[hh][cc] != 0)
                        {
                            cnt++;
                        }
                    }
                    if(cnt > max)
                    {
                        xx =i;
                        yy =j;
                        max = cnt;
                    }            
        }

                




        cout << "#" << ii+1 << " " << xx << " " << yy << " " << max << endl;
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                map_chess[i][j] = 0;
            }
        }
    }
}



int main()
{
    selected_knight();
    return 0;
}