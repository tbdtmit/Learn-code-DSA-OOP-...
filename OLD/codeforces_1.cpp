#include<iostream>
#include<string>
#include<math.h>
using namespace std;
            //TAXI

void taxi()
{
    int a[100005];
    int mark[100005] = {0};
    int n;
    cin >> n;
    int count[5] = {0};  // phu thuoc vao so nguoi toi da trong 1 xe taxi, vd o day la 4 nguoi --> mang dem co index toi da la 4
    for(int i =0;i<n;i++)
    {
        int in;
        cin >> in;
        count[in]++;
    }
    int index =0;
    for(int i =1;i<=4;i++)
    {
        for(int j=0;j<count[i];j++)
        {
            a[index] = i;
            //cout << a[index] << " ";
            index++;
        }
    }
    index =0;
    int ans =0;
    for(int i = n-1;i>=0;i--)
    {
        if(mark[i] == 0)
        {
            
            int sum = a[i];
            while(sum+a[index] <= 4)
            {
                sum+=a[index];
                mark[index] = 1;
                index++;

            }

            ans++;
        }
    }
    cout << ans <<endl;

}
            //TAXI

            //**************************
int a[100];
int d[100] = {0};


void tinh_toan(int n)
{


    d[0] = 1;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(d[i] == 1 && d[i+1] != 3 )
        {
            ans += a[i];
        }
        else if(d[i] == 2 && d[i+1] !=3)
        {
            ans -= a[i];
        }
        else if(d[i] == 1 && d[i+1] == 3)
        {
            int res = 0;
            i = i+1;
            while(d[i] ==3 && i<n)
            {
                res = res*10+a[i-1];
                i++;
            }
            res = res*10+a[i-1];
            ans += res;
            i--;

        }

        else if(d[i] == 2 && d[i+1] == 3)
        {
            int res = 0;
            i = i+1;
            while(d[i] ==3 && i<n)
            {
                res = res*10+a[i-1];
                i++;
            }
            res = res*10+a[i-1];
            ans -= res;
            i--;

        }
    }
    for(int i =0;i<n;i++)
    {
        if(d[i] == 1)
            cout << " + ";
        else if(d[i] == 2)
            cout << " - ";
        cout << a[i];
    }
    cout << " = ";
    cout << ans <<endl;
}

void recursive(int n,int index) // index bat dau = 1
{
    if(index == n)
    {
        tinh_toan(n);
        return;
    }
    for(int i = 1;i<=3;i++)
    {
        d[index] = i;
        recursive(n,index+1);
    }  
} 

void bai_toan_to_hop_3_dau()
{
    int n;
    cin >> n;
    for(int i =0; i<n;i++)
    {
        cin >> a[i];
    }
    recursive(n,1);
}
            //**************************

            //Interesting drink UN FN

    int cost_id[100005] ;
    int coin_id[100005] ;
int binary_search(int left, int right,int target)
{
    int mid;
    while(left<=right)
    {
        mid = (left+right)/2;
        if(cost_id[mid] == target)
        {
            return mid;
        }
        else if(cost_id[mid] > target)
        {
            right = mid -1;

        }
        else{   
            left = mid+1;
        }

    }
    return mid;
}
void interesting_drink()
{

    int counting[100005] = {0};
    int n;
    cin >> n;
    int max ;
    for(int i=0;i<n;i++)
    {
        cin >>  cost_id[i];
        if(max < cost_id[i])
        {
            max = cost_id[i];
        }
        counting[cost_id[i]]++;
    }
    int k;
    cin >> k;
    int a =0;
    for(int i =0;i<k;i++)
    {
        cin >> coin_id[i];

    }
    for(int i = 1;i<=max;i++)
    {
        for(int j = 0;j<counting[i];j++)
        {
            cost_id[a] = i;
            a++;
        }
    }

    for(int i =0;i<k;i++)
    {
        int b = binary_search(0,n-1,coin_id[i]);
        if(coin_id[i] == cost_id[b])
            cout << b+1 <<endl;
        else if(coin_id[i] > cost_id[b])
            {
                if(coin_id[i] > cost_id[b+1] && b+1 <n)
                    cout << b+2 <<endl;
                else   
                    cout << b+1 << endl;
            }

        else 
            cout << b<<endl;
    }


}
        
            //Interesting drink UN FN

            // Fence
void fence()
{
    int a[200000] = {0};
    int n,k;
    cin >>n >>k;

    for(int i =1 ;i<=n;i++)
    {
        cin >> a[i];
        if(i)
        {
            a[i]+= a[i-1];
        }
    }
    long long min  ;
    int index_min  ;
    for(int i = 1;i<=n-k+1;i++)
    {
        long long sum = a[i+k-1] - a[i-1];
        if(i == 1)
        {
            min = sum;
            index_min = i;
        }
        else
        {
            if(min>sum)
            {
                min = sum;
                index_min = i;
            }
        }

    }
    cout << index_min << endl;

}
            // Fence

            //LAPTOPS UN FN
void laptops()
{
    int cost[100005];
    int index_cost[100005];
    int quality[100005];
    int counting[100005] = {0};
    int n;
    cin >> n;
    int max =0;

    for(int i= 1;i<=n;i++)
    {
        cin >> cost[i] >> quality[i];
        counting[cost[i]]++;
        if(max < cost[i])
        {
            max = cost[i];

        }

    }
    int a =0;
    for(int i =1;i<=max;i++)
    {
        for(int j =0;j<counting[i];j++)
        {
            cost[a] =i;
            a++;
        }
    }
    
}
            //LAPTOPS UN FN

            //SORT ZERO
int check_index_of_non_decreasing_order(int a[], int n)
{
    int index = 1;
    for(int i = 1;i<n;i++)
    {
        if(a[i+1] < a[i])
        {
            index = i+1;
        }

    }
    return index;
}

void sort_zero()
{
    int tc;
    cin >>tc;
    for(int ii =0;ii<tc;ii++)
    {
        int a[100005] ;
        int n;
        cin >> n;
        for(int i =1;i<=n;i++)
        {
            cin >> a[i];
        }
    int cnt =0;
    int status =1;
    for(int i = 1;i<=n;i++)
    {
        if(status == 1)
        {
        if(check_index_of_non_decreasing_order(a,n) == 1)
            {
                break;
            }
        }


        if(a[i] != 0)
        {

        int target = a[i];
            status =0;
        for(int j = i;j<=n;j++)
        {
            if(a[j]  == target)
            {
                a[j] =0;
                status = 1;
            }
        }
        if(status) cnt++;
        }


    }

    cout <<cnt<<endl;
    }


}
            //SORT ZERO
            
            //Petya and Countryside


void petya_countryside()
{
    int garden[1005];
    int n;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        cin >> garden[i];
    }
    int max =0;
    int ii = 0;
    while(ii <= n-1)
    {
        int i = ii;
        int cnt =1;
        while(garden[i] >= garden[i-1] && i-1 >=0)
        {
            i--;
            cnt++;

        }
        i = ii;
        while(garden[i] >= garden[i+1] && i+1 <= n-1)
        {
            i++;
            cnt++;

        }
        ii = i+1;
        if(max < cnt)  max = cnt;
    }
    cout << max <<endl;
}
            //Petya and Countryside

            //Jumping on Tiles

void jump_on_tiles()
{
    int tc;
    cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        string str;
        cin >>str;
        char a[100005] ;
        int mark[100005] = {0};
        int n = str.length();
        int step = 0;
        for(int i=0;i<str.length();i++)
        {
            a[i] = str[i];
            if(i>0 && i<n-1)
            {
                if( str[i] >= str[0] && str[i] <= str[n-1] || str[i] <= str[0] && str[i] >= str[n-1])
                    step++;
            }
        }

        int cost = int((a[n-1]) - a[0]);
        if(cost < 0) cost = 0 - cost;

        int ans[100005];
        ans[0] = 1;
        ans[step+1] = n;
        if(a[0] <= a[n-1])
        {
            for(int j=1;j<1+step;j++)
            {
                int min = 100;
                int index_min;
                int status =0;
            for(int i = 1;i<n-1;i++)
            {
                if(a[i] >= a[0] && a[i] <= a[n-1] && mark[i] == 0)
                {
                    int res = a[i] - a[0];
                    if(min > res)
                    {
                        min = res;
                        index_min = i;
                        status =1;
                    }
                }


            }
                if(status)
                {
                mark[index_min] = 1;  
                ans[j] = index_min+1;              
                }
            }

        }

        else{
            for(int j=1;j<1+step;j++)
            {
                int min = 100;
                int index_min;
                int status = 0;
            for(int i = 1;i<n-1;i++)
            {
                if(a[i] <= a[0] && a[i] >= a[n-1] && mark[i] == 0)
                {
                    int res = a[0] - a[i];
                    if(min > res)
                    {
                        min = res;
                        index_min = i;
                        status =1;
                    }
                }





            }
                if(status)
                {
                mark[index_min] = 1;  
                ans[j] = index_min+1;                
                }
            }

        }

        cout << cost <<" " << step +2 << endl;
        for(int i = 0;i<step+2;i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;



    }

}
        
            //Jumping on Tiles

            //Deadline
long long dl_optimize(long long d, long long x)
{
    long long ans =0;
    if(d%(x+1) != 0)
    {
        ans = d/(x+1) +1;
    }
    else
        ans = d/(x+1);
    return ans;

}

void deadline() // su dung dao ham de tinh gia tri cuc tieu cua phuong trinh x + d/(x+1)
                // --> pt min = 2*sqrt(d) -1
{
    int tc;
    cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        long long n,d;
        cin >> n >> d;
        int status = 0;
        double aa = (2*sqrt(d) -1) ;
        if( aa != int(aa))
            aa = int(aa) +1;
        if(  aa <= n)
            status =1;
        if(status)
            cout << "YES" <<endl;
        else
            cout << "NO" <<endl;
    }
}
            //Deadline

            //Kill Demodogs UN FN
void kill_demodogs()
{
    int tc;
    cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        long long n;
        cin >> n;
        long long sum = 1;
        long long h =1;
        long long c =1;
        for(long long i = 0 ; i<2*n-2;i++)
        {
            if(i%2 == 0)
            {
                c++;
            }
            else
            {
                h++;
            }
            sum += h*c;
        }
        sum = sum*2022;

        cout << sum << endl;
    }
}

            //Kill Demodogs UN FN

            //Benches
void benches()
{
    int a[1000];
    int bench;
    int addd;
    cin >> bench >>addd;
    int max =0;
    int person =0;
    for(int i =0;i<bench;i++)
    {
        cin >> a[i];
        if(max < a[i])
            max = a[i];
        person+= a[i];
    }
    int mini;
    int add =addd;
    add = add - (max*bench - person);
    if(add <=0)
    {
        mini = max;
    }
    else{
        if(add%bench == 0)
            mini = max + add/bench;
        else
            mini = max + add/bench +1;
    }
    int maxi = max + addd;
    cout << mini <<" " << maxi << endl;

}
            //Benches
            //k-Factorization

unsigned long long pow_kf(int mu, int a)
{
    unsigned long long n =1;
    for(int i=0;i<mu;i++)
    {
        n = n*a;
    }
    return n;
}

int kk_kf[30];
int ans_kf =0;
void recursive_kf(int n, int k ,int cnt, int index) // cnt =1;index =0
{
    if(cnt == k)
    {
        ans_kf =1;
        kk_kf[index] = n;
        return;
    }
    for(int i =2;i*i<=n;i++)
    {
        if(n%i == 0 && ans_kf == 0)
        {
            kk_kf[index] =i;
            recursive_kf(n/i,k,cnt+1,index+1);
        }
    }
}
void k_fac()
{
    int n,k;
    cin >> n >>k;

    ans_kf =0;
    recursive_kf(n,k,1,0);
    if(ans_kf)
    {
        for(int i=0;i<k;i++)
        {
            cout << kk_kf[i] << " ";
        }
        cout << endl;
    }
    else
        cout << "-1" <<endl;


}
            //k-Factorization
            
            //The Eternal Immortality
void eternal_immortality()
{
    unsigned long long a,b;
    cin >> a >>b;
    if(a == b) cout << "1" <<endl;
    else if(b-a > 5) cout << "0" << endl;
    else{
    unsigned long long aa = a%10;
    unsigned long long bb = b%10;
    if(bb <= aa) bb = b%100;
    if(bb - aa > 5 || bb == aa)
    {
        cout << "0" << endl;
    }
    else{
    unsigned long long ans =1;
    for(int  i = aa+1;i<=bb;i++)
    {
        ans = ans*i;
    }
    cout << ans%10 <<endl;
    }
    }


}

            //The Eternal Immortality
            

int main()
{
    eternal_immortality();


    return 0;
}