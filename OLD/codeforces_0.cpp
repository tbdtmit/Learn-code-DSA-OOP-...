#include<iostream>
#include<string>
using namespace std;

void garden()
{
    int A[1000];
    int n,k;
    cin >> n>> k;
    for(int i=0;i<n;i++)
    {
        cin >> A[i];
    }

    int min_hour = 1000;
    for(int i=0;i<n;i++)
    {
        if(k%A[i] == 0 )
        {
            if(min_hour > k/A[i])
                min_hour = k/A[i];
        }
    }
    cout << min_hour <<endl;
}

            //Silent Classroom_begin
int chatting_pairs(int n)
{
    int pair =0;
    for(int i = 0;i<n;i++)
        pair+=i;
    return pair;
}

void silent_classroom()
{
    int n ;
    string str[1000];
    int mark[1000] = {0};
    cin >>n;

    for(int  i =0;i<n;i++)
    {
        string s;
        cin >> s;
        str[i] = s;
        mark[s[0]]++;

    }
    int x =0;
    for(int i = 'a';i<= 'z';i++)
    {
        if(mark[i] >2)
        {
            if(mark[i]%2 == 0)
            {
                x+= chatting_pairs(mark[i]/2) *2;
            }
            else
            {
                x += (chatting_pairs(mark[i]/2) + chatting_pairs(mark[i]/2 +1));
            }
        }
    }
    cout <<x <<endl;
}
            //Silent Classroom_end

            //From 0 to Y_begin
int pow(int x, int p)
{
    int xx =0;
    for(int i =0;i<p;i++)
        xx*=10;
    return xx;
}
void from_0_to_y()
{
    int tc; 
    cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int x,y;
        int cnt =0;
        cin >> x >>y;
        while(y >= x)
        {
            int p = 0;
            while(y>= pow(x,p))
            {

                p++;
            }
            y -= pow(x,p-1);
            cnt++;

        }
        cnt = cnt + y;
        cout << cnt << endl;

    }
}
            //From_0_to_Y_end

            //Lazy_land*** UN AC
void lazy_land()
{
    int n,k;
    int jo[100005];
    int m[100005];
    int mark[100005] = {0};
    int count[100005] = {0};
    cin >> n>>k;
    for(int i = 1;i<=n;i++)
    {
        cin >> jo[i];
        count[jo[i]]++;

    }
    for(int i = 1;i<=n;i++)
    {
        cin >> m[i];
        
    }
    for(int i=1;i<=n;i++)
    {
        if(mark[i]  == 0)
        {
        int index_max =  i;
        for(int j =i+1;j<=n;j++)
        {
            if(jo[i] == jo[j] && mark[j] == 0 )
            {
                if(m[index_max] <= m[j])
                {
                    mark[index_max] = 1;
                    index_max = j;

                }

                else
                {

                    mark[j] = 1;
                }

            }
        }
        }

    }
    int cnt =0;
    for(int i=1;i<=k;i++)
    {
        if(count[i] == 0)
            cnt++;
    }
    int ans =0;
    for(int i= 1;i<=cnt;i++)
    {
        int min = 100005 ;
        int index_min;
        for(int j=1;j<=n;j++)
        {
            if(mark[j] == 1)
            {

                if(min > m[j])
                {
                    index_min = j;
                    min = m[j];
                }
            }
        }
        mark[index_min]  = 0;
        ans += m[index_min];

    }
    cout << ans <<endl;
}
            //Lazy_land

            //Theatre Square
void theatre_square()
{
    long long m,n,a;
    cin >> m >> n >> a;
    long long mm ,nn;
    if(m%a == 0)
         mm = m/a;
    else
         mm = m/a +1;

    if(n%a == 0)
         nn = n/a;
    else
         nn = n/a +1;

    cout << nn*mm <<endl;
}
            //Theatre Square
            
            //String Task
void string_task()
{
    char chr[1000];
    string str;
    cin >>str;
    for(int i=0;i<str.length();i++)
    {
        chr[i] = str[i];
    }

    for(int i=0;i<str.length();i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;

        if(str[i] == 'o' ||str[i] == 'i' ||str[i] == 'a' ||str[i] == 'e' ||str[i] == 'u' || str[i] == 'y' )
        {
            str[i]  = '!';
        }

        

    }
    for(int  i=0;i<str.length();i++)
    {
        if(str[i] >='a' && str[i] <= 'z')
        {
            cout << "." <<str[i];
        }
    }
    cout <<endl;
}
            //String Task

            // Mike and palindrome
void mike_palindrome()
{
    string str;
    cin >>str;
    int check =0;
    int n = str.length();

    for(int i=0;i<str.length()/2;i++)
    {
        if(str[i] != str[str.length()-1-i])
            check++;
    }
    if(check == 1 )
        cout << "YES" <<endl;
    else if( check == 0 && n%2 == 1)
        cout << "YES" <<endl;
    else
        cout << "NO" << endl;
}
            // Mike and palindrome

            //Gold Rush
int gr_ans =0;
void gr_rescursive(int m, int n)
{
    if( m == n)
        gr_ans = 1;
    else if(m>n)
        return;
    else{
        gr_rescursive(m*3,n);
        if( ((float)m*3/2) == int(m*3/2) )
            gr_rescursive(m*3/2,n);
    }

}
void gold_rush()
{
    int tc ;
    cin >> tc;
    for(int ii=0;ii<tc;ii++)
    {
        int n,m;
        gr_ans =0;
        cin >> n >>m;
        gr_rescursive(m,n);
        if(gr_ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
            //Gold Rush            

            //Rudolf and Snowflakes (simple version)
int pow_rs(int mu, int i)
{
    int ans =1;
    for(int j =0;j<mu;j++)
    {
        ans = ans*i;
    }
    return ans;
}
void rudolf_snowflakes()
{
    int  tc ;
    cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int n;
        cin >> n;
        int x = 2;
        int status =0;
        while(pow_rs(0,x) + pow_rs(1,x) + pow_rs(2,x) <= n)
        {
            int  nn =n;
            int k=0;
            while(nn >=0)
            {
                nn = nn - pow_rs(k,x);
                k++;
                if(nn == 0)
                {
                    cout << "YES" <<endl;
                    status =1;
                    break;
                }
            }
            if(status) break;
            x++;

        }
        if(status == 0)
            cout << "NO" <<endl;    
    }
}
            //Rudolf and Snowflakes (simple version)

            //Vampiric Powers, anyone? UN FN
void jojo()
{
    int tc;
    cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int A[100005];
        int n;
        cin >>n;
        int max =0;
        int index_max = 0;
        for(int i=0;i<n;i++)
        {
            cin >> A[i];
            if(max < A[i])
            {
                max = A[i];
                index_max = i;
            }

        }

        for(int i =0;i<n;i++)
        {
            int power = 0;
            for(int j =i;j<n;j++)
            {
                power = power^A[j];
                if(power > max) 
                    max = power;  
            
            }

        }
        cout << max << endl;
    }
}
            //Vampiric Powers, anyone?

            //Happy Birthday, Polycarp!
void polycarp()
{
    int tc;
    cin >> tc;
    for(int ii=0;ii<tc;ii++)
    {
        long long n;
        cin >> n;
        long long ans =0;
        for(long long i = 1;i<=9;i++)
        {
            long long cnt = 0;
            long long res = cnt*10+i;
            while( res <= n)
            {
                cnt++;
                res = res*10+i;
            }
            //cnt--;
            ans += cnt;
        }
        cout << ans <<endl;
    }
}

            //Happy Birthday, Polycarp!

int main()
{
    polycarp();
    return 0;
}