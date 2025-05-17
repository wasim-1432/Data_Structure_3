#include<iostream>
using namespace std;
int main()
{
    int i,arr[]={58,62,91,43,29,37,88,72,16};
    int left=0,right=8,loc=0;
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
    for(i=0;i<9;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}