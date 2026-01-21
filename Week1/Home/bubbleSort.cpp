#include <iostream>
#include <stdio.h>

using namespace std;

// to compare between the two elements in array at a time and swap the greater one to the right.
// this one is for ascending.

void sortArray(int input[])
{
    int temp, j, k = 7;
    int l;

    for (int i = 0; i < 7; i++)
    {
        j = 0;
        while (j < k - 1)
        {
            l = j + 1;
            if (input[j] <= input[l]) // use >= for decending order
            {
                j++;
                continue;
            }
            else
            {
                temp = input[j];
                input[j] = input[l];
                input[l] = temp;
                j++;
            }
        }
        k--;
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