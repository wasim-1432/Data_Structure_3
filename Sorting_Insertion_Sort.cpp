#include<iostream>
using namespace std;
void Insertion_Sort(int* arr,int size);
int main()
{
    int arr[]={22,66,55,33,4,5,7,99,100};
    Insertion_Sort(arr,9);
    cout<<endl;
    return 0;
}
void Insertion_Sort(int* arr,int size)
{
    int i,j;
    int arr1[size];
    arr1[0]=arr[0];
    for(i=1;i<size;i++)
    {
        for(j=i-1;j>=0 && arr[i]<arr1[j];j--)
        {
            arr1[j+1]=arr1[j];
        }
        arr1[j+1]=arr[i];
    }
    for(i=0;i<size;i++)
    {
        cout<<arr1[i]<<" ";
    }
}