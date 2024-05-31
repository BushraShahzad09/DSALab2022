// recursive functions
#include <iostream>
using namespace std;
int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}
int power(int x, int y)
{

    if (y == 1)
        return x;

    return x * power(x, y - 1);
}
int sumArray(int *arr, int n)
{
    if (n == 0)
        return 0;
    return arr[n - 1] + sumArray(arr, n - 1);
}
int fibonacciTerm(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fibonacciTerm(n - 1) + fibonacciTerm(n - 2);
}
int fibonacciSum(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fibonacciTerm(n) + fibonacciSum(n - 1);
}
int main()

{
    int a, b, n;
    int choice;
    while (1)
    
    {   
        cout << "\nEnter '1' to find factorial of number.\n";
        cout << "Enter '2' to find power a to b.\n";
        cout << "Enter '3' to find sum of array. \n";
        cout << "Enter '4'to print fibonacci series till n.\n";
        cout << "Enter '5' to find sum of n terms of fibonacci.\n";
        cout << "Enter '6' to Exit!\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the number:\n";
            cin >> n;
            cout << "Factorial of "<<n<<" is " << factorial(n)<<".";
            break;

            break;
        case 2:
            cout << "Enter a and b respectively:\n";
            cin >> a;
            cin >> b;
            cout <<a<< "^" <<b<<" = " << power(a, b) << endl;
            break;
        case 3:
            cout << "Enter the number of elements:\n";
            cin >> n;
            int array[100];
            cout << "Enter the elements:\n";
            for (int i = 0; i < n; i++)
            {
                cin >> array[i];
            }
            cout << "Sum of array ele is " << sumArray(array, n);

            break;
        case 4:

            cout << "Enter the number of elements:\n";
            cin >> n;
            cout << "Printing fib:\n";
            for (int i = 0; i <= n; i++)
            {
                cout << fibonacciTerm(i) << " ";
            }

            break;
        case 5:
            cout << "Enter the number of elements:\n";
            cin >> n;
            cout << "Sum of "<<n<<" fibonacci terms is " << fibonacciSum(n);
            break;
        case 6:
            exit(1);
            break;

        default:
            cout << "Invalid input!\n";
            break;
        }
    }

    return 0;
}