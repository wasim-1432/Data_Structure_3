#include<iostream>
using namespace std;
#define OVERFLOW 1
#define UNDERFLOW 2
class Queue
{
    private:
        int capacity;
        int front;
        int rear;
        int* ptr;
    public:
        Queue(int);
        void Insert_New_Element_At_Rear(int);
        bool Is_Full();
        bool Is_Empty();
        void View_Rear();
        void View_Front();
        int Delete_Front_Element();
        ~Queue();
        int Count_Number_Of_Elements_In_The_Queue();
};
Queue::Queue(int cap)
{
    capacity=cap;
    front=-1;
    rear=-1;
    ptr=new int[capacity];
}
bool Queue::Is_Full()
{
    return capacity-1==rear;
}
bool Queue::Is_Empty()
{
    return front==rear==-1;
}
void Queue::Insert_New_Element_At_Rear(int data)
{
    if(Is_Full())
    {
        throw  OVERFLOW;
    }
    if(front==-1 && rear==-1)
    {
        front++;
        rear++;
        ptr[rear]=data;
    }
    else
    {
        rear++;
        ptr[rear]=data;
    }
}
void Queue::View_Rear()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    cout<<ptr[rear];
}
void Queue::View_Front()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    cout<<ptr[front]<<" ";
}
int Queue::Delete_Front_Element()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    int temp=ptr[front];
    front++;
    return temp;
}
Queue::~Queue()
{
    delete []ptr;
}
int Queue::Count_Number_Of_Elements_In_The_Queue()
{
    return rear+1;
}
int main()
{
    Queue q1(5);
    q1.Insert_New_Element_At_Rear(65);
    q1.Insert_New_Element_At_Rear(33);
    q1.Insert_New_Element_At_Rear(87);
    q1.Insert_New_Element_At_Rear(66);
    //q1.View_Rear();
    //q1.View_Front();
    //q1.Delete_Front_Element();
    //q1.View_Front();
    q1.Count_Number_Of_Elements_In_The_Queue();
    cout<<endl;
    return 0;
}