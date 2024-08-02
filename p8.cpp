// to implement complete binary tree using array
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int choice, n, count = 0, x, left_child, right_child, cnt, level;
    char array[100];
    cout << "Enter the no. of nodes you want to insert : ";
    cin >> n;
    while (1)
    {
        cout << "\nEnter : \n";
        cout << "1-Insert node.";
        cout << "\n2-Information of node.";
        cout << "\n3-Total no of nodes.";
        cout << "\n4-Display.";
        cout << "\n5-Exit.\n";
        cin >> choice;
        switch (1)
        {
        case 1:
            cout << "Enter the nodes and their children : \n";
            for (int i = 0; i < n; i++)
                cin >> array[i];
            break;
        case 2:
            cout << "Enter the node whose information you wish to know : ";
            cin >> x;
            for (int i = 0; i < n; i++)
            {
                if (array[i] == x)
                {
                    left_child = (2 * i) + 1;
                    right_child = (2 * i) + 2;
                    cout << "\nLeft child : " << left_child;
                    cout << "\nRight child : " << right_child;
                }
            }
            break;
        case 3:
            for (int i = 0; i < n; i++)
            {
                if (array[i] != '-' && array[i] != -1)
                    count++;
            }
            cout << "\nThe number of nodes are " << count << endl;
        case 4:
            level = int(log(n + 1) / log(2));
            for (int i = 0; i < level; i++)
            {
                for (int j = 0; j < n; i++)
                {
                    if (array[i] == -1)
                        cout << "-\t";
                    else
                        cout << array[i];
                }
            }

        case 5:
            exit(0);
            break;

        default:
            cout << "Invalid input!\n";
            break;
        }
    }

    return 0;
}
double average = (double)(static_cast<double>(min_val) + static_cast<double>(max_val)) / 2.0;