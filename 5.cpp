/*Beginning with empty binary search tree Construct BST by inserting the values in 
given order. After construction a binary tree do:
1. Insert new node.   
2. Find number of nodes from longest path from root. 
3. Search a specific value and display comparisons required.

5 3 7 2 4 6 8
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

void insertnode(Node* &root, int val)
{
    if (root == nullptr)
    {
        root = new Node(val);
        cout << "node inserted successfully\n";
    }
    else if (val >= root->data)
    {
        insertnode(root->right, val);
    }
    else
    {
        insertnode(root->left, val);
    }
}

int height(Node* &root)
{
    if (root == nullptr)
    {
        return -1;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    return max(leftheight, rightheight) + 1;
}

int search(Node *&root, int val, int comp)
{
    if (root == nullptr)
    {
        return -1;
    }
    if (root->data == val)
    {
        return comp + 1;
    }
    if (val < root->data)
    {
        return search(root->left, val, comp + 1);
    }
    else
    {
        return search(root->right, val, comp + 1);
    }
}

int main()
{
    Node *root = nullptr;
    int choice, val;
    do
    {
        cout << "\nMENU\n";
        cout << "1 insert node\n";
        cout << "2 display tree height\n";
        cout << "3 search a value\n";
        cout << "4 exit\n";
        cout << "enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "enter value to insert : ";
            cin >> val;
            insertnode(root, val);
            break;
        }
        case 2:
        {
            cout << "Tree height : " << height(root);
            break;
        }
        case 3:
        {
            cout << "enter a value to search : ";
            cin >> val;
            int s = search(root, val, 0);
            if (s != -1)
            {
                cout << "Value found\n";
                cout << "comparisons : " << s << endl;
            }
            else
            {
                cout << "Value not found" << endl;
            }
            break;
        }
        case 4:
        {
            cout << "exiting-----" << endl;
            break;
        }
        default:
        {
            cout << "enter valid choice : ";
        }
        }

    } while (choice != 4);
    return 0;
}