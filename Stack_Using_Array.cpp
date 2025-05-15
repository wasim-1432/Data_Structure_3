#include<iostream>
using namespace std;
#define OVERFLOW 1
#define UNDERFLOW 2
class Stack
{
    private:
        int capacity;
        int top;
        int* ptr;
    public:
        Stack(int);
        bool Is_Empty();
        bool Is_Full();
        void Push(int);
        void Peek();
        int Pop();
        ~Stack();
        int Get_Capacity();
        int Get_Size();
};
Stack::Stack(int cap)
{
    capacity=cap;
    top=-1;
    ptr=new int[capacity];
}
bool Stack::Is_Empty()
{
    return top==-1;
}
bool Stack::Is_Full()
{
    return capacity-1==top;
}
void Stack::Push(int data)
{
    if(Is_Full())
    {
        throw OVERFLOW;
    }
    top++;
    ptr[top]=data;
}
void Stack::Peek()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    cout<<ptr[top];
}
int Stack::Pop()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    int temp=ptr[top];
    top--;
    return temp;
}
Stack::~Stack()
{
    delete []ptr;
}
int Stack::Get_Capacity()
{
    return capacity;
}
int Stack::Get_Size()
{
    return top+1;
}
void Reverse_Stack(Stack &skt)
{
    int v;
    Stack skt2(skt.Get_Capacity());
    for(int i=0;i<skt.Get_Size();i++)
    {
        v=skt.Pop();
        skt2.Push(v);
    }
    skt=skt2;
}
void Minimum_Value_In_The_Stack(Stack &skt)
{
    int min=skt.Pop();
    for(int i=0;i<skt.Get_Size();i++)
    {
        int v=skt.Pop();
        if(min>v)
        {
            min=v;
        }
    }
    cout<<"MAximum Value is="<<min;
}
int main()
{
    Stack s1(5);
    if (!s1.Is_Full()) s1.Push(77);
    if (!s1.Is_Full()) s1.Push(87);
    if (!s1.Is_Full()) s1.Push(45);
    if (!s1.Is_Full()) s1.Push(21);
    if (!s1.Is_Full()) s1.Push(90);
    if (!s1.Is_Empty()) {
        cout << "Original Top Element: ";
        s1.Peek();
        cout << endl;
    }
    Reverse_Stack(s1);
    if (!s1.Is_Empty()) {
        cout << "Top Element After Reversing: ";
        s1.Peek();
        cout << endl;
    }
    if (!s1.Is_Empty()) {
        Minimum_Value_In_The_Stack(s1);
        cout << endl;
    }
    return 0;
}
