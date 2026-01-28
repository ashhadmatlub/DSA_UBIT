#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    Node *next;
    Node *prev;
    int data;
};

Node *list = NULL;
Node *curr;
Node *temp;

void insert(int value)
{
    temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;

    if (list == NULL)
    {
        list = temp;
        list->prev = NULL;
    }
    else
    {
        curr = list;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }

        curr->prev = curr;
        curr->next = temp;
    }
}
void delet()
{
    if (list == NULL)
    {
        cout << "List is Empty. \n";
        return;
    }
    int value;
    cout << "Enter Value to delete: ";
    cin >> value;
    Node *cur = list;
    if (value = cur->data)
    {
        list = list->next;
        curr = list;
        curr->prev = NULL;
        free(cur);
        cout << value << " : Deleted Successfully \n";
        return;
    }
    Node *pre = list;
    cur = cur->next;
    while (cur != NULL)
    {
        if (cur->data == value)
        {
            pre->next = cur->next;
            cur->prev = pre;
            free(cur);
            cout << value << " : Deleted Successfully \n";
            return;
        }
        cur = cur->next;
        pre = pre->next;
        cur->prev = pre;
    }
    cout << value << " Not Found \n";
}
void display()
{
    if (list == NULL)
    {
        cout << "List is Empty. \n";
        return;
    }

    curr = list;
    while (curr != NULL)
    {
        cout << curr->data << "\n";
        curr = curr->next;
    }
}
void search()
{
    if (list == NULL)
    {
        cout << "List is Empty. \n";
        return;
    }

    int value;
    cout << "Search value : ";
    cin >> value;

    Node *cur = list;
    while (cur != NULL)
    {
        if (cur->data == value)
        {
            cout << "Found : " << cur->data << "\n";
            return;
        }
        cur = cur->next;
    }
    cout << value << "Not Found \n";
}
int main()
{
    bool flag = true;
    int input, times, value;
    while (flag)
    {
        cout << "Enter: 1 : For Insert , 2 : For Display , 3 : For Search , 4 : For Delete , 5 : To Exit => ";
        cin >> input;

        if (input == 1)
        {
            cout << "How many values you want to Enter ? : ";
            cin >> times;
            for (int i = 0; i < times; i++)
            {
                cout << "Enter value : ";
                cin >> value;
                insert(value);
            }
        }
        else if (input == 2)
        {
            display();
        }
        else if (input == 3)
        {
            search();
        }
        else if (input == 4)
        {
            delet();
        }
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