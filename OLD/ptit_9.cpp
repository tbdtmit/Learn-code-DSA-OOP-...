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

void pytago()
{
    int tc;cin >> tc;
    for(int ii=0;ii<tc;ii++)
    {
        set<int> s;
        int n;cin >> n;
        bool check = 0;
        for(int i=0;i<n;i++)
        {
            int te;cin >> te;
            s.insert(te);
        }

        auto  max = s.end();max--;
        int  mx = *max;
       // cout << mx << endl;

        for( auto i = s.begin();i != s.end();i++)
        {
            auto j = ++i;
            if(i == s.end()) break;
            i--;
            int jj = *j;
            int ii = *i;
                                    //cout << jj << " " << ii << "  " << mx <<endl;
            if((ull)ii*ii + (ull)jj*jj > (ull)mx * mx) break;
            else{
                for(j;j!=s.end();j++)
                {
                    jj = *j;
                    ull ans = (ull)ii*ii + (ull)jj*jj ;
                    if(sqrtl(ans) == (int)(sqrt(ans))  && s.find(sqrtl(ans)) != s.end())
                    {
                        //cout << jj << " " << ii << "  " << mx <<endl;
                        cout << "YES" << endl;
                        check = 1;
                        break;

                    }
                }
            }
            if(check) break;

         
            
        }
        if(!check)
        cout << "NO" << endl;

    }
}

            //

            //
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}
void sort_by_duplicated()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n;
        cin >> n;
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            int te;cin >> te;
            mp[te]++;
        }
        vector<pair<int,int>> vt;
        for(auto i : mp)
        {
            vt.push_back({i.second,i.first});
        }
        sort(vt.begin(), vt.end(),cmp);
        for(auto i : vt)
        {
            for(int j =0;j<i.first;j++)
            {
                cout << i.second << " ";
            }
    
        }
        cout << endl;


    }
}
            //

            //CHỌN Ô - 1
void o_1()
{

}
            //CHỌN Ô - 1

            //BẬC THANG
void stair()
{
    int tc;cin >> tc;
    for(int ii=0;ii<tc;ii++)
    {
        int n,k;
        cin >> n >> k;
        int dp[100005] = {};
        dp[0]= dp[1] = 1;
        for(int i =2;i<=n;i++)
        {
            for(int j = 1;j<=k;j++)
            {
                if(j <= i)
                {
                    dp[i] = (dp[i] + dp[i-j]) % MOD ;

                }
            }
        }
        cout  << dp[n] << endl;
    }
}
            //BẬC THANG
            
            //CẶP SỐ CÓ TỔNG BẰNG K
void couple_equal_k()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n,k;
        cin >> n >> k;
        map<int,int> mp;
        for(int i =0;i<n;i++)
        {
            int te;
            cin >>te;
            mp[te]++;
        }

        ull ans = 0;
        for(auto i : mp)
        {
            if(i.first *2 == k &&  i.second >1)
            {
                for(int j = i.second-1;j>=1;j--)
                {
                    ans +=j;
                }
            }
            else if(i.second != 0){
                if(mp.find(k - i.first) != mp.end())
                {
                    auto id = mp.find(k - i.first);
                    int j = (*id).second;
                    ans += i.second * j;

                    i.second = 0;
                    (*id).second = 0;
                }
            }
        }
        cout << ans << endl;
    }
}
            //CẶP SỐ CÓ TỔNG BẰNG K

            //
int bin_search(int l, int r, int val, vector<int> &arr)
{
    while(l<r)
    {
        int m = (l+r)/2;
        if(arr[m] < val) l = m+1;
        else r = m;
    }
    return r;
}
void bigger_k()
{
    int tc;cin>> tc;
    for(int ii =0;ii<tc;ii++)
    {
    int n,k;
    cin >> n >> k;
    vector<int> vt;
    for(int i =1;i<=n;i++)
    {
        int te;
        cin >> te;
        vt.push_back(te);
    }
    sort(vt.begin(), vt.end());

    ull ans =0;
    for(int i=0;i<n-1;i++)
    {

        int te = bin_search(i+1,n-1,k+vt[i],vt);
        //cout << "te = " << te << endl;
        if(vt[te] - vt[i] >= k)
        ans += (ull)te - i -1;
        else if(vt[te] - vt[i] < k)
        {
            ans += (ull)te - i ;
        }
        
    }
    cout << ans << endl;
    }

}
            //SO CAP CO HIEU < K

            //NHÀ KHÔNG KỀ NHAU
void nha_0_ke_nhau()
{
    int tc;
    cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n ;cin >> n;
        vector<int> vt(1000005);
        vector<ull> dp(1000005,0);
        for(int i =0;i<n;i++)
        {
            cin >> vt[i];
        }
        dp[0] = vt[0];
        dp[1] = vt[1];
        dp[2] = vt[0] + vt[2];
        ull mx = 0;
        for(int i =3;i<n;i++)
        {
            dp[i] = max(dp[i-2] + vt[i] , dp[i-3] + vt[i]);
            if(mx < dp[i])
                mx = dp[i];
        }
        cout << mx << endl;

    }
}
            //NHÀ KHÔNG KỀ NHAU

            //Kangaru
void kangaru()
{
    int tc;
    cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        vector<int> vt;
        int n;
        cin >>n;
        for(int i=0;i<n;i++)
        {
            int te;cin >> te;
            vt.push_back(te);
        }
        int ans = n;
        sort(vt.begin(),vt.end());
        int mid = n/2;
        int l = n/2;
        int r = n-1;
        //chỉ cần xét từ vị trí n/2 bởi vì số lượng kangaru tối đa có thể tối ưu là n/2
        while(l>=0 && r>=mid)
        {
            if(vt[r] >= vt[l] *2)
            {
                ans--;
                l--;
                r--;
            }
            else
            l--;
        }
        cout << ans <<endl;


    }
}
            //Kangaru

            //GHÉP VÁN GỖ

void ghep_van()
{
    int tc;
    cin >>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n;cin >> n;
        vector<int> vt; vt.push_back(-1);
        stack<int> left; left.push(0);
        stack<int> right; right.push(n+1);

        vector<pair<int,int>> min(n+5);
        
        for(int i =0 ;i<n;i++)
        {
            int te;cin >>te;
            vt.push_back(te);
        }
        vt.push_back(-1);

        for(int i =1;i<=n;i++)
        {
            int m = n+1-i;

            while(vt[i] <= vt[left.top()] )
            {
                left.pop();
            }
            min[i].first = left.top() + 1;
            left.push(i);

            while(vt[m] <= vt[right.top()] )
            {
                right.pop();
            }
            min[m].second = right.top() - 1;
            right.push(m);

        }
          int ans = 0;
        for(int i = 1;i<=n;i++)
        {
            if(min[i].second - min[i].first + 1 >= vt[i])
            {
                int te = vt[i];
                if(ans < te) ans = te;
            }
        }
        cout << ans << endl;

    }
}
            //GHÉP VÁN GỖ

            //HÌNH CHỮ NHẬT 0-1
int hcn_max(int mask[][505], int ii, int jj, int h) //ii=1;jj=n(so cot)
{
        int n = jj;
        vector<int> vt; vt.push_back(-1);
        stack<int> left; left.push(0);
        stack<int> right; right.push(n+1);

        vector<pair<int,int>> min(n+5);
        
        for(int i = 1  ;i<= n;i++)
        {

            vt.push_back(mask[h][i]);
        }
        vt.push_back(-1);

        for(int i =1;i<=n;i++)
        {
            int m = n+1-i;

            while(vt[i] <= vt[left.top()] )
            {
                left.pop();
            }
            min[i].first = left.top() + 1;
            left.push(i);

            while(vt[m] <= vt[right.top()] )
            {
                right.pop();
            }
            min[m].second = right.top() - 1;
            right.push(m);

        }
          int ans = 0;
        for(int i = 1;i<=n;i++)
        {
            int te = vt[i] * ( min[i].second - min[i].first +1);
            if(ans < te) ans = te;
        }
        return ans;
}
void hcn_0_1()
{
    int tc;cin >>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n,m;
        cin >> n>> m;
        int a[505][505] = {};
        int mask[505][505] = {};
        for(int i = 1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin >> a[i][j];
                if(a[i][j] == 1)
                {
                    mask[i][j] = a[i][j] + mask[i-1][j];
                }
                //cout << mask[i][j] << " ";
            }
            //cout << endl;
        }
        int ans = 0;
        for(int i= 1;i<=n;i++)
        {
            int te = hcn_max(mask,1,m,i);
            if(ans < te) ans  = te;
        }
        cout << ans << endl;
    }

}
            //HÌNH CHỮ NHẬT 0-1

            //BÀI TOÁN CÁI TÚI 0-1
void cai_tui()
{
    int tc;cin >> tc;
    for(int ii=0;ii<tc;ii++)
    {
        int n;cin >> n;
        int mx ;cin >> mx;
        int w[n+5];
        int v[n+5];
        int dp[n+5][mx+5] = {};
        for(int i =1;i<=n;i++)
        {
            cin >> w[i];
        }
        for(int i =1;i<=n;i++)
        {
            cin >> v[i];
        }

        for(int i =1;i<=n;i++)
        {
            for(int j = 1;j<=mx;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j>=w[i])
                dp[i][j] = max(dp[i][j] , dp[i-1][j - w[i]] + v[i]);
            }
        }
        cout << dp[n][mx] << endl;
    }
}
            //BÀI TOÁN CÁI TÚI 0-1

            //BIẾN ĐỔI SỐ TỰ NHIÊN
int convert(int x)
{
    if(x<4) return x;
    int  a = (int)sqrt(x);
    for(int i = a;i>=2;i--)
    {
        if(x%i == 0)
            return x/i;
    }
    return x;
}
void bien_doi_so_tn()
{
    int tc;cin >>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n;cin >> n;
        //priority_queue<int,vector<int>,greater<int>> q;
        queue<int> q;
        map<int,int> m;
        m[n] = 1;
        q.push(n);
        int ans = 0;
        bool check = 0;
        while(q.empty() == false)
        {
            int te = q.size();
            for(int i=0;i<te;i++)
            {
                if(q.front() == 1) {
                    check = 1;break;
                }
                int tmp = q.front();
                q.pop();
                if(m[tmp-1] == 0)
                {
                    q.push(tmp-1);
                    m[tmp-1] = 1;
                }

                int  a = (int)sqrt(tmp);
                for(int ij = a;ij>=2;ij--)
                {
                    if(tmp%ij == 0 && m[tmp/ij] == 0)
                    {
                        q.push(tmp/ij);
                        m[tmp/ij] = 1;
                    }

                }

            

            
            }
            if(check) break;
                ans++;
        }

        //cout << endl;
        
        cout << ans << endl;

    }
}
            //BIẾN ĐỔI SỐ TỰ NHIÊN

            //TÌM SỐ K THỎA MÃN ĐIỀU KIỆN
void so_k_re(int &ans,int l, int r, int s , int mask[], int cnt )
{
    if(cnt > 0 && s == 0) return;
    if(s> r) return;
    if( s>= l && s<= r)
    {
        //cout << s << " ";
        ans++;
    }

        for(int i = 0;i<=5;i++)
        {
            if(mask[i] == 0)
            {
                mask[i]= 1;
                so_k_re(ans,l,r,s*10+i,mask, cnt+1);
                mask[i] = 0;
            }

        }
    
  
}
void so_k()
{
    int tc;cin >>tc;
    for(int ii=0;ii<tc;ii++)
    {
        int l,r;
        cin >> l >> r;
            int ans = 0;
            int mask[10] = {};
            so_k_re(ans,l,r,0,mask,0);
            //if(l == 0) ans++;
            cout << ans << endl;
    }
}
            //TÌM SỐ K THỎA MÃN ĐIỀU KIỆN

            //BIẾN ĐỔI SỐ NGUYÊN TỐ
void sang_snt(int n, int snt[])
{
    snt[0] = snt[1] = 1;
    for(int i = 2;i*i<=n;i++)
    {
        if(snt[i] == 0 )
        for(int j = i;j*i<=n;j++)
        {

            {
                snt[i*j] = 1;
            }
        }
    }
}

void convert_prime()
    {

        int tc;cin >>tc;
        for(int ii = 0;ii<tc;ii++)
        {
        int snt[10005] = {};
        sang_snt(10000,snt);
            string st,en;
            cin >> st >> en;

            queue<string> q;
            map<string,int> m;
            m[st] = 1;
            q.push(st);
            bool check  = 0;
            
            while (q.empty() == false)
            {
                string te1 = q.front();
                
                if(te1 == en) {
                    cout << 0 << endl;break;
                }
                //cout << te1 << " ";
                q.pop();    

                for(int i =0;i<te1.length();i++)
                {
                        string te = te1;
                    for(char j = '0';j<='9';j++)
                    {

                        te[i] = j;
                        if(m[te] == 0 && snt[stoi(te)] == 0 && stoi(te) >=1000)
                        {
                            m[te] = m[te1] + 1;
                            q.push(te);
                            if(te == en)
                            {
                                cout << m[te] - 1 << endl;
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


    }

            //BIẾN ĐỔI SỐ NGUYÊN TỐ

            //QUAY HÌNH VUÔNG
string rotate_left(string s)
{
    s = " " + s;
    auto te = s[2];
    s[2] = s[5];
    s[5] = s[6];
    s[6] = s[3];
    s[3] = te;

    string ss = s.substr(1,s.length()- 1);
    return ss;

}

string rotate_right(string s)
{
    s = " " + s;
    auto te = s[1];
    s[1] = s[4];
    s[4] = s[5];
    s[5] = s[2];
    s[2] = te;

    string ss = s.substr(1,s.length()- 1);
    return ss;

}

void rotate_square()
{
    int tc;cin >> tc;
    for(int ii = 0 ;ii<tc;ii++)
    {
        string st = "";
        string en = "";
        for(int i = 0 ;i<6;i++)
        {
            char c;
            cin >> c;
            st += c;

        }
        for(int i = 0 ;i<6;i++)
        {
            char c;
            cin >> c;
            en += c;

        }

        queue<string> q;
        map<string,int> m;
        q.push(st);
        m[st] = 1;
        bool check = 0 ;
        while(1)
        {
            string te = q.front();
            q.pop();
            if(te == en)
            {
                check = 1;
                cout << m[en] - 1 << endl;
                break;
            }
            string l = rotate_left(te);
            string r = rotate_right(te);
            if(m[l] == 0)
            {
                m[l] = m[te] + 1;
                q.push(l);
            }
            if(m[r] == 0)
            {
                m[r] = m[te] + 1;
                q.push(r);
            }

        
        }
    }
}
            //QUAY HÌNH VUÔNG

int main()
{

    rotate_square();
    return 0;
}