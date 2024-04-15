#include "myLib.cpp"
#include<memory>


std::string encryptDataByLetterInc(std::string data)
{
    for(int i = 0; i < data.size(); i++)
    {
        if( (data[i] >= 'a' && data[i] <= 'z' ) || (data[i] >= 'A' && data[i] <= 'Z' ) )
            data[i]++;
    }
    return data;
}

std::string buildCompleteMessage(std::string rawData )
{
    // Add some header and footer to data to make it complete message
    rawData = "[HEADER]" + rawData + "[FooTER]";
    // Call the callBack provided i.e. function pointer to encrypt the message
    rawData = encryptDataByLetterInc(rawData);
    return rawData;
}

class A{
    public:
    int value = 1;
};
int main()
{
    A a;
    {
    shared_ptr<A> ptr1 =  make_shared<A>(a);
    {
            shared_ptr<A> ptr2(&a);
                cout << ptr1.use_count() << endl;
    }
    }


    cout << "oke" << endl;
    return 0;
}