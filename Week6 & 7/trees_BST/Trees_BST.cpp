#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *Root = NULL;

Node *insert(Node *curr, int value)
{
    if (curr == NULL)
    {
        Node *temp;
        temp = (Node *)malloc(sizeof(Node));
        temp->data = value;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if (value > curr->data)
    {
        curr->right = insert(curr->right, value);
    }
    else if (value < curr->data)
    {
        curr->left = insert(curr->left, value);
    }
    else if (value == curr->data)
    {
        cout << "Can't store same data ";
    }
    return curr;
}

void display_Pre_Order(Node *curr)
{
    if (curr != NULL)
    {
        cout << curr->data << "\n";
        display_Pre_Order(curr->left);
        display_Pre_Order(curr->right);
    }
}

void display_In_Order(Node *curr)
{
    if (curr != NULL)
    {
        display_In_Order(curr->left);
        cout << curr->data << "\n";
        display_In_Order(curr->right);
    }
}

void display_Post_Order(Node *curr)
{
    if (curr != NULL)
    {
        display_Post_Order(curr->left);
        display_Post_Order(curr->right);
        cout << curr->data << "\n";
    }
}

Node *deleteNode(Node *curr, value)
{
    if (curr == NULL)
    {
        cout << value << " Not Found \n";
        return NULL;
    }
    if (curr->data == value)
    {
        if (curr->right == NULL && curr->left == NULL)
        {
            free(curr);
            return NULL;
        }
        // for one child
        if (curr->left == NULL)
        {
            Node *temp;
            temp = (Node *)malloc(sizeof(Node));
        }
        if (curr->right == NULL)
        {
        }
        // for two childs
        Node *temp;
        temp = (Node *)malloc(sizeof(Node));
        temp = curr->right;
        temp = minNode(curr);
        curr->data = temp->data;
        curr->right = deleteNode(curr->right, temp->data);
        return curr;
    }
    if (value > curr->data)
    {
        curr->right = DeleteNode(curr->right, value);
        return curr;
    }
    if (value < curr->data)
    {
        curr->left = DeleteNode(curr->left, value);
        return curr;
    }
}

// to find the minimum node

Node *minNode(Node *curr)
{
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

int main()
{
    bool flag = true;
    int input, value;
    while (flag)
    {
        cout << " 1 : For Insert , 2 : For Display , 3 : To Delete , 4 : For Exit \n";
        cin >> input;
        if (input == 1)
        {
            cout << "Enter value";
            cin >> value;
            Root = insert(Root, value);
        }
        else if (input == 2)
        {
            cout << " Display order ?  1 : Pre Order , 2 : In Order , 3 : Post Order";
            cin >> input;
            if (input == 1)
            {
                display_Pre_Order(Root);
            }
            else if (input == 2)
            {
                display_In_Order(Root);
            }
            else if (input == 3)
            {
                display_Post_Order(Root);
            }
            else
            {
                cout << "Invalid Input";
            }
        }
        else if (input == 3)
        {
            deleteNode(Root);
        }
        else if (input == 4)
        {
            flag = false;
        }
        else
        {
            cout << "Invalid Input ";
        }
    }
}
