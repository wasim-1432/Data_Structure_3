#include<iostream>
using namespace std;
#define OVERFLOW 1
#define INVALIDINDEX 2
class Array
{
    private:
        int capacity;
        int lastIndex;
        int *arr;
    public:
        Array(int);
        bool Is_Empty();
        bool Is_Full();
        void Append(int);
        void ShowData();
        void Insert_At_Specified_Index(int,int);
        void Edit_At_Specified_Index(int,int);
        void Delete_At_Specified_Index(int);
        int Get_Element_At_Specified_Index(int);
        int Count_Number_Of_Elements_Present_In_The_Array();
        ~Array();
        int Found(int);
};
Array::Array(int cap)
{
    capacity=cap;
    lastIndex=-1;
    arr=new int[capacity];
}
bool Array::Is_Empty()
{
    return lastIndex==-1;
}
bool Array::Is_Full()
{
    return lastIndex==capacity-1;
}
void Array::Append(int data)
{
    if(Is_Full())
    {
        throw OVERFLOW;
    }
    lastIndex++;
    arr[lastIndex]=data;
}
void Array::ShowData()
{
    int i;
    for(i=0;i<=lastIndex;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void Array::Insert_At_Specified_Index(int index,int data)
{
    if(Is_Full())
    {
        throw OVERFLOW;
    }
    else if(index<0 || index>lastIndex+1)
    {
        throw INVALIDINDEX;
    }
    lastIndex++;
    int i;
    for(i=lastIndex;i>=index;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[index]=data;
}
void Array::Edit_At_Specified_Index(int index,int data)
{
    if(index<0 || index>lastIndex)
        throw INVALIDINDEX;
    arr[index]=data;
}
void Array::Delete_At_Specified_Index(int index)
{
    if(index<0 || index>lastIndex)
        throw INVALIDINDEX;
    int i;
    for(i=index;i<=lastIndex;i++)
    {
        arr[i]=arr[i+1];
    }
    lastIndex--;
}
int Array::Get_Element_At_Specified_Index(int index)
{
    if(index<0 || index>lastIndex)
        throw INVALIDINDEX;
    return arr[index];
}
int Array::Count_Number_Of_Elements_Present_In_The_Array()
{
    return lastIndex+1;
}
Array::~Array()
{
    delete []arr;
}
int Array::Found(int data)
{
    int i;
    for(i=0;i<=lastIndex;i++)
    {
        if(arr[i]==data)
        {
            return arr[i];
        }
    }
    return -1;
}
int main()
{
    Array a1(4);
    a1.Append(22);
    a1.Append(34);
    a1.Append(23);
    a1.Insert_At_Specified_Index(1,33);
    a1.Edit_At_Specified_Index(3,35);
    //a1.Delete_At_Specified_Index(2);
    //a1.Get_Element_At_Specified_Index(0);
    //a1.Count_Number_Of_Elements_Present_In_The_Array();
    a1.Found(33);
    a1.ShowData();
    cout<<endl;
    return 0;
}