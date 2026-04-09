#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int array[15];
int i = 0, siz = 1;

// here i made swaping function because we need it in several places
void swap(int greater, int smaller)
{
    int temp = greater;
    greater = smaller;
    smaller = temp;
}

// We use UpHeapify Function to insert the values in Heap
void upHeapify(int arr[], int index)
{

    int parent = (index - 1) / 2;
    if (arr[index] > arr[parent])
    {
        swap(arr[index], arr[parent]);
        upHeapify(arr, parent);
    }
    else
    {
        return;
    }
}

void insert(int value)
{
    if (siz > sizeof(array))
    {
        cout << "Array is Full , Can't insert value " << endl;
    }
    array[i] = value;
    i++;
    if (i > 1)
    {

        upHeapify(array, i);
    }
    siz++;
}

// We use DownHeapify Function to delete values in Heap
void downHeapify(int array[], int ind, int siz)
{
    bool flag1 = true;
    int child1 = (2 * ind) + 1;
    int child2 = (2 * ind) + 2;

    if (child1 < siz)
    { // left child check
        if (child2 < siz)
        { // right child check
            if (array[child1] > array[ind])
            {
                swap(array[child1], array[ind]);
                flag1 = false;
            }
            if (array[child2] > array[ind])
            {
                swap(array[child2] > array[ind]);
            }
        }
        if (flag1 == true) // only for left child
        {
            swap(array[child1], array[ind]);
        }
    }
}

// To delete values
void del()
{
    swap(array[0], array[siz - 1]);
    siz--;
    downHeapify(array, 0, siz);
}

int main()
{
    bool flag = true;
    int input;

    while (flag)
    {
        cout << "Enter: 1 : To Insert , 2 : To Delete , 3 :To  Display  , 4 : Heap Sort, 5 : To Exit => ";
        cin >> input;

        if (input == 1)
        {
            int value;
            cout << "Enter Value " << endl;
            cin >> value;
            insert(value);
        }
        else if (input == 2)
        {
            del();
        }
        else if (input == 3)
        {
        }
        else if (input == 4)
        {
        }
        else if (input == 5)
        {
            flag = false;
            cout << "Program Exits ";
        }
    }
}