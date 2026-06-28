#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

// seprate chaining , open hashing , time complexity , empty spaces issue like there would be several empty spaces but we still add in the same block
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
        // MultiNode *temp;
        // temp = (MultiNode *)malloc(sizeof(MultiNode));
        MultiNode *temp = new MultiNode;
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
        curr->next = temp;
        // HT[index].next = temp;
    }
}

void del(int value) // done
{
    int ind = value % 10; // % size
    bool flag = false;
    if (HT[ind].flag == false) // the element is not in the list
    {
        cout << "Value doesn't exist\n";
        return;
    }
    if (HT[ind].data == value) // to delete the array item / override which means the first element
    {
        if (HT[ind].next == NULL)
        {
            // HT[ind].data = NULL;
            HT[ind].flag = false;
            cout << HT[ind].data << " Deleted Successfully\n";
            return;
        }
        if (HT[ind].next != NULL)
        {

            HT[ind].data = HT[ind].next->data; // replacing the first element
            HT[ind].next = HT[ind].next->next;
            return;

            // while (curr->next != NULL)
            // {
            //     prev->data = curr->data; // coping the data from 1 to 0 , 2 to 1 , 3 to 2
            //     // so in this manner if last lists data is empty i will delete that data ;
            //     prev = prev->next;
            //     curr = curr->next;
            // }
            // MultiNode *temp = curr;
            // curr = prev;
            // delete (temp);
            // return;
        }
    }
    if (HT[ind].next != NULL)
    {

        if (HT[ind].next->data == value) // to delete head of the list , which is the second element
        {
            MultiNode *temp = HT[ind].next;
            if (HT[ind].next->next != NULL)
            {
                HT[ind].next = HT[ind].next->next; // so the list head pointer changes
            }
            else
            {
                HT[ind].next = NULL;
            }
            cout << temp->data << " Deleted Successfully\n";
            delete (temp);
            return;
        }
    }
    else
    {
        cout << "Value doesn't exist\n";
        return;
    }

    MultiNode *prev = HT[ind].next;
    MultiNode *curr = HT[ind].next->next;
    while (curr != NULL) // to delete the item which is in the list
    {
        if (curr->data == value)
        {
            MultiNode *temp = curr;
            prev->next = curr->next;
            if (curr->next != NULL)
            {
                curr = curr->next;
            }

            else
                curr = prev;
            flag = true;
            free(temp);
            break;
        }
        curr = curr->next;
        prev = prev->next;
    }
    if (flag)
    {
        cout << value << " Deleted Successfully\n ";
    }
    else
    {
        cout << " Value doesn't exist\n";
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
    if (HT[index].data == value) // it checks the data which is in array, not in the list
    {
        cout << value << ": Found \n";
        return;
    }

    MultiNode *cur = HT[index].next;
    if (cur->data == value) // it checks the head of the list
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
    if (!flag1) // personal review .. just this  ( !  means ( not ) cause me a great trouble ) cuz i didnt use it, and i was thinking that there is an error in my insert function ;
    {
        cout << value << ": Found \n";
    }
    else
    {
        cout << "Value Not Found \n";
    }
}
void display()
{
    int i = 0;
    while (i < size(HT))
    {
        if (HT[i].flag == false)
        {
            i++;
            continue;
        }
        cout << HT[i].data;
        MultiNode *curr = HT[i].next;
        if (curr == NULL)
        {
            i++;
            cout << "\n";
            continue;
        }
        while (curr != NULL)
        {
            cout << " => " << curr->data;
            curr = curr->next;
        }
        cout << "\n";
        i++;
    }
}
int main()
{

    bool flag = true;
    int input, value;

    while (flag)
    {
        cout << " 1: For Insert " << "2: To Search " << "3 : To Delete " << "4 : To Display " << "5 : For Exit ";
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
            cout << "Enter value to Delete ";
            cin >> value;
            del(value);
        }
        else if (input == 4)
        {
            display();
        }
        else if (input == 5)
        {
            cout << "Program Exits ..... !";
            flag = false;
        }
        else
        {
            "Inavlid input ";
        }
    }
}