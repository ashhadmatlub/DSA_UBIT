#include <iostream>
#include <stdio.h>

using namespace std;

void sortArray(int arr[])
{
    for (int i = 1; i < 7; i++)
    {
        int j = i - 1;
        while (j != -1)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                i--, j--; // if the next element is smaller then the current , then swap and also
                // change the next and make it current , and current will be previous
                continue;
            }
            j--;
        }
    }
}

int main()
{
    int input[7] = {1, 1, 1, 1, 1, 1, 1};
    // {9999, 888, 750, 50, 12, 2, 1};
    // {9999, -50, 888, 888, 12, 0, -50, 750, 1000000, 888, -9999, 50, 2, 1};

    sortArray(input);

    for (int i = 0; i < 7; i++)
    {
        cout << input[i] << " ";
    }

    return 0;
}