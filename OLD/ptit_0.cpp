#include<bits/stdc++.h>
using namespace std;

            //LIỆT KÊ XÂU KÝ TỰ
void lkxkt_recursive(char index, string s,int n, char c)
{
    if(s.length() == n)
    {
        cout << s << endl;
        return;
    }
    else{
        for(char i = index;i<= c;i++)
        {
            lkxkt_recursive(i,s+i,n,c);
        }   
    }
    
}
void lkxkt()
{
    char c;cin >> c;
    int n;cin>>n;
    lkxkt_recursive('A',"",n,c);
}
            //LIỆT KÊ XÂU KÝ TỰ

            //TRÒ CHƠI VỚI CÁC CON SỐ
int tcvccs_a[20];
int tcvccs_mask[20] = {0};
bool tcvccs_check(int n)
{
    for(int i =1;i<n;i++)
    {
        if(tcvccs_a[i] - tcvccs_a[i+1] == 1 ||tcvccs_a[i] - tcvccs_a[i+1] == -1)
            return false;
        
    }
    return true;
}
void tcvccs_recursice(int index, int n)// index =1
{
    if(index == n+1)
    {
        if(tcvccs_check(n))
            {
                for(int i =1;i<=n;i++)
                    cout << tcvccs_a[i];
                    cout << endl;
            }
        return;
    }
    else{
        for(int i=1;i<=n;i++)
        {
            if(tcvccs_mask[i] == 0)
            {
                tcvccs_mask[i] = 1;
                tcvccs_a[index] = i;
                tcvccs_recursice(index+1,n);
                tcvccs_mask[i] = 0;
            }
        }
    }
}
void tcvccs()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n;
        cin >> n;
        for(int i =1;i<=n;i++)
        {
            tcvccs_a[i] = i;
            tcvccs_mask[i] = 0;
        }
        tcvccs_recursice(1,n);
    }

}
            //TRÒ CHƠI VỚI CÁC CON SỐ

            //LỰA CHỌN TỐI ƯU
void lctu()
{
    int lctu_a[100005];
    int lctu_b[100005];
    int tc;
    cin>>tc;
    for(int ii =0 ;ii<tc;ii++)
    {
        int n;cin >> n;
        for(int i =0;i<n;i++)
        {
            cin >> lctu_a[i];
            cin >> lctu_b[i];
        }

        for(int i =0;i<n;i++)
        {
            int min = lctu_a[i];
            int indexmin = i;
            for(int j = i;j<n;j++)
            {
                if(lctu_a[j] < min )
                {
                    min = lctu_a[j];
                    indexmin = j;
                }
            
            }
            int temp = min;
            lctu_a[i] = lctu_a[indexmin];
            lctu_a[indexmin] = temp;
            temp = lctu_b[i];
            lctu_b[i] =  lctu_b[indexmin];
            lctu_b[indexmin] = temp;
        }
        for(int i =0;i<n;i++)
        {
            
        }
    }

}
            //LỰA CHỌN TỐI ƯU UN FN

            //TÍNH FLOOR(X)
void floor()
{
    int tc;cin >> tc;
    for(int ii=0;ii<tc;ii++)
    {
        int n, k;
        cin >> n >> k;
        int ans =-1 ;
        for(int i =0;i<n;i++)
        {
            int temp;
            cin >> temp;
            if(temp < k)
            {
                ans = i;
            }
            else if(temp == k)
            {
                ans = i;//break;
            }
            //else
            //break;
        }
        if(ans == -1) cout << ans << endl;
        else
        cout << ans +1 << endl;
    }
}
            //TÍNH FLOOR(X)

            //DÃY CON LIÊN TIẾP CÓ TỔNG LỚN NHẤT
void tong_lt_max()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int a[105];
        int n;cin >> n;
        for(int i =0;i<n;i++)
        {
            cin >> a[i];
        }
        int ans = a[0] + a[1];
        for(int i =0;i<n-1;i++)
        {
            int res = a[i];
            for(int j = i+1;j<n;j++)
            {
             res += a[j];
             if(res > ans) ans = res;   
            }
        }
        cout  << ans << endl;

    }
}
            //DÃY CON LIÊN TIẾP CÓ TỔNG LỚN NHẤT

            //TÍNH LŨY THỪA
long long ans =1;
long long lt_recursive(long long a, long long b)
{
    ans = ans%1000000007;
    if(b == 0)
        return 1;
    if(b%2 ==0)
    {
        ans = lt_recursive(a,b/2) * lt_recursive(a,b/2);
    }
    else
    ans = a*lt_recursive(a,b/2);
}
void luy_thua()
{
    for(int ii=0;ii<21;ii++)
    {
        long long a,b;
        long long d = 1000000007;
        cin >> a >>b;
        ans =1 ;
        if(a==0 && b == 0)break;
        else
        {
            lt_recursive(a,b);
            cout << ans%d << endl;
        }
    }
}
            //TÍNH LŨY THỪA

            //CHIA MẢNG
int cm_a[30];
int cm_mask[30] = {0};
int cm_ans =0;
int cm_cnt =0;
int cm_status =0;
void cm_recursive(int k, int n, int sum)
{
    if(sum == k)
    {
        cm_cnt++;
        cm_status = 1;
        return;


    }
    else{
        for(int i=0;i<n;i++)
        {
            if(cm_mask[i] == 0 && sum + cm_a[i] <= k)
            {
                cm_mask[i] =1;
                cm_recursive(k,n,sum+cm_a[i]);
                if(cm_status == 0)
                cm_mask[i] =0;
            }
        }
        cm_status = 0;
    }
}
void chia_mang()
{
    int tc;
    cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        cm_ans =0;
        int n,k;
        cin >> n>>k;
        int sum =0;
        for(int i=0;i<n;i++)
        {
            cin >> cm_a[i];
            sum += cm_a[i];
            cm_mask[i] = 0;
        }
        if(sum%k != 0)  cout << "0" <<endl;
        else{
            int t = sum/k;
            cm_recursive(t,n,0);
            if(cm_cnt == k)
                cout << "1" << endl;
        }
    }
}
            //CHIA MẢNG

            //SẮP XẾP CHÈN - LIỆT KÊ NGƯỢC
void lkn_recursive(int n,int index, int a[])
{
    if(index==n)
    {
        return;
    }
    else if(index == 0)
    {
        int temp =a[0];
        lkn_recursive(n,index+1,a);
        for(int i =0;i<=index;i++)
        {
            cout << "Buoc " << index << ": " << temp;
        }
        cout << endl;
    }
    else{
        int indexx = index;
        while(a[indexx] < a[indexx -1] && indexx-1>=0)
        {
            int temp = a[indexx];
            a[indexx] = a[indexx-1];
            a[indexx-1] = temp;
            indexx--;        
        }
        int temp[index+1];
        for(int i =0;i<=index;i++)
        {
            temp[i] = a[i];
        }
        lkn_recursive(n,index+1,a);
        cout << "Buoc " << index << ": ";
        for(int i =0;i<= index;i++)
        {
            cout << temp[i] <<" ";
        }
        cout << endl;
    }
}
void sxc_lkn()
{
    int n;
    int a[101]; 
    cin >> n;
    for(int i =0;i<n;i++)
    {
        cin >> a[i];
    }
    lkn_recursive(n,0,a);
}
            //SẮP XẾP CHÈN - LIỆT KÊ NGƯỢC

            //PHẦN TỬ LỚN NHẤT TRONG DÃY CON
void ptlntdc()
{
    int tc;
    
}
            //PHẦN TỬ LỚN NHẤT TRONG DÃY CON

            //BỘ BA SỐ CÓ TỔNG NHỎ HƠN K
int bo_3_a[5005];
int bo_3_ans =0;
void bo_3_recursive(int index, int sum, int k, int cnt, int n) 
{
    if(cnt == 3)
    {
        if(sum <k)
            bo_3_ans++;
        return;
    }
    else{
        for(int  i = index;i<n;i++)
        {
            bo_3_recursive(i+1,sum+bo_3_a[i],k,cnt+1,n);
        }
    }
}
void bo_3_nho_hon_k()
{
    int tc; cin>>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n, k;
        cin>>n>>k;
        bo_3_ans = 0;
        for(int i =0;i<n;i++)
        {
            cin >> bo_3_a[i];
        }
        bo_3_recursive(0,0,k,0,n);
        cout << bo_3_ans << endl;
    }
}
            //BỘ BA SỐ CÓ TỔNG NHỎ HƠN K
            
            // Is Super Prime
bool is_prime(int n)
{
    if(n ==2) return true;
    else if(n < 2) return false;
    else{
        for(int i =2; i*i<=n;i++)
    {
        if(n%i == 0) return false;
    }
    }
    return true;
}
bool is_super_prime(int n)
{
    if(n == 0) return false;
    while(n)
    {
        if(is_prime(n) == false) return false;

        n/=10;
    }

    return true;
}
            // Is Super Prime

            //DÃY CON TĂNG DẦN UN FN
void dctc_recursive(int n,int a[],string s, int index)
{
    if(1)
    {

    }
    else{
        for(int i = index;i<n;i++)
        {
            
        }
    }
}
void dctd()
{
    int n;cin >>n;
    int a[30];
    int mask[30] = {0};
    for(int i =0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i = 0 ;i<n;i++)
    {
        int min ;
        int index = 0 ;
        while(mask[index] == 1)
        {
            index++;
        }
        min = a[index];
        for(int j =0;j<n;j++)
        {
            if(mask[j] == 0 && min > a[j])
            {
                min = a[j];
                index = j;
            }
        }
    }
}
            //DÃY CON TĂNG DẦN UN FN

            //MUA LƯƠNG THỰC
void mua_lt()
{
    int tc;
    cin>>tc;

    for(int ii=0;ii<tc;ii++)
    {
    int m,s ,n;
    cin >>m>>s>>n;
    int d =1;
    int mm =m;
    m = 0;
    int cnt = 0;
    while(d<=s)
    {
        if(d%7 == 0)
            {

            }
        else
        {
            if(m<n) 
            {
                m=m+mm;
                cnt++;
            }
        }
        m = m-n;
        if(m<0) {cnt = -1;break;}
        d++;
        
    }
    cout << cnt << endl;
    }

    
}

            //MUA LƯƠNG THỰC

            //THÁP HÀ NỘI
void thn_recursive(int n, char a, char b, char c)
{
    if ( n == 1) cout << a <<" -> " << c << endl;
    else{
        thn_recursive(n-1,a,c,b);
        thn_recursive(1,a,b,c);
        thn_recursive(n-1,b,a,c);
    }
}

void thn()
{
    int n;cin >> n;
    thn_recursive(n,'A','B','C');
}
            //THÁP HÀ NỘI

            //SẮP XẾP QUÂN HẬU 1

void queen_recursive(int a[][20], int n,int h, int c)
{
    if(1)
    {}
    else{

    
    }
}
void queen()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n;
        cin >> n;
        int a[20][20] = {0};
    }
}
            //SẮP XẾP QUÂN HẬU 1

            //MERGE SORT

int a[1000005];
void merge(int a[], int l, int m, int r)
{
    int i ,j,k = l;
    int n1 = m-l+1;
    int n2 = r -m;
    int *left = new int[n1];
    int *right = new int[n2];
    for(i = 0; i<n1;i++)
    {
        left[i] = a[l+i];
    }

    for( i = 0;i<n2;i++)
    {
        right[i] = a[m+i+1];
    }
        //tron
    i = 0;j=0;
    while(i<n1&&j<n2)
    {
        if(left[i] <= right[j])
        {
            a[k++] = left[i++];
        }
        else{
            a[k++] = right[j++];
        }
    }
    while(i<n1)
    {
        a[k++] = left[i++];
    }
    while(j<n2)
    {
        a[k++] = right[j++];
    }


    delete[] left;
    delete[] right;
}

void merge_sort(int a[], int l, int r)
{
    if(l<r)
    {
        int m = (l+r)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        merge(a,l,m,r);

    }
}

void merge_sort_main()
{
    int tc;cin>>tc;
    for(int ii=0;ii<tc;ii++)
    {
    int n;cin>>n;

    for(int i=0;i<n;i++)
    {
        cin >> a[i];

    }
    merge_sort(a,0,n-1);
    //cout<<"n = " << n <<endl;
    for(int i =0;i<n;i++)
    {cout << a[i] << " ";}
        cout<< endl;
    }
}
            //MERGE SORT

            //SẮP XẾP THEO GIÁ TRỊ TUYỆT ĐỐI
int abs(int a, int b)
{
    if(a>b) return a-b;
    else
    return b-a;
}

void abs_merge(int a[], int l, int m, int r,int x)
{
    int i ,j,k = l;
    int n1 = m-l+1;
    int n2 = r -m;
    int *left = new int[n1];
    int *right = new int[n2];
    for(i = 0; i<n1;i++)
    {
        left[i] = a[l+i];
    }

    for( i = 0;i<n2;i++)
    {
        right[i] = a[m+i+1];
    }
        //tron
    i = 0;j=0;
    while(i<n1&&j<n2)
    {
        if(abs(left[i],x) <= abs(right[j],x))
        {
            a[k++] = left[i++];
        }
        else{
            a[k++] = right[j++];
        }
    }
    while(i<n1)
    {
        a[k++] = left[i++];
    }
    while(j<n2)
    {
        a[k++] = right[j++];
    }


    delete[] left;
    delete[] right;
}

void abs_merge_sort(int a[], int l, int r, int x)
{
    if(l<r)
    {
        int m = (l+r)/2;
        abs_merge_sort(a,l,m,x);
        abs_merge_sort(a,m+1,r,x);
        abs_merge(a,l,m,r,x);

    }
}

void abs_merge_sort_main()
{
    int tc;cin>>tc;
    for(int ii=0;ii<tc;ii++)
    {
    int n;cin>>n;
    int x;cin>>x;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];

    }
    abs_merge_sort(a,0,n-1, x);
    //cout<<"n = " << n <<endl;
    for(int i =0;i<n;i++)
    {cout << a[i] << " ";}
        cout<< endl;
    }
}

            //SẮP XẾP THEO GIÁ TRỊ TUYỆT ĐỐI

            //TẬP CON BẰNG NHAU
bool tcbn_check = 0;
void tcbn_recursive(int a[],int n ,int res, int sum, int index ) // n = n thuc te - 3;
{
    if(sum == res)
    {
        tcbn_check = 1;
        return;
    }
    else{

            for(int i=index;i<n;i++)
            {
                if(sum + a[i] <= res&&tcbn_check == 0)
                {
                    tcbn_recursive(a,n,res,sum+a[i],i+1);
                }
            }
        
        
    }
}
void tcbn()
{
    int tc;cin>>tc;
    for(int ii=0;ii<tc;ii++)
    {
        int n;cin>>n;
        int a[200];
        int sum = 0;
        for(int i=0;i<n;i++)
        {
        cin >> a[i];
        sum+=a[i];
        }

        merge_sort(a,0,n-1);
        int max = a[n-1];
        if(sum%2 !=0) cout << "NO" <<endl;
        else{
            if(max > sum/2) cout << "NO" <<endl;
            else if( max == sum/2) cout << "YES" << endl;
            else{
                int res = sum/2 - max;
                tcbn_check = 0;
                tcbn_recursive(a,n-3,res,0,0);
                if(tcbn_check) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }

    }
}
            //TẬP CON BẰNG NHAU

            //SỐ XA CÁCH
bool sxc_check(string s)
{
    for(int i =0;i<s.length()-1;i++)
    {
        if(abs(int(s[i]) , int(s[i+1]))  == 1) return false;
    }
    return true;
}
void sxc_recursive(int a[],  int n, string s)
{
    if(s.length() == n)
    {
        if(sxc_check(s)) cout << s << endl;
        return;
    }
    else{
        for(int i = 1;i<=n;i++)
    {
        if(a[i] == 0)
        {
            a[i] = 1;
            sxc_recursive(a,n, s+ char('0'+i));
            a[i] = 0;
        }
    }
}
}
void sxc()
{
    int tc;cin>>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n;cin >> n;
        int a[20] = {0};
        sxc_recursive(a,n,"");     
    }
}
            //SỐ XA CÁCH

            //SẮP XẾP CÔNG VIỆC 1
void sxcv1_recursive(int a[], int b[],int cnt, int begin, int n, int &ans, int max) //cnt =0 , begin = 0
{
    if(begin  == max)
    {

        return;
    }
    else{
    if(cnt > ans)
    {
        ans = cnt;
    }
        for(int i =0;i<n;i++)
        {
            if(a[i] >= begin)
            {
                sxcv1_recursive(a,b,cnt+1,b[i],n,ans,max);
            }
        }
    }
}
void sxcv1()
{
    int tc;cin>>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n;
        cin >> n;
        int a[1005];
        int b[1005];
        int min;
        for(int i =0;i<n;i++)
        {
            cin >> a[i];
            if(i == 0) min = a[i];
            if(min>a[i]) min = a[i];
        }
        int max = 0;
            for(int i =0;i<n;i++)
        {
            cin >> b[i];
            if(b[i] > max) max = b[i];
        }
        int ans =0;
        sxcv1_recursive(a,b,0,0,n,ans,max);
        cout << ans+1 << endl;
    }
}
            //SẮP XẾP CÔNG VIỆC 1

int main()
{
    sxcv1();
}