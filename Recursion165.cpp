#include<iostream>
using namespace std;
int Print_N_Natural_Numbers(int n);
int main()
{
    int n;
    cout<<"Enter any numbers\n";
    cin>>n;
    cout<<"Factorial is="<<Print_N_Natural_Numbers(n);
    cout<<endl;
    return 0;
}
int Print_N_Natural_Numbers(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    else if(n)
    {
        return n*Print_N_Natural_Numbers(n-1);
    }
}