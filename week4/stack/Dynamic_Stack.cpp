#include <iostream>
#include <stdlib.h>

using namespace std;

// Dynamic Stack

struct Node
{
    int data;
    Node *next;
};

Node *curr = NULL;

void push(int value)
{
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = curr;
    curr = temp;
}

int pop()
{
    if (curr == NULL)
    {
        cout << "Stack underflow ";
        return -1;
    }
    Node *temp = curr;
    int value = temp->data;

    curr = curr->next;
    free(temp);
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