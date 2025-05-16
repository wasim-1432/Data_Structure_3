#include<iostream>
using namespace std;
#define UNDERFLOW 1
struct Node
{
    Node* prev;
    int item;
    Node* next;
};
class Queue
{
    private:
        Node* front;
        Node* rear;
    public:
        Queue();
        void Insert_New_Element_At_Rear(int);
        bool Is_Empty();
        void View_Rear();
        void View_Front();
        int Delete_Front();
        ~Queue();
        int Count_Total_Elements_In_The_Queue();
};
Queue::Queue()
{
    front=nullptr;
    rear=nullptr;
}
bool Queue::Is_Empty()
{
    return front==nullptr && rear==nullptr;
}
void Queue::Insert_New_Element_At_Rear(int data)
{
    Node* n=new Node;
    n->item=data;
    if(Is_Empty())
    {
        n->next=n;
        n->prev=n;
        front=n;
        rear=n;
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
void Queue::View_Rear()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    cout<<rear->item<<" ";
}
void Queue::View_Front()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    cout<<front->item<<" ";
}
int Queue::Delete_Front()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    Node* temp=front;
    front=front->prev;
    delete temp;
    return front->item;
}
Queue::~Queue()
{
    while(front!=nullptr && rear!=nullptr)
    {
        Delete_Front();
    }
}
int Queue::Count_Total_Elements_In_The_Queue()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    Node* temp=rear;
    int count=1;
    while(temp!=front)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
int main()
{
    Queue q1;
    q1.Insert_New_Element_At_Rear(87);
    q1.Insert_New_Element_At_Rear(76);
    q1.Insert_New_Element_At_Rear(99);
    //q1.View_Rear();
    q1.Delete_Front();
    q1.View_Rear();
    q1.View_Front();
    q1.Count_Total_Elements_In_The_Queue();
    cout<<endl;
    return 0;
}