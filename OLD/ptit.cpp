#include<bits/stdc++.h>
using namespace std;
int X[1000000], n, sum, cnt =0;
int mark[1000000] = {0};

char XX[2000];
bool kt()
{
	for(int i=1;i<=n/2;i++)
	{
		if(X[i]!=X[n-i+1]) return false;
	}
	return true;
}

bool kt2()
{
    int sum1 = 0;
    for(int i =1 ; i<=n;i++)
    {
        if(mark[i])
        {
            sum1 += X[i];
        }
    }
    if(sum1 == sum ) 
    {
            cnt ++ ;
            return 1;
    }

    else return 0;
}

void print()
{
	for(int i=1;i<=n;i++) cout<<X[i]<<" ";
	cout<<endl;
}


void print2()
{
	for(int i=1;i<=n;i++) 
    {
        if(mark[i])
        {
                cout<<X[i]<<" ";
        }
        
    }

	cout<<endl;
}
void Try(int i)
{
	for(int j=0;j<=1;j++)
	{
		mark[i]=j;
		if(i==n)
		{
			if(kt2())
				print2();
		}
		else Try(i+1);
	}
}

void Try2(int n)
{
    if(XX[n] == '0')
        XX[n] = '1';
    else{
        XX[n]  = '0';
        Try2(n-1) ;
    }
}


void print3()
{
    for(int i=1;i<=sum;i++)
    {
        cout<< X[i] << " ";
    }
    cout<<endl;
}

void Try3(int n, int index)
{
    if(index == sum+1)
    {
        print3();
        return;
    }
    for(int i =1;i<=n;i++)
    {
        if(mark[i] ==0)
        {
            mark[i] = 1;
            X[index] = i ;

            Try3(n,index+1);
            mark[i] = 0;
        }
        
    }
}

void Try4(int j ,int n,int index)
{
    if(index == sum+1)
    {
        print3();
        return;
    }
    for(int i =j;i<=n;i++)
    {
        X[index] = i;
        Try4(i+1,n,index+1);
    }
}
///////////////////////////////////////////////////////////////////////////////////////////

            //Tập con kế tiếp
void recursive_tckt(int k, int n)
{
    if(X[k] == n)
    {
        X[k] = 1;
        recursive_tckt(k-1,n);
    }
    else{
        X[k]++;
    }
}
void tap_con_ke_tiep()
{
    int tc;
    cin >>tc;
    for(int ii=0;ii<tc;ii++)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<k;i++)
        {
            cin >> X[i];
        }
        recursive_tckt(k-1,n);
        for(int i=0;i<k;i++)
        {
            cout << X[i] <<" ";
        }
        cout << endl;
    }
}
            //DAT TEN 2
char dt_chr[100];
void dt_print(int k)
{
    for(int i=0;i<k;i++)
    {
        cout << dt_chr[i] ;
    }
    cout <<endl;
}
void recursive_dt(int n, int index,int k, char j)
{   
    if(index == k)
        {
            dt_print(k);
            return;
        }
    else{

        for(char i = j;i<'A' +n;i++)
        {
            dt_chr[index] = i;
            recursive_dt(n,index+1,k,i+1);
        }
    }
}
void dat_ten_2()
{
    int tc;
    cin >>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n,k;
        cin>>n>>k;
        recursive_dt(n,0,k,'A');
    }
}
            //DAT TEN 2

            //DAT TEN 1
string s[100] = {};
string ss[100] = {};

void dt1_sort(int n)
{
    for(int i =0;i<n;i++)
    {
        int min = i;
        for(int j=i;j<n;j++)
        {
            if(s[min][0] > s[j][0])
            {
                min = j;
            }
        }
        string temp = s[min];
        s[min] = s[i];
        s[i] = temp;

    }
}
void dt1_print(int k)
{
    for(int i=0;i<k;i++)
    {
        cout << ss[i] << " " ;
    }
    cout <<endl;
}
bool check_str(string a, string b)
{
    if(a.length() == b.length())
    {
        for(int i =0;i<a.length();i++)
        {
            if(a[i] != b[i])
                return false;

        }
        return true;
    }
    else
        return false;
}

void recursive_dt1(int n,int index, int k , int ii )
{
    if(index == k)
    {
        dt1_print(k);

    }
    else{
        for(int i =ii;i<n;i++)
        {
            ss[index] = s[i];
            recursive_dt1(n,index+1,k,i+1);
        }
    }
    
}
void dat_ten_1()

{
    int n,k;
    cin >> n >>k;

    int nn = 0;
    for(int i=0;i<n;i++)
    {
        int status =0;
        string str;
        cin >>str;
        for(int j=0;j<n;j++)
        {
            if(check_str(str,s[j]) == true)
            {
                status = 1;
                break;
            }
        }
        if(status == 0)
        {
            s[i] = str;
            nn++;
        }

        

    }
    
    dt1_sort(nn);
    recursive_dt1(nn,0,k,0);
}

            //DI CHUYỂN TRONG MÊ CUNG 1
int m1_maze[100][100];
int m1_mark[100][100] ={0};
int m1_move_h[2] = {1,0} ;
int m1_move_c[2] = {0,1} ;
char m1_chr[10000] ;
int m1_ans = 0;

void m1_print(int k)
{
    for(int i=0;i<k;i++)
    {
        cout << m1_chr[i];
    }
    cout << " ";
}

void m1_recursive(int h, int c,int k,int n, int nn)
{
    m1_mark[h][c] = 1;
    if(h == n-1 && c == nn-1)
    {
       // m1_print(k);
        m1_mark[h][c] = 0;
        m1_ans++;
        return;
    }
    for(int i=0;i<2;i++)
    {
        if(h+m1_move_h[i] >=0 && h+m1_move_h[i]<= n-1 /*&& m1_maze[h+m1_move_h[i]][c +m1_move_c[i]] == 1*/
        && c +m1_move_c[i] >=0 && c+m1_move_c[i] <=nn-1 && m1_mark[h+m1_move_h[i]][c +m1_move_c[i]] == 0)
        {
            if(i ==0)   m1_chr[k] = 'D';
            else m1_chr[k] = 'R';
            m1_recursive(h+m1_move_h[i],c +m1_move_c[i],k+1,n, nn);
        }
    }
    m1_mark[h][c] = 0;
}
void maze_1()
{
    int tc;
    cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int nn,n;
        m1_ans =0;
        cin >> n >>nn;
        for(int i=0;i<n;i++)
        {
            for(int j =0;j<nn;j++)
            {
                cin >> m1_maze[i][j];
                m1_mark[i][j] =0;
            }
        }

        m1_recursive(0,0,0,n,nn);
        cout << m1_ans<<endl;
        if(m1_ans == 0)
        {
            cout << "-1" <<endl;
        }
    }
}

            //DI CHUYỂN TRONG MÊ CUNG 1

            //SẮP XẾP CHỮ SỐ
void sxcs()
{
    int tc;
    cin >> tc;
    for(int ii=0;ii<tc;ii++)
    {
        int a[100] = {0};
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            string s;
            cin >> s;
            for(int j=0;j<s.length();j++)
            {
                if(a[s[j] - '0'] == 0)
                {
                    a[s[j] - '0'] = 1;
                }
            }
        }
        for(int i=0;i<=9;i++)
        {
            if(a[i] == 1)
                cout << i<< " ";
        }
        cout <<endl;
    }
}
            //SẮP XẾP CHỮ SỐ

            //SẮP XẾP THEO GIÁ TRỊ TUYỆT ĐỐI
int abs(int a, int b){
    if(a - b <0)
        return b-a;
    else
    return a-b;
}

void sxtgttd()
{
    int tc;
    cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n,k;
        int a[100005];
        cin >>n>>k;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        for(int i=0;i<n;i++)
        {
            int min = abs(k,a[i]);
            int index_min = i;
            for(int j =i+1;j<n;j++)
            {
                if(abs(k,a[j]) < min)
                {
                    min = abs(k,a[j]);
                    index_min = j;
                }

            }
            int temp = a[i];
            a[i]  = a[index_min];
            a[index_min] = temp;
        }
        for(int i =0;i<n;i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}
            //SẮP XẾP THEO GIÁ TRỊ TUYỆT ĐỐI

            //TỔNG SỐ CÁCH DI CHUYỂN
int ans_tscdc = 0;
int a_tscdc[100005] = {0};
void print_tscdc(int index)
{
    for(int i =0;i<=index;i++)
    {
        cout << a_tscdc[i] << " ";

    }
    cout << endl;
}
void recursive_tscdc(int n,int k, int sum, int index)
{
    if(sum == n)
    {
        ++ans_tscdc;
        //print_tscdc(index -1);
        return;
    }

    else{
        for(int i=1;i<=k;i++)
        {
            if(sum +i <= n)
            {
                a_tscdc[index]  = i;
                recursive_tscdc(n,k,sum+i, index+1);
            }

        }
    }
}
void tscdc()
{
    int tc;
    cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        ans_tscdc =0;
        int n,k;
        cin >> n>>k;
        recursive_tscdc(n,k,0,0);
        cout << ans_tscdc << endl;
    }
}
            //TỔNG SỐ CÁCH DI CHUYỂN

            //TẬP CON BẰNG NHAU
int tcbn_ans = 0;
int tcbn_a[105] ;
int tcbn_mask[105] = {0};
bool tcbn_check(int n)
{
    int sum = 0;
    int check = 0;
    int cnt =0;
    for(int i =0;i<n;i++)
    {
        if(tcbn_mask[i] == 1)
        {
            sum += tcbn_a[i];
            cnt++;
        }
        else
            check += tcbn_a[i];
    }
    if(cnt == n || cnt == 0)
        return false;
    if(check == sum )
        return true;
    else
        return false;
}
void tcbn_recursive(int index, int n)
{
    if(index == n)
    {
        if(tcbn_check(n))
            tcbn_ans = 1;
        return;
    }
    if(tcbn_ans == 0) {
        for(int i =0;i<=1;i++)
        {
            tcbn_mask[index] = i;
            tcbn_recursive(index+1,n);
        }
    }
}
void tcbn()
{
    int tc;
    cin >> tc;
    for(int ii =0 ;ii<tc;ii++)
    {
        int n;
        cin >> n;
        tcbn_ans = 0;

        for(int i =0;i<n;i++)
        {
            cin >> tcbn_a[i];
            tcbn_mask[i] = 0;
        }
        tcbn_recursive(0,n);
        if(tcbn_ans)
            cout << "YES" << endl;
        else    
            cout << "NO" << endl;

    }
}
            //TẬP CON BẰNG NHAU

            //GHÉP CHỮ CÁI
int gcc_mask[10] = {0};
bool gcc_check(string s)
{
    int ans =0;
    for(int i =1;i<s.length()-1;i++)
    {
        if( s[i] == 'A' || s[i] == 'E')
        {
            if(s[i-1] == 'A' || s[i+1] == 'A' || s[i-1] == 'E' || s[i+1] == 'E')
                ans = 1;
            else
                return false;

        }
    }
    if(ans == 0 || ans == 1)
        return true;
}
void gcc_recursive(string s,int n)
{
    if(s.length() == n )
    {
        if (gcc_check(s) == true)
            cout << s << endl;
        return;
    }
    else{
        for(char i = 'A';i <= 'A'+n-1;i++)
        {
            if(gcc_mask[i - 'A'] == 0)
            {
                gcc_mask[i - 'A'] = 1;
                gcc_recursive(s + i, n);
                gcc_mask[i - 'A'] = 0;
            }
        }
    }

}
void gcc()
{
    char c;
    cin >> c;
    int n = 1 + c -'A';
    gcc_recursive("",n);

}
            //GHÉP CHỮ CÁI

            //TỔNG NHỎ NHẤT
void tnn()
{
    int tc;
    cin >> tc;
    for(int  ii =0;ii<tc;ii++)
    {
        int a[30];
        int count[10] ={0};
        int n;
        cin >> n;
        for(int i =0;i<n;i++)
        {
            cin >> a[i];
            count[a[i]]++;
        }
        int index = 0;
        for(int i=0;i<=9;i++)
        {
            if(count[i] !=0)
            {
                for(int j=0;j<count[i];j++)
                {
                    a[index] = i;
                    index++;
                }
            }
        }
        long long sum1 =0;
        long long sum2 =0;   
        for(int i =0;i<n;i++)
        {
            if(i%2 == 0)
            {
                sum1 = sum1*10 + a[i];
            }
            else{
                sum2 = sum2*10 + a[i];
            }

        }
        long long sum = sum1 + sum2 ;
        cout << sum <<endl;
    }
}
            //TỔNG NHỎ NHẤT
            //LIỆT KÊ TỔ HỢP
int lkth_a[30];
int lkth_k[20];

void lkth_recursive(int index, int k, int j, int n)
{
    if(index == k)

    {
        for(int i =0;i<k;i++)
        {
            cout << lkth_k[i] << " ";

        }
        cout << endl;
        return;

    }
    else{
        for(int i =j;i<n;i++)
        {

            lkth_k[index] = lkth_a[i];
            lkth_recursive(index+1,k,i+1,n);
            

        }
    }
}
void lkth()
{
    int n,k;
    cin >>n>>k;
    int count[1005] = {0};
    for(int i=0;i<n;i++)
    {
        int s;
        cin>> s;
        if(count[s] == 0)
        {
            count[s]++;
        }
    }
    int index =0;
    for(int i =0;i<1005;i++)
    {
        if(count[i] == 1)
        {
            lkth_a[index] = i;
            index++;
        }
    }
    lkth_recursive(0,k,0,index);

}
            //LIỆT KÊ TỔ HỢP

            //NGÀY ĐẶC BIỆT

void ndb( string s, int index) // index =0
{   
    if(s.length() == 10)
    {
        if(s[0] == '0' && s[1] == '0');

        else
        cout << s << endl;
        return;
    }
    else
    {
        for(int i =0;i<=2;i+=2)
        {
            if(index == 2 || index == 5)
                {
                    ndb(s + '/',index+1);
                    break;
                }
            else if(index == 3)
            {
                ndb(s+'0',index+1);
                break;
            }
            else if (index == 6 || index ==4)
            {
                ndb(s + '2', index +1);
                break;

            }
            else
            {
                ndb(s + char('0' + i) , index +1);
            }
        }
    }
}
            //NGÀY ĐẶC BIỆT

            //ĐẾM SỐ 0
void dem_so_0()
{
    int tc;
    cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int a[2000];
        int n;
        cin >> n;
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            if( a[i] == 0)
                cnt++;
        }
        cout << cnt << endl;
    }
}
            //ĐẾM SỐ 0

            //PHẦN TỬ KHÁC NHAU
void ptkn()
{
    int tc;
    cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n;
        cin>>n;
        long long *p = new long long[n];
        for(int i =0;i<n;i++)
        {
            cin >> p[i];
    
        }
        int ans = -1;
        for(int i=0;i<n-1;i++)
        {
            long long temp;
            cin >> temp;
            if(temp != p[i] && ans ==-1)
            {
                ans = i+1;

            }
        }

        cout << ans << endl;
        delete[] p;

    }
}
            //PHẦN TỬ KHÁC NHAU
            //TÌM KIẾM NHỊ PHÂN
void tknp()
{
    int tc;
    cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int a[100005];
        int n,k;
        cin >> n>>k;
        for(int i =0;i<n;i++)
        {
            cin >> a[i];

        }
        int l = 0 ;
        int r = n-1;
        int ans = 0;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(a[m] == k)
            {
                cout << m+1 << endl;
                ans =1;
                break;
            }
            else if(a[m] > k)
            {
                r = m -1;
            }
            else
            {
                l = m+1;
            }
        }
        if( ans == 0) cout << "NO" << endl;
    }
}
            //TÌM KIẾM NHỊ PHÂN

            //KÝ TỰ THỨ K TRONG XÂU
void kttktx()
{
    int tc;
    cin >> tc;
    for(int ii = 0;ii<tc;ii++)
    {
        int n,k;
        cin >>n >> k;
        string s = "";
        for(int i =0;i<n;i++)
        {
            s = s + char(i + 'A')  + s;
        }
        cout << s[k-1] << endl;  
    }
}
            //KÝ TỰ THỨ K TRONG XÂU

            //DÃY SỐ 2
int ds2_a[100005];
void ds2_recursive(int n, int a[])
{
    if(n == 0)
    {
        return;
    }
    else{
        int b[n-1];
        for(int i =0;i<n-1;i++)
        {
            b[i] = a[i] + a[i+1];
        }
        ds2_recursive(n-1,b);
        cout << "[" ;
        for(int i =0;i<n;i++)
        {

            if(i == n-1) cout<< a[i] <<"] ";
            else
            cout  << a[i] << " ";

        }
        //cout << endl;
    }
}
void ds_2()
{
    int tc;cin>>tc;
    for(int ii=0;ii<tc;ii++)
    {
        int n;
        cin>>n;
        int a[20];
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        ds2_recursive(n,a);
    }
}

            //DÃY SỐ 2

            //TỔ HỢP TIẾP THEO
int thtt_a[50];
int thtt_b[50];
int thtt_ans = 1;
void thtt_recursive( int index,int n,int val, int k)
{
    if(index == -1 || index == k )
    {
        if(index == -1)
            thtt_ans = 0;
        return;
    }

    if(thtt_a[index] == n ||thtt_a[index] == val -1)
    {
        thtt_recursive(index -1,n,thtt_a[index],k);
    }
    else{
        int temp = thtt_a[index];
        for(int i = index;i<k;i++)
        {
            temp++;
            thtt_a[i] = temp;
        }

    }
}
void thtt()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n,k;
        cin >> n>>k;
        thtt_ans =1;
        for(int i =0;i<k;i++)
        {
            cin >> thtt_a[i];
            thtt_b[i] = thtt_a[i];
        }
        thtt_recursive(k-1,n,thtt_a[k-1],k);

        for(int i=0;i<k;i++)
        {
            cout << thtt_a[i] << " ";
        }
        cout << endl;
                for(int i=0;i<k;i++)
        {
            cout << thtt_b[i] << " ";
        }
        cout << endl;

        if(thtt_ans == 0) cout << k << endl;
        else{
            int cnt =0;
            for(int i =0;i<k;i++)
            {


                for(int j =0;j<k;j++)
                {
                   if(thtt_a[i] == thtt_b[j])
                   {
                    cnt++;
                    break;
                   } 
                }
            }
            //cout << k - cnt << endl;
            
        }
    }
}
            //TỔ HỢP TIẾP THEO

            // DI CHUYỂN TRONG MÊ CUNG 1
void move_in_maze1_recursive(string s, int h, int c, int n, int a[][20],int &ans, int mask[][20])
{
    if(h == n-1 && c == n-1 )
    {
        cout << s << " ";
        ans = 1;
        return;
    }
    else{
        if(a[h+1][c] == 1 && mask[h+1][c] == 0)
        {
            mask[h+1][c] = 1;
            move_in_maze1_recursive(s+'D',h+1,c,n,a,ans,mask);
            mask[h+1][c] = 0;
        }
        if(a[h][c-1] == 1 && mask[h][c-1] == 0)
        {
            mask[h][c-1] = 1;
            move_in_maze1_recursive(s+'L',h,c-1,n,a,ans,mask);
            mask[h][c-1] = 0;
        }
        if(a[h][c+1] == 1 && mask[h][c+1] == 0)
        {
            mask[h][c+1] = 1;
            move_in_maze1_recursive(s+'R',h,c+1,n,a,ans,mask);
            mask[h][c+1] = 0;
        }
        if(a[h-1][c] == 1 && mask[h-1][c] == 0)
        {
            mask[h-1][c] = 1;
            move_in_maze1_recursive(s+'U',h-1,c,n,a,ans,mask);
            mask[h-1][c] = 0;
        }

        
        
    }
}
void move_in_maze1()
{
    int tc;cin >> tc;
    for(int ii = 0;ii<tc;ii++)
    {
        int n;
        cin >>n;
        int a[20][20] = {0};
        int mask[20][20] = {0};
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> a[i][j];
            }
        }
        int ans = 0;
        if(a[0][0] == 1)
        {
            mask[0][0] = 1;
            move_in_maze1_recursive("",0,0,n,a,ans,mask);
        }

        if(ans == 1) cout << endl;
        if(ans == 0) cout << "-1" << endl;

    }    
}
            //DI CHUYỂN TRONG MÊ CUNG 1

            //TẬP CON CỦA XÂU KÝ TỰ
void print(string s)
{
    
}
void tccxkt_recursive(string s, int index, char a[], int n)
{   if(s.length() >=1)
    cout << s << " ";
    if(s.length() == n)
    {
        return;
    }
    else{
        for(int i = index;i<n;i++)
        {
            tccxkt_recursive(s+ a[i],i+1,a,n);
        }
    }
}
void tccxkt()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n;
        cin >> n;
        char a[20] = {0};
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        for(int i =0;i<n-1;i++)
        {
            int mini = a[i];
            int index = i;
            for(int j = i+1;j<n;j++)  
            {
                if(mini > a[j])
                {
                    mini = a[j];
                    index = j;

                }

            }  
                int temp = a[i];
                a[i] = a[index];
                a[index] = temp;

        }

        tccxkt_recursive("",0,a,n);
        cout<< endl;
    }
}
            //TẬP CON CỦA XÂU KÝ TỰ
int main()
{
    ds_2();







    

	return 0;
}

