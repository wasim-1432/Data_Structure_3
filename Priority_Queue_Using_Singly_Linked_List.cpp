#include<iostream>
using namespace std;
#define UNDERFLOW 1
struct Node
{
    int Priority;
    int item;
    Node* next;
};
class PriorityQueue
{
    private:
        Node* start;
    public:
        PriorityQueue();
        void Insert_element_According_Priority_Number(int,int);
        bool Is_Empty();
        void Show_List();
        void Delete_Heighest_Priority_Queue();
        int Get_Heighest_Priority_Element();
        int Get_Heighest_Priority_Number();
        ~PriorityQueue();
};
PriorityQueue::PriorityQueue()
{
    start=nullptr;
}
bool PriorityQueue::Is_Empty()
{
    return start==nullptr;
}
void PriorityQueue::Insert_element_According_Priority_Number(int pno,int data)
{
    Node* n=new Node;
    n->item=data;
    n->Priority=pno;
    if(Is_Empty())
    {
        n->next=start;
        start=n;
    }
    else
    {
        Node* temp=start;
        if(temp->next!=nullptr && temp->Priority>=pno)
        {
            n->next=start;
            start=n;
        }
        else
        {
            while(temp->next!=nullptr)
            {
                if(temp->next!=nullptr && temp->next->Priority>=pno)
                {
                    break;
                }
                temp=temp->next;
            }
            if(temp->next==nullptr || temp->next->Priority>=pno )
            {
                n->next=temp->next;
                temp->next=n;
            }
        }
    }
}
void PriorityQueue::Delete_Heighest_Priority_Queue()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    Node* temp=start;
    while(temp->next->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=nullptr;
}
void PriorityQueue::Show_List()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    Node* temp=start;
    while(temp)
    {
        cout<<temp->Priority<<"-"<<temp->item<<endl;
        temp=temp->next;
    }
}
int PriorityQueue::Get_Heighest_Priority_Element()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    Node* temp=start;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    return temp->item;
}
int PriorityQueue::Get_Heighest_Priority_Number()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    Node* temp=start;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    return temp->Priority;
}
PriorityQueue::~PriorityQueue()
{
    while(start)
    {
        Delete_Heighest_Priority_Queue();
    }
}
int main()
{
    PriorityQueue q1;
    q1.Insert_element_According_Priority_Number(2,32);
    q1.Insert_element_According_Priority_Number(8,33);
    q1.Insert_element_According_Priority_Number(7,99);
    q1.Insert_element_According_Priority_Number(1,98);
    q1.Insert_element_According_Priority_Number(0,23);
    //q1.Delete_Heighest_Priority_Queue();
    //q1.Get_Heighest_Priority_Element();
    q1.Get_Heighest_Priority_Number();
    q1.Show_List();
    cout<<endl;
    return 0;
}