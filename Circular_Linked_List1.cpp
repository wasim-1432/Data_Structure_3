#include<iostream>
using namespace std;
struct Node
{
    int item;
    Node* next;
};
class CSLL
{
    private:
        Node* last;
    public:
        CSLL();
        void Insert_At_Beginning(int);
        void ShowData();
        void Insert_At_End(int);
        Node* Search_Node(int);
        void Insert_After_Specified_Node(Node*,int);
        void Delete_First();
        void Delete_Last();
        void Delete_Specific_Node(Node*);
        ~CSLL();
};
CSLL::CSLL()
{
    last=nullptr;
}
void CSLL::Insert_At_Beginning(int data)
{
    Node* n=new Node;
    n->item=data;
    if(last==nullptr)
    {
        n->next=n;
        last=n;
    }
    else
    {
        n->next=last->next;
        last->next=n;
    }
}
void CSLL::ShowData()
{
    if(last)
    {
        Node* temp=last;
        do
        {
            temp=temp->next;
            cout<<temp->item<<" ";
        }while(temp!=last);
    }
}
void CSLL::Insert_At_End(int data)
{
    Node* n=new Node;
    n->item=data;
    if(last==nullptr)
    {
        n->next=n;
        last=n;
    }
    else
    {
        n->next=last->next;
        last->next=n;
        last=n;
    }
}
Node* CSLL::Search_Node(int data)
{
    Node* temp=last;
    do
    {
        temp=temp->next;
        if(temp->item==data)
        {
            return temp;
        }
    } while (temp!=last);
    return nullptr;
}
void CSLL::Insert_After_Specified_Node(Node* s,int data)
{
    Node* n=new Node;
    n->item=data;
    n->next=s->next;
    s->next=n;
    if(s==last)
    {
        last=n;
    }
}
void CSLL::Delete_First()
{
    Node* temp=last->next;
    if(last==last->next)
    {
        delete temp;
        last=nullptr;
    }
    else
    {
        last->next=temp->next;
        delete temp;
    }
}
void CSLL::Delete_Last()
{
    Node* temp=last->next;
    if(last==last->next)
    {
        delete temp;
        last=nullptr;
    }
    else
    {
        while(temp->next!=last)
        {
            temp=temp->next;
        }
        temp->next=last->next;
        delete last;
        last=temp;
    }
}
void CSLL::Delete_Specific_Node(Node* s)
{
    Node* temp=last->next;
    if(last->next==last)
    {
        delete temp;
        last=nullptr;
    }
    if(s==last)
    {
        while(temp->next!=last)
        {
            temp=temp->next;
        }
        temp->next=last->next;
        delete last;
        last=temp;
    }
    else
    {
        while(temp->next!=s)
        {
            temp=temp->next;
        }
        temp->next=s->next;
        delete s;
    }
}
CSLL::~CSLL()
{
    while(last)
    {
        Delete_First();
    }
}
int main()
{
    CSLL c1;
    c1.Insert_At_Beginning(65);
    c1.Insert_At_Beginning(87);
    c1.Insert_At_End(66);
    c1.Insert_At_End(69);
    Node* temp=c1.Search_Node(69);
    if(temp)
    {
        c1.Delete_Specific_Node(temp);
    }
    //c1.Delete_First();
    //c1.Delete_Last();
    c1.ShowData();
    cout<<endl;
    return 0;
}