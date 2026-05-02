#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Edge;

struct Vertex
{
    int data;
    Vertex *next;
    Edge *edgeList;
} *Graph = NULL;

struct Edge
{
    Vertex *v;
    Edge *next;
};

void addVertex(Vertex *&curr, int data)
{
    if (curr == NULL)
    {
        Vertex *temp = new Vertex;
        temp->data = data;
        temp->next = NULL;
        temp->edgeList = NULL;
        if (Graph == NULL)
        {
            Graph = temp;
            return;
        }
        curr = temp;
        return;
    }
    addVertex(curr->next, data);
}

void display()
{
    Vertex *curr;
    curr = Graph;
    while (curr != NULL)
    {
        cout << curr->data << "\n";
        curr = curr->next;
    }
    return;
}

void removeVertex(int data)
{

    if (Graph == NULL)
    {
        cout << "There are no Vertices \n";
        return;
    }
    Vertex *temp;
    if (Graph->data == data)
    {
        temp = Graph;
        Graph = Graph->next;
        delete (temp);
        cout << data << "Deleted Successfully\n";
        return;
    }
    Vertex *prev = Graph;
    Vertex *cur = Graph->next;
    while (cur != NULL)
    {
        if (cur->data == data)
        {
            temp = cur;
            prev->next = cur->next;
            cur = cur->next;
            delete (temp);
            cout << data << "Deleted Successfully \n";
            return;
        }
        cur = cur->next;
        prev = prev->next;
    }
    cout << "Vertex doesn't exists\n";
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\n===== GRAPH =====\n";
        cout << "1. Add Vertex\n2. Remove Vertex\n3. Add Edge\n4. Remove Edge\n5. Find Degree\n6. Find In-Degree\n7. Find Out-Degree\n8. Find Path\n9. Check Cyclic\n10. Check Connected\n11. Check Adjacent\n12. Find Neighbours\n13. Search Vertex\n14. Display Graph\n0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int data;
            cout << "Enter Vertex in numbers : \n";
            cin >> data;
            addVertex(Graph, data);
            display();
        }
        else if (choice == 2)
        {
            int value;
            cout << "Enter Vertex Number you want to delete ";
            cin >> value;
            removeVertex(value);
            display();
        }
        else if (choice == 3)
        {
            // Add Edge
        }
        else if (choice == 4)
        {
            // Remove Edge
        }
        else if (choice == 5)
        {
            // Find Degree
        }
        else if (choice == 6)
        {
            // Find In-Degree
        }
        else if (choice == 7)
        {
            // Find Out-Degree
        }
        else if (choice == 8)
        {
            // Find Path
        }
        else if (choice == 9)
        {
            // Check Cyclic
        }
        else if (choice == 10)
        {
            // Check Connected
        }
        else if (choice == 11)
        {
            // Check Adjacent
        }
        else if (choice == 12)
        {
            // Find Neighbours
        }
        else if (choice == 13)
        {
            // Search Vertex
        }
        else if (choice == 14)
        {
            // Display Graph
        }
        else if (choice == 0)
        {
            cout << "Exiting program...\n";
            break;
        }
        else
        {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}