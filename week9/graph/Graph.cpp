#include <iostream>
using namespace std;

// undirected graph
// Graph Operations => Degree of a vertex , Sum of Degree , Path b/w two vertices , Connected or not , Acyclic or cyclic

const int maxx = 100; // Globally Declare array size

// ploting the value in graph
void plot_Graph(int value, int (*arr)[maxx])
{
    int suc, j;
    int suc_Value;
    // int arr[value][value];

    // TO FILL ARRAY WITH 0
    for (int i = 0; i < value; i++)
    {
        for (int c = 0; c < value; c++)
        {
            arr[i][c] = 0;
        }
    }

    for (int i = 0; i < value; i++) // it will runs n/value times
    {
        do // i did this because , vertices successors must be <= no.of vertices
        {
            cout << "Vertices successors must be <= no.of vertices \n";
            cout << "How many successors are of vertice ? : " << (i + 1) << " : ";
            cin >> suc;
        } while (suc > value);
        int arr1[suc];
        j = 0;
        while (j < suc) // to ask from the user how many successors are there
        {
            cout << "Enter successor of vertice : " << (i + 1) << " : ";
            cin >> suc_Value;
            if (suc_Value <= value && suc_Value >= 0) // constraints ( that the value of vertice must be inside the vertice like the vertice which doesnt exists can't be added )
            {
                arr1[j] = suc_Value;
                j++;
            }
            else
            {
                cout << "Vertice doesnt exists \n";
                continue;
            }
        }
        int len = sizeof(arr1) / sizeof(arr1[0]); // to store value
        for (int k = 0; k < len; k++)
        {
            int val;
            val = arr1[k];
            arr[i][val - 1] = 1;
        }
    }
}

// display
void display(int value, int (*arr)[maxx])
{
    for (int i = 0; i < value; i++)
    {
        for (int k = 0; k < value; k++)
        {
            cout << arr[i][k];
        }
        cout << "\n";
    }
}

// it will give the degree of a vertex.
int degree_Finder(int value, int vertices, int (*arr)[maxx]) // value means the loop will run this times , verices tells to find the value of that vertice ;
{
    if (vertices > value)
    {
        cout << "Vertices doesnt exists ";
        return 0;
    }
    int count = 0;
    vertices -= 1; // so we can use it in indexing ;
    for (int i = 0; i < value; i++)
    {
        int deg = arr[vertices][i];
        if (deg == 1)
        {
            count++;
        }
    }
    return count;
}

// sum of degree
void degree_Sum(int value, int (*arr)[maxx])
{
    int count = 0;
    for (int i = 0; i < value; i++)
    {
        for (int k = 0; k < value; k++)
        {
            cout << arr[i][k];
            if (arr[i][k] == 1)
            {
                count++;
            }
        }
        cout << "\n";
    }
    cout << "Sum of Degree is : " << count << " \n ";
}

// connected or not // under process
void connection(int value, int (*arr)[maxx])
{
    int i = 0, j = 1;
    bool flag = true;
    int arra[value - 1];
    for (int ind = 0; ind < (value - 1); ind++)
    {
        arra[ind] = 1;
    }
    while (i < value && j < value)
    {
        if (arr[i][j] == 1)
        {
            arra[j - 1] = 0;
            j++;
            if (i > 0)
                i--;
        }
        else
        {
            i++;
        }
    }
    for (int n = 0; n < (value - 1); n++)
    {
        if (arra[n] == 1)
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "Graph is connected \n";
    else
        cout << "Graph isn't connected \n";
}

int main()
{
    int input, vertices;
    bool flag = true;

    cout << "Enter no of vertices to plot on graph : ";
    cin >> vertices;

    if (vertices > 0 && vertices < 100)
    {
        int arra[100][100];
        plot_Graph(vertices, arra);
        while (flag)
        {
            cout << "Enter => : 1 To Find Degree of a vertex \n 2 : Find Sum of Degree \n 3 : To find path b/w two vertices \n 4 : To Find connected or not \n 5 : Cyclic or Acyclic \n 6 : To Display \n 7 : Exit \n";
            cin >> input;
            if (input == 1)
            {
                int vertex;
                cout << "Enter Vertex to find its degree : ";
                cin >> vertex;
                int degree = degree_Finder(vertices, vertex, arra);
                cout << "The Degree of Vertex " << vertex << " is : " << degree << "\n";
            }
            else if (input == 2)
            {
                degree_Sum(vertices, arra);
            }
            else if (input == 4)
            {
                connection(vertices, arra);
            }
            else if (input == 6)
            {
                display(vertices, arra);
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