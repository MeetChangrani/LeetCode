#include<iostream>
#include<string.h>
using namespace std;
class A
{
    char *ptr;
    public:
    A(const char *p)
    {
        int l=strlen(p);
        ptr=new char[l+1];
        for(int i=0;i<l;i++)
        {
            ptr[i]=p[i];
        }
    }
    void display()
    {
        cout<<ptr;
    }
};




int main()
{
    A a("meet");
    
    a.display();
    return 0;
}