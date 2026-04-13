#include <iostream>
using namespace std;

const int siz = 10;
int hashs[siz];

// closed hashing

void fill(int i) // to fill the array with -1 so it would be easy to identify its empty slot
{
    if (i >= siz)
    {
        return;
    }
    hashs[i] = -1;
    fill(i++);
}

void insert(int value)
{
    bool flag = true;
    int ind = value % siz;
    if (hashs[ind] == -1)
    {
        hashs[ind] = value;
        return;
    }

    int i = 1;
    while (flag && i < 10)
    {
        int idx = (ind + i) % siz; // for quadratic probing we would use ( i*i )
        if (hashs[idx] == -1)
        {
            hashs[idx] = value;
            flag = false;
        }
        i++;
    }
    if (!flag)
    {
        cout << "Entered ";
    }
    else
    {
        cout << "Full";
    }
}

int main()
{
    bool flag = true;
    int input;
    fill(0);

    while (flag)
    {
        cout << "Enter: 1 : To Insert , 2 : To Search , 3 : To Delete => ";
        cin >> input;

        if (input == 1)
        {
            int value;
            cout << "Enter Value " << endl;
            cin >> value;
            insert(value);
        }
        // else if (input == 2)
        // {

        // }
        else if (input == 3)
        {
            flag = false;
            cout << "Program Exits ";
        }
        else
        {
            cout << "Invalid Input ";
        }
    }
}