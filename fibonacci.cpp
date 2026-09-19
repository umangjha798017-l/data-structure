// #include<iostream>

// using namespace std;

// int main ()
// {
//     int arr[100],n;

//     cout<<"enter size of aaray";

//     cin>>n;

//     cout<<"enter"<<n<<"values";

//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];

//     }
//     cout<<"you had entered the value";

//     for(int i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";

//     }
//     cout<<"\ninsert new value";
//     for(int i=0;i<=n;i++)

//     {
//         cout<<arr[i]<<" ";

//     }
//     return 0; 

// }


#include<iostream>

using namespace std;

int fib(int n)

{
    if(n<=1)
    return n;

    else
    return fib(n-1)+fib(n-2);

}

int main()
{
    int n;
    cout<<"enter no";
    cin>>n;
    cout<<"fibonacci number="<<fib(n);
    return 0;
}