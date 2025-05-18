#include<iostream>
using namespace std;
void Bubble_Sort(int *arr,int size);
int main()
{
    int arr[]={12,88,54,77,44,22,2,3,6};
    Bubble_Sort(arr,9);
    cout<<endl;
    return 0;
}
void Bubble_Sort(int *arr,int size)
{
    int round,i;
    for(round=0;round<size-1;round++)
    {
        for(i=0;i<size-round-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
    for(i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}