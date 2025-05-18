#include<iostream>
using namespace std;
void Selection_Sort(int* arr,int size);
int main()
{
    int arr[]={38,90,47,69,52,88,71,18,20};
    Selection_Sort(arr,9);
    cout<<endl;
    return 0;
}
void Selection_Sort(int* arr,int size)
{
    int min=0,i,k,j;
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
}