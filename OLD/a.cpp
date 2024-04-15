#include<iostream>
#include<string>
using namespace std;
void tachso(int a)
{   while(a)
    {
        int b;
        b = a%10;
        cout << b << " ";
        a/=10;
    }
}

int first_duplicate(int n, int *arr)
{  
    int vn = n;
    for(int i=0;i<vn-1;i++)
    {
        for(int j = i+1;j<vn;j++)
        {   
            if(arr[i] ==  arr[j])
            vn = j;
        }
    }
    return vn;
}
void chess()
{   int board[1001][1001];
    int m,n;
    int q,k,p;
    int vq[2][100], vk[2][100], vp[2][100];
    int mqx[8] = {-1,-1,-1,0,1,1,1,0};
    int mqy[8] = {-1,0,1,1,1,0,-1,-1};
    int mkx[8] = {-1,-2,-2,-1,1,2,2,1};
    int mky[8] = {-2,-1,1,2,2,1,-1,-2};
    int cnt = 0;

    cin >> m >> n;
    cin >> q;
    for(int i = 0;i<q;i++)
    {
        cin >> vq[0][i] >> vq[1][i];  
        board[vq[0][i]][vq[1][i]] = 1;
    }

    cin >> k;
    for(int i = 0;i<k;i++)
    {
        cin >> vk[0][i] >> vk[1][i];  
        board[vk[0][i]][vk[1][i]] = 2;
    }

    cin >> p;
    for(int i = 0;i<p;i++)
    {
        cin >> vp[0][i] >> vp[1][i];  
        board[vp[0][i]][vp[1][i]] = 3;
    }
    /*
    cout << "n= " << n << endl;
    cout << "m= " << m << endl;
    for(int i = 0;i<=m;i++)
    {
        for(int j = 0;j<=n;j++)
        cout << board[i][j];
        cout << endl;
    }
    */
    // queen
    for(int i =0;i <q;i++)
    {
        for(int j = 0;j<8;j++)
        {   int x = vq[0][i];
            int y = vq[1][i];
            while(x>=1 && y >=1 && x <= m && y <= n )
            {   
                x = x + mqx[j];
                y = y + mqy[j];
                if(board[x][y]==0 && x>=1 && y >=1 && x <= m && y <= n)
                {
                    board[x][y] = -1;
                     cnt ++;
                }
                else
                {
                    break;    
                }
            }
        }
    }
cout << cnt << endl;
    // knight
        for(int i =0;i <k;i++)
    {
        for(int j = 0;j<8;j++)
        {   int x = vk[0][i];
            int y = vk[1][i];

                x = x + mkx[j];
                y = y + mky[j];
                if(board[x][y]==0 && x>=1 && y >=1 && x <= m && y <= n)
                {
                    board[x][y] = -1;
                    cnt ++;
                } 
        }
    }
    // pawn
    // xuat
    cout << m*n- cnt -k -q-p <<endl;}

void checks1ins2()
{
int ans =0;
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    cout << s1.length() << " " << s2.length()<<endl;
    for(int i =0; i<s2.length(); i++)
    {
        if(s2[i] == s1[0])
        {   int j=0;
            int ii = i;
            while(s1[j] == s2[ii] && j<(s1.length()))
            {   
                    j++;
                    ii++;
                
     
            }
            if((j) == s1.length()) ans++;
        }
    }
    cout << ans;

}

bool check(char a, int b[],int n)
{

    for(int i=0;i<n;i++)
    {
        if(a == b[i] + '0') return 1;
    }
    return 0;
}

void btfnum()
{
        int n,m;
    int a[10];
    int x,y;
    int ans;
    cin >> n >> m;
    for(int i = 0; i<n;i++)
    {
        cin >> a[i];
    }
    cin >> x >>y;
    for(int i =x;i<=y;i++)
    {   string s2;
        int cnt =0;
        int j =0;
        s2 = to_string(i);

        while (cnt<m && j<s2.length())
        {
            if(check(s2[j],a,n)) cnt++;
            j++;
        }
        if(cnt == m) ans++;
        
    }
    cout << ans;
}
void firstdup()
{    int n, m[100000];
    int max = 1;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> m[i];
        if(max < m[i]) max = m[i];
        

    }
    cout << "max " << max <<endl;
    int b[max+1];
        for(int i=0;i<n;i++)
    {
        b[m[i]]++;
        if(b[m[i]] == 2) 
        {
            cout <<  m[i];
            exit(0);
        }

    }
    cout << "-1";}

void xep_hang(int a,int arr[])
{
    int temp = arr[0];
    for(int i =0; i <a-1;i++)
    {
        arr[i] = arr[i+1];
        if(i == a-2) arr[a-1] = temp;
    }

}
void xep_hang(int x,int a,int arr[], int &b)
{
    int temp = arr[x];
    for(int i =x; i <a-1;i++)
    {
        arr[i] = arr[i+1];
        if(i == a-2) arr[a-1] = temp;
    }
    b = b-1;
    if(b == -1) b=a-1;
}

int index_max(int x,int a,int arr[])
{
    int index = x ;
    for(int i =x;i<a;i++)
    {   int max = arr[index];
        if(arr[i] > max) index = i;
    }
    return index;
}

void queue_print()
{
    int t;
    cin >> t;
    while ((t--))
    {  
    int ans =0;
    int a,b;
    int arr[100] ;
    cin >> a >>b;
    for( int i=0;i<a;i++)
    {
        cin >> arr[i];
    }
    
    for(int x = 0;x <a;x++)
    {  
        int indexmax = index_max(x,a,arr);
        //cout << "indexmax lan " << x+1 << " la " << indexmax <<endl;
        if( indexmax == b) 
        {
            ans = ans+1;
            break;
        }
        for(int j =0;j<indexmax;j++)
        {
            xep_hang(x,a,arr,b);
        }
        //cout << "b sau lan xep thu " << x+1 << " la "<< b <<endl;
        ans++ ;
        //cout  << "ans = " << ans << endl;
    }
    
    
    
    cout << "ans = " << ans <<endl;
    }
}
int main()
{   
    checks1ins2();
}
