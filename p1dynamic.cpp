// to print 1d & 2d array using pointers
#include <iostream>
using namespace std;

int main()
{
    int n1, *array, m, n, **array2;
    cout << "Enter the size of  1-D array : ";
    cin >> n1;
    array = new int[n1];
    cout << "Enter the elements : \n";
    for (int i = 0; i < n1; i++)
    {
        cin >> *(array + i);
    }
    cout << "Printing 1-d array:\n";

    for (int i = 0; i < n1; i++)
    {
        cout << *(array + i) << " ";
    }
    cout << "\nEnter the rows and columns of  2-D array respectuvely : \n";
    cin >> m >> n;
    array2 = new int *[m];

    for (int i = 0; i < m; i++)
    {
        array2[i] = new int[n];
    }
    cout << "Enter the elements : \n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> *(*(array2 + i) + j);
        }
    }
    cout << "Printing 2-d array:\n";

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << *(*(array2 + i) + j) << "\t";
        }
        cout << "\n";
    }
    delete array;
    delete array2;

    return 0;
}