#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct MultiNode
{
    int data;
    MultiNode *next;
};

struct Node
{
    int data;
    MultiNode *next;
    bool flag = false;
};

Node HT[10];

void insert(int value)
{
    int index = value % 10;

    if (HT[index].flag == false)
    {
        HT[index].data = value;
        HT[index].next = NULL;
        HT[index].flag = true;
    }
    else
    {
        MultiNode *temp;
        temp = (MultiNode *)malloc(sizeof(MultiNode));
        temp->data = value;
        temp->next = NULL;
        MultiNode *curr = HT[index].next;
        if (curr == NULL)
        {
            HT[index].next = temp;
            return;
        }
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        HT[index].next = temp;
    }
}

void search(int value)
{
    int index = value % 10;
    bool flag1 = true;

    if (HT[index].flag == false)
    {
        cout << "Value not Found \n ";
        return;
    }
    if (HT[index].flag == true)
    {
        if (HT[index].data == value)
        {
            cout << value << ": Found \n";
            return;
        }

        MultiNode *cur = HT[index].next;
        if (cur->data == value)
        {
            cout << value << ": Found \n";
            return;
        }
        while (cur != NULL)
        {
            cur = cur->next;
            if (cur->data == value)
            {
                flag1 = false;
                break;
            }
        }
        if (flag1)
        {
            cout << value << ": Found \n";
        }
        else
        {
            cout << value << ": Not Found \n";
        }
    }
}
void display()
{
    
}
int main()
{

    bool flag = true;
    int input, value;

    while (flag)
    {
        cout << " 1: For Insert, " << "2: To Search, " << "3 : To Display ," << "4 : For Exit: ";
        cin >> input;

        if (input == 1)
        {
            cout << "Enter value ";
            cin >> value;
            insert(value);
        }
        else if (input == 2)
        {
            cout << "Search value ";
            cin >> value;
            search(value);
        }
        else if (input == 3)
        {
            display();
        }
        else if (input == 4)
        {
            flag = false;
        }
        else
        {
            "Inavlid input ";
        }
    }
}