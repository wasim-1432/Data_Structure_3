#include<iostream>
using namespace std;
#define UNDERFLOW 1
struct Node
{
    Node* prev;
    int item;
    Node* next;
};
class Stack
{
    private:
        Node* top;
    public:
        Stack();
        bool Is_Empty();
        void Push(int);
        void Peek();
        int Pop();
        ~Stack();
        int Get_Size();
};
Stack::Stack()
{
    top=nullptr;
}
bool Stack::Is_Empty()
{
    return top==nullptr;
}
void Stack::Push(int data)
{
    Node* n=new Node;
    n->item=data;
    if(top==nullptr)
    {
        n->prev=nullptr;
    }
    else
    {
        n->prev=top;
        top->next=n;
    }
    n->next=nullptr;
    top=n;
}
void Stack::Peek()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    cout<<top->item<<endl;
}
int Stack::Pop()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    int data=top->item;
    top=top->prev;
    delete top->next;
    return data;
}
Stack::~Stack()
{
    while(top)
    {
        Pop();
    }
}
int Stack::Get_Size()
{
    Node* temp=top;
    int count=0;
    while(temp)
    {
        count++;
        temp=temp->prev;
    }
    return count;
}
void Reverse_Stack(Stack &skt)
{
    Stack skt2;
    while (!skt.Is_Empty())
    {
        skt2.Push(skt.Pop());
    }
    skt = skt2;
}
int main()
{
    Stack s1;
    s1.Push(76);
    s1.Push(87);

    if (!s1.Is_Empty()) {
        cout << "Top before reverse: ";
        s1.Peek();
    }

    Reverse_Stack(s1);

    if (!s1.Is_Empty()) {
        cout << "Top after reverse: ";
        s1.Peek();
    }

    cout << endl;
    return 0;
}
