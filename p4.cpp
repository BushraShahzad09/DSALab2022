#include <iostream>
using namespace std;
struct stack
{
    int top;
    int size;
    int *s;
};
stack st;
void display()
{
    int i;
    cout << "Displaying Stack:\n";
    for (int i = st.top; i >= 0; i--)
    {
        cout << st.s[i] << " ";
    }
}
void push(int x)
{
    if (st.top == st.size - 1)
    {
        cout << "Stack is full!\n";
    }
    else
    {
        st.top++;
        st.s[st.top] = x;
    }
}
void pop()
{
    if (st.top == -1)
    {
        cout << "Satck is empty.\n";
    }
    else
    {
        st.s[st.top] = NULL;
    }
    st.top--;
}
int isEmpty()
{
    if (st.top == -1)
        return 1;
    return 0;
}
int isFull()
{
    if (st.top == st.size - 1)
        return 1;
    return 0;
}
int top()
{
    if (st.top == -1)
        return -1;
    return st.s[st.top];
}

int main()
{
    cout << "Enter the size of a stack" << endl;
    cin >> st.size;
    st.s = new int[st.size];
    st.top = -1;
    int n, key;
    while (1)
    {
       
        cout << "\nPress '1' to push an element.\n";
        cout << "Press '2' to pop an element.\n";
        cout << "Press '3' for checking if stack is empty.\n";
        cout << "Press '4' for checking if stack is full.\n";
        cout << "Press '5' for displaying the top element.\n";
        cout << "Press '6' to Exit!.\n";
        cin >> key;
        switch (key)
        {
        case 1:
            cout << "Enter the element to be pushed in stack" << endl;
            cin >> n;
            push(n);
            display();
            break;
        case 2:

            pop();
            display();
            break;
        case 3:
            if (isEmpty())
                cout << "yes, stack is empty" << endl;
            else
                cout << "noi, stack is not empty!" << endl;
            break;
        case 4:
            if (isFull())
                cout << "yes, stack is full" << endl;
            else
                cout << "noi, stack is not full!" << endl;

            break;
        case 5:
            cout << "The top element of stack is " << top() << endl;
            break;
        case 6:
            exit(1);
            break;
        default:
            cout << "Invalid input!" << endl;
            break;
        }
    }
    return 0;
}