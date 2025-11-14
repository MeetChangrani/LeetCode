#include<iostream>
using namespace std;
int main()
{
    int a=123;
    int digit;
    int sum;
    for(int i=0;i<3;i++)
    {
        digit=a%10;
         a=a/10;
        sum+=digit;

    }
cout<<digit;
return 0;
}