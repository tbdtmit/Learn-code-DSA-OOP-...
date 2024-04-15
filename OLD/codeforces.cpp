#include<iostream>
#include<string>
using namespace std;

void watermelon()
{
    int w;
    cin >> w;
    if(w <=3)
    cout << "NO";
    else
    {
        if(w%2 == 0)
        cout << "YES";
        else
        cout << "NO";
    }
}

void way_to_long_words()
{
    int tc;
    cin >> tc;
    for(int tcc = 0;tcc<tc;tcc++)
    {
        string str;
        cin >> str;
        if(str.length() <= 10)
            cout << str << endl;
        else
        {
            cout << str[0] << str.length() - 2 << str[str.length() -1]<<endl;
        }
    }
}

void the_third_letter()
{
    
    int tc;
    cin >>tc;
    for(int tcc =0;tcc<tc;tcc++)
    {
        int n,m;
        cin >> n >> m;
        for(int mm =0;mm<m;mm++)
        {
            int a,b,d;
            cin >> a >> b >>d;
        }
    }
}

void hamon_odyssey()
{

    int tc;
    cin >> tc;
    for(int tcc=0;tcc<tc;tcc++)
    {
        int arr[20000];
        int n;
        cin>>n;
        for(int i =0;i<n;i++)
        {
            cin >> arr[i];
        }

        int cnt =0;
        int res = arr[0];
        int index = 1;
        while(index < n )
        {
            while((res &= arr[index]) != 0)
            {
                index++;
                
            }
            cnt++;
            index++;
            res = arr[index];
            index++;
        }
        if(n == 1 )
        {
            cnt = 1;
        }
        cout << cnt <<endl;

    }
}

void collecting_coins()
{
    int tc;
    cin >>tc;
    for(int ii=0 ;ii<tc;ii++)
    {
        int A[3],n;
        for(int i =0;i<3;i++)
            cin >> A[i];
        cin >> n;
    int max =0;
    for(int i =0;i<3;i++ )
    {
        if(max < A[i])
            max = A[i];
    }

    int sum = A[0] +A[1] + A[2] + n;
    if(sum%3 == 0)
    {
        if(sum/3 >= max)
            cout << "YES";
        else
            cout << "NO";
    }

    else
        cout << "NO";
    
    cout << endl;

    }

}

void juggling_letters()
{
    int tc;
    cin >> tc;
    for(int ii = 0;ii<tc;ii++)
    {
        int A[1000] = {0};
        int n;
        cin >> n;
        for(int i =0;i<n;i++)
        {
            string str;
            cin >> str;
            for(int j =0;j<str.length();j++)
            {
                A[str[j]] ++;
            }
        }
        
        int status = 0;
        for(int i = 'a';i<='z';i++)
        {
            if((A[i]%n) != 0)
            {
                cout << "NO"<<endl;
                status =1 ;
                break;
            }
                
        }
        if(status == 0)
            cout << "YES" <<endl;
    }
}

void remove_duplicates()
{
    int X[100];
    int mark[100] = {0};
    int n;
    cin >> n;
    for(int i =0;i<n;i++)
    {
        cin >> X[i];
    }
    for(int i=0;i<n;i++)
    {
        int index = i;
        for(int j = i+1;j<n;j++)
        {
            if(X[index] == X[j])
            {
                mark[index] = 1;
                index = j;
            }
        }
    }
    int cnt =0;
    for(int i =0;i<n;i++)
    {
        if(mark[i] == 0)
            cnt++;
    }
    cout << cnt <<endl;
    for(int i =0;i<n;i++)
    {
        if(mark[i] == 0)
            cout << X[i] << " ";
    }
}

void snowball()
{
    int W[1000] = {0};
    int w, h;
    cin >> w >>h;
    int w1,h1,w2,h2;
    cin >> w1 >>h1>>w2>>h2;
    W[h1] = w1;
    W[h2] = w2;

    for(int i = h;i>=0;i--)
    {
        w+= i;
        if(W[i] != 0)
        {
            w-=W[i];
            if(w<0)
                w=0;
        }

    }
    cout<< w;
}

void avoid_local_maximums()
{
    int tc;
    cin >>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int X[200000];
        int n;
        int max=0;
        cin >> n;
        for(int i = 0;i<n;i++)
        {
            cin >> X[i];
            if(max < X[i])
                max =X[i];
        }

        int cnt =0;
        for(int i =1;i<=n-2;i++)
        {
            if(X[i] > X[i-1] && X[i] > X[i+1])
            {
                X[i+1] = max;
                cnt++;
            }
        }
        cout << cnt << endl;
        for(int i =0;i<n;i++)
        {
            cout << X[i] << " ";
        }
        cout <<endl;
    }
}

void football()
{
    char chr[200];
    string str;
    cin >>str;
    for(int i =1;i<=str.length();i++)
    {
        chr[i] = str[i-1];
    }
    if(str.length() < 7)
        cout << "NO" <<endl;
    else{
    for(int i=1;i<=str.length() -6;i++)
    {
        if(chr[i] == chr[i+1])
        {
            int cnt =0;
            for(int j = i+1;j<=i+7;j++)
            {
                if(chr[i] == chr[j] && j <= str.length())
                    cnt++;
                else
                    break;

            }
            if(cnt >= 6)
                {
                cout << "YES" <<endl;
                exit(0);
                }

        }
    }
    cout << "NO" <<endl;;
    }
}

void duff_meat()
{
    int need[200000];
    int cost[200000];
    int n;
    cin >> n;
    for(int i =1;i<=n;i++)
    {
        cin >> need[i];
        cin >> cost[i];
    }
    int min_index = n;
    int sum =0;
    if(min_index == 1)
    {
        sum = cost[1] * need[1];
        cout << sum;
    }
    else{
    while(min_index > 1)
    {
        min_index = n;
        for(int i= n;i>=1;i--)
        {
            if(cost[i] <= cost[min_index])
            {
                min_index = i;
            }

        }
        int sum_need = 0;
        for(int i = n;i>=min_index;i--)
        {
            sum_need+=need[i];
        }
        sum += sum_need*cost[min_index];
        n = min_index -1;


    }
    cout << sum;
    }


}

void display_the_number()
{
    int tc;
    cin >>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int X[200000];
        int n;
        int index =0;
        cin >>n;
        while(n>0)
        {
        if(n %2 == 1)
        {
            X[index] = 7;
            index++;
            n=n-3;
        }
        else
        {
            X[index] = 1;
            index++;
            n = n-2;
        }
        }
        for(int i=0;i<index;i++)
        {
            cout << X[i];

        }
        cout <<endl;
    }
}

            //***
void bubble_sort(int n,int a[])
{
    int temp =0;
    for(int i =0;i<n;i++)
    {
        for(int j = n-1;j>i;j--)
        {
            if(a[j] < a[j-1] )
            {

                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }

    }
}
            //***
void index_sort(int n, int a[], int mark[])
{
    int index_min;
    int tick[100005] ={0};
    for(int i=0;i<n;i++)
    {   
        int min = 1000000005;
        for(int j =0;j<n;j++)
        {
            if(min > a[j] && tick[j] == 0)
            {
                min = a[j];
                index_min = j;
            }

        }
        mark[i] = index_min;
        tick[index_min] =1;
    }
}
            // UN AC
void restore_the_weather()
{

    int tc;
    cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
    int A[100005];
    int B[100005];
    int AA[100005];
    int BB[100005];
    int mark[100005] = {0};
        int n, k;
        cin >> n >>k;
        for(int i =0;i<n;i++)
        {
            cin >> A[i];
            AA[i] = A[i];
        }
        for(int i =0;i<n;i++)
        {
            cin >> B[i];
            BB[i] = B[i];
        }

        bubble_sort(n,AA);
        bubble_sort(n,BB);
        int index =0;
        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(AA[j] == A[i] && mark[j] == 0)
                {
                    B[i] = BB[j];
                    mark[j] = 1;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            cout << B[i] <<  " ";
        }
        cout << endl;
    }
}
            //*** UN AC ***
char A_mrb[1000];
void mocha_red_blue_recursive(int i)
{
    if(A_mrb[i+1] == 'R')
        A_mrb[i] = 'B';
    else if(A_mrb[i+1] == 'B')
        A_mrb[i] = 'R';
    else
        mocha_red_blue_recursive(i+1);
}
void mocha_red_blue()
{   
    int tc;
    cin>>tc;
    for(int ii=0;ii<tc;ii++)
    {

        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin >> A_mrb[i];
        }

        for(int i=0;i<n;i++)
        {
            if(A_mrb[i] == '?')
            {
                while(A_mrb[i] == '?')
                {
                    mocha_red_blue_recursive(i);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<A_mrb[i];
        }
        cout<<endl;
    }
}

void doggo_recoloring()
{
    char chr[100005];
    int A[1000] = {0};
    int n; cin>>n;
    if(n ==1)
    {
        cout << "Yes" <<endl;
        exit(0);
    }
    for(int i=0;i<n;i++)
    {
        cin >> chr[i];
        A[chr[i]]++;
    }
    for(int i='a';i<='z';i++)
    {
        if(A[i] >=2 )
        {
            cout << "Yes" <<endl;
            exit(0);
        }

    }
    cout << "No" <<endl;
}

int ans =0;
void hsp_recursive(int a, int b, int x)
{
    if(3*a + 7*b == x)
        {
            ans =1;
            cout << a << " " << b << endl;
        }
    else if(3*a + 7*b > x)
        return;
    else
    {
        hsp_recursive(a+1,b,x);
        hsp_recursive(a,b+1,x);
    }

}


void hungry_student_problem()
{
    int tc;
    cin>>tc;
    for(int ii  =0;ii<tc;ii++)
    {
        int x;
        cin >> x;
        ans =0;
        hsp_recursive(0,0,x);
        if(ans)
            cout << "YES" <<endl;
        else
            cout << "NO" <<endl;
    }


}

            //HSP part2
void hsp()
{
    int tc;
    cin>>tc;
    for(int ii  =0;ii<tc;ii++)
    {
        int x;
        cin >> x;
        ans =0;
        int a = -1;
        int b ;
        while(a*3 <= x)
        {
            b=0;
            a++;
            while(a*3+b*7 <= x)
            {
                if(a*3 + b*7 == x)
                {
                    ans =1;
                   // cout << a << " " <<b <<endl;
                    break;
                }
                else
                    b++;
            }
        }
        if(ans)
            cout << "YES" <<endl;
        else
            cout << "NO" <<endl;
    }    
}
int main()
{
    hsp();

    return 0;
}

    

