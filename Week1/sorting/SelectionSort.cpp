#include <iostream>
#include <stdio.h>

using namespace std;

void sortArray(int arr[])
{
    int r = 15;
    for (int j = 0; j < r; j++)
    {
        int i = j;
        int k = arr[j];
        int l;
        bool flag = false;
        while (i < r)
        {
            if (k <= arr[i]) // finding the smallest one
            {
                i++;
                continue;
            }
            else
            {
                k = arr[i]; // stores the value
                l = i;      // stores the index of the smallest element
                flag = true;
                i++;
            }
        }
        if (flag)
        {
            int temp = arr[j]; // swapping
            arr[j] = k;        // with the element of the current to the smallest .
            arr[l] = temp;
        }
        // arr[j] = temp;
        // r--;
    }
}

int main()
{
    int input[15] = {9999, -50, 888, 888, 12, 0, -50, 750, 1000000, 888, -9999, 50, 2, 1};
    //{1, 1, 1, 1, 1, 1, 1};
    // {23, 45, 67, 8, 7, 12, 4};

    sortArray(input);

    for (int i = 0; i < 15; i++)
    {
        cout << input[i] << " ";
    }

    return 0;
}