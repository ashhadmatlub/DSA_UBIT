#include <iostream>
#include <stdlib.h>

using namespace std;

// Dynamic Stack

struct Node
{
    int data;
    Node *next;
};

Node *stack = NULL;

void push(int value)
{
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    if (stack == NULL)
    {
        stack = temp;
        return;
    }
    Node *curr = stack;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
}

int pop()
{
    if (stack == NULL)
    {
        cout << "Stack underflow ";
        return -1;
    }
    Node *curr = stack;
    Node *prev = NULL;
    while (curr ->next!= NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    Node *del = curr;
    int value = curr->data;
    prev = curr;
    free(del);
    // temp = NULL;
    return value;
}

int main()
{
    bool flag = true;
    int input;

    while (flag)
    {
        cout << "Enter: 1 : To Push , 2 : To Pop , 3 : To Exit => ";
        cin >> input;

        if (input == 1)
        {
            int value;
            cout << "Enter Value " << endl;
            cin >> value;
            push(value);
        }
        else if (input == 2)
        {
            int value;
            value = pop();
            cout << value << "\n";
        }
        else if (input == 3)
        {
            flag = false;
            cout << "Program Exits ";
        }
        else
        {
            cout << "Invalid Input ";
        }
    }
}