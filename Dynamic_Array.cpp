#include<iostream>
using namespace std;
#define UNDERFLOW 1
#define INVALIDINDEX 2
class DynArray
{
    private:
        int capacity;
        int lastIndex;
        int* arr;
    protected:
        void Double_Array();
        void Half_Array();
    public:
        DynArray(int);
        void Return_Capacity();
        bool Is_Empty();
        void Append(int);
        bool Is_Full();
        void Show_Dyn_Array();
        void Insert_At_Specified_Index(int,int);
        void Edit_Element_At_Specifed_Index(int,int);
        void Delet_An_Element_At_Specified_Index(int);
        int Get_Element_At_Specified_Index(int);
        int Count_Number_Of_Elements_Present_In_The_Array();
        ~DynArray();
        int Find(int);
};
DynArray::DynArray(int cap)
{
    capacity=cap;
    lastIndex=-1;
    arr=new int[capacity];
}
void DynArray::Double_Array()
{
    int *temp;
    temp=new int[2*capacity];
    for(int i=0;i<=lastIndex;i++)
    {
        temp[i]=arr[i];
    }
    delete []arr;
    arr=temp;
    capacity=2*capacity;
}
void DynArray::Half_Array()
{
    int *temp;
    temp=new int[capacity/2];
    for(int i=0;i<=lastIndex;i++)
    {
        temp[i]=arr[i];
    }
    delete []arr;
    arr=temp;
    capacity=capacity/2;
}
void DynArray::Return_Capacity()
{
    cout<<capacity<<endl;
}
bool DynArray::Is_Empty()
{
    return lastIndex==-1;
}
bool DynArray::Is_Full()
{
    return lastIndex==capacity-1;
}
void DynArray::Append(int data)
{
    if(Is_Full())
    {
        Double_Array();
    }
    lastIndex++;
    arr[lastIndex]=data;
}
void DynArray::Show_Dyn_Array()
{
    if(Is_Empty())
        throw UNDERFLOW;
    int i;
    for(i=0;i<=lastIndex;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void DynArray::Insert_At_Specified_Index(int index,int data)
{
    if(index<0 || index>lastIndex+1)
        throw INVALIDINDEX;
    if(Is_Full())
        Double_Array();
    int i;
    lastIndex++;
    for(i=lastIndex;i>=index;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[index]=data;
}
void DynArray::Edit_Element_At_Specifed_Index(int index,int data)
{
    if(index<0 || index>lastIndex)
        throw INVALIDINDEX;
    arr[index]=data;
}
void DynArray::Delet_An_Element_At_Specified_Index(int index)
{
    if(index<0 || index>lastIndex)
        throw INVALIDINDEX;
    for(int i=index;i<=lastIndex;i++)
    {
        arr[i]=arr[i+1];
    }
    lastIndex--;
    if(lastIndex + 1 <= capacity / 2 && capacity > 1)
        Half_Array();
}
int DynArray::Get_Element_At_Specified_Index(int index)
{
    if(index<0 || index>lastIndex)
        throw INVALIDINDEX;
    return arr[index];
}
int DynArray::Count_Number_Of_Elements_Present_In_The_Array()
{
    return lastIndex+1;
}
DynArray::~DynArray()
{
    delete []arr;
}
int DynArray::Find(int data)
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
    DynArray d1(2);
    d1.Append(77);
    d1.Append(87);
    d1.Insert_At_Specified_Index(2,778);
    //d1.Edit_Element_At_Specifed_Index(2,44);
    d1.Return_Capacity();
    d1.Delet_An_Element_At_Specified_Index(0);
    d1.Delet_An_Element_At_Specified_Index(1);
    d1.Show_Dyn_Array();
    d1.Return_Capacity();
    cout<<endl;
    return 0;
}