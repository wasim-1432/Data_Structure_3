#include<iostream>
using namespace std;
#define OVERFLOW 1
#define UNDERFLOW 2
#define INVALIDINDEX 3
class Array
{
    private:
        int capacity;
        int lastIndex;
        int* arr;
    public:
        Array(int);
        Array(Array &);
        Array& operator=(Array &);
        bool Is_Empty();
        bool Is_Full();
        void Append(int);
        void ShowArray();
        void Insert_data_At_Specified_Index(int,int);
        void Edit_At_Specified_Index(int,int);
        void Delete_Element_At_Specified_Index(int);
        int Get_Element_At_Specified_Index(int);
        int Count_Number_Of_Elements_In_The_Array();
        ~Array();
        int Found(int);
};
Array::Array(int cap)
{
    capacity=cap;
    lastIndex=-1;
    arr=new int[capacity];
}
Array::Array(Array &arr1)
{
    capacity=arr1.capacity;
    lastIndex=arr1.lastIndex;
    arr=new int[capacity];
    int i;
    for(i=0;i<=lastIndex;i++)
    {
        arr[i]=arr1.arr[i];
    }
}
Array& Array::operator=(Array &arr1)
{
    if(arr!=nullptr)
    {
        delete []arr;
    }
    capacity=arr1.capacity;
    lastIndex=arr1.lastIndex;
    arr=new int[capacity];
    int i;
    for(i=0;i<=lastIndex;i++)
    {
        arr[i]=arr1.arr[i];
    }
    return *this;
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
void Array::ShowArray()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    else
    {
        int i;
        for(i=0;i<=lastIndex;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
}
void Array::Insert_data_At_Specified_Index(int index,int data)
{
    if(Is_Full())
    {
        throw OVERFLOW;
    }
    if(index<0 || index>lastIndex+1)
    {
        throw INVALIDINDEX;
    }
    lastIndex++;
    int i;
    for(i=lastIndex;i>index;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[i]=data;
}
void Array::Edit_At_Specified_Index(int index,int data)
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    if(index<0 || index>lastIndex)
    {
        throw INVALIDINDEX;
    }
    arr[index]=data;
}
void Array::Delete_Element_At_Specified_Index(int index)
{
    if(index<0 || index>lastIndex)
    {
        throw INVALIDINDEX;
    }
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
    {
        throw INVALIDINDEX;
    }
    return arr[index];
}
int Array::Count_Number_Of_Elements_In_The_Array()
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
            return i;
        }
    }
    return -1;
}
int main()
{
    Array a1(5);
    a1.Append(88);
    a1.Append(87);
    a1.Append(65);
    a1.Insert_data_At_Specified_Index(3,33);
    a1.Edit_At_Specified_Index(0,34);
    //a1.Delete_Element_At_Specified_Index(3);
    a1.Get_Element_At_Specified_Index(3);
    a1.ShowArray();
    cout<<endl;
    return 0;
}