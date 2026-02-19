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
    if (value < curr->data)
    {
        curr->left = insert(curr->left, value);
    }
    if (value == curr->data)
    {
        cout << "Can't store same data ";
    }
}

void display_Pre_Order(Node *curr)
{
    if (curr != NULL)
    {
        cout << curr->data;
        display_Pre_Order(curr->left);
        display_Pre_Order(curr->right);
    }
}

int main()
{
    bool flag = true;
    int input, value;
    while (flag)
    {
        cout << " 1 : For Insert , 2 : For Display , 3 : For Exit";
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

            if (input == 1)
            {
                display_Pre_Order(Root);
            }
            else if (input == 2)
            {
            }
            else if (input == 3)
            {
            }
            else
            {
                cout << "Invalid Input";
                input == 1;
            }
        }
        else if (input == 3)
        {
            flag == false;
        }
        else
        {
            cout << "Invalid Input ";
        }
    }
}
