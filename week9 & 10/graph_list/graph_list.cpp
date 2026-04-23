#include <iostream>
using namespace std;

struct Vertex
{
    int data;
    bool visited = false;
    Vertex *next;
    Edge *Edge_List;
};

struct Edge
{
    Edge *next;
    Vertex *V;
};

int main()
{
    int input;
    bool flag = true;
    while (flag)
    {
        cout << "Enter => 1: To Insert, 2:  , 3: Find Degree of a vertex, 4 : To Find Path, 5: To Display , 6: To Exit";
        cin >> input;
        if (input == 1)
        {
        }
        else if (input == 6)
        {
            flag = false;
            cout << "Program Exits\n";
        }
        else
        {
            cout << "Invalid input ";
        }
    }
}