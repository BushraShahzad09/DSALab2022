#include <iostream>
using namespace std;
struct tree
{
    char array[100];
};
tree tr;
int j = 1;
void create()
{
    char x;
    int i;
    if (j == 1)
    {
        cout << "Enter root value : ";
        cin >> x;
        tr.array[j++] = x;
        return;
    }
    else
    {
        i = j % 2;
        if (i == 0)
        {
            cout << "Enter left child of " << tr.array[j / 2] << " : ";
            cin >> x;
            tr.array[j++] = x;
        }
        if (i == 1)
        {
            cout << "Enter right child of " << tr.array[j / 2] << " : ";
            cin >> x;
            tr.array[j++] = x;
        }
        return;
    }
}
void nodeInfo()
{
    int flag = 0;
    char x;
    cout << "Enter the charachter : ";
    cin >> x;
    for (int i = 1; i <= j; i++)
    {
        if (tr.array[i] == x)
        {
            flag = 1;
            cout << "Left child of " << x << " is " << tr.array[2 * i] << ".\n";
            cout << "Right child of " << x << " is " << tr.array[(2 * i) + 1] << ".\n";
            cout << "Parent of " << x << " is " << tr.array[i / 2] << ".\n";
            break;
        }
    }
    if (flag == 0)
        cout << "Charchter is not present.\n";
}
int nodes()
{
    return j - 1;
}
void display()
{
    int i = 1;
    cout << "Tree Display : \n";
    if (j >= 1)
        cout << "       " << tr.array[i++] << "      " << endl;
    if (i <= j)
    {
        for (; i <= 3; i++)
            cout << "    " << tr.array[i] << "  ";
        cout << endl;
        if (i <= j)
        {
            for (; i <= 7; i++)
                cout << "  " << tr.array[i] << " ";
            cout << endl;
        }
        if (i <= j)
        {
            for (; i <= 15; i++)
                cout << " " << tr.array[i] << "";
            cout << endl;
        }
        if (i <= j)
        {
            for (; i <= 31; i++)
                cout << "  " << tr.array[i] << " ";
            cout << endl;
        }
    }
    cout << endl;
}
int main()
{
    for (int i = 0; i < 99; i++)
    {
        tr.array[i] = '-';
    }

    int choice;
    while (1)
    {
       
        cout << "Press 1 to Insert." << endl;
        cout << "Press 2 to get information of any node." << endl;
        cout << "Press 3 to find total no of nodes." << endl;
        cout << "Press 4 to display tree." << endl;
        cout << "Press 5 to exit!" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            nodeInfo();
            break;
        case 3:
            cout << "Total number of nodes are : " << nodes() << ".\n";
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
            break;

        default:
            cout << "Invalid input.\n";
            break;
        }
    }

    return 0;
}