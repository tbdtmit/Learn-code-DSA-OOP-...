#include<bits/stdc++.h>
using namespace std;

            //HÌNH CHỮ NHẬT LỚN NHẤT
void max_rectangle()
{
    int tc;
    cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        stack<int> left; // chua index
        stack<int> right; // chua index
        vector<pair<int,int>> vt(100005); //chua index
        int a[100005] = {};
        int n;cin >> n;
        left.push(0);
        right.push(n+1);
        a[0] = -1;
        a[n+1] = -1;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
        }
        for(int i=1;i<=n;i++)
        {

            int m = n+1 - i;
            if(a[i] > a[left.top()])
            {
                vt[i].first = left.top();
                left.push(i);
            }
            else{
                while (a[i] <=  a[left.top()])
                {
                    left.pop();
                }
                vt[i].first = left.top();
                left.push(i);
                
            }

            if(a[m] > a[right.top()])
            {
                vt[m].second = right.top();
                right.push(m);
            }
            else{
                while (a[m] <=  a[right.top()])
                {
                    right.pop();
                }
                vt[m].second = right.top();
                right.push(m);
                
            }    
        }
        long long max =0;
        for(int i=1;i<=n;i++)
        {
            long long area = (long long)a[i] * (long long)(vt[i].second - vt[i].first - 1);
            if(area > max ) max = area;
        }
        cout << max << endl;

    }
}
            //HÌNH CHỮ NHẬT LỚN NHẤT

            //BIẾN ĐỔI TRUNG TỐ - HẬU TỐ
int degree(char a)
{
    if(a == '(' || a == ')') return 0;
    else if(a == '^') return 4;
    else if( a == '/' || a == '*') return 3;
    else if(a== '+' || a == '-') return 2;
    return 1;
}
void convert_mid_to_bot()
{
    int tc;
    cin >>tc;
    for(int ii=0;ii<tc;ii++)
    {
        string s;
        cin >> s;
        int n = s.length();
        string ans = "";
        stack<char> st;

        for(int i = 0;i<n;i++)
        {
            if(isalpha(s[i]))
            {
                ans += s[i];
            }
            else if( s[i] == '(')
            {
                st.push(s[i]);

            }
            else if(s[i] == ')')
            {
                while(st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();

            }
            else    
            {

                    while (st.size() != 0 && degree(st.top()) >= degree(s[i]) ) // phai la >= vi pjep toan tu trai sang phai,
                                                                                    // dau nao xuat hien trc phai dc push ra truoc mac du co do uu tien bang nhau
                    {
                        ans+=st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                
            }
        }

            while(st.size() )
            {
                ans+=st.top();
                st.pop();
            }

        cout << ans << endl;
    }
}
            //BIẾN ĐỔI TRUNG TỐ - HẬU TỐ

            //GIẢI MÃ XÂU KÝ TỰ
void fix_string()
{
    int tc;
    cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        string s;
        cin >> s;
        int n =s.length();
        stack<char> stc;
        for(int i =0;i<n;i++)
        {
            if(s[i] >='0' && s[i] <= '9')
            {
                while(s[i] >='0' && s[i] <= '9')
                {
                
                    stc.push(s[i]);
                    i++;
                }
                i--;
            }
            else if(isalpha(s[i]))
            {

                while(isalpha(s[i]))
                {
                    stc.push(s[i]);
                    i++;
                }
                i--;
    

            }
            else if( s[i] == '[')
            {
       
                stc.push(s[i]);
            }
            else if( s[i] == ']')
            {
    

                string tt ="";
                string num ="";
                while(stc.top() != '[')
                {
                    tt = stc.top() + tt;
                    stc.pop();
                }
                stc.pop();
                while(stc.size() && isdigit(stc.top()))
                {
                    num = stc.top() + num;
                    stc.pop();
                }
                if(num == "")
                    num = "1";
                string ans = "";
                int nu = stoi(num);
                for(int iz =0;iz<nu;iz++)
                {
                    ans+= tt;
                }
                for(int iz =0;iz<ans.length();iz++)
                {
                    stc.push(ans[iz]);
                }




            }
        }
        string ans ="";
        while(stc.size())
        {
            ans = stc.top() + ans;
            stc.pop();
        }
        cout << ans << endl;

        

    }
}
            //GIẢI MÃ XÂU KÝ TỰ

            //BIỂU THỨC TƯƠNG ĐƯƠNG
string same_func(string s)
{
    // int tc;
    // cin >> tc;
    // for(int ii =0;ii<tc;ii++)
    // {
        // string s;
        // cin >> s;
        stack<char> st;
        vector<char> a;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == ')')
            {

                string tem = "";
                while(st.top()  != '(')
                {
                    tem = st.top() + tem;
                    st.pop();
                }
                st.pop();
                if(isalpha(tem[0])) tem = '+' + tem;
                
                
                if(st.size() && st.top() == '+')
                {
                    st.pop();
                    for(int j =0;j<tem.length();j++)
                    {

                        st.push(tem[j]);
                    }
                }
                else if(st.size() ==0 || st.top() == '(')
                {
                    for(int j =0;j<tem.length();j++)
                    {

                        st.push(tem[j]);
                    }    
                }
                else{
                    st.pop();
                    for(int j =0;j<tem.length();j++)
                    {
                        if(tem[j] == '-')
                        {
                            st.push('+');
                        }
                        else if(tem[j] == '+'){
                            st.push('-');
                        }
                        else 
                            st.push(tem[j]);
                    }
                }
            }
            else if(s[i] == '-' || s[i] == '+')
            {
                char dau = '+';
                while(s[i] == '-' || s[i] == '+' && i <s.length())
                {
                    if(s[i] == '-' && dau == '+') dau = '-';
                    else if(s[i] == '-' && dau == '-') dau = '+';
                    i++;

                }
                i--;
                st.push(dau);
            }
            else{
                st.push(s[i]);
            }
        }
        string ans ="";
        while (st.size())
        {
            if(st.size() == 1 && st.top() == '+') break;
            ans = st.top() + ans;

            st.pop();
            
        }
        //cout << ans << endl;
        return ans;
        
    }
//}
            //BIỂU THỨC TƯƠNG ĐƯƠNG     

            //SO SÁNH BIỂU THỨC
void compare_expression()
{
    int tc;
    cin>>tc;
    for(int ii =0;ii<tc;ii++)
    {
        string s;
        cin >> s;
        string ss;
        cin >> ss;
        if(same_func(ss) == same_func(s)) cout << "YES" <<endl;
        else cout << "NO" << endl;
    }
}
            //SO SÁNH BIỂU THỨC

            //TẬP CON LIỀN KỀ PHÍA TRƯỚC
void next_generation()
{
    int tc;cin >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        int a[1005] = {};
        a[0] = -100;
        int n, k;
        cin >> n >> k;
        for(int i=1;i<=k;i++)
        {
            cin >> a[i];

        }
        int id = k;
        if(a[id] - 1 > a[id-1])
        {
            a[id] = a[id] -1;
        }
        else{
            while(a[id] - 1 <= a[id-1])
            {
                id--;
            }
            if(a[id] - 1 ==0)
            {
                for(int j=1;j<=k;j++)
                {
                    a[j] = n+j-k;
                }
            }
            else
                a[id] = a[id] -1 ;
                for(int jj = k;jj>=id+1;jj--)
                {
                    a[jj] = n--;
                }
        }
        for(int i=1;i<=k;i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}
            //TẬP CON LIỀN KỀ PHÍA TRƯỚC

            //GIÁ TRỊ LỚN NHẤT
void max_value()
{
    int n;
    cin >> n;
    unsigned long long sum = 0;
    for(int i=1;i<=n;i++)
    {
        int tem;
        cin >> tem;
        if(tem <= 0) tem = 0;
        else tem *= 2;
        sum += (unsigned long long)tem;
    }
    cout << sum << endl;
}
            //GIÁ TRỊ LỚN NHẤT

            //KHOẢNG CÁCH XA NHẤT
int max_mask[1000005] = {};
void max_distance(){
    int tc;
    cin  >> tc;
    for(int ii =0;ii<tc;ii++)
    {
        vector<pair<int,int>> vt;
        int n;cin >> n;
        for(int i=0;i<n;i++)
        {
            int tem;
            cin >> tem;
            vt.push_back({tem,i});
        }
        sort(vt.begin(),vt.end());
        int max = vt[n-1].second;
        int mxval = vt[n-1].first;
        int ans = -1;
        for(int i = n-2;i>=0;i--)
        {
            if(vt[i].second > max && vt[i].first <= mxval)
            {   
                max_mask[i] = vt[i].second;
                max = vt[i].second;
                mxval = vt[i].first;
            }
            else if(vt[i].second < max &&  vt[i].first < mxval){
                max_mask[i] = max;
                int te = max - vt[i].second;
                if(te > ans) ans = te;
            }

        }
        cout << ans << endl;
    }
}
            //KHOẢNG CÁCH XA NHẤT

void cv(int a)
{
    a = 9;
}
int main()
{
    // int *a = new int ;
    // *a = 10;
    // *(a+1) = 8;
    // cout << *a << " " << *(a+1) ;
    // delete a;
    int a = 99 ;
    int &b = a;
     cout << a << endl;
    cv(b);
    cout << a << endl;
    return 0 ;
}