#include "Bai2.h"
template<class T, int n>

// Push function
void Stack<T,n>::Push(const T &x)
{  
    if (i==(n))
    {
        cout<<"Stack is full!"<<endl;
    }
    else
    {
        array[i]=x;
        i++;  
    }
}

//Pop function
template<class T, int n>
T Stack<T,n>::Pop()
{   
    if (i==0)
    {
        cout<<"Stack empty!"<<endl;
        //return NULL;
        _Exit(0);
    }
    else
    {
        T last= array[i-1];
        this->array[i-1]=NULL;
        i--;
        return last;
    }
}

//Peek function
template<class T, int n>
void Stack<T,n>::Peek()
{   if (i==0)
    {
        cout<<"Stack empty!"<<endl;
    }
    else
    {
        cout<<array[i-1]<<endl;
    }
}

//Check full function
template<class T, int n>
bool Stack<T,n>::isFull()
{
    if(i>=(n-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Check empty fuction
template<class T, int n>
bool Stack<T,n>::isEmpty()
{
    if(i==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    Stack<int,3> stack;

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);

    stack.Pop();
    stack.Pop();
    cout<<stack.Pop()<<endl;

    cout<<stack.isFull()<<endl;
    cout<<stack.isEmpty()<<endl;

    cout<<stack.Pop()<<endl;

    return 0;
}
    
