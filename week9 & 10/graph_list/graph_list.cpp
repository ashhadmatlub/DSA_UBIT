#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Edge;

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

Vertex *V_list;

void insert_Vertex(int vertex)
{
    Vertex *temp;
    temp = (Vertex *)malloc(sizeof(Vertex));
    temp->data = vertex;
    temp->next = NULL;
    temp->Edge_List = NULL;

    if (V_list == NULL)
    {
        V_list = temp;
    }
}

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