#include<iostream>
#define max_size 10

using namespace std;

void push(int n);
void pop();
void display();

int top=-1, stack[max_size];

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    push(80);
    push(90);
    push(100);

    display();

    push(1000);

    pop();

    display();

    return 0;
}

void push(int n)
{
    if(top>=max_size-1)
        cout<<"\noverflow";
    else
    {
        top++;
        stack[top]=n;
    }
}

void pop()
{
    if(top==-1)
        cout<<"underflow";
    else
    {
        cout<<"deleted element "<<stack[top]<<endl;
        top--;
    }
}

void display()
{
    for(int i=0; i<=top; i++)
    {
        cout<<stack[i]<<" ";
    }
}