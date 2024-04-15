#include<bits/stdc++.h>
using namespace std;


            //MERGE SORT
void swap(long long &a,long long &b)
{
    long long temp = a;
    a=b;
    b=temp;
}

void merge(long long a[], long long b[],long long l,long long m, long long r)
{
    long long n1 = m-l+1;
    long long n2 = r-m;
    long long *left = new long long[n1];
    long long *right = new long long[n2];
    long long *aleft = new long long[n1];
    long long *aright = new long long[n2];
    long long k =0;
    for(long long i = l;i<=m;i++)
    {
        left[k++] = b[i];
        aleft[k-1] = a[i];
    }
    k = 0;
    for(long long i = m+1;i<=r;i++)
    {
        right[k++] = b[i];
        aright[k-1] = a[i];
    }
    long long i =0;
    long long j =0;
    k = l;
    while(i<n1&&j<n2)
    {
        if(left[i] <= right[j])
        {
            b[k++] = left[i];
            a[k-1] = aleft[i];
            i++;

        }
        else
        {
            b[k++] = right[j];
            a[k-1] = aright[j];
            j++;
        }
    }
    while(i<n1)
    {
        b[k++] = left[i++];
        a[k-1] = aleft[i-1];
    }
    while(j<n2)
    {
        b[k++] = right[j++];
        a[k-1] = aright[j-1];
    }

    delete[] left;
    delete[] right;

    delete[] aleft;
    delete[] aright;
}

void merge_sort(long long a[], long long b[], long long l, long long r)
{
    if(l<r)
    {
        long long m = (l+r)/2;
        merge_sort(a,b,l,m);
        merge_sort(a,b,m+1,r);
        merge(a,b,l,m,r);
    }
}
            //MERGE SORT

            //SẮP XẾP CÔNG VIỆC 1
void sxcv()
{
    long long tc;cin >> tc;
    for(long long ii=0;ii<tc;ii++)
    {
        long long n;cin >> n;
        long long a[100005];
        long long b[100005];
        for(long long i=0;i<n;i++) cin >> a[i] >>b[i];
        //for(long long i=0;i<n;i++) cin >> b[i];
        for(long long i =0;i<n;i++)
        {
            long long min = b[i];
            long long index = i;
            for(long long j = i;j<n;j++)
            {
                if(min > b[j])
                {
                    min = b[j];
                    index = j;
                }

            }
                long long temp = b[index];
                b[index] = b[i];
                b[i] = temp;
                temp = a[index];
                a[index] = a[i];
                a[i] = temp;
        }

        long long cnt =1, temp = b[0];
        for(long long i =1;i<n;i++)
        {
            if(a[i] >= temp)
            {
                cnt++ ;
                temp = b[i];
            }
        }
        cout << cnt << endl;
    }
}
            //SẮP XẾP CÔNG VIỆC 1

            //LỰA CHỌN TỐI ƯU
void lctu()
{
    long long tc;cin >> tc;
    for(long long ii=0;ii<tc;ii++)
    {
        long long n;cin >> n;
        long long a[100005];
        long long b[100005];
        for(long long i=0;i<n;i++) cin >> a[i] >>b[i];
        //for(long long i=0;i<n;i++) cin >> b[i];

        merge_sort(a,b,0,n-1);
        long long cnt =1, temp = b[0];
        for(long long i =1;i<n;i++)
        {
            if(a[i] >= temp)
            {
                cnt++ ;
                temp = b[i];
            }
        }
        cout << cnt << endl;
    }
}
            //LỰA CHỌN TỐI ƯU

            //BỘ BA SỐ CÓ TỔNG NHỎ HƠN K (UN AC)
void bo_3_recursive(long long sum, long long a[], long long index, long long n,long long &check, long long k, long long cnt, long long &ans)
{
    if(sum >=k )
    {
        check = 1;
        return;
    }
    if(cnt == 3)
    {
        if(sum < k) ans++;
        return;
    }
    else{
        for(long long i=index;i<n;i++)
        {
            if(check == 0)
            {
                bo_3_recursive(sum+a[i],a,i+1,n,check,k,cnt+1,ans);
                if(check ==1)
                {
                    i = n;check=0;
                }
            }
        }
    }
}
void bo_3()
{
    long long tc;cin >> tc;
    for(long long ii=0;ii<tc;ii++)
    {
        long long n, k;
        cin >> n>>k;
        long long a[5005];
        for(long long i =0;i<n;i++)
        {
            cin >> a[i];

        }
        long long b[5005] = {0};
        merge_sort(b,a,0,n-1);
        //for(long long i =0;i<n;i++) cout << a[i] << " ";cout << endl;
        long long check = 0;
        long long ans =0;
        bo_3_recursive(0,a,0,n,check,k,0,ans);
        cout << ans << endl;

}
}
            //BỘ BA SỐ CÓ TỔNG NHỎ HƠN K (UN AC)

            //PHẦN TỬ LỚN NHẤT TRONG DÃY CON
//********************************************************************
            //PHẦN TỬ LỚN NHẤT TRONG DÃY CON



            //SỐ KHỐI LẬP PHƯƠNG
bool check_so_lap_phuong(long long a)
{
    for(long long i = 1;i*i*i<=a;i++)
    {
        if(i*i*i == a) return true;
    }
    return false;
}
void sklp_recursive(char c[],long long index,long long sum, long long n, long long &max)
{
    if(check_so_lap_phuong(sum))
    {
        if(max < sum) max = sum;
    }

        for(long long i = index;i<n;i++)
        {
            sklp_recursive(c,i+1,sum*10+int(c[i] - '0'),n,max);
        }

}
void sklp()
{
    long long tc;cin >> tc;
    for(long long ii =0;ii<tc;ii++)
    {
        char c[20];
        string s;cin >> s;
        long long n = s.length();
        for(long long i=0;i<n;i++)
        {
            c[i] = s[i];
        }
        long long max = -1;
        sklp_recursive(c,0,0,n,max);
        cout << max << endl;

    }
}
            //SỐ KHỐI LẬP PHƯƠNG

            //ĐỔI CHỖ CÁC CHỮ SỐ
void dcccs()
{
    long long tc; cin >> tc;
    for(long long ii =0;ii<tc;ii++)
    {
        long long n;cin >> n;
        char c[20];
        string s;cin >>s;
        long long l = s.length();
        for(long long i=0;i<l;i++)
        {
            c[i] = s[i];
        }
        long long index = 0;
        while(n--)
        {
            if(index == l-1) break;
                char max = c[index];
                long long idxmax = index;
            for(long long i=index+1;i<l;i++)
            {
                if(c[i] >= max) {
                    max = c[i];
                    idxmax = i;
                }
            }
            if(idxmax == index || max == c[index])
            {
                n++;
                index ++ ;
            }
            else
            {
                swap(c[index], c[idxmax]);
                index++;
            }
        }
        for(long long i =0;i<l;i++)
        {
            cout << c[i] ;
        }
        cout << endl;
    }
}
            //ĐỔI CHỖ CÁC CHỮ SỐ

            //CHỌN SỐ TỪ MA TRẬN VUÔNG CẤP N
void cstmt_recursive(long long a[][20],long long mask[], long long h, long long c, long long sum, long long k, long long n, string s, long long &cnt, string &ss)
{
    if(h == n)
    {
        if(sum == k)
        {
            ss+= s;
            cnt++;
        }
        return;
    }
    else{

        for(long long i =0;i<n;i++)
        {
            if(mask[i] == 0)
            {
                mask[i] = 1;
                cstmt_recursive(a,mask,h+1,i,sum+a[h][i],k,n,s+char(i +'0'),cnt,ss);
                mask[i] = 0;
            }
        }
    }
}
void cstmt()
{
    long long n; long long k;
    cin >>n>>k;
    long long a[20][20] = {0};
    long long mask_cot[20] = {0};
    for(long long i =0;i<n;i++)
    {
        for(long long j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    string ss ="";
    long long cnt = 0;
    cstmt_recursive(a,mask_cot,0,0,0,k,n,"",cnt,ss);
    cout << cnt << endl;
    //cout << ss<<endl;
    for(long long i =0;i<ss.length()/n;i++)
    {
        for(long long j=i*n;j<n+i*n;j++)
        {

            cout << char(ss[j] + 1) << " ";
        }
        cout << endl;
    }
}
            //CHỌN SỐ TỪ MA TRẬN VUÔNG CẤP N

            //SỐ NGUYÊN TỐ
vector<string> snt_s;
bool is_prime(long long a)
{
    if(a <= 1) return false;
    if(a > 2)
    {
        for(long long i=2;i*i<=a;i++)
        {
            if(a%i == 0) return false;
        }

    }
    return true;
}
void snt_recursive(long long a[], long long index, long long n, long long sum, long long s,long long cnt,string ss, long long nn)
{
    if(cnt == nn)
    {
        if(sum == s)
        {
            snt_s.push_back(ss);
        }
        return;
    }
    else{
        for(long long i=index;i<n;i++)
        {
            string q ="";
            long long g = a[i];
            while(g)
            {
                q = char(g%10 +'0') + q;
                g/=10;
            }
            snt_recursive(a,i+1,n,sum+a[i],s,cnt+1,ss+q+' ', nn);
        }
    }
}
void snt()
{
    long long tc;cin >> tc;
    for(long long ii = 0;ii<tc;ii++)
    {
        long long n,p,s;
        cin>> n>>p>>s;
        long long a[200];
        long long index =0;
        for(long long i =p+1;i+p<s;i++)
        {
            if(is_prime(i))
            {
                a[index] = i;
                index++;
            }
        }
        snt_s.clear();
        snt_recursive(a,0,index,0,s,0,"",n);
        cout << snt_s.size() << endl;
        for(long long i=0;i<snt_s.size();i++)
        {
            cout << snt_s[i] << endl;
        }

    }
}
            //SỐ NGUYÊN TỐ

            //SẮP XẾP QUÂN HẬU 2
void queen2_mask(long long mask[][20],long long hm, long long cm, long long n )
{
    long long hh[8] ={-1,-1,0,1,1,1,0,-1};
    long long cc[8] ={0,1,1,1,0,-1,-1,-1};
    for( long long i =0;i<8;i++)
    {
        long long h = hm;
        long long c = cm;
    
        while(h+hh[i] >=1 && h+hh[i] <=8 && c+cc[i] >=1 && c+cc[i]<=8 )
        {
            h+=hh[i];
            c+=cc[i];
            if(mask[h][c] == 0)
            {
                mask[h][c] = n;
            }
        }
    }
}
void queen2_unmask(long long mask[][20],long long hm, long long cm, long long n )
{
    long long hh[8] ={-1,-1,0,1,1,1,0,-1};
    long long cc[8] ={0,1,1,1,0,-1,-1,-1};
    for( long long i =0;i<8;i++)
    {
        long long h = hm;
        long long c = cm;
    
        while(h+hh[i] >=1 && h+hh[i] <=8 && c+cc[i] >=1 && c+cc[i]<=8 )
        {
            h+=hh[i];
            c+=cc[i];
            if(mask[h][c] == n)
            {
                mask[h][c] = 0;
            }
        }
    }
}

void queen2_recursive(long long a[][20],long long mask[][20],long long n,
long long sum, long long &max, long long h, long long c) // n =8,h=1, c k can thiet
{
    if(h == n+1)
    {
        if(sum > max)
        {
            max =sum;
        }
        return;
    }
    else{
        for(long long i=1;i<=n;i++)
        {
            if(mask[h][i] == 0)
            {
                mask[h][i] = h;
                queen2_mask(mask,h,i,h);
                queen2_recursive(a,mask,n,sum+a[h][i],max,h+1,c);
                queen2_unmask(mask,h,i,h);
                mask[h][i] = 0;
            }
        }
    }
}
void queen2()
{
    long long tc;cin >> tc;
    for(long long ii =0;ii<tc;ii++)
    {
        long long a[20][20] = {0};
        long long mask[20][20] = {-1};
        for(long long i =1 ;i<=8;i++)
        {
            for(long long j=1;j<=8;j++)
            {
                cin >> a[i][j];
                mask[i][j] = 0;
            }
        }
        long long max = 0;
        queen2_recursive(a,mask,8,0,max,1,1);
        cout << max << endl;
    }
}
            //SẮP XẾP QUÂN HẬU 2

            //KÝ TỰ LẶP
long long ktl_check(string s1, string s2)
{
        long long cnt =0;


        long long a[30] ={0};
        for(long long j=0;j<s1.length();j++)
        {
            a[s1[j] - 'A']++;
        }
        for(long long j=0;j<s2.length();j++)
        {
            a[s2[j]- 'A']++;
            if(a[s2[j] - 'A'] == 2)
            cnt++;
        }

    return cnt;
}

void ktl_update(long long str[],long long n, long long &min, long long count[][30])
{
    long long temp =0;
    for(long long i =0;i<n-1;i++)
    {
        temp += count[str[i]][str[i+1]];

    }
    if(temp < min ) min =temp;
}
void ktl_recursive( long long n, long long index, long long &min, long long str[],long long mask[], long long count[][30] )
{
    if(index == n)
    {
        ktl_update(str,n,min,count);
        return;
    }
    else{
        for(long long i =0;i<n;i++)
        {
            if(mask[i] == 0)
            {
                mask[i] = 1;
                str[index] = i;
                ktl_recursive(n,index+1,min,str,mask, count);
                mask[i] = 0;
            }
        }
    }
}
void ktl()
{
    long long n;cin >> n;
    long long mask[30] = {0};
    long long count[30][30] = {0};
    string str[30];
    long long show[30];
    for(long long i=0;i<n;i++)
    {
        cin >> str[i];
    }
    for(long long i=0;i<n-1;i++)
    {
        for(long long j = i+1;j<n;j++)
        {
            count[i][j] = ktl_check(str[i], str[j]);
            count[j][i] = count[i][j];
        }
    }

    long long min = 1e9;
    ktl_recursive(n,0,min,show,mask,count);
    cout << min<< endl;


}
            //KÝ TỰ LẶP

            //PHÉP TOÁN CƠ BẢN
bool ptcb_check(char c[])
{
    long long n = 8; // vi mang luon co 8 ki tu
    long long a = (c[0]-'0') *10 + c[1] - '0';
    long long b = (c[3]-'0') *10 + c[4] - '0';
    long long ans = (c[6]-'0') *10 + c[7] - '0';
    if(c[2] == '+')
    {
        if(a+b == ans) return true;
        else return false;
    }
    else if(c[2] == '-')
    {
        if(a-b == ans) return true;
        else return false;
    }
        else if(c[2] == '*')
    {
        if(a*b == ans) return true;
        else return false;
    }
        else if(c[2] == '/')
    {
        if(a%b == 0 && a/b == ans) return true;
        else return false;
    }
}
void ptcb_show(char s[])
{
    for(long long i =0 ;i<8;i++)
    {
        cout<< s[i];
        if(i == 1||i == 2||i == 4||i==5)
            cout << " ";
    }
    cout<<endl;
}
void ptcb_recursive(long long index, char s[], long long &ans, long long n) // n =8
{
    if(ans == 1) return;
    if(index == n )
    {
        if(ptcb_check(s) &&  ans == 0) 
        {
            ptcb_show(s);
            ans =1;
        }
        return;
    }
    else{
        if(s[index] == '?')
        {
            if(index == 2)
            {
                char dau[4] = {'+','-','*','/'};
                for(long long  i =0;i<4;i++)
                {
                    s[index] =  dau[i];
                    ptcb_recursive(index+1,s,ans,n);
                    s[index] = '?';
                }
            }
            else if(index == 0|| index == 3||index==6)
            {
                for(char i = '1';i<='9';i++)
                {
                    s[index] = i;
                    ptcb_recursive(index+1,s,ans,n);
                    s[index]= '?';
                }
            }
            else if(index == 5)
            {
                s[index] = '=';
                ptcb_recursive(index+1,s,ans,n);
            }
            else
            {
                for(char i = '0';i<='9';i++)
                {
                    s[index] = i;
                    ptcb_recursive(index+1,s,ans,n);
                    s[index]= '?';
                }
            }
        }
        else{
            ptcb_recursive(index+1,s,ans,n);
        }
    }
}

void ptcb()
{
    long long tc;cin >> tc;
    for(long long i =0;i<tc;i++)
    {
        long long n = 8;
        char s[20];
        char show[20];
        for(long long i=0;i<n;i++)
        {
            cin >> s[i];
            show[i] = s[i];

        }
        long long ans =0;
        ptcb_recursive(0,s,ans,n);
        if(ans == 0)
        cout << "WRONG PROBLEM!" << endl;
    }
}
            //PHÉP TOÁN CƠ BẢN

            //TỔ HỢP SỐ CÓ TỔNG BẰNG X
vector<string> thsctbx_str;
void thsctbx_recursive(long long a[], long long index, string s, long long sum, long long x, long long &ans, long long n, long long &cnt)
{
    if(sum==x)
    {
        s =  '{'+s;
        s[s.length() -1 ] = '}';
        thsctbx_str.push_back(s);
        ans =1 ;
        cnt++;
        return;
    }
    else
    {
        for(long long i = index;i<n;i++)
        {
            if(sum + a[i] <= x)
            {
                string temp ="";
                long long t = a[i];
                while(t)
                {
                    temp = char(t%10 + '0') + temp;
                    t/=10;
                }
                thsctbx_recursive(a,i,s+temp + ' ',sum+a[i],x,ans, n, cnt);
            }
        }
    }
}
void thsctbx()
{
    long long tc;cin>>tc;
    for(long long ii =0;ii<tc;ii++)
    {
        long long n ;
        long long a[30];
        long long s;
        cin >> n >>s ;
        for(long long i=0;i<n;i++)
        {cin >> a[i];}
        if(a[0] >  s) cout << "-1" <<endl;
        else{
            long long ans =0;
            long long cnt = 0;
            thsctbx_str.clear();
            thsctbx_recursive(a,0,"",0,s,ans,n,cnt);
            
            if(ans == 0) 
            cout << "-1" << endl;
            else
            {
                cout<< cnt << " ";
                for(long long i=0;i<thsctbx_str.size();i++)
                {
                    cout << thsctbx_str[i] <<" ";
                }
                cout << endl;
            }
        }
    }
}
            //TỔ HỢP SỐ CÓ TỔNG BẰNG X

            //DÃY CON CÓ TỔNG LẺ
void dcctl_recursive(long long a[], long long index, string s,long long sum)
{
    if(sum%2 == 1)
    {
        cout << s << endl;
    }

        for(long long i=index;i>=0;i--)
        {
            long long t = a[i];
            string temp ="";
            while(t)
            {
                temp = char(t%10 + '0') + temp;
                t /=10;
            }
            dcctl_recursive(a,i-1,s+temp+' ',sum+a[i]);
        }
    }

void dcctl()
{
    long long tc;cin >> tc;
    for(long long ii =0;ii<tc;ii++)
    {
        long long a[200];
        long long b[200];
        long long n;cin >>n;
        for(long long i=0;i<n;i++)
        {
            cin >> a[i];

        }
        merge_sort(b,a,0,n-1);
        for(long long i =0;i<n;i++)
        {
            long long t = a[i];
            string temp ="";
            while(t)
            {
                temp = char(t%10 + '0') + temp;
                t /=10;
            }            
            dcctl_recursive(a,i-1,temp+' ',a[i]);  
        }


    }
}
            //DÃY CON CÓ TỔNG LẺ

            //DÃY CON CÓ K PHẦN TỬ TĂNG DẦN
void dcc_recursive(long long a[],long long n, string s, long long k, long long index, long long cnt)
{
    if(cnt ==k)
    {
        cout << s << endl;
        return;
    }   
    else
    {
        for(long long i=index;i<n;i++)
        {
            long long t = a[i];
            string temp ="";
            while(t)
            {
                temp = char(t%10 + '0') + temp;
                t /=10;
            }
            dcc_recursive(a,n,s+temp+' ',k,i+1,cnt+1);
        }
    }
}
void dcckpttd()
{
    long long tc;cin >> tc;
    for(long long ii =0;ii<tc;ii++)
    {
        long long n,k;
        cin >>n>>k;
        long long a[20];
        long long b[20];
        for(long long i =0;i<n;i++)
        {
            cin >>a[i];
        }
        merge_sort(b,a,0,n-1);
        dcc_recursive(a,n,"",k,0,0);

    }
}
            //DÃY CON CÓ K PHẦN TỬ TĂNG DẦN

            //PHÂN TÍCH SỐ 2
vector<string> pts2_s;
void pts2_recursive(long long n, long long sum, string str, long long index)
{
    if(sum == n)
    {
        str = '('+ str;str[str.length()-1] =')';
        //cout << str << endl;
        pts2_s.push_back(str);
        return;
    }
    else{

            for(long long i=index;i>=1;i--)
            {
                if(sum+i <= n)
                {
                long long t = i;
                string temp ="";
                while(t)
                {
                    temp = char(t%10 + '0') + temp;
                    t /=10;
                }   
                pts2_recursive(n,sum+i,str+temp+' ',i) ;
                }
            
            }
            
        
    }
}
void pts2()
{
    long long tc;cin >> tc;
    for(long long ii =0;ii<tc;ii++)
    {
        long long n;
        cin >> n;
    //vector<string> str;
    pts2_s.clear();
    pts2_recursive(n,0,"",n);
    cout << pts2_s.size() << endl;
    for(long long i=0;i<=pts2_s.size() - 1;i++)
    {
        cout << pts2_s[i]<< " ";
    }
    cout << endl;

    }

}
            //PHÂN TÍCH SỐ 2

            // /BIẾN ĐỔI VỀ 1

void bdv1()
{
    long long tc;cin >> tc;
    for(long long ii=0;ii<tc;ii++)
    {
        long long n;
        cin >> n;
        long long a[100005] = {0};
        a[1] = 0;
        for(long long i = 2;i<=n;i++)
        {
            a[i] = a[i-1] +1;
            if(i%2==0)
            a[i] = min(a[i], a[i/2] + 1);
            if(i%3==0)
            a[i] = min(a[i],a[i/3]+1);
        }
        cout << a[n] << endl;
    }
}
            // /BIẾN ĐỔI VỀ 1

            //GIÁ TRỊ NHỎ NHẤT CỦA BIỂU THỨC
void gt_min_cbt()
{
    long long tc;cin>>tc;
    for(long long ii =0;ii<tc;ii++)
    {
        long long n;
        cin >> n;
        long long a[n];
        long long b[n];
        long long c[n] = {0};
        for(long long i =0;i<n;i++)
            cin >> a[i];
        for(long long i =0;i<n;i++)
            cin >> b[i];
        merge_sort(c,a,0,n-1);
        merge_sort(c,b,0,n-1);
        long long res = 0;
        for(int i=0;i<n;i++)
        {
            res += a[i] * b[n-1-i];
        }
        cout << res << endl;
    }
}

            //GIÁ TRỊ NHỎ NHẤT CỦA BIỂU THỨC
int  main()
{   
    gt_min_cbt();
    return 0;
}
