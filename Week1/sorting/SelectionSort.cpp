#include <iostream>
#include <stdio.h>

using namespace std;

void sortArray(int arr[])
{
    int r = 7;
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
                k = arr[i];
                l = i;
                flag = true;
                i++;
            }
        }
        if (flag)
        {
            int temp = arr[j];
            arr[j] = k;
            arr[l] = temp;
        }
        // arr[j] = temp;
        // r--;
    }
}

int main()
{
    int input[7] = {23, 45, 67, 8, 7, 12, 4};

    sortArray(input);

    for (int i = 0; i < 7; i++)
    {
        cout << input[i] << " ";
    }

    return 0;
}