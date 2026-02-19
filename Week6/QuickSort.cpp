#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int set_pivot(int L, int R)
{
    int arr[10] = {77, 82, 11, 54, 76, 57, 25, 98, 59, 101};
    int piv_ind = (L + R) / 2;

    while (L != R || L < R)
    {
        while (piv_ind < R) // for traversing through right hand side
        {

            if (arr[piv_ind] > arr[R])
            {
                int temp = arr[piv_ind];
                arr[piv_ind] = arr[R];
                arr[R] = temp;
                piv_ind = R;
                break;
            }
            else
            {
                R--;
            }
        }
        while (piv_ind > L) // for traversing through left hand side
        {
            if (arr[piv_ind] < arr[L])
            {
                int temp = arr[piv_ind];
                arr[piv_ind] = arr[L];
                arr[L] = temp;
                piv_ind = L;
                break;
            }
            else
            {
                L++;
            }
        }
    }
    return piv_ind;
}
void Quick_Sort(int L, int R)
{
    if (L < R)
    {
        int piv_ind = set_pivot(L, R);
        Quick_Sort(L, (piv_ind)-1);
        Quick_Sort((piv_ind) + 1, R);
    }
}

int main()
{
    int L = 0;
    int R = 9;

    int arr[10] = {77, 82, 11, 54, 76, 57, 25, 98, 59, 101};
    cout << "Before Sorting" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i];
        if (i < 9)
            cout << " , ";
    }
    Quick_Sort(L, R);
    cout << "\nAfter Sorting\n";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i];
        if (i < 9)
            cout << " , ";
    }
}