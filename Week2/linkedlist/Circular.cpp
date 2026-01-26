#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *list = NULL;
Node *curr;
Node *temp;

void insert(int value)
{
    temp = (Node *)malloc(sizeof(Node)); // malloc used for allocating the memory acc to the given arguments
    temp->data = value;                  // the temp is holding the data which is been passed from the arguments of this function

    if (list == NULL)
    {
        list = temp;
        temp->next = list;
    }
    else
    {
        curr = list; // to strt pointer from above

        while (curr->next != list) // run until the current's next element is not null
        {
            curr = curr->next; // to change the current
        }

        curr->next = temp; // to store value.
        temp->next = list; // to make it circular , like the last element's next would be the start of the list.
    }
}
void display()
{
    if (list == NULL)
    {
        cout << "List is empty \n";
        return;
    }
    cout << list->data << "\n";
    curr = list->next;
    while (curr != list)
    {
        cout << curr->data << "\n";
        curr = curr->next;
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
    cout << "Enter the value you want to delete : ";
    cin >> value;

    Node *cur = list;
    if (value == list->data)
    {
        if (list->next != list)
        {

            list = list->next;
            temp->next = list; // here i did this because when i delete the first value
            // after then the temp next will still pointing to the last list head so now i updated it
            // with new one
            free(cur);
            cout << value << " : Deleted Successfully \n";
            return;
        }
        free(cur);
        list = NULL;
        cout << value << " : Deleted Successfully \n";
        return;
    }
    cur = list->next;
    Node *prev = list;
    while (cur != list)
    {
        if (value == cur->data)
        {
            prev->next = cur->next;
            free(cur);
            cout << value << " : Deleted Successfully \n";
            return;
        }
        prev = prev->next;
        cur = cur->next;
    }
    cout << "Can't Found: " << value << endl;
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
    if (value == list->data)
    {
        cout << value << " Found\n";
        return;
    }
    cur = list->next;
    while (cur != list)
    {
        if (value == cur->data)
        {
            cout << value << " Found\n";
            return;
        }
        cur = cur->next;
    }
    cout << "Can't Found : " << value << "\n";
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