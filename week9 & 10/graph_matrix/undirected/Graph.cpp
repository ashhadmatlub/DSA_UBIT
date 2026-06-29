#include <iostream>
using namespace std;

// undirected graph
// Graph Operations => Degree of a vertex , Sum of Degree , isAdjacent , Neighbour

const int maxx = 100; // Globally Declared array size

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
            cout << "How many successors are of vertice ? : " << (i + 1) << " : "; // means tell the number of node is been pointed by this node .
            cin >> suc;
        } while (suc > value);
        int arr1[suc];
        j = 0;
        while (j < suc) // to ask from the user how many successors are there/ means which nodes are been pointed by this node
        {
            cout << "Enter successor(the current vertices pointing towards) of vertice : " << (i + 1) << " : ";
            cin >> suc_Value;
            if (suc_Value <= value && suc_Value > 0) // constraints ( that the value of vertice must be inside the vertice like the vertice which doesnt exists can't be added )
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
        cout << "Vertices doesnt exists so";
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
            // cout << arr[i][k];
            if (arr[i][k] == 1)
            {
                count++;
            }
        }
        // cout << "\n";
    }
    cout << "Sum of Degree is : " << count << " \n ";
}

// connected or not // under process
// void connection(int value, int (*arr)[maxx])
//  to check wheather we can start with a vertice and come back to it without repition of edges
// bool isCyclic(int value, int (*arr)[maxx])
// {
//     if (value <= 1)
//     {
//         cout << "Since there is only 1 vertex, hence no cycle exists";
//         return false;
//     }
//     for two vertices
//     if (value == 2)
//     {
//         int i = 0, j = 1;
//         while (i < 2)
//         {
//             if (arr[i][j] == 1)
//             {
//                 i++, j--;
//             }
//         }

//     for more multiple vertices
//     }
//}

// adjacent vertice
bool isAdjacent(int (*arr)[maxx], int v1, int v2)
{
    if (arr[v1 - 1][v2 - 1] == 1)
    {
        return true;
    }
    return false;
}

// neighbour
int neighbour(int (*arr)[maxx], int vertex, int idx, int totalVertices)
{
    int count = 0;
    if (idx < totalVertices)
    {
        if (arr[vertex - 1][idx] == 1)
        {
            count++;
            cout << "vertex " << (idx + 1) << "\n";
        }
        neighbour(arr, vertex, idx += 1, totalVertices);
    }
    return count;
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
            cout << "Enter => : 1 To Find Degree of a vertex \n 2 : Find Sum of Degree \n 3 : To Display \n 4 : To Find Adjacent \n 5 : To Find Neighbour \n 6 : Exit \n";
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
            else if (input == 3)
            {
                display(vertices, arra);
            }
            else if (input == 4)
            {
                int v1, v2;
                do
                {
                    cout << "Enter Vertex 1, vertex must lie in a range from 1 to " << vertices << "\n";
                    cin >> v1;
                } while (v1 > vertices || v1 < 1);
                do
                {
                    cout << "Enter Vertex 2, vertex must lie in a range from 1 to " << vertices << "\n";
                    cin >> v2;
                } while (v2 > vertices || v2 < 1);

                cout << (isAdjacent(arra, v1, v2) ? "Vertices are adjacent\n" : "Not Adjacent\n");
            }
            else if (input == 5)
            {
                int vertex;
                cout << "Enter Vertex of which you find neighbours ";
                cin >> vertex;
                if (vertex > vertices || vertex < 1)
                {
                    cout << "Vertex doesn't exists ";
                }
                cout << "The Neighbour of Vertex " << vertex << " are : \n";
                int exists = neighbour(arra, vertex, 0, vertices);
                if (exists == 0)
                {
                    cout << 0 << "\n";
                }
            }
            else if (input == 6)
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