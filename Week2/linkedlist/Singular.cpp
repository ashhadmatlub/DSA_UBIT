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
int count = 0; //  for Sorting

void swap(int &greater, int &smaller)
// One of the most IMP  ( & operator )
// here i used the &operator so it pass by refrence now the change would be made inside an actual array not in the copy which is been made by me.
{
    int temp = greater;
    greater = smaller;
    smaller = temp;
}

void bubbleSort()
{
    int k = count - 1;
    int j;
    bool flag = true;
    if (list == NULL)
    {
        cout << "List is empty ";
        return;
    }
    Node *cur;
    for (int i = 0; i < count; i++)
    {
        cur = list;
        j = 0;
        while (j < k)
        {
            if (cur->next == NULL)
            {
                break;
            }
            if (cur->data < cur->next->data)
            {
                cur = cur->next;
                j++;
            }
            else
            {
                swap(cur->data, cur->next->data);
                flag = false;
                cur = cur->next;
                j++;
            }
        }
        k--;
    }
    if (flag == false)
    {
        cout << "Sorted successfully \n";
    }
    else
    {
        cout << "Not Sorted Due to an error\n";
    }
}

void insert(int value)
{
    count++; // used for sorting kind of tracking
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;

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
    }
}
void search()
{
    bool valid = true;
    int value;
    if (list == NULL)
    {
        cout << "List is empty ,Now : ";
        return;
    }
    cout << "Search value: ";
    cin >> value;
    curr = list;
    while (curr != NULL)
    {
        if (curr->data == value)
        {
            valid = false;
            break;
        }
        curr = curr->next;
    }
    if (valid)
    {
        cout << "Not Found, ";
    }
    else
    {
        cout << "Found: " << value << ", Now: ";
    }
}
void display()
{
    if (list == NULL)
    {
        cout << "List is empty ,Now : ";
        return;
    }
    curr = list;
    while (curr != NULL)
    {
        cout << curr->data << "\n";
        curr = curr->next;
    }
}
void del(int value)
{
    if (list == NULL)
    {
        cout << "List is empty ,Now : ";
        return;
    }

    Node *cur = list;
    if (value == list->data)
    {
        list = list->next;
        free(cur);
        cout << "Deleted successfully : " << value;
        count--;
        return;
    }
    cur = list->next;
    Node *prev = list;
    while (cur != NULL)
    {
        if (value == cur->data)
        {
            prev->next = cur->next;
            free(cur);
            cout << "Deleted successfully : " << value;
            count--;
            return;
        }
        cur = cur->next;
        prev = prev->next;
    }
}
int main()
{
    int input;
    int times, values;
    bool flag = false;

    // cout << "Check the following instructions below ";

    while (!flag)
    {
        cout << " 1: For Insert, " << "2: For Display, " << "3: For Search, " << "4: To Delete, " << " , 5: To Sort , 6: Exit => ";
        cin >> input;

        if (input == 1)
        {
            cout << " how many values do you want to enter in the list ";
            cin >> times;
            for (int i = 0; i < times; i++)
            {
                cout << "Enter value ";
                cin >> values;
                insert(values);
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
            int value;
            if (list == NULL)
            {
                cout << "List is empty ,Now : ";
                continue;
            }
            cout << "Enter the value you want to delete: ";
            cin >> value;
            del(value);
        }
        else if (input == 5)
        {
            bubbleSort();
        }
        else if (input == 6)
        {
            flag = true;
        }
        else
        {
            cout << "Invalid Input";
        }
    }
}
