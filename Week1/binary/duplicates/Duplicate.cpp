#include <iostream>
#include <stdio.h>

using namespace std;

// binary duplicate

int main()
{
    int input[10] = {5,5,5,5,5,5,5,5,5,5};
    int find;
    cout << " Enter the number you wanna find ";
    cin >> find;
    int count = 0;
    bool valid = true;
    int l = 0;
    int r = 9;
    int mid, traverse;
    int i = 1;

    while (l <= r  )
    {
        mid = (l + r) / 2;
        if (input[mid] == find)
        {
            count++;
            valid = false;
            traverse = mid;
            while ((mid + count) < 10 || (traverse - i) >= 0)
            {

                if ((mid + count) < 10 && input[(mid + count)] == find)
                {
                    count++;
                }
                if (  (traverse - i) >= 0 && input[(traverse - i)] == find )
                {
                    i++;
                    count++;
                }
                else
                {
                    break;
                }
            }
            break;
        }
        if (input[mid] > find && count == 0)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }

    }
    if (valid)
    {
        cout << find << " Not Found ";
    }
    else
    {
        cout << " The number is found " << count << " time ";
    }
    return 0 ;
}