#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

            //QUEUE
class my_queue{

    int front = -1;
    int rear = -1;
    ll *a = new ll[1000000];
    public:

    void push(ll a);
    ll pop();
    bool is_empty();
    int show_front();
    int show_rear();
    ~my_queue()
    {
        delete[] a;
    }
};

void my_queue :: push(ll z)
{
    a[++rear] = z;
}
ll my_queue :: pop()
{
    ll z = a[front+1];
    front++;
    return z;
}
bool my_queue :: is_empty()
{
    if(rear == front) return true;
    return false;
}
int my_queue :: show_rear()
{
    return rear;
}
int my_queue :: show_front()
{
    return front;
}

            //QUEUE

            //STACK
class my_stack{
    int *a = new int[1000005];
    int top = 0;
    public:
    bool is_empty();
    int pop();
    void push(int t);
    int show_top();
    ~my_stack()
    {
        delete[] a;
    }

};


bool my_stack :: is_empty()
{
    if(top == 0) return true;
    return false;
}

int my_stack :: pop()
{
    int z = a[top];
    top--;
    return z;
}

void my_stack :: push(int z)
{
    a[++top] = z;
}

int my_stack :: show_top()
{
    return top;
}
            //STACK

            //PHẦN TỬ BÊN PHẢI ĐẦU TIÊN LỚN HƠN
void ptbpdtlh()
{
    int tc;cin>>tc;
    for(int ii=0;ii<tc;ii++)
    {
        int n;cin>>n;
        int a[100005] = {-1};
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        for(int i=0;i<n;i++)
        {
            int check = 0;
            for(int j=i+1;j<n;j++)
            {
                if(a[j] > a[i])
                {
                    check =1;
                    cout<< a[j] << " ";break;
                }

                
            }
            if(check == 0) cout << "-1" <<" ";
        }
        cout << endl;
    }   
}
            //PHẦN TỬ BÊN PHẢI ĐẦU TIÊN LỚN HƠN

            //KIỂM TRA DÃY NGOẶC ĐÚNG
void ktdnd()
{
    int tc;cin >> tc;
    for(int ii=0;ii<tc;ii++)
    {
        string s;cin >> s;
        my_stack st;
        int check = 0;
        for(int i =0;i<s.length();i++)
        {
            if( s[i] == '{' || s[i] == '[' || s[i] == '(')
            {
                st.push(s[i]);

            }
            else if(s[i] == '}')
            {
                if(st.pop() != '{')
                {
                    cout << "NO" <<endl;check=1;break;
                }
            }
            else if(s[i] == ']')
            {
                if(st.pop() != '[')
                {
                    cout << "NO" <<endl;check=1;break;
                }
            }
            else if(s[i] == ')')
            {
                if(st.pop() != '(')
                {
                    cout << "NO" <<endl;check =1;break;
                }
            }
        }
        if(check == 0) cout << "YES" << endl;
    }
}
            //KIỂM TRA DÃY NGOẶC ĐÚNG

            //CẤU TRÚC DỮ LIỆU HÀNG ĐỢI 1
void queue1()
{
    int tc;cin >> tc;
    for(int ii=0;ii<tc;ii++)
    {
        int n;cin >> n;
        queue<int> q;
        for(int i =0;i<n;i++)
        {
            int a;cin >> a;
            if(a==1)
            {
                cout << q.size()<<endl;
            }
            else if(a==2)
            {
                if(q.empty()) cout << "YES" <<endl;
                else cout << "NO" << endl;
            }
            else if(a==3)
            {
                int t;cin >> t;
                q.push(t);
            }
            else if(a==4)
            {
                if(q.empty());
                else{
                    q.pop();
                }
            }
            else if(a==5)
            {
                if(q.empty()) cout << "-1" <<endl;
                else cout << q.front() <<endl;
            }
            else
            {
                if(q.empty()) cout << "-1" <<endl;
                else cout << q.back() <<endl;                
            }
        }
    }
}
            //CẤU TRÚC DỮ LIỆU HÀNG ĐỢI 1 

            //CẤU TRÚC DỮ LIỆU HÀNG ĐỢI 2
void queue2()
{

        int n;cin >> n;
        queue<int> q;
        for(int i =0;i<n;i++)
        {
            string a;cin >> a;
            if(a=="PUSH")
            {
                int t;cin >> t;
                q.push(t);
            }
            else if(a=="POP")
            {
                if(q.empty());
                else{
                    q.pop();
                }
            }
            else if(a=="PRINTFRONT")
            {
                if(q.empty()) cout << "NONE" <<endl;
                else cout << q.front() <<endl;
            }
            else
            {
                if(q.empty()) cout << "-1" <<endl;
                else cout << q.back() <<endl;                
            }
        }
}

            //CẤU TRÚC DỮ LIỆU HÀNG ĐỢI 2

            //HÀNG ĐỢI HAI ĐẦU (DEQUEUE)
void dequeue1()
{

        int n;cin >> n;
        deque<int> q;

        for(int i =0;i<n;i++)
        {
            string a;cin >> a;
            if(a=="PUSHFRONT")
            {
                int t;cin >> t;
                q.push_front(t);
            }
            else if(a== "PRINTFRONT")
            {
                if(q.empty()) cout << "NONE"<<endl;
                else{
                    cout << q.front() << endl;
                }
            }
            else if(a=="POPFRONT")
            {
                if(q.empty());
                else{
                    q.pop_front();
                }
            }
            else if(a=="PUSHBACK")
            {
                int t;cin >> t;
                q.push_back(t);
            }
            else if(a== "PRINTBACK")
            {
                if(q.empty()) cout << "NONE"<<endl;
                else{
                    cout << q.back() << endl;
                }
            }
            else if(a=="POPBACK")
            {
                if(q.empty());
                else{
                    q.pop_back();
                }
            }

        }
}
            //HÀNG ĐỢI HAI ĐẦU (DEQUEUE)

            //SỐ 0 VÀ SỐ 9
void so0va9()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n;cin >> n;
        queue<int>  q;
        q.push(9);
        int check =0;
        while(1)
        {
            int t =q.size();
            for(int i =0;i<t;i++)
            {
                int temp = q.front();
                q.pop();
                if(temp%n != 0)
                {
                    q.push(temp*10);
                    q.push(temp*10+9);
                }
                else
                {
                    check =1;
                    cout << temp << endl; break;
                }
            }
            if(check) break;
        }

    }
}
            //SỐ 0 VÀ SỐ 9

            //SỐ BDN 1
void bdn1()
{
    int tc;cin >>tc;
    for(int ii =0;ii<tc;ii++)
    {
        ull n;cin >> n;
        queue<ull> q;
        q.push(1);
        bool check =0;
        int cnt = 1;
        while(1)
        {
            int sz = q.size();
            for(int i =0;i<sz;i++)
            {
                ull temp = q.front();
                q.pop();
                for(int j =0;j<=1;j++)
                {
                    if(temp*10+j <= n)
                    {
                        cnt++;
                        q.push(temp*10+j);
                    }
                    else{
                        check = 1;break;
                    }
                }
                if(check ) break;
            }
            if(check) break;
        }
        cout << cnt << endl;
    }
}
            //SỐ BDN 1

            //SỐ BDN 2
void bdn2()
{
    int tc;cin >>tc;
    for(int ii =0;ii<tc;ii++)
    {
        ull n;cin >> n;
        queue<ull> q;
        q.push(1);
        bool check =0;
        while(1)
        {
            int sz = q.size();
            for(int i =0;i<sz;i++)
            {
                ull temp = q.front();
                q.pop();
                if(temp%n == 0)
                {
                    check =1;
                    cout<<temp <<endl;break;
                }
                for(int j =0;j<=1;j++)
                {

                    q.push(temp*10+j);

                }
                if(check ) break;
            }
            if(check) break;
        }
    }
}
            //SỐ BDN 2

            //SỐ LỘC PHÁT 1
void slp_recursive1(string s, int n)
{
    if(s.length() == n)
    {
        cout << s << " ";
        return;
    }
    else{
        for(int i = 8;i>=6;i-=2)
        {
            slp_recursive1(s+char(i+'0') ,n );
        }
        //cout << s << " " ;
    }

    if(s == "" && n >0)
    {
        slp_recursive1(s,n-1);
    }

}

void slp_recursive2(string s, int n, int max)
{
    if(s.length() == n)
    {

        cout << s << " ";
        return;
    }
    else{
        for(int i = 6;i<=8;i+=2)
        {
            slp_recursive2(s+char(i+'0') ,n,max );
        }
        //cout << s << " " ;
    }

    if(s == "" && n <max)
    {
        slp_recursive2(s,n+1,max);
    }

}
void slp()

{
    int tc;cin >> tc;
    for(int  ii =0;ii<tc;ii++)
    {
        int n;cin >>n;
        int cnt =0;
        for(int i =1;i<=n;i++)
        {
            cnt += pow(2,i);
        }
        cout << cnt <<endl;
        slp_recursive1("",n);
        cout << endl;
    }
}            
            //SỐ LỘC PHÁT 1

            //DI CHUYỂN TRONG MA TRẬN
int map_maze[1005][1005];
int map_maze_mask[1005][1005] = {-1};

void move_in_maze()
{
    int tc;cin>>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int m,n;cin>>m>>n;
        for(int i =0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                cin >> map_maze[i][j];
                map_maze_mask[i][j] = -1;

            }
        }
        queue<pair<int, int>> q;
        q.push({0,0});
        int cnt = 0;
        bool check =0;
        while(q.empty() == false)
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                int h = q.front().first;
                int c = q.front().second;
                q.pop();
                if(h == m-1&&c==n-1)
                {
                    cout << cnt <<endl;
                    check =1;break;
                }
                if(map_maze[h][c] + h <= m-1 && map_maze_mask[map_maze[h][c] + h ][c] != ii)
                {
                    q.push({map_maze[h][c] + h,c});
                    map_maze_mask[map_maze[h][c] + h ][c] = ii;
                }
                if(map_maze[h][c] + c <= n-1 && map_maze_mask[h][map_maze[h][c] + c] != ii)
                {
                    q.push({h,map_maze[h][c] + c});
                    map_maze_mask[h][map_maze[h][c] + c] = ii;
                }
            }
            if(check) break;
            cnt++;
        }
        if(check ==0)cout <<"-1" <<endl;
    }
}
            //DI CHUYỂN TRONG MA TRẬN

            //CHUYỂN DANH SÁCH CẠNH SANG DANH SÁCH KỀ
void covert_to_dsk()
{
    int tc;cin>>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int d, c;
        cin >> d>>c;
        multimap<int, int> mp;
        for(int i=0;i<c;i++)
        {
            int a,b;
            cin >> a>>b;
            map_maze_mask[a][b] = 1;
            map_maze_mask[b][a] = 1;
        }
        for(int i= 1;i<=d;i++)
        {
            cout << i << ": ";
            for(int j =1;j<=d;j++)
            {
                if(map_maze_mask[i][j] == 1)
                cout << j <<" ";
                map_maze_mask[i][j] =0;


            }
            cout << endl;
        }
    }
}
            // /CHUYỂN DANH SÁCH CẠNH SANG DANH SÁCH KỀ

            //CHUYỂN TỪ DANH SÁCH KỀ SANG DANH SÁCH CẠNH UN AC
void covert_to_dsc()
{

        int d;
        cin >> d;
        cin.ignore();
        vector<set<int>> vt(1005);
        for(int i=1;i<=d;i++)
        {
            string s;
            getline(cin,s);
            stringstream ss(s);
            while(ss >> s)
            {
                int temp = atoi(s.c_str());
                vt[i].insert(temp);

            }


        }
            for(int i =1;i<=d;i++)
            {
                for(auto j : vt[i])
                {
                    cout << i << " "<< j << endl;
                    vt[j].erase(i);
                }
            }

    }

            //CHUYỂN TỪ DANH SÁCH KỀ SANG DANH SÁCH CẠNH UN AC

            //BIỂU DIỄN ĐỒ THỊ CÓ HƯỚNG.
void covert_to_dtch()
{
    int tc;cin>>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int d, c;
        cin >> d>>c;
        for(int i=0;i<c;i++)
        {
            int a,b;
            cin >> a>>b;
            map_maze_mask[a][b] = 1;
        }
        for(int i= 1;i<=d;i++)
        {
            cout << i << ": ";
            for(int j =1;j<=d;j++)
            {
                if(map_maze_mask[i][j] == 1)
                cout << j <<" ";
                map_maze_mask[i][j] =0;


            }
            cout << endl;
        }
    }
}

            //BIỂU DIỄN ĐỒ THỊ CÓ HƯỚNG.

            //DFS &&  BFS
void dfs_recursive(int start, vector<vector<int>> &vt, int mask[])
{


                mask[start] = 1;
                cout << start<< " ";
                for(int i=0;i<vt[start].size();i++)
                {
                    if(mask[vt[start][i]] == 0)
                    {
                        dfs_recursive(vt[start][i],vt, mask);
                        //mask[i] = 0;
                    }

                }

            
        
}

void dfs_find(int start, vector<vector<int>> &vt, int mask[],int end,  string s, int &check)
{



                mask[start] = 1;
                s = s+ to_string(start) + " ";
                for(int i=0;i<vt[start].size();i++)
                {
                    if(mask[vt[start][i]] == 0)
                    {
                        dfs_find(vt[start][i],vt, mask,end,s,check);
                        //mask[i] = 0;
                    }

                }

    if(start == end && check == 0)
    {
        check = 1;
        cout << s;
        return;
    }              

            
        
}
void bbfs_recursive( vector<vector<int>> &vt, int mask[],int d) // fail
{

        for(int i=1;i<=d;i++)
        {
            if(mask[i] == 1)
            {
            cout << i <<" ";
            mask[i] = 2;
            }

        }
        for(int i =1;i<=d;i++)
        {
            if(mask[i] == 2)
            {
                mask[i] = 3;
                for(int j=0;j<vt[i].size();j++)
                {
                    if(mask[vt[i][j]] == 0)
                    {
                        mask[vt[i][j]] = 1;
                        //mask[i] = 0;
                    }

                }

            }
        }
        for(int i =1;i<=d;i++)
        {
            if(mask[i] != 3)
                    bbfs_recursive(vt,mask,d);
        }





            
        
}


void dfs()
{
    int tc;cin>>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int d, c , start,end;
        cin >> d>>c >> start>> end;
        vector<vector<int>> vt(1005);
        for(int i=0;i<c;i++)
        {
            int a,b;
            cin >> a>>b;
            vt[a].push_back(b) ;
            //vt[b].push_back(a);
        }     
        int mask[1005] ={0}; 
        //mask[start] = 1; 
        //dfs_recursive( vt,mask,d);
        int check =0;
        dfs_find(start,vt,mask,end,"",check);
        if(check == 0) cout << "-1";
        cout << endl;


    } 
}

void bfs()
{
    int tc;cin>>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int d, c , start;
        cin >> d>>c >> start;
        vector<vector<int>> vt(1005);
        for(int i=0;i<c;i++)
        {
            int a,b;
            cin >> a>>b;
            vt[a].push_back(b) ;
            //vt[b].push_back(a) ;
        } 
            int mask[1005] ={0};
            mask[start] =1;
            queue<int> q;
            q.push(start);
            while(q.empty() == false)
            {
                int sz = q.size();
                for(int i=0;i<sz;i++)
                {
                    int temp = q.front();
                    q.pop();
                    if(mask[temp] == 1)
                    cout << temp <<" ";
                    for(int j = 0;j<vt[temp].size();j++)
                    {
                        if(mask[vt[temp][j]] == 0)
                        {
                            mask[vt[temp][j]] = 1;
                            q.push(vt[temp][j]);
                        }
                    }
                }
            }
            cout << endl;
    }

}


void bfs_find()
{
    int tc;cin>>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int d, c , start,end;
        cin >> d>>c >> start >> end;
        vector<vector<int>> vt(1005);
        for(int i=0;i<c;i++)
        {
            int a,b;
            cin >> a>>b;
            vt[a].push_back(b) ;
            //vt[b].push_back(a) ;
        } 
            int mask[1005] ={0};
            mask[start] =1;
            queue<int> q;
            queue<string> qq;
            vector<int> res(1005);
            q.push(start);
            qq.push(to_string(start) + ' ');
            int check  =0;
            while(q.empty() == false)
            {
                int sz = q.size();
                for(int i=0;i<sz;i++)
                {
                    int temp = q.front();
                    q.pop();
                    string str = qq.front();
                    qq.pop();
                    if(temp == end)
                    {
                        cout << str;
                        check =1;break;
                    }
                    if(check) break;
                    
                    for(int j = 0;j<vt[temp].size();j++)
                    {
                        if(mask[vt[temp][j]] == 0)
                        {
                            mask[vt[temp][j]] = 1;
                            q.push(vt[temp][j]);
                            string stemp = str + to_string(vt[temp][j]) +' ';
                            qq.push(stemp);

                        }
                    }
                }
                if(check) break;
            }
            if(check ==0) cout<< "-1";
            cout << endl;
    }   
}

            //DFS &&  BFS




int main()
{
    bfs_find();
}