#include<iostream>
using namespace std;
int Quick_Sort_Procedure(int* arr,int left,int right)
{
    int loc=left;
    while(left!=right)
    {
        if(arr[loc]>arr[right])
        {
            int temp=arr[loc];
            arr[loc]=arr[right];
            arr[right]=temp;
            loc=right;
            if(arr[loc]>arr[left])
            {
                left++;
            }
        }
        else if(arr[loc]<arr[left])
        {
            int temp=arr[loc];
            arr[loc]=arr[left];
            arr[left]=temp;
            loc=left;
            if(arr[loc]<arr[right])
            {
                right--;
            }
        }
        else if(arr[loc]<arr[right])
        {
            right--;
        }
        else if(arr[loc]>arr[left])
        {
            left++;
        }
    }
    return loc;
}
void Quick_Sort_Using_Recusion(int* arr,int left,int right)
{
    if(left<right)
    {
        int pviot=Quick_Sort_Procedure(arr,left,right);
        Quick_Sort_Using_Recusion(arr,left,pviot-1);
        Quick_Sort_Using_Recusion(arr,pviot+1,right);
    }
}
void Quick_Sort(int *arr,int size)
{
    Quick_Sort_Using_Recusion(arr,0,size);
    int i;
    for(i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={58,62,91,43,29,37,88,72,16};
    Quick_Sort(arr,9);
    cout<<endl;
    return 0;
}