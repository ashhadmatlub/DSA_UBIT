#include <iostream>
#include <stdlib.h>

using namespace std;

// Dynamic Stack

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *list = NULL;
Node *curr = NULL;
Node *pre = NULL;

// void push(int value)
// {
//     Node *temp;
//     temp = (Node *)malloc(sizeof(Node));
//     temp->data = value;
//     temp->next = NULL;
//     temp->prev = curr;
//     curr = temp;

//     if (list == NULL)
//     {
//         list = temp;
//         pre = list;
//     }
// }

// int pop()
// {
//     if (list == NULL)
//     {
//         cout << "Stack underflow ";
//         return -1;
//     }
//     Node *temp;
//     temp = curr;
//     free(temp);
//     int value = curr->data;
//     curr = pre;
//     pre = pre->prev;
//     return value;
// }

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