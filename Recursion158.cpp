#include<iostream>
using namespace std;
int Print_N_Natural_Numbers(int n);
int main()
{
    int n;
    cout<<"Enter any numbers\n";
    cin>>n;
    Print_N_Natural_Numbers(n);
    cout<<endl;
    return 0;
}
int Print_N_Natural_Numbers(int n)
{
    if(n)
    {
        cout<<n*n<<" ";
        Print_N_Natural_Numbers(n-1);
    }
}