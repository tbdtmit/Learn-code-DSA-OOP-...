#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define mod (ll)1000000007

            //LŨY THỪA ĐẢO UN AC
ll pow(ll a, ll b)
{
    a=a%mod;
    if(b==0) return 1;
    ll x = pow(a,b/2)%mod;

    if(b%2==0) return (x*x)%mod;
    return (a*x*x)%mod;
}
void ltd()
{
    int tc;cin>>tc;
    for(int ii=0;ii<tc;ii++)
    {
        ll n;
        cin >> n;
        ll a = n;
        ll nn=0;
        while(n)
        {
            nn = 10*nn+(n%10);
            n/=10;
        }

        cout << pow(a,nn) <<endl;

    }

}
            //LŨY THỪA ĐẢO UN AC
            
            //KÝ TỰ THỨ K TRONG XÂU
ll power_up(ll a, ll b)
{
    ll ans =1;
    for(ll i =0;i< b;i++)
    {
        ans = ans *a;
    }
    return ans;
}
void kttktx()
{
    int tc;
    cin >> tc;
    for(int ii=0;ii<tc;ii++)
    {
        ll n,k;
        cin >> n>>k;
        ll res = power_up(2,n);
        while(k < res )
        {
            res /=2;
            if(k>res)
            {
                k = res - (k -res);
            
            }
        }
        int cnt =0;
        while(res >1)
        {
            res/=2;
            cnt++;
        }
        cout << char('A'  +cnt) << endl;
    }
}
            //KÝ TỰ THỨ K TRONG XÂU

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

            //QUICK SORT
int partition_lomuto(int a[], int l, int r) //doan tu  i -> j(k tinh i) la doan > pivot
{
    int i = l-1;
    int pivot = a[r];
    for(int j = l;j<=r;j++)
    {
        if(a[j] <= pivot)
        {
            int temp = a[++i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    return i;
}

void quick_sort_lomuto(int a[], int l, int r)
{
    if(l<r)
    {
        int p = partition_lomuto(a,l,r);
        quick_sort_lomuto(a,l,p-1);
        quick_sort_lomuto(a,p+1,r);
    }
}

int partition_hoare(int a[], int l, int r)
{
    int i = l-1;
    int j = r+1;
    int pivot = a[r];
    while(1)
    {
        do
        {
            ++i;
        } while(a[i] <= pivot && i< r);

        do
        {
            --j;
        } while (a[j] > pivot && j>l);
        

        if(i<=j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        //a[i] = a[i] + a[j];
        //a[j] = a[i] - a[j];
        //a[i] = a[i] - a[j];
        }


        else
        return j;

        
        
    }
    
}

void quick_sort_hoare(int a[], int l ,int r)
{
    if(l<r)
    {
        int p = partition_hoare(a,l,r);
        quick_sort_hoare(a,l,p);
        quick_sort_hoare(a,p+1,r);
    }
}

            //QUICK SORT

            //SỐ NHỊ PHÂN TỪ 1 ĐẾN N

void snpt1dk()
{
    int tc;
    cin >>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n;cin >>n;
        my_queue q;
        q.push(1);
        bool check = 0;
        ll cnt = 1;
        cout << "1" << " ";
        while(q.is_empty() == false)
        {
            for(int i =0;i<q.show_rear() - q.show_front();i++)
            {
                ll temp = q.pop();
                for(int j=0;j<=1;j++)
                {
                    ll  temp1 = temp *10+j;
                    cnt++;
                    if(cnt > n) {
                        check = 1;break;
                    }
                    q.push(temp1);
                    cout << temp1 << " ";

                }
                if(check) break;

            }
            if(check) break;

        }
        cout << endl;

    }
}
            //SỐ NHỊ PHÂN TỪ 1 ĐẾN N

            //PHẦN TỬ LỚN NHẤT TRONG DÃY CON
void ptlntdc()
{
    int tc;cin >>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n,k;
        cin >> n>>k;
        multiset <unsigned int> s;
        unsigned int a[100005];
        for(int i =0;i<n;i++)
        {
            cin >> a[i];
        }
        for(int i=0;i<k-1;i++)
        {

            s.insert(a[i]);
        }
        for(int i = k-1;i<n;i++)
        {

            s.insert(a[i]);
            cout << *(--s.end()) << " ";
            s.erase(s.find(a[i-k+1]));
        }
        cout << endl;
    }
}

            //PHẦN TỬ LỚN NHẤT TRONG DÃY CON

            //BỘ BA SỐ CÓ TỔNG NHỎ HƠN K
void bo_3()
{
    int tc;cin >>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n;
        long long k;
        cin >> n>> k;
        int a[6000];
        for(int i =0;i<n;i++)
        {
            cin >> a[i];
        }
        quick_sort_hoare(a,0,n-1);
        //for(int i =0;i<n;i++) cout << a[i] << " ";cout << endl;
        long long ans = 0;
        for(int i =0;i<n;i++)
        {
            if((long long)((long long)a[i] + (long long)a[i+1] + (long long)a[i+2]) >= k) break;
            for(int j = i+1;j<n-1;j++)
            {
                long long index = upper_bound(a+j+1,a+n,(long long)(k-(long long)a[i] -(long long)a[j]-(long long)1)) - a;
                //cout << "index = " << index << endl;

                    ans += index - (j+1);





            }
        }
        cout << ans  << endl;
    }
}

            //BỘ BA SỐ CÓ TỔNG NHỎ HƠN K

            //CẶP SỐ CÓ TỔNG BẰNG K
bool my_binary_search(int a[], int l, int r, int k)
{
    //if(l<=r)
    while(l<=r)
    {
        int m  = (l+r)/2;
        if(a[m] == k) return true;
        else if(a[m] > k) r = m -1;//return my_binary_search(a,l,m-1,k);
        else l = m+1;//return my_binary_search(a,m+1,r,k);
    }
    return false;
}

void cap_so_bang_k()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n,k;
        map<int,int> mp ;
        multimap<int,int> mp1;
        cin >> n>>k;
        int a[100005];
        for(int i =0;i<n;i++)
        {
            cin >> a[i];
            mp[a[i]]++;
            mp1.insert({a[i],1});
        }
        int ans = 0;
        //cout << " size " << mp1.size() <<endl;
        
        for(map<int,int> :: iterator i= mp1.begin() ; i!=mp1.end();++i)
        {
            if((*i).first + (*(++i)).first >k) break;
                --i;

                if((*i).first == k - (*i).first)
                {
                    mp[(*i).first]--;
                    ans +=mp[(*i).first];
                }
                else
                {
                    ans+=mp[k-(*i).first];
                }
            

        }
        cout << ans << endl;
    }
}
            // Luu y: thay int bang long long de dat ket qua dung nhat
            //CẶP SỐ CÓ TỔNG BẰNG K

            //BỘ BA SỐ BẰNG K
void bo_3_bang_k()
{
    int tc;cin >> tc;
    for(int ii =0; ii<tc;ii++)
    {
        ll n, k;
        cin >>n>>k;
        multiset<ll> s;
        for(int i =0;i<n;i++)
        {
            ll temp;cin >> temp;
            s.insert(temp);
        }
        bool ans = 0;
        for(auto i = s.begin();i!=s.end();++i)
        {
            if(*i + *(++i)+ *(++i) > k) break;
            --i;--i;
            for(auto  j = ++i;j!=s.end();j++)
            {
                if(j == i) --i;
                if(s.find(k-*i-*j) != s.end() && s.find(k-*i-*j) != i && s.find(k-*i-*j) != j )
                    {
                        ans = 1;break;
                    }
            }
            if(ans) break;
        }
        if(ans == 0) cout <<"NO"<<endl;
        else cout << "YES" << endl;
    }
}
            //BỘ BA SỐ BẰNG K

            //SỐ ĐẦU TIÊN BỊ LẶP
void first_duplicated_number()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n;cin >>n;
        unordered_map<int, int> mp;
        bool ans = 0;
        int a[100005];
        for(int i =0;i<n;i++)
        {
            int temp;cin >> temp;
            mp[temp]++;
            a[i] = temp;
        }
        for(int i =0;i<n;i++)
        {
            if(mp[a[i]] == 2)
            {
                ans =1;
                cout << a[i] << endl;
                break;
            }
        }

        


        if(ans == 0) cout <<"NO" <<endl;
    }
}
            //SỐ ĐẦU TIÊN BỊ LẶP

            //SỐ XUẤT HIỆN NHIỀU NHẤT
void most_duplicated_number()
{
    int tc;
    cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n;
        unordered_map<int, int> ump;
        map<int, int> mp;
        cin >> n;
        for(int i =0;i<n;i++)
        {
            int temp;cin>> temp;
            ump[temp]++;
        }
        for(auto i :ump)
        {
            mp[i.second] = i.first;
        }
        auto i = mp.end();--i;
        if((*i).first > (n/2))
            cout << (*i).second << endl;
        else 
            cout << "NO"<<endl;
    }
}
            //SỐ XUẤT HIỆN NHIỀU 
            
            //ĐIỂM CÂN BẰNG

void dcb()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n;
        cin >> n;
        int a[100005] = {0};
        long long sum =0;
        int maxi = -2000;
        for(int i =1;i<=n;i++)
        {
            cin >> a[i];
            sum+=a[i];
            if(a[i] > maxi) maxi =a[i];
        }
        // int sum_min = (sum-maxi)/2;
        // int sum_mini =0;
        // int index= 0;
        // while(sum_mini < sum_min)
        // {
        //     sum_mini += a[index++];
    
        // }
        // for(int i = index;i<n;i++)
        // {

        // }
        int i= 1;
        long long check_sum = 0;
        for(i = 1;i<=n;i++)
        {   
            if((abs(sum -a[i]))%2 == 0)
            {
                //cout << "sum"<<sum <<endl;
                //cout << "cs" << check_sum <<endl;
                if((sum -(long long)a[i])/2 == check_sum)
                {
                    cout << i << endl;break;
                }
            }
            check_sum += a[i];
        }
        if(i == n+1) cout <<"-1" <<endl;

    }
}
            //ĐIỂM CÂN BẰNG

            //CHÊNH LỆCH NHỎ NHẤT
void min_diff()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int a[100005];
        int n;cin>>n;
        for(int i =0;i<n;i++)
        {
            cin >> a[i];

        }
        quick_sort_hoare(a,0,n-1);
        int min = 2000000000;
        for(int i =0;i<n-1;i++)
        {
            if(a[i+1] - a[i] < min)
                min = a[i+1] - a[i];
        }
        cout << min << endl;
    }
}
            //CHÊNH LỆCH NHỎ NHẤT

            //BỘ BA SỐ PYTAGO UN AC
long double pow_double(long double a)
{
    return a*a;
}
void pytago_triple()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n;cin >> n;
        long double a[6000];
        multiset<long double> s;
        for(int i =0;i<n;i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }
        bool ans =0;
        auto ie = s.end();ie--;ie--;
        auto je = s.end();je--;
        for(auto i = s.begin();i!=ie;i++)
        {
            if(pow_double(*i) + pow_double(*(++i))  > pow_double(*je)      )break;
            --i;
            for(auto j=++i;j!=je;j++)
            {
                if(i == j ) --i;

                auto check = s.find(sqrtl( pow_double(*i) + pow_double(*j)));
                if(check  != s.end() && 
                    check  != i &&  
                    check != j )
                    {
                        ans =1;
                        cout << "YES" << endl;break;
                    }
                
            }
            if(ans) break;
        }
        if(ans == 0) cout << "NO"<< endl;
    }
}
            //BỘ BA SỐ PYTAGO UN AC

            //SỐ LẦN QUAY VÒNG
void slqv()
{
    int tc;cin >> tc;

    for(int  ii =0;ii<tc;ii++)
    {
        int n;cin >> n ;
        long long fi = -1;
        long long se = -1;
        //long long th = -1;
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            //if(th != se) th =se;
            if(se != fi) se = fi;
            cin >> fi;

            if(/*se>=th &&*/ se > fi ) cnt = i ;

        }
        cout << cnt << endl;
    }
}
            //SỐ LẦN QUAY VÒNG

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

            //ĐẾM SỐ DẤU NGOẶC ĐỔI CHIỀU
void dscndc()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        string s;cin>> s;
        my_stack st;
        int cnt = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == ')' && st.is_empty() == true)
            {
                cnt++;
                st.push('(');
            }
            else if(s[i] == '(')
            {
                st.push('(');
            }
            else
            {
                st.pop();
            }
        }

        cout << cnt + st.show_top()/2 << endl;
        
    }
}
            //ĐẾM SỐ DẤU NGOẶC ĐỔI CHIỀU

            //TÍNH GIÁ TRỊ BIỂU THỨC HẬU TỐ
void tgtbtht()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
            string s;
            cin >> s;
            my_stack st;
            for(int i=0;i<s.length();i++)
            {
                if(s[i] >= '0' && s[i] <= '9')
                {
                    st.push(s[i] - '0');

                }   
                else{
                    if(s[i] == '*')
                    {
                        int b = st.pop();
                        int a = st.pop();
                        st.push(a*b);
                    }
                                        if(s[i] == '/')
                    {
                        int b = st.pop();
                        int a = st.pop();
                        st.push(a/b);
                    }
                                        if(s[i] == '+')
                    {
                        int b = st.pop();
                        int a = st.pop();
                        st.push(a+b);
                    }
                                        if(s[i] == '-')
                    {
                        int b = st.pop();
                        int a = st.pop();
                        st.push(a-b);
                    }
                }    

            }
            cout << st.pop() <<endl;

        
    }
}
            //TÍNH GIÁ TRỊ BIỂU THỨC HẬU TỐ

            //TÍNH GIÁ TRỊ BIỂU THỨC TIỀN TỐ
void tgtbttt()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
            string s;
            cin >> s;
            my_stack st;
            for(int i=s.length() -1;i>=0;i--)
            {
                if(s[i] >= '0' && s[i] <= '9')
                {
                    st.push(s[i] - '0');

                }   
                else{
                    if(s[i] == '*')
                    {
                        int b = st.pop();
                        int a = st.pop();
                        st.push(b*a);
                    }
                                        if(s[i] == '/')
                    {
                        int b = st.pop();
                        int a = st.pop();
                        st.push(b/a);
                    }
                                        if(s[i] == '+')
                    {
                        int b = st.pop();
                        int a = st.pop();
                        st.push(b+a);
                    }
                                        if(s[i] == '-')
                    {
                        int b = st.pop();
                        int a = st.pop();
                        st.push(b-a);
                    }
                }    

            }
            cout << st.pop() <<endl;

        
    }
}
            //TÍNH GIÁ TRỊ BIỂU THỨC TIỀN TỐ

            //DÃY NGOẶC ĐÚNG DÀI NHẤT
void dnddn()
{
    int tc;cin>>tc;
    for(int ii =0;ii<tc;ii++)
    {
        string s;cin >> s;
        stack<int> st;
        st.push(-1);
        int res = -1;
        for(int i=0;i<s.length();i++){
            
            if(s[i] == '(')
            {
                st.push(i);
            }
            else {
                st.pop();
                if(st.empty())
                {
                    st.push(i);

                }
                else{

                    res = max(res, i - st.top());

                    

        
                }
            }
        }

        cout << res << endl;
    }
}
            //DÃY NGOẶC ĐÚNG DÀI NHẤT

            //ĐẢO TỪ
void dao_tu()
{
    int tc;
    cin >> tc;
    cin.ignore();
    for(int i =0;i<tc;i++)
    {
        string s[10000];
        string temp;

        getline(cin,temp);
        stringstream str(temp);
        int index=0;
        while(str >> temp)
        {
            s[index] = temp;
            index++;
        }
        for(int i=0;i<index;i++)
        {
            cout<< s[index-1-i] <<" ";
        }
        cout<< endl;

    }
}
            //ĐẢO TỪ

int main()
{

    // int a[10]= {1,2,3,4,5,6,7,8,9,10};
    // for(int i=0;i<10;i++)
    // {
    //     cout << a+i <<endl;
    // }
    // cout << upper_bound(a+2,a+10,7)  ;


    dnddn();


    return 0;
}