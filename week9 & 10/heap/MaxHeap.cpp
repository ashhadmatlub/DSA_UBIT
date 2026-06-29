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
// here i used the &operator so it pass by refrence now the change would be made inside an actual array not in just between these two elements which remains inside this functions.
{
    int temp = greater;
    greater = smaller;
    smaller = temp;
}

// We use UpHeapify Function to insert the values in Heap
void upHeapify(int arr[], int index)
{
    if (index == 0)
        return;
    int parent = (index - 1) / 2; //  by using this formula we got the parent node of this child
    if (arr[index] > arr[parent]) // and then we compare the parent with child if the child is greater then we swap it with parent, as it neccessary that the parent must be the greater then all its child elements in MaxHeap. (vice versa in min Heap).
    {
        swap(arr[index], arr[parent]);
        upHeapify(arr, parent); // here we pass it again so it would check through the head or root of the tree, and if the parent node we send would be zero then it means that it has no parents so then we would stop.
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
        return;
    }
    arrayy[i] = value;
    siz++;
    if (siz > 1)
    {
        upHeapify(arrayy, i); // to maintain the maxHeap concept we would do this.
    }
    i++;
    lvl = levelFinder(); // calcuating it for the tree display ;
}

// We use DownHeapify Function to delete values in Heap
void downHeapify(int arra[], int ind, int sizee)
{
    // bool flag1 = true;
    // bool flag2 = true;
    int child1 = (2 * ind) + 1; // this formula would tell the node of it child elements .
    int child2 = (2 * ind) + 2;

    // --------- ind = parent ; size = size of an array;

    if (child1 < sizee) // left child check ( exists or not )
    {
        if (child2 < sizee) // // right child check ( exists or not )
        {
            if (arra[ind] < arra[child1] && arra[ind] > arra[child2]) // if the parent is smaller then child1 and greater then child 2 so swap it with child 1 ;
            {
                swap(arra[child1], arra[ind]);
                downHeapify(arra, child1, sizee);
            }
            if (arra[ind] > arra[child1] && arra[ind] < arra[child2]) // if the parent is smaller then child 2 and greater then child 1 so swap it with child 2 ;
            {
                swap(arra[child2], arra[ind]);
                downHeapify(arra, child2, sizee);
            }
            if (arra[ind] < arra[child1] && arra[ind] < arra[child2]) // if the parent is smaller then both child then swap it with the greater child
            {
                if (arra[child1] < arra[child2]) // child 2 greater swap it with parent
                {
                    swap(arra[child2], arra[ind]);
                    downHeapify(arra, child2, sizee);
                }
                if (arra[child1] > arra[child2]) // child 1 greater swap it with parent
                {
                    swap(arra[child1], arra[ind]);
                    downHeapify(arra, child1, sizee);
                }
            }
        }
        if (arra[ind] < arra[child1]) // means second child doesn't exist ; and child 1 is greater then it parent;
        {

            swap(arra[child1], arra[ind]);
            downHeapify(arra, child1, sizee);
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
        cout << " ";
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
        // cout << "\n";
        return;
    }
    cout << "\n";
    exp++;
    ind++;
    count++;
    lvl--;
    treeDisplay(count, ind, true, lvl, exp);
    cout << "\n";
    return;
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

// Heap Sort ( after heap Sort the Heap loses its Structure, However the elements gets sorted)
void heapSort(int length)
{
    if (length <= 1)
    {
        return;
    }
    swap(arrayy[0], arrayy[length - 1]);
    length--;
    downHeapify(arrayy, 0, length);
    heapSort(length);
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
            heapSort(siz);
        }
        else if (input == 5)
        {
            flag = false;
            cout << "Program Exits ... ! ";
        }
    }
}