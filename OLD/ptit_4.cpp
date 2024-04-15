#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

            //KIỂM TRA ĐƯỜNG ĐI
void dfs(int a, int b, vector<vector<int>> &vt, int mask[], bool &check)
{
    if(a == b)
    {
        check =1; return;
    }
    mask[a] = 1;
    for(int i=0;i<vt[a].size();i++)
    {
        if(mask[vt[a][i]] == 0 && check ==0)
        {
            dfs(vt[a][i],b,vt,mask,check);
        }   
    }
}
void ktdd()
{
    int tc;cin >>tc;
    for(int ii=0;ii<tc;ii++)
    {
        int n,m;
        cin >> n>> m;
        vector<vector<int>> vt(1005);
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>> a>>b;
            vt[a].push_back(b) ;
            vt[b].push_back(a) ;
        }
        int k;cin>>k;

        for(int i=0;i<k;i++)
        {
            bool check =0;
            int mask[1005] = {0};
            int a,b;
            cin >> a>>b;
            dfs(a,b,vt,mask,check);
            if(check)
                cout << "YES" << endl;
            else
                cout << "NO" <<endl;
        }
    }
}
            //KIỂM TRA ĐƯỜNG ĐI

            //TÌM BỘI SỐ
void tbs() // su dung long long de toi accept
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n;cin >>n;
        queue<int> q;
        q.push(9);
        bool check  =0;
        while(1)
        {
            int sz = q.size();
            for(int i =0;i<sz;i++)
            {
                int temp = q.front();
                q.pop();
                if(temp%n ==0)
                {
                    cout << temp << endl;
                    check =1;
                    break;
                }
                for(int j=0;j<=9;j+=9)
                {
                    int ttemp = temp*10+j;
                    q.push(ttemp);
                }
            }
            if(check) break;
        }

    }
}
            //TÌM BỘI SỐ

            //PHÂN TÍCH SỐ 1
void pts1_recursive(string s, int n , int sum, int index)
{
    if(sum == n)
    {
        s[s.length()-1] = ')';
        cout << "(" << s <<" ";
        return;
    }
    else if(sum > n) return;
    else{
        for(int i =index;i>=1;i--)
        {
            pts1_recursive(s+ to_string(i)+' ',n,sum+i,i);
        }
    }
}
void pts1()
{
    int tc;
    cin >> tc;
    for(int ii=0;ii<tc;ii++)
    {
        int n;cin >> n;
        pts1_recursive("",n,0,n);
        cout << endl;
    }
}
            //PHÂN TÍCH SỐ 1

            //DÃY CON CÓ TỔNG LẺ && DÃY CON CÓ TỔNG NGUYÊN TỐ
bool is_prime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i == 0)
            return false;
    }
    return n>1;
}
void dcctl_recursive(int a[],vector<int> n,int index,vector<vector<int>> &vt,int sum)
{
    if(is_prime(sum))
    {
        vt.push_back(n);
    }
    //     if(sum%2==1)
    // {
    //     vt.push_back(n);
    // }
    if(index < 0)
    {
        return;
    }
    else{

        for(int i=index;i>=0;i--){
            n.push_back(a[i]);
            dcctl_recursive(a,n,i-1,vt,sum+a[i]);
            n.pop_back();
        }
    }
}


void dcctl()
{
    int tc;cin >> tc;
    for(int ii=0;ii<tc;ii++)
    {
        int n ;cin >>n;
        int a[100];
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        sort(a,a+n);
        vector<vector<int>> vt;
        vector<int> nn;
        dcctl_recursive(a,nn,n-1,vt,0);
        sort(vt.begin(),vt.end());
        for(auto i: vt)
        {
            for(int j=0;j<i.size();j++)
            {
                cout << i[j] << " ";
            }
            cout << endl;
        }




    }
}
            //DÃY CON CÓ TỔNG LẺ && DÃY CON CÓ TỔNG NGUYÊN TỐ

            //SẮP XẾP VIÊN BI UN AC
void sxvb()
{
    //int tc;
    //cin >>tc;
        string s;
        cin>>s;
        int n = s.length();
        int i = -1;
        int j = n;
        int cnt = 0;
        char c[3] = {'X','T','D'};
        int cc = 0;
        while(cc<2)
        {
            while(i<j)
            {
                do
            {
                /* code */
                i++;
            } while (s[i] == c[cc] && i<j);

            do
            {
                /* code */
                j--;
            } while (s[j] != c[cc] && j>i);

            if(i<j)
            {
                swap(s[i],s[j]);
                cnt++;
            }
            }
            cc++;
            i =j;
            j=n;


            
            
        }
        cout << s << endl;
        cout << cnt  <<endl;

    }

            // /SẮP XẾP VIÊN BI UN AC

            //TỔ HỢP SỐ CÓ TỔNG BẰNG X
void thsctbx_recursive(int sz, int index, string s, int x, int sum, int a[], int &check)
{
    if(sum == x)
    {
        s[s.length()-1] = ']';
        cout << '['<<s;
        check = 1;
        return;
    }
    else if(sum>x) return;
    else{
        for(int i=index;i<sz;i++)
        {
            string ss = s+ to_string(a[i])+' ';
            thsctbx_recursive(sz,i,ss,x,sum+a[i],a,check);
        }
    }
}
void thsctbx()
{
    int tc;cin>>tc;
    for(int ii=0;ii<tc;ii++)
    {
        int n,x;
        cin >> n>>x;
        int a[30];
        set<int> s;
        for(int i=0;i<n;i++)
        {   
            int t;cin>>t;
            s.insert(t);
        }
        int i =0;
        int sz = s.size();
        for(auto ii:s)
        {
            a[i] = ii;
            i++;
        }
        int check =0;
        thsctbx_recursive(sz,0,"",x,0,a,check);
        if(check == 0) cout <<"-1";
        cout << endl;
    }
}
            //TỔ HỢP SỐ CÓ TỔNG BẰNG X

            //CHIA MẢNG
void chia_mang_recursive(int a[], int mask[], int x, int &cnt, int index, int n, vector<int> vt, int sum, int dr, int j, int &f)
{
    if(sum == x)
    {
        for(int i =0;i<vt.size();i++)
        {
            mask[vt[i]]  = 1;
            cout << a[vt[i]] << " ";
        }
        cout << "||";
        cnt++;
        f = 1;
        return;
    }
    else if(sum>x) return;
    else{
        if(dr == 0)
        {
        for(int i =0;i<n;i++)
        {
            if(mask[i] == 0)
            {
                f = 0;
                vt.push_back(i);
                chia_mang_recursive(a,mask,x,cnt,n-1,n,vt,sum+a[i],1,i,f);
                vt.pop_back();
            }
        }
        }
        else if(dr == 1)
        {
        for(int i =index;i>j;i--)
        {
            if(mask[i] == 0 && f == 0)
            {
                vt.push_back(i);
                chia_mang_recursive(a,mask,x,cnt,i-1,n,vt,sum+a[i],1,j,f);
                vt.pop_back();
            }
        }
        }

    }
}
void chia_mang()
{
    int tc;
    cin>>tc;
    for(int ii=0;ii<tc;ii++)
    {
        int n,k;
        cin >>n>>k;
        int a[50];
        int mask[50] = {0};
        int sum =0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i] ;
            sum+= a[i];
        }
        sort(a,a+n);
        if(sum%k !=0)
            cout << "0"<<endl;
        else{
            int x = sum/k;
            int cnt =0;
            vector<int> vt;
            int f =0;
            chia_mang_recursive(a,mask,x,cnt,0,n,vt,0,0,0,f);
            if(cnt == k)
            {
                // for(int i=0;i<n;i++)
                // {
                //     if(mask[i] == 0)
                //     {    cout <<"0" <<endl;
                //     ; cnt =-1;break;}

                // }
                // if(cnt != -1)
                    cout <<"1" <<endl;
            }

            else
                cout <<"0" << endl;

        }

    }
}
            //CHIA MẢNG

            //NGƯỜI DU LỊCH UN AC
int cal(int ans[], int n,int a[][30])
{
    int sum =0;
    for(int i = 1;i<=n;i++)
    {
        //cout << ans[i] <<" ";
        if(i == n)
        {
            sum += a[ans[i]][1];
        }
        else{
            sum += a[ans[i]][ans[i+1]];
        }

    }
    return sum;
}
void sinh_hoan_vi(int a[][30], int mask[], int n,int &min, int h, int cnt, int sum)//cnt =1
{
    if(cnt==n)
    {
        sum = sum + a[h][1];
        if(sum<min)
            min = sum;
        return;
    }
    else{
        for(int i= 1;i<=n;i++)
        {
            if(mask[i] == 0)
            {
                mask[i] = 1;
                sinh_hoan_vi(a,mask,n,min,i,cnt+1, sum+a[h][i]);
                mask[i] = 0;
            }
        }
    }
}
void ndl()
{
    int a[30][30] = {-1};
    int n;cin >> n;
    for(int i=1 ;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> a[i][j];
        }
    }
    int mask[30] = {0};
    int ans[30];
    ans[1] = 1;
    mask[1] =1;
    int min = INT_MAX; 
    sinh_hoan_vi(a,mask,n,min,1,1,0);
    cout << min <<endl;

}
            //NGƯỜI DU LỊCH UN AC

            //CHIA ĐỀU

            //CHIA ĐỀU

            //BIỂU THỨC TĂNG GIẢM
void bttg()
{
    int tc;cin>>tc;
    for(int ii=0;ii<tc;ii++)
    {
        string s;
        cin >>s;
        int n =s.length();
        int mask[10] = {0};
        deque<int> dq;
        dq.push_back(1);
        int a =2;
        for(int i =0;i<n;i++)
        {
            if(s[i] == 'D')
            {
                dq.push_front(a);
                a++;
            }
            else if(s[i] == 'I')
            {
                int j = i+1;
                int cnt =0;
                while(j<n && s[j] == 'D')
                {
                    cnt++;
                    j++;
                }
                int b =a ;
                a= a+cnt;
                while(a>=b)
                {
                    dq.push_back(a);
                    a--;
                }
                i+=cnt;

                a++;
                a= a+cnt+1;




            }
        }
        while(dq.empty() == false)
        {
            cout << dq.front();
            dq.pop_front();
        }
        cout << endl;
    }
}
            //BIỂU THỨC TĂNG GIẢM

            //PHẦN TỬ BÊN PHẢI NHỎ HƠN
void ptbpnh()
{
    int tc;
    cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        vector<int> a(1000005);
        vector<int> ln(1000005);
        vector<int> nn(1000005);
        stack<int> st;
        stack<int> stt;
        int n;
        cin >>n;
        for(int i =0;i<n;i++)
        {
            int t;cin >>t;
            a[i] = t;

        }
        st.push(n-1);
        stt.push(n-1);
        nn[n-1] = -1;
        ln[n-1] = -1;
        for(int i=n-2;i>=0;i--)
        {
            while(1)
            {
                if(st.empty())
                {
                    ln[i] = -1;
                    st.push(i);
                    break;

                }
                if(a[i]>= a[st.top()])
                {
                    st.pop();
                }
                else{
                    ln[i] = st.top();
                    st.push(i);
                    break;
                }
            }


            while(1)
            {
                if(stt.empty())
                {
                    nn[i] = -1;
                    stt.push(i);
                    break;

                }
                if(a[i]<= a[stt.top()])
                {
                    stt.pop();
                }
                else{
                    nn[i] = stt.top();
                    stt.push(i);
                    break;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(ln[i] == -1)
            cout << "-1" <<" ";
            else
            {
                if(nn[ln[i]] == -1)
                {
                    cout << "-1" << " ";
                }
                else
                    cout<< a[nn[ln[i]]] <<" ";
            }

        }
        cout << endl;

    }
}
            //PHẦN TỬ BÊN PHẢI NHỎ HƠN

            //HÌNH CHỮ NHẬT LỚN NHẤT
void hcn_max()
{
    int tc;cin>>tc;
    for(int ii =0;ii<tc;ii++)
    {
        vector<int> a(100005);
        stack<int> st;
        vector<int> dt(100005);
        int n;cin >>n;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }

        st.push(n-1);
        dt[n-1] = a[n-1];
        
    }
}
            //HÌNH CHỮ NHẬT LỚN NHẤT


int main()
{
    ptbpnh();
    
    return 0;
}