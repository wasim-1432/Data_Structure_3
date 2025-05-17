#include<iostream>
using namespace std;
int main()
{
    int i,arr[]={50,20,37,91,64,18,43,59,72,81},j,k=0;
    int arr1[10];
    arr1[0]=arr[0];
    for(i=1;i<10;i++)
    {
        for(j=i-1;j>=0 && arr[i]<arr1[j];j--)
        {
            arr1[j+1]=arr1[j];
        }
        arr1[j+1]=arr[i];
    }
    for(i=0;i<10;i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    return 0;
}