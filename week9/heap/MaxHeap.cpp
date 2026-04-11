#include <iostream>
#include <cmath>

using namespace std;

int arrayy[15];
int i = 0, siz = 0;
bool flag;
int lvl, power = 0;

// It is the levelFinder function which finds the level / height of the tree
int levelFinder()
{
    flag = true;      // for tree
    double power = 0; // for tree
    int level = 0;
    int n = 0;
    while (n < siz)
    {
        n += (1 << level);
        level++;
    }
    return level;
}

// here i made swaping function because we need it in several places
void swap(int &greater, int &smaller)
// One of the most IMP  ( & operator )
// here i used the &operator so it pass by refrence now the change would be made inside an actual array not in the copy which is been made by me.
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
    return;
}

// insert method
void insert(int value)
{
    int length = sizeof(arrayy) / sizeof(arrayy[0]);
    if (siz >= length)
    {
        cout << "Array is Full, Can't insert value, Delete First to insert new one" << endl;
    }
    arrayy[i] = value;
    siz++;
    if (siz > 1)
    {
        upHeapify(arrayy, i);
    }
    i++;
    lvl = levelFinder();
}

// We use DownHeapify Function to delete values in Heap
void downHeapify(int arra[], int ind, int sizee)
{
    // bool flag1 = true;
    // bool flag2 = true;
    int child1 = (2 * ind) + 1;
    int child2 = (2 * ind) + 2;

    if (child1 < sizee) // left child check ( exists or not )
    {
        if (child2 < sizee) // // right child check ( exists or not )
        {
            if (arra[ind] < arra[child1] && arra[ind] > arra[child2])
            {
                swap(arra[child1], arra[ind]);
                downHeapify(arrayy, child1, siz);
            }
            if (arra[ind] > arra[child1] && arra[ind] < arra[child2])
            {
                swap(arra[child2], arra[ind]);
                downHeapify(arrayy, child2, siz);
            }
            if (arra[ind] < arra[child1] && arra[ind] < arra[child2])
            {
                if (arra[child1] < arra[child2])
                {
                    swap(arra[child2], arra[ind]);
                    downHeapify(arrayy, child2, siz);
                }
                if (arra[child1] > arra[child2])
                {
                    swap(arra[child1], arra[ind]);
                    downHeapify(arrayy, child1, siz);
                }
            }
        }
        if (arra[ind] < arra[child1])
        {

            swap(arra[child1], arra[ind]);
            downHeapify(arrayy, child1, siz);
        }
    }
}

// To delete values
void del()
{
    if (siz == 0)
    {
        cout << "Heap is empty\n";
        return;
    }
    swap(arrayy[0], arrayy[siz - 1]);
    siz--;
    i--; // so the last element get lost / delete / remove
    cout << "Root Element Deleted \n";
    downHeapify(arrayy, 0, siz);
    lvl = levelFinder();
}

// It is the Function which Displays the tree in an actual tree Structure like level by level

void treeDisplay(int count, int ind, bool flag, int lvl, int exp)
{
    if (ind >= siz)
    {
        return;
    }

    int m = 0;
    while (m < lvl)
    {
        cout << "  ";
        m++;
    }
    cout << arrayy[ind];
    if (flag == true)
    {
        power += (1 << exp);
    }
    if (count < power)
    {
        ind++;
        count++;
        treeDisplay(count, ind, false, lvl, exp);
        cout << "\n";
        return;
    }
    cout << "\n";
    exp++;
    ind++;
    count++;
    lvl--;
    treeDisplay(count, ind, true, lvl, exp);
}

// display like a Tree Structure / normal
void display()
{
    cout << " 1 : Normal Display, 2: Tree Display: ";
    int input;
    cin >> input;
    if (input == 1)
    {
        for (int i = 0; i < siz; i++)
        {
            cout << arrayy[i] << endl;
        }
    }
    // Tree Structure Display
    else if (input == 2)
    {
        int lev = levelFinder();
        power = 0;
        treeDisplay(1, 0, true, lev, 0); //  count , ind , flag , lvl , exp
    }
    else
    {
        cout << "Invalid ";
    }
}

int main()
{
    bool flag = true;
    int input;

    while (flag)
    {
        cout << "Enter: 1 : To Insert , 2 : To Delete , 3 : To  Display  , 4 : Heap Sort, 5 : To Exit => ";
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
            display();
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