#include <iostream>
#include <stdio.h>

using namespace std;

void sortArray(int arr[])
{
    for (int i = 1; i < 7; ++i)
    {
        int j = i - 1;
        int k = arr[i];

        while (j >= 0 && arr[j] > k)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = k;
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