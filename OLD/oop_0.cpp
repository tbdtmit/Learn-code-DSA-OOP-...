#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class SV{
    string msv;
    string name;
    string lop;
    string email;
    public:
    friend istream &operator>> (istream &,SV &);
    friend ostream &operator<< (ostream &,SV &);
    bool operator < (SV );
};

istream &operator>> (istream &in,SV &sv)
{
    cout << "msv : ";
    in >> sv.msv;
    cout <<  "name : ";
    in.ignore();
    getline(in,sv.name);
    cout << "lop : ";
    in >> sv.lop;
    cout << "email : ";
    in >> sv.email;
    return in;
}

ostream &operator<< (ostream &out,SV &sv)
{
    out << sv.msv << " ";
    out << sv.name << " ";
    out << sv.lop << " ";
    out << sv.email << " ";



    return out;
}

bool SV:: operator < (SV sv)
{
    return this->lop < sv.lop;
}

            //  //  //
class DN{
        string mdn;
        string name;
        string sv;
        public:
        friend istream &operator >> (istream&,DN &);
        friend ostream &operator << (ostream&,DN &);
        bool operator < (DN dn);

};

istream &operator >> (istream &in,DN &dn)
{
    in >> dn.mdn;
    in.ignore();
    getline(in,dn.name);
    in >> dn.sv;
    return in;
}
ostream& operator << (ostream &out,DN &dn)
{
    out << dn.mdn << " ";
    out << dn.name << " ";
    out << dn.sv << " ";
    return out;
}
bool DN :: operator < (DN dn) // phuc vu yeu cau bai toan sap xep theo so sv tang dan, neu = nhau thi sx theo mdn
                                // toan tu < luon dung de sap xep trong ham sort mac dinh nen overload toan tu nay cho nhanh
{
    if(this->sv != dn.sv)
    return this->sv > dn.sv;
    return this->mdn < dn.mdn;
}
            //  //  //
int main()
{
    DN dn[5];
    for(int i=0;i<5;i++)
    {
        cin >> dn[i];
    }
    sort(dn,dn+5);
    for(auto i : dn)
    {
        cout << endl;
        cout << i;
    }
    return 0;
}
