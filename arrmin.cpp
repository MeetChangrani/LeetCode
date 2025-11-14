#include<iostream>
using namespace std;

int main()
{
    int arr[5]={1,2,3,4,5};
    int arrmin=arr[0];
    for(int i=0;i<5;i++)
    {
        if(arr[i]<arrmin)
        {
            arrmin=arr[i];
        }
    }
    cout<<arrmin;
    return 0;

}