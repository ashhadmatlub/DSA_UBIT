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
Node *curr;

void insert(int value)
{

    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = value;

    if (list == NULL)
    {
        list = temp;
    }
    else
    {
        curr = list;

        while (curr->next != NULL)
        {
            curr = curr->next;
        }

        curr->next = temp;
        temp->next = list;
    }
}
void display()
{
    if (list == NULL)
    {
        cout << "List is Empty, Now : ";
        return;
    }
    curr = list;
    cout << curr->data << "\n";
    curr = curr->next;
    while (curr != list)
    {
        cout << curr->data << "\n";
        curr = curr->next;
    }
}
int main()
{
    int input;
    int times, values;
    bool flag = true;

    while (flag)
    {
        cout << " 1: For Insert, " << "2: For Display, " << "3: For Search, " << "4: To Delete, " << "5: Exit => ";
        cin >> input;

        if (input == 1)
        {
            cout << "Enter the number of values you wanna enter: ";
            cin >> times;
            for (int i = 0; i < times; i++)
            {
                cout << "Enter value: ";
                cin >> values;
                insert(values);
            }
        }
        else if (input == 2)
        {
            display();
        }
        // else if (input == 3)
        // {
        //     search();
        // }
        else if (input == 5)
        {
            flag = false;
        }
        else
        {
            cout << "Invalid Input";
        }
    }
}