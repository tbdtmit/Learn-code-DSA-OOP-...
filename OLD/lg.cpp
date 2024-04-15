#include<iostream>
#include<vector>
using namespace std ;

int array[4] ={0};
bool check[4] ={0};
int counting_arr[10000] = {-1};

void selected_sort(int arr[], int n)
{   
    int temp =0;
    int index_min ;
    for(int i =0;i<n;i++)
    {   
        index_min =i;
        for(int j=i;j<n;j++)
        {   
            if(arr[j] < arr[index_min])
            {
                index_min = j;
            }
        }

        if(index_min != i)
        {   
            temp = arr[i];
            arr[i] = arr[index_min];
            arr[index_min] = temp;
        }
    }

}

void back_tracking(int temp)
{   

    if(temp >4)
    {   
        for(int j=0;j<4;j++)
        {   
            cout << array[j] <<" ";

        }
        cout << endl;
        return;
    }
    for(int i=0;i<4;i++)
    {   
        if(check[i] == 0)
        {   
            array[i] = temp;
            check[i] = 1 ;
            back_tracking(temp+1);
            check[i] = 0;
        }
    }
}

void bubble_sort(int *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        int temp;
        for(int j=n-1;j>i;j--)
        {   
            if( arr[j] < arr[j-1] )
            {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

void counting_sort(int arr[], int n)
{
    int max = arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    for(int i =0;i<n;i++)
    {
        counting_arr[arr[i]]++;
    }

    int cnt =0;
    for(int i =0;i<=max;i++)
    {
        if(counting_arr[i] > 0)
        {
            for(int j =0;j<counting_arr[i];j++)
            {
                arr[cnt] = i;
                cnt++;
            }
        }
    }
}

void insert_sort(int arr[], int n)
{
    for(int i =1;i<n;i++)
    {
        int cnt = i;
        int temp;
        while( arr[cnt] < arr[cnt-1] && cnt >0)
        {
            temp =  arr[cnt];
            arr[cnt] = arr[cnt-1] ;
            arr[cnt-1] = temp;
            cnt--;
        }
        

    }
}

void show_arr(int arr[] , int n)
{   
    for(int i=0;i<n;i++)
    {
        cout << arr[i] <<" ";
    }
}

void sinh_to_hop(int n, int cnt,int s)
{
    if(cnt >s-1)
    {
        cout << n <<endl;
        return;
    }
    else{
    for(int i= 1;i<=s;i++)
    {

        sinh_to_hop(n*10 + i, cnt+1,s);
    }
    }

}

int giai_thua(int a)
{
    if( a== 1)
        return 1;
    else{
        return giai_thua(a-1)*a;
    }
}

int fibonacci(int n)
{
    if(n == 1)
        return 1;
    else if(n ==2 )
        return 1;
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}


int N, X[100] ;

void inkq()
{
    for(int i=1;i<=N;i++)
    {
        cout << X[i];
            }
            cout << endl;
}

void binary(int n)
{
    for(int i=0;i<=1;i++)
    {
        X[n] = i;
        if(n == N)
        {
            inkq();
        }
        else{
            binary(n+1);
        }
    }
}


class sinhvien{
public:
    int tuoi;
    char gen;
    virtual void print()
    {
        cout << "sinh vien"<<endl;
    }

};

class vatly : public sinhvien{
    public:
    int nam;

    void print()
    {
        cout << "sinh vien vat ly" <<endl;
    }
};

void continous_array_equal_zero()
{
    int ans =0;
    int cnt = 0;
    int n;
    int temp =0;
    cin >> n;
    int *A = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> A[i];
    }
    for(int i =0;i<n;i++)
    {
        temp = A[i];
        cnt =1;
        for(int j=i+1;j<n;j++)
        {
            temp+= A[j];
            cnt++;
            if(temp == 0)
            {
                if(ans < cnt)
                {
                    ans = cnt;
                    break;
                }
                else
                break;
            }
        }
    }
    cout << ans;
    delete[] A;
}

void merge(int a[], int l, int m , int r)
{
    int  *x ;
}

void chuyen(int n, char a, char b)
{
    cout << "chuyen dia thu " <<  n << " tu coc " << a << " sang coc "<< b << endl;
}

void thapHaNoi(int n, char a , char b, char c)
{
    if(n == 1) chuyen(1,a,c);
    else{
        thapHaNoi(n-1,a,c,b);
        chuyen(n, a, c);
        thapHaNoi(n-1,b,a,c);
    }
}


int arr[100][100];
char mark[4][4];

void xuatmang_xoan_oc_thuan(int *sort,int so_hang, int so_cot)
{
    int direct = 0;
    int i =0;
    int j =0;
    int dh =0;
    int ch = so_cot -1;
    int dc =1; 
    int cc = so_hang -1;
    for(int a =0;a <so_cot*so_hang;a++)
    {
        if(direct == 0 )
        {
            arr[i][j] = sort[a];
            j++;
            if(j>ch)
            {
                direct = 1;
                j--;
                i++;
                ch--;
            }
        }
        else if(direct == 1 )
        {
            arr[i][j] = sort[a];
            i++;
            if(i > cc)
            {
                direct = 2;
                i--;
                j--;
                cc--;
            }    
        }
        else if(direct == 2 )
        {
            arr[i][j] = sort[a];
            j--;
            if(j < dh)
            {
                direct = 3;
                j++;
                i--;
                dh++;
            }    
        }
        else if(direct == 3 )
        {
            arr[i][j] = sort[a];
            i--;
            if(i<dc)
            {
                direct = 0;
                i++;
                j++;
                dc++;
            }    
        }
    }

    
}


void xuatmang_2(int *sort,int so_hang, int so_cot)
{
    int i =0;
    int j =0;
    int status = 1;
    for(int a =0; a<so_cot*so_hang;a++)
    {
        if(status)
        {
            arr[i][j] = sort[a];
            j++;
            i--;
            
        }
    }

}
void prj1()
{
    int so_hang , so_cot;
    cout << "nhap so hang, so cot: " <<endl;
    cin >> so_hang >> so_cot;
    int *sort = new int[so_cot*so_hang];
    int a =0;
    cout << "nhap cac phan tu cua mang: " << endl;
    for(int i =0;i<so_hang;i++)
    {
        for(int j =0;j<so_cot;j++)
        {
            cin >> arr[i][j];
            sort[a] = arr[i][j];
            a++;
        }
    }

    bubble_sort(sort,so_cot*so_hang);
    xuatmang_xoan_oc_thuan(sort,so_hang,so_cot);
    for(int i =0; i<so_hang;i++)
    {
        for(int j =0;j<so_cot;j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    delete[] sort;

}

        // MAXIMUM_PATH_SUM aka mps
int ans_of_mps = 0;
int arr_of_mps[100][100];
    int move_h_of_mps[3] = {1,1,1};
    int move_c_of_mps[3] = {-1,0,1};
void move_of_maximum_path_sum(int i, int j, int sum, int h, int c)
{
    if(sum > ans_of_mps)
        ans_of_mps =sum;
    if(i == h -1)
        return;
    for(int a = 0;a<3;a++)
    {
        if( i+move_h_of_mps[a] >=0 && j+move_c_of_mps[a] >= 0 && i+move_h_of_mps[a] <h && j+move_c_of_mps[a] < c)
        {
            move_of_maximum_path_sum(i+move_h_of_mps[a],j+move_c_of_mps[a],sum+arr_of_mps[i+move_h_of_mps[a]][j+move_c_of_mps[a]], h, c);
        }
    }
}
void maximum_path_sum()
{

    int h,c;
    cin >> h>>c;
    for(int i =0;i<h;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin >> arr_of_mps[i][j];
        }
    }

    for(int i =0 ;i<c;i++)
    {
        move_of_maximum_path_sum(0,i,arr_of_mps[0][i],h,c);
        cout << "ans = " << ans_of_mps <<endl ;
    }
    


}


int main()
{
    maximum_path_sum();
    

    return 0;
}