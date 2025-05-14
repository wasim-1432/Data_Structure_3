#include<iostream>
using namespace std;
struct Node
{
    Node* prev;
    int item;
    Node* next;
};
class CDLL
{
    private:
        Node* start;
    public:
        CDLL();
        void Insert_At_Beginning(int);
        void ShowData();
        void Insert_At_Last(int);
        Node* Search(int);
        void Insert_After_Specified_Node(Node*,int);
        void Delete_First_Node();
        void Delete_Last_Node();
        void Delete_Specific_Node(Node*);
        ~CDLL();
};
CDLL::CDLL()
{
    start=nullptr;
}
void CDLL::Insert_At_Beginning(int data)
{
    Node* n=new Node;
    n->item=data;
    if(start==nullptr)
    {
        n->prev=n;
        n->next=n;
    }
    else
    {
        n->prev=start->prev;
        n->next=start;
        start->prev->next=n;
        start->prev=n;
    }
    start=n;
}
void CDLL::ShowData()
{
    Node* temp=start;
    do
    {
        cout<<temp->item<<" ";
        temp=temp->next;
    } while (temp!=start);
}
void CDLL::Insert_At_Last(int data)
{
    Node* n=new Node;
    n->item=data;
    if(start==nullptr)
    {
        n->prev=n;
        n->next=n;
        start=n;
    }
    else
    {
        n->next=start->prev->next;
        n->prev=start->prev;
        start->prev->next=n;
        start->prev=n;
    }
}
Node* CDLL::Search(int data)
{
    Node* temp=start;
    do
    {
        if(temp->item==data)
        {
            return temp;
        }
        temp=temp->next;
    } while (temp!=start);
    return nullptr;
}
void CDLL::Insert_After_Specified_Node(Node* s,int data)
{
    Node* n=new Node;
    n->item=data;
    n->next=s->next;
    n->prev=s;
    s->next->prev=n;
    s->next=n;
}
void CDLL::Delete_First_Node()
{
    if(start)
    {
        if(start->next==start)
        {
            Node* temp=start;
            start=nullptr;
            delete temp;
        }
        else
        {
            Node* temp=start;
            start->next->prev=start->prev;
            start->prev->next=start->next;
            start=start->next;
            delete temp;
        }
    }
}
void CDLL::Delete_Last_Node()
{
    if(start)
    {
        if(start->next==start)
        {
            Node* temp=start;
            start=nullptr;
            delete temp;
        }
        else
        {
            Node* temp=start->prev;
            temp->next->prev=temp->prev;
            temp->prev->next=start;
            delete temp;
        }
    }
}
void CDLL::Delete_Specific_Node(Node* s)
{
    if(s==start)
    {
        if(start->next==start)
        {
            Node* temp=start;
            start=nullptr;
            delete temp;
        }
        else
        {
            Node* temp=start;
            start->next->prev=start->prev;
            start->prev->next=start->next;
            start=start->next;
            delete temp;
        }
    }
    else
    {
        s->prev->next=s->next;
        s->next->prev=s->prev;
        delete s;
    }
}
CDLL::~CDLL()
{
    while(start)
    {
        Delete_First_Node();
    }
}
int main()
{
    CDLL d1;
    d1.Insert_At_Beginning(87);
    d1.Insert_At_Beginning(98);
    d1.Insert_At_Last(86);
    d1.Insert_At_Last(66);
    Node* temp=d1.Search(98);
    if(temp)
    {
        d1.Delete_Specific_Node(temp);
    }
    //d1.Delete_First_Node();
    //d1.Delete_Last_Node();
    d1.ShowData();
    cout<<endl;
    return 0;
}