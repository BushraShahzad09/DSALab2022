// to insert and delete from particluar position
#include <iostream>
using namespace std;
void display(int *arr, int n)
{
    cout << "Displaying Array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void insertAtIndex(int *arr, int &n, int index, int value)
{
    if (index >= 0 && index <= n)
    {
        int i;
        for (i = n; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        n++;
        arr[index] = value;
    }
    else
    {
        cout << "Index exceeds the no of elements.\n";
    }
}
void deleteElement(int *arr, int &n, int value)
{
    int flag = 0, newIndex;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            flag = 1;
            newIndex = i;
        }
    }
    if (flag == 0)
    {
        cout << "no such ele exists\n";
    }
    else
    {
        for (int i = newIndex; i < n; i++)
        {
            arr[i] = arr[i + 1];
        }
        n--;
    }
}
int main()
{
    int n, choice, index, value;
    cout << "Enter the size of array : ";
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    display(array, n);

    while (1)
    {
        cout << "\nEnter '1' to insert element at at any index.";
        cout << "\nEnter '2' to delete particular element :";
        cout << "\nEnter '3' to exit! :";

        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the index where you want to insert in an array : ";
            cin >> index;
            cout << "Enter the value : ";
            cin >> value;
            insertAtIndex(array, n, index, value);
            display(array, n);
            break;
        case 2:
            cout << "Enter the element to be deleted : ";
            cin >> value;
            deleteElement(array, n, value);
            display(array, n);
            break;
        case 3:
            exit(1);
            break;

        default:
            cout << "Invalid input!\n";
            break;
        }
    }

    return 0;
}