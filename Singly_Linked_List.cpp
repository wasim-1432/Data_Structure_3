#include<iostream>
using namespace std;
struct Node
{
    int item;
    Node* next;
};
class SLL
{
    private:
        Node* start;
    public:
        SLL();
        void Insert_At_Biginning(int);
        bool Is_Empty();
        void Show_Linked_List();
        void Insert_At_End(int);
        Node* Search(int);
        void Insert_After_Specified(Node*,int);
        void Delete_First_Node();
        void Delete_Last_Node();
        void Delete_Specified_Node(Node*);
        ~SLL();
};
SLL::SLL()
{
    start=nullptr;
}
bool SLL::Is_Empty()
{
    return start==nullptr;
}
void SLL::Insert_At_Biginning(int data)
{
    Node* n=new Node;
    n->item=data;
    if(Is_Empty())
    {
        n->next=nullptr;
    }
    else
    {
        n->next=start;
    }
    start=n;
}
void SLL::Show_Linked_List()
{
    Node* temp=start;
    do
    {
        cout<<temp->item<<" ";
        temp=temp->next;
    }while(temp!=nullptr);
}
void SLL::Insert_At_End(int data)
{
    Node* n=new Node;
    n->item=data;
    Node* temp=start;
    if(start==nullptr)
    {
        n->next=start;
        start=n;
    }
    else
    {
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        n->next=temp->next;
        temp->next=n;
    }
}
Node* SLL::Search(int data)
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
void SLL::Insert_After_Specified(Node* s,int data)
{
    Node* n=new Node;
    n->item=data;
    n->next=s->next;
    s->next=n;
}
void SLL::Delete_First_Node()
{
    Node* temp=start;
    start=start->next;
    delete temp;
}
void SLL::Delete_Last_Node()
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
        temp->next=nullptr;
    }
}
void SLL::Delete_Specified_Node(Node* s)
{
    Node* temp=start;
    if(start==s)
    {
        Delete_First_Node();
    }
    else
    {
        do
        {
            temp=temp->next;
        }while(temp->next!=s);
        temp->next=s->next;
        delete s;
    }
}
SLL::~SLL()
{
    while(start)
    {
        Delete_First_Node();
    }
}
int main()
{
    SLL s1;
    s1.Insert_At_Biginning(3);
    s1.Insert_At_Biginning(77);
    s1.Insert_At_Biginning(76);
    s1.Insert_At_End(65);
    Node* temp=s1.Search(76);
    if(temp!=nullptr)
    {
        s1.Delete_Specified_Node(temp);
    }
    //s1.Delete_First_Node();
    //s1.Delete_Last_Node();
    
    s1.Show_Linked_List();
    cout<<endl;
    return 0;
}