#include <iostream>
using namespace std;
int j = 1;
class tree
{
private:
    char A[100];

public:
    tree()
    {
        for (int i = 0; i < 99; i++)
            A[i] = '_';
    }
    void insert();
    void insert2();
    void display();
    void information();
    void nodes();
};
void tree::insert()
{
    if (j == 1)
    {
        cout << "enter root value" << endl;
        char x;
        cin >> x;
        A[j++] = x;
    }
    else
    {
        int i;
        i = j % 2;
        if (i == 0)
        {
            cout << "left child of " << A[j / 2] << endl;
            char x;
            cin >> x;
            A[j++] = x;
        }
        if (i == 1)
        {
            cout << "right child of " << A[j / 2] << endl;
            char x;
            cin >> x;
            A[j++] = x;
        }
    }
}
void tree::information()
{
    cout << "enter the character" << endl;
    char x;
    cin >> x;
    for (int i = 1; i <= j; i++)
    {
        if (A[i] == x)
        {
            cout << "left child of " << x << " is " << A[2 * i] << endl;
            cout << "right child of " << x << " is " << A[(2 * i) + 1] << endl;
            cout << "parent of " << x << " is " << A[i / 2] << endl;
            return;
        }
    }
    cout << "character not present" << endl;
}
void tree::nodes()
{
    cout << "TOTAL NODES =" << (j - 1) << endl;
}
void tree::display()
{
    int i = 1;
    if (j >= 1)
        cout << "       " << A[i++] << "      " << endl;
    if (i <= j)
    {
        for (; i <= 3; i++)
            cout << "    " << A[i] << "  ";
        cout << endl;
        if (i <= j)
        {
            for (; i <= 7; i++)
                cout << "  " << A[i] << " ";
            cout << endl;
        }
        if (i <= j)
        {
            for (; i <= 15; i++)
                cout << " " << A[i] << "";
            cout << endl;
        }
        if (i <= j)
        {
            for (; i <= 31; i++)
                cout << "  " << A[i] << " ";
            cout << endl;
        }
    }
    cout << endl;
}
int main()
{
    printf("Mohammad Hamza| Roll No. 21BCS085\n");
    tree t;
    cout << "press 1 to insert" << endl;
    cout << "press 2 to get information of any node" << endl;
    cout << "press 3 to find total no of nodes" << endl;
    cout << "press 4 to display" << endl;
    cout << "press 5 to exit" << endl;
    int x;
    do
    {
        cout << "enter your choice" << endl;
        cin >> x;
        switch (x)
        {
        case 1:
            t.insert();
            break;
        case 2:
            t.information();
            break;
        case 3:
            t.nodes();
            break;
        case 4:
            t.display();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice " << endl;
        }
    } while (x != 6);
    return 0;
}