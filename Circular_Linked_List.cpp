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
    if(last)
    {
        last->next=last->next->next;
        delete temp;
    }
    if(last==last->next)
    {
        delete temp;
        last=nullptr;
    }
}
int main()
{
    CSLL c1;
    c1.Insert_At_Beginning(65);
    //c1.Insert_At_Beginning(87);
    //c1.Insert_At_End(66);
    //c1.Insert_At_End(69);
    /*Node* temp=c1.Search_Node(87);
    if(temp)
    {
        c1.Insert_After_Specified_Node(temp,89);
    }*/
    c1.Delete_First();
    c1.ShowData();
    cout<<endl;
    return 0;
}