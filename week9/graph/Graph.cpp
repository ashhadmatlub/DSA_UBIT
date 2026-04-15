#include <iostream>
using namespace std;

// Graph Operations => Degree of a vertex , Sum of Degree , Path b/w two vertices , Connected or not , Acyclic or cyclic

// ploting the value in graph
void plot_Graph(int value)
{
    int times = value;
    int suc, j;
    value -= 1;
    int suc_Value;
    int arr[value][value];
    for (int i = 0; i < times; i++) // it will runs n/value times
    {
        cout << "How many successors are of vertice ? : " << (i + 1) << " : ";
        cin >> suc;
        int arr1[suc];
        j = 0;
        while (j < suc) // to ask from the user how many successors are there
        {
            cout << "Enter successor of vertice : " << (i + 1) << " ";
            cin >> suc_Value;
            arr1[j] = suc_Value;
            j++;
        }
        int len = sizeof(arr1) / sizeof(arr1[0]); // to store value
        for (int k = 0; k < len; k++)
        {
            int val;
            val = arr1[k];
            arr[i][val - 1] = 1;
        }
    }

    // to display
    int m = value;
    for (int i = 0; i < value; i++)
    {
        for (int k = 0; k < m; k++)
        {
            cout << arr[i][k];
        }
        cout << "\n";
    }
}

// display
// void display(int ver)
// {
// int j = ver;
// for (int i = 0; i < ver; i++)
// {
//     for (int k = 0; k < j; k++)
//     {
//         cout << arr2[i][k];
//     }
//     cout << "\n";
// }
// }

int main()
{
    int input, vertices;
    bool flag = true;

    cout << "Enter no of vertices to start the program : ";
    cin >> vertices;

    if (vertices > 0)
    {
        plot_Graph(vertices);
        // display(vertices);
        while (flag)
        {
            cout << "Enter => : 1 To Find Degree of a vertex , 2 : Find Sum of Degree , 3 : To find path b/w two vertices , 4 : To Find connected or not , 5 : Cyclic or Acyclic, 6 : To Display , 7 : Exit";
            cin >> input;
            if (input == 1)
            {
            }
            else if (input == 7)
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
    else
    {
        cout << "Graph cant exist on as there are no vertices ";
        return 0;
    }
}