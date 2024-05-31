// to implement complete binary tree using linked list
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *right_child;
    node *left_child;
} *root = NULL;
void createBinaryTree()
{
    node *temp, *newNode;
    int x;
    queue<node *> q;
    cout << "Enter the root: ";
    cin >> x;
    root = new node;
    root->data = x;
    root->left_child = root->right_child = NULL;
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        cout << "Enter the left child of " << temp->data << " : ";
        cin >> x;
        if (x != -1)
        {
            newNode = new node;
            newNode->data = x;
            newNode->left_child = newNode->right_child = NULL;
            temp->left_child = newNode;
            q.push(newNode);
        }
        cout << "Enter the right child of " << temp->data << " : ";
        cin >> x;
        if (x != -1)
        {
            newNode = new node;
            newNode->data = x;
            newNode->left_child = newNode->right_child = NULL;
            temp->right_child = newNode;
            q.push(newNode);
        }
    }
}
void preOrder(node *root)
{

    if (root)
    {
        cout << root->data << " ";
        preOrder(root->left_child);
        preOrder(root->right_child);
    }
}
void inorder(node *root)
{

    if (root)
    {
        inorder(root->left_child);
        cout << root->data << " ";
        inorder(root->right_child);
    }
}
void postorder(node *root)
{

    if (root)
    {
        postorder(root->left_child);
        postorder(root->right_child);
        cout << root->data << " ";
    }
}
void levelOrder(node *root)
{
    queue<node *> Q;
    node *temp;
    cout << "Level-Order : ";
    cout << root->data << " ";
    Q.push(root);
    while (!Q.empty())
    {
        temp = Q.front();
        Q.pop();
        if (temp->left_child)
        {
            cout << temp->left_child->data << " ";
            Q.push(temp->left_child);
        }
        if (temp->right_child)
        {
            cout << temp->right_child->data << " ";
            Q.push(temp->right_child);
        }
    }
}
int height(node *root)
{
    int x = 0, y = 0;
    if (root == NULL)
        return 0;
    x = height(root->left_child);
    y = height(root->right_child);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
int count(node *root)
{
    int x, y;
    if (root != NULL)
    {
        x = count(root->left_child);
        y = count(root->right_child);
        return x + y + 1;
    }
}
int main()
{
    int choice, choice1;
    while (1)
    {
      
        cout << "\nEnter '1' to create binary tree.";
        cout << "\nEnter '2' to traverse nodes of tree.";
        cout << "\nEnter '3' to find height of tree.";
        cout << "\nEnter '4' to count the number of nodes in the tree. \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            createBinaryTree();
            break;
        case 2:
            cout << "\nEnter '1' for pre-order traversal.";
            cout << "\nEnter '2' for in-order traversal.";
            cout << "\nEnter '3' for post-order traversal.";
            cout << "\nEnter '4' for level-order traversal.";
            cin >> choice1;
            switch (choice1)
            {
            case 1:
                cout << "Pre-Order : ";
                preOrder(root);
                cout << endl;
                break;
            case 2:
                cout << "In-Order : ";
                inorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Post-Order : ";
                postorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Level-Order : ";
                levelOrder(root);
                cout << endl;
                break;
            }

            break;
        case 3:
            cout << "The height of the tree is " << height(root) << endl;
            break;
        case 4:
            cout << "The no of nodes in tree are " << count(root) << endl;
            break;

        default:
            cout << "Invalid Input!\n";
            break;
        }
    }

    return 0;
}