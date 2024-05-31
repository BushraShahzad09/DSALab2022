#include <iostream>
using namespace std;

struct Queue
{
    int rear, front;
    int size;
    int *arrayQueue;
};
Queue que;
void enqueue(int value)
{

    if ((que.front == 0 && que.rear == que.size - 1) ||
        (que.rear == (que.front - 1)))
    {
        cout << "\nQueue is full";
        return;
    }
    else if (que.front == -1)
    {
        que.front = que.rear = 0;
        que.arrayQueue[que.rear] = value;
    }
    else if (que.rear == que.size - 1 && que.front != 0)
    {
        que.rear = 0;
        que.arrayQueue[que.rear] = value;
    }
    else
    {
        que.rear++;
        que.arrayQueue[que.rear] = value;
    }
}

void dequeue()
{
    if (que.front == -1)
    {
        cout << "\nQueue is empty";
    }

    que.arrayQueue[que.front] = -1;
    if (que.front == que.rear)
    {
        que.front = -1;
        que.rear = -1;
    }
    else if (que.front == que.size - 1)
        que.front = 0;
    else
        que.front++;
}

void display()
{
    if (que.front == -1)
    {
        cout << "\nQueue is empty";
        return;
    }
    cout << "\nCircular queue : ";
    if (que.rear >= que.front)
    {
        for (int i = que.front; i <= que.rear; i++)
            cout << " " << que.arrayQueue[i];
    }
    else
    {
        for (int i = que.front; i < que.size; i++)
            cout << " " << que.arrayQueue[i];
        for (int i = 0; i <= que.rear; i++)
            cout << " " << que.arrayQueue[i];
    }
}
void frontRear()
{
    cout << "Front = " << que.arrayQueue[que.front] << endl;
    cout << "Rear = " << que.arrayQueue[que.rear] << endl;
}
int isEmpty()
{
    if (que.front == -1)
        return 1;
    return 0;
}
int isFull()
{
    if ((que.front == 0 && que.rear == que.size - 1) ||
        (que.rear == (que.front - 1)))
        return 1;
    return 0;
}

int main()
{
    int choice, value;
    cout << "Enter the size of queue: ";
    cin >> que.size;
    que.arrayQueue = new int[que.size];
    que.front = que.rear = -1;

    while (1)
    {
       
        cout << "\nPress '1' to enqueue an element.";
        cout << "\nPress '2' to dequeue an element.";
        cout << "\nPress '3' to check if queue is full.";
        cout << "\nPress '4' to check if queue is empty.";
        cout << "\nPress '5' to display front and rear. ";
        cout << "\nPress '6' to display circular queue!.";
        cout << "\nPress '7' to exit!.\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element to be inserted : ";
            cin >> value;
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            if (isFull())
                cout << "yes, queue is full" << endl;
            else
                cout << "noi, queue is not full!" << endl;

            break;
        case 4:
            if (isEmpty())
                cout << "yes, queue is empty" << endl;
            else
                cout << "noi, queue is not empty!" << endl;
            break;
        case 5:
            frontRear();
            break;
        case 6:
            display();
            break;
        case 7:
            exit(1);
            break;

        default:
            cout << "Invalid input!" << endl;
            break;
        }
    }
    return 0;
}