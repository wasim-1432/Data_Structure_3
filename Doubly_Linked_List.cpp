#include<iostream>
using namespace std;
struct Node
{
    Node* prev;
    int item;
    Node* next;
};
class DLL
{
    private:
        Node* start;
    public:
        DLL();
        void Insert_At_Beginning(int);
        bool Is_Empty();
        void Show_Data();
        void Insert_At_End(int);
        Node* Search(int);
        void Insert_At_Specified_Node(Node*,int);
        void Delete_First_Node();
        void Delete_Last_Node();
        void Delete_Specified_Node(Node*);
        ~DLL();
};
DLL::DLL()
{
    start=nullptr;
}
bool DLL::Is_Empty()
{
    return start==nullptr;
}
void DLL::Insert_At_Beginning(int data)
{
    Node* n=new Node;
    n->item=data;
    if(start!=nullptr)
    {
        start->prev=n;
    }
    n->prev=nullptr;
    n->next=start;
    start=n;
}
void DLL::Show_Data()
{
    Node* temp=start;
    while(temp)
    {
        cout<<temp->item<<" ";
        temp=temp->next;
    }
}
void DLL::Insert_At_End(int data)
{
    Node* n=new Node;
    n->item=data;
    n->next=nullptr;
    if(Is_Empty())
    {
        n->prev=nullptr;
        start=n;
    }
    else
    {
        Node* temp=start;
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=n;
        n->prev=temp;
    }
}
Node* DLL::Search(int data)
{
    Node* temp=start;
    while(temp!=nullptr)
    {
        if(temp->item==data)
        {
            return temp;
        }
        temp=temp->next;
    }
    return nullptr;
}
void DLL::Insert_At_Specified_Node(Node* s,int data)
{
    Node* n=new Node;
    n->item=data;
    n->next=s->next;
    n->prev=s;
    s->next=n;
    if(start->next!=nullptr)
    {
        s->next->prev=n;
    }
}
void DLL::Delete_First_Node()
{
    Node *temp=start;
    if(start)
    {
        start=start->next;
        start->prev=nullptr;
        delete temp;
    }
}
void DLL::Delete_Last_Node()
{
    Node* temp=start;
    if(start->next==nullptr)
    {
        Delete_First_Node();
    }
    else
    {
        while(temp->next->next!=nullptr)
        {
            temp=temp->next;
        }
        delete temp->next->next;
        temp->next=nullptr;
    }
}
void DLL::Delete_Specified_Node(Node* s)
{
    if(s==start)
    {
        Node* temp=start;
        start=start->next;
        start->prev=nullptr;
        delete temp;
    }
    else if(s->next==nullptr)
    {
        s->prev->next=s->next;
        delete s;
    }
    else
    {
        s->prev->next=s->next;
        s->next->prev=s->prev;
        delete s;
    }
}
DLL::~DLL()
{
    while(start)
    {
        Delete_First_Node();
    }
}
int main()
{
    DLL d1;
    d1.Insert_At_Beginning(3);
    d1.Insert_At_Beginning(88);
    d1.Insert_At_Beginning(98);
    d1.Insert_At_End(76);
    Node* temp=d1.Search(76);
    if(temp)
    {
        d1.Delete_Specified_Node(temp);
    }
    //d1.Delete_First_Node();
    //d1.Delete_Last_Node();
    d1.Show_Data();
    cout<<endl;
    return 0;
}