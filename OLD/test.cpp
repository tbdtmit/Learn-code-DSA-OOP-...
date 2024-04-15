#include<bits/stdc++.h>
using namespace std;

void merge(vector <pair<int, int>> &a,int l,int m, int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    vector<pair<int , int>> left;
    vector<pair<int , int>> right;
    int k =0;

    for(int i = l;i<=m;i++)
    {
        left.push_back(a[i]);
    }

    for(int i = m+1;i<=r;i++)
    {
        right.push_back(a[i]);
    }

    int i =0;
    int j =0;
    k = l;
    while(i<n1&&j<n2)
    {
        if(left[i].second <= right[j].second)
        {
            a[k++] = left[i++];
        }
        else
        {
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

}

void merge_sort(vector <pair<int, int>> &a, int l, int r)
{
    if(l<r)
    {
        int m = (l+r)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main()
{
    vector <pair<int, int>> a ;
    int n ;
    cout << "nhap so phan tu can sap xep: " <<endl;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        pair<int, int> s;
        cout << "nhap phan tu dau tien cua pair thu " << i+1<< " : ";
        cin >> s.first;
        cout << "nhap phan tu thu hai cua pair thu " << i+1<< " : ";
        cin >> s.second;
        a.push_back(s);

    }
    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++)
    {

        cout << a[i].first << " "<< a[i].second << endl;
    }
    return 0;
}
