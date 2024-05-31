// linked list
#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
} *head = NULL;
// display functon
void display()
{
    if (head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }
    struct node *temp;
    temp = head;
    cout << "The linked list is : \n";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        if (temp->next != NULL)
        {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}
// insert at beginning
void insertHead()
{

    int value;
    cout << "Enter the value to be inserted.\n";
    cin >> value;
    struct node *temp;
    temp = new node;
    temp->data = value;

    if (head == NULL)
    {
        temp->next = NULL;
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}
// insert at end
void insertEnd()
{
    int value;
    cout << "Enter the value to be inserted.\n";
    cin >> value;
    struct node *temp, *traversal;
    temp = new node;
    traversal = head;
    temp->data = value;
    while (traversal->next != NULL)
    {
        traversal = traversal->next;
    }
    temp->next = NULL;
    traversal->next = temp;
}
// insert at any position
void insertAtPos()
{
    int value, pos, counter = 0;
    cout << "Enter the value to be inserted: ";
    cin >> value;
    struct node *temp, *traversal, *ptr;
    temp = new node;
    cout << "Enter the postion at which node to be inserted: ";
    cin >> pos;
    int i;
    traversal = head;
    temp->data = value;
    while (traversal != NULL)
    {
        traversal = traversal->next;
        counter++;
    }
    if (pos == 1)
    {
        if (head == NULL)
        {
            head = temp;
            head->next = NULL;
        }
        else
        {
            ptr = head;
            head = temp;
            head->next = ptr;
        }
    }
    else if (pos > 1 && pos <= counter)
    {
        traversal = head;
        for (i = 1; i < pos; i++)
        {
            ptr = traversal;
            traversal = traversal->next;
        }
        ptr->next = temp;
        temp->next = traversal;
    }
    else
    {
        cout << "Positon out of range" << endl;
    }
}
// delete at beginning
void deleteHead()
{
    struct node *temp;
    temp = head;
    head = head->next;
    temp->next = NULL;
    delete (temp);
}
// delete at end
void deleteEnd()
{
    struct node *cur, *prev;
    cur = head;
    prev = NULL;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    delete cur;
}
// delete at position
void deletePosition()
{
    int pos, counter = 0, i;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    cout << "Enter the position whose next node you want to delete : ";
    cin >> pos;

    if (pos == 1)
    {
        deleteHead();
    }
    else if (pos > 1)
    {
        struct node *cur, *prev;
        cur = head;
        prev = NULL;
        for (int i = 2; i <= pos; i++)
        {
            prev = cur;
            cur = cur->next;
        }
        if (cur->next == NULL)
        {
            cout << "No node exist after " << pos << "\n";
        }
        else
        {
            prev->next = cur->next;
            cur->next = NULL;
            delete cur;
        }
    }
}

int main()
{

    int choice;

    while (1)
    {  
        cout << "\nPress '1' to insert node at beginning.\n";
        cout << "Press '2' to insert node at end.\n";
        cout << "Press '3' to insert node at given position.\n";
        cout << "Press '4' to delete node from beginning.\n";
        cout << "Press '5' to delete node from end.\n";
        cout << "Press '6' to delete node at given position.\n";
        cout << "Press '7' to exit.\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            insertHead();
            display();

            break;
        case 2:
            insertEnd();
            display();
            break;
        case 3:
            insertAtPos();
            display(); 
            break;
        case 4:
            deleteHead();
            display();
            break;
        case 5:
            deleteEnd();
            display();
            break;
        case 6:
            deletePosition();
            display();
            break;
        case 7:
            exit(1);
            break;

        default:
            cout << "Invalid Input!\n";
            break;
        }
    }

    return 0;
}