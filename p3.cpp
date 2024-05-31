#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct student
{
    char name[30];
    int roll_no;
    int sem;
    int marks;
};
student s[30];
void enterData(int n)
{
    int i = 0;
    while (i < n)

    {
        cout << "Enter data of student " << i + 1 << "\n";
        cout << "Name  : ";
        getchar();
        gets(s[i].name);

        cout << "Roll No : ";
        cin >> s[i].roll_no;
        cout << "Semester : ";
        cin >> s[i].sem;
        cout << "Marks : ";
        cin >> s[i].marks;
        i++;
    }
}
void display(int n)
{
    cout << "Roll No\t\tName\t\t\tSemester\t\tMarks\n";
    int i = 0;
    while (i < n)
    {
        cout << s[i].roll_no << "\t\t" << s[i].name << "\t\t\t" << s[i].sem << "\t\t\t" << s[i].marks << "\n";
        i++;
    }
}
void search_name(int n)
{
    int flag = 0;
    char searchName[50];
    cout << "Enter the name you want to search : ";
    cin >> searchName;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(s[i].name, searchName) == 0)
        {
            flag = 1;
            cout << "Following are the records of " << searchName << " : " << endl;
            cout << "Roll No\t\tName\t\t\tSemester\t\tMarks\n";
            cout << s[i].roll_no << "\t\t" << s[i].name << "\t\t\t" << s[i].sem << "\t\t\t" << s[i].marks << "\n";
            break;
        }
    }
    if (flag == 0)
        cout << "\nNo student by such name exists!\n";
}
void search_roll(int n)
{
    int flag = 0;
    int x;
    cout << "Enter the roll no. you want to search : ";
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        if (s[i].roll_no == x)
        {
            flag = 1;
            cout << "Following are the records of roll no." << x << " : " << endl;
            cout << "Roll No\t\tName\t\t\tSemester\t\tMarks\n";
            cout << s[i].roll_no << "\t\t" << s[i].name << "\t\t\t" << s[i].sem << "\t\t\t" << s[i].marks << "\n";
            break;
        }
    }
    if (flag == 0)
        cout << "\nNo student of such roll no exists!\n";
}
void compare(int n)
{
    int max = 0, x;
    for (int i = 0; i < n; i++)
    {
        if (s[i].marks > max)
            max = s[i].marks;
        x = i;
    }
    cout << "Following are the records of topper"
         << " : " << endl;
    cout << "Roll No\t\tName\t\t\tSemester\t\tMarks\n";
    cout << s[x].roll_no << "\t\t" << s[x].name << "\t\t\t" << s[x].sem << "\t\t\t" << s[x].marks << "\n";
}
int main()
{
    int choice, n, flag;
    char searchName[50];
    while (1)
    {
       
        cout << "\nPress '1' to enter student data.\n";
        cout << "Press '2' to display student records.\n";
        cout << "Press '3' to search student by Roll No.\n";
        cout << "Press '4' to search student by name.\n";
        cout << "Press '5' to display topper student's details.\n";
        cout << "Press '6' to Exit!\n";
        cin >> choice;
        switch (choice)
        {
        case 1:

            cout << "Enter no of students : ";
            cin >> n;

            enterData(n);

            break;
        case 2:
            display(n);
            break;
        case 3:
            search_roll(n);
            break;
        case 4:
            search_name(n);
            break;
        case 5:
            compare(n);

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