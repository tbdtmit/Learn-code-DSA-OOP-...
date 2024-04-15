#include<iostream>
#include<string>
#include<deque>
#include<queue>


using namespace std;

int abcd = 0;
class A{
public:
    static int cnt;
    A()
    {
        cnt++;
    }
    void static in()
    {
        cout << "in A" << endl;
        abcd++;
        cnt++;
    }
    static void inn()
    {
        cout << "Hello World" << endl;
        in();
    }
};

class B : public A{
    public:
    virtual void in()
    {
        cout << "in B" << endl;
    }
};

class C  :  public B {
    protected:
    int c = 9;
    string cc = " string c ";
    public:
    C()
    {
        cnt++;
    }
    void in()
     {
        cout << "in C" << endl;
     }



};

class D : public C{
    public:
    int d = 15;
    public:
    D() : C()
    {

    }
    virtual void in()
    {
        cout << "in D" << endl;
        cout << cc << endl;
        cout << c << endl;
    }

};

class E : public D{
    public:
    E()
    {
        cnt +=cnt;
    }
    // void in()
    // {
    //     cout << "in E " << endl;

    // }
};

class F {
    private:
    string a;
    public:

    void in_f()
    {
        cout << " f = " << this->a << endl;
    }
    void cin_f()
    {
        cout << " nhap a: " ;
        getline(cin , this->a);
    }
};

int A:: cnt = 0;

int x =5;
static int y;
int i =0;
 static void  myFn()
{
    y = x++ + ++i;
    A :: cnt++;

}

void abc(int a =0 )
{
    cout << a;
}

void abc( string a ="abc")
{

   cout << a;
}


            //Phan So OOP
class phan_so{
    public:
    int mau;
    int tu;
    const int cst = 100 ;
    public:
    phan_so(int tu,int mau = 1) {
        this->tu = tu;
        this->mau = mau;
    }
    phan_so(){tu = 1;mau=1;};


    friend istream &operator >> (istream  &, phan_so &);
    friend ostream &operator << (ostream &, phan_so &);
    phan_so operator+ (phan_so ps);
    phan_so operator++ ();
    phan_so operator++ (int);
    phan_so operator += (phan_so);

    void out()
    {
        cout << this->tu << "/" << this->mau;
    }

};

istream &operator >> (istream  &in, phan_so &ps)
{
    cout << "ps : ";
    in >> ps.tu;
    //cout << "mau : ";
    in >> ps.mau;
    return in;
}
ostream &operator << (ostream &out, phan_so &ps){
    out << ps.tu << "/" << ps.mau;
    return out;
}
phan_so phan_so::operator+ (phan_so ps)
{
    phan_so t;
    t.tu = mau * ps.tu + tu * ps.mau ;
    t.mau = mau * ps.mau;
    return t;
}
phan_so phan_so :: operator ++()
{
    tu = tu +mau;  
    return *this; // return phanso(tu,mau);
}
phan_so phan_so:: operator++(int)
{
    phan_so t(tu, mau);
    tu = tu + mau;
    return t;
}
phan_so phan_so:: operator+= ( phan_so ps)
{
    tu = mau * ps.tu + tu * ps.mau ;
    mau = mau * ps.mau;    
}
            //Phan So OOP
//extern int a ;

auto hello()
{
    cout << "hehehe" ;
    return 1;
}

void swap(int a,int b)
{
    int t = a;
    a = b;
    b= t;
}


class node{
    public:
    int id;
    string s;

};

queue<node*> q;

int main()
{
    // C c;
    // C *cc = &c;
    // cout << cc << " " << cc + 1 << endl;
    // D d;
    // D *dd = &d;
    // cc = &d;
    // cout << dd << " " << dd + 1 << endl;
    // cout << cc << " " << cc + 1 << endl;
    // d.C::in();
    // a = 10;
    // cout << a << endl;
    // int abcd = 10;
    // A a;
    // a.in();
    // a.in();
    // a.in();
    // cout << abcd;
    // cout << endl << a.cnt<<endl;
    // A :: inn();
    // cout << ::abcd << endl;
    // cout << hello();

    // int a = 100;
    // void *ptr = &a;
    // cout << (int*)ptr;

    // aa->in();
    // bb->in();
    // cc->in();
    // dd->in();
    //cc = &d;

    // int a = 100;
    // int b = 200;

    // int &aa = a;
    // int &bb = b;
    // swap(aa,bb);
    // cout << a <<" " <<b ;

    // int te =10;
    // cout << te++ + te++ + ++te + te++ << endl;
    // cout << te;
    // char a[] = {'1','2','3','4','5','1','2','3','4','5','1','2','3','4','5','1','2','3','4','5'};
    // char*ab = &a[0];
    // for(int i=0;i<5;i++)
    // {
    // cout << *ab << endl;
    // ab++;
    // }
    // cout << endl;
    
    // long long *aa = (long long*)a;
    // cout << char(*aa) << endl;
    // aa++;
    // cout << char(*aa) << endl;
    


    
    // priority_queue<int,vector<int>,greater<int>> pq;
    // int i;
    // do
    // {
    //     /* code */
    //     cin >> i;
    //     pq.push(i);
    // } while (i!= 100);
    
    // while(!pq.empty()) {
    //     cout << pq.top() << " ";
    //     pq.pop();
    // }

    node b ;
    node *a  = &b;
    q.push(a);
    node* c = q.back();
    q.pop();
    return 0;
}
