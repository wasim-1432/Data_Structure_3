#include<iostream>
using namespace std;
#define UNDERFLOW 1
struct Node
{
    Node* prev;
    int item;
    Node* next;
};
class Deque
{
    private:
        Node* front;
        Node* rear;
    public:
        Deque();
        void Insert_At_Front(int);
        void Insert_At_Rear(int);
        bool Is_Empty();
        void View_Front();
        void View_Rear();
        void Delete_Front_Element();
        void Delete_Rear_Element();
        ~Deque();
};
Deque::Deque()
{
    front=nullptr;
    rear=nullptr;
}
bool Deque::Is_Empty()
{
    return rear==nullptr && front==nullptr;
}
void Deque::Insert_At_Front(int data)
{
    Node* n=new Node;
    n->item=data;
    if(Is_Empty())
    {
        n->next=n;
        n->prev=n;
        rear=n;
        front=n;
    }
    else
    {
        n->next=front->next;
        n->prev=front;
        front->next=n;
        rear->prev=n;
        front=n;
    }
}
void Deque::Insert_At_Rear(int data)
{
    Node* n=new Node;
    n->item=data;
    if(Is_Empty())
    {
        n->next=n;
        n->prev=n;
        rear=n;
        front=n;
    }
    else
    {
        n->next=rear;
        n->prev=rear->prev;
        rear->prev->next=n;
        rear->prev=n;
        rear=n;
    }
}
void Deque::View_Front()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    cout<<front->item<<" ";
}
void Deque::View_Rear()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    cout<<rear->item<<" ";
}
void Deque::Delete_Front_Element()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    Node* temp=front;
    front->prev->next=front->next;
    rear->prev=front->prev;
    front=front->prev;
    delete temp;
}
void Deque::Delete_Rear_Element()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    Node* temp=rear;
    rear->next->prev=front;
    front->next=rear->next;
    rear=rear->next;
    delete temp;
}
Deque::~Deque()
{
    while(rear)
    {
        Delete_Rear_Element();
    }
}
int main()
{
    Deque d1;
    d1.Insert_At_Rear(76);
    d1.Insert_At_Rear(86);
    d1.Insert_At_Rear(77);
    //d1.Insert_At_Front(55);
    //d1.Insert_At_Front(65);
    //d1.Delete_Front_Element();
    d1.Delete_Rear_Element();
    d1.View_Rear();
    d1.View_Front();
    cout<<endl;
    return 0;
}