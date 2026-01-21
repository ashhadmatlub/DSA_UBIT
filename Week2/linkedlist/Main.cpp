#include <iostream>
#include <stdlib.h>
#include <stdio.h>
// #include "Node.cpp"
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *list = NULL;

void insert(int value)
{

    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    Node *curr;

    if (list == NULL)
    {
        list = temp;
    }
    else
    {
        curr = list;
    }

    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = temp;
}
int main()
{
    int input;

    cout << "Check the following instructions below";

    cout << " 1: For Insert" << "2: For Display";
    cin >> input;
    int times, values;

    // while (input < 1 || input > 2)
    // {

    if (input == 1)
    {
        cout << " how many values do you want to enter in the list";
        cin >> times;
        for (int i = 0; i < times; i++)
        {
            cout << "Enter value ";
            cin >> values;
            insert(values);
        }
    }
    // else if (input == 2)
    // {
    // }
    // }
}
