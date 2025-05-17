#include<iostream>
using namespace std;
int main()
{
    int min=0,i,arr[]={38,90,47,69,52,88,71,18,20},k,j;
    for(i=0;i<9;i++)
    {
        for(j=i+1;j<9;j++)
        {
            if(arr[i]>arr[j])
            {
                min=arr[j];
                k=j;
                int temp=arr[i];
                arr[i]=min;
                arr[k]=temp;
            }
        }
    }
    for(i=0;i<9;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}