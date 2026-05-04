#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

stack<int> path;
stack<int> result;

struct Edge;
bool flag; // for isConnected

struct Vertex
{
    int data;
    Vertex *next;
    Edge *edgeList;
    bool flag = false;
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
        Vertex *point = Graph; // constraints so the same vertex will not be entered twice
        while (point != NULL)
        {
            if (point->data == data)
            {
                cout << "Vertice already exists with the same name\n";
                return;
            }
            point = point->next;
        }
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
    Edge *edgeCurr;
    curr = Graph;
    while (curr != NULL)
    {
        cout << curr->data;
        if (curr->edgeList != NULL)
        {
            edgeCurr = curr->edgeList;
            while (edgeCurr != NULL)
            {
                cout << " => " << edgeCurr->v->data;
                edgeCurr = edgeCurr->next;
            }
        }
        cout << "\n";
        curr = curr->next;
    }
    return;
}

void removeAllEdge(int v1);

void removeVertex(int data)
{

    if (Graph == NULL)
    {
        cout << "There are no Vertices \n";
        return;
    }

    // removeAllEdge(data);

    Vertex *temp;
    if (Graph->data == data)
    {
        temp = Graph;
        if (Graph->edgeList != NULL)
            removeAllEdge(Graph->data); // this will remove the vertex address from other vertice list
        // like if we delete  v1 so we check whether v1 is the outgoing vertice of any other if yes then delete them also
        Graph = Graph->next;
        delete (temp);
        cout << "Vertex " << data << " Deleted Successfully\n";
        return;
    }

    Vertex *prev = Graph; // to travers in other vertices
    Vertex *cur = Graph->next;
    while (cur != NULL)
    {
        if (cur->data == data)
        {
            temp = cur;
            prev->next = cur->next;
            if (cur->edgeList != NULL)
                removeAllEdge(cur->data); // this will remove the vertex address from other vertice list
            // like if we delete  v1 so we check whether v1 is the outgoing vertice of any other if yes then delete them also
            cur = cur->next;
            delete (temp);
            cout << "Vertex " << data << " Deleted Successfully\n";
            return;
        }
        cur = cur->next;
        prev = prev->next;
    }
    cout << "Vertex doesn't exists\n";
}

// it tells the vertex exists or not , this is also known as helper method
Vertex *checkVertexExistence(int v1)
{
    Vertex *curr = Graph;
    Vertex *ver = NULL; // to hold the address
    while (curr != NULL)
    {
        if (curr->data == v1)
        {
            ver = curr;
            return ver;
        }
        curr = curr->next;
    }
    return ver;
}

void addEdge(int v1, int v2)
{
    Vertex *curr = Graph; // pointer
    Vertex *ver1 = NULL;  // to hold the address
    Vertex *ver2 = NULL;
    ver1 = checkVertexExistence(v1);
    ver2 = checkVertexExistence(v2);
    if (ver1 == NULL)
    {
        cout << "Vertex " << v1 << " doesn't exists, can't draw edge";
        return;
    }
    if (ver2 == NULL)
    {
        cout << "Vertex " << v2 << " doesn't exists can't draw edge";
        return;
    }

    Edge *point = ver1->edgeList; // constraints ..
    while (point != NULL)
    {
        if (point->v->data == v2)
        {
            cout << "There is already an edge existing between these two vertices \n";
            return;
        }
        point = point->next;
    }

    Edge *temp = new Edge;
    temp->v = ver2;
    temp->next = NULL;

    if (ver1->edgeList == NULL)
    {
        ver1->edgeList = temp;
        cout << "Edge Drawn Successfully \n";
        return;
    }
    Edge *edgeCurr = ver1->edgeList;
    while (edgeCurr->next != NULL)
    {
        edgeCurr = edgeCurr->next;
    }
    edgeCurr->next = temp;

    cout << "Edge Drawn Successfully \n";
}

void removeEdge(int v1, int v2)
{
    Vertex *curr = Graph; // pointer
    Vertex *ver1 = NULL;  // to hold the address
    Vertex *ver2 = NULL;
    ver1 = checkVertexExistence(v1);
    ver2 = checkVertexExistence(v2);
    if (ver1 == NULL || ver1->edgeList == NULL)
    {
        cout << "Vertex " << v1 << " doesn't exists or there are no Edges of Vertex " << v1;
        return;
    }
    if (ver2 == NULL)
    {
        cout << "Vertex " << v2 << " doesn't exists can't draw edge";
        return;
    }

    // Edge *edgeCurr = ver1->edgeList;
    if (ver1->edgeList->v->data == v2)
    {
        Edge *temp = ver1->edgeList;
        ver1->edgeList = ver1->edgeList->next;
        // ver1->edgeList = edgeCurr;
        delete (temp);
        cout << v2 << " Deleted successfully\n";
        return;
    }

    Edge *edgeCurr = ver1->edgeList->next;
    Edge *edgePrev = ver1->edgeList;
    while (edgeCurr != NULL)
    {
        if (edgeCurr->v->data == v2)
        {
            edgePrev->next = edgeCurr->next;
            Edge *temp = edgeCurr;
            edgeCurr = edgeCurr->next;
            delete (temp);
            cout << v2 << " Deleted successfully\n";
            return;
        }
        edgeCurr = edgeCurr->next;
        edgePrev = edgePrev->next;
    }
    return;
}

// it will remove all the edges of the vertex which is deleted.
void removeAllEdge(int v1)
{
    Vertex *temp = Graph;

    while (temp != NULL)
    {
        Edge *curr = temp->edgeList;
        Edge *prev = NULL;

        while (curr != NULL)
        {
            if (curr->v->data == v1)
            {
                if (prev == NULL)
                    temp->edgeList = curr->next;
                else
                {
                    prev->next = curr->next;
                }

                Edge *del = curr;
                curr = curr->next;
                delete (del);
            }
            else
            {
                prev = curr;
                // prev = prev->next;
                curr = curr->next;
            }
        }

        temp = temp->next;
    }
}

int inDegree(int v1) // find inDegree, which means tells how many vertex terminal point is this
{
    if (Graph == NULL)
    {
        cout << "No Vertice exists\n";
        return 0;
    }
    Vertex *temp = Graph;
    Edge *edgeCurr;
    int count = 0;
    while (temp != NULL)
    {
        edgeCurr = temp->edgeList;
        if (edgeCurr == NULL)
        {
            temp = temp->next;
            continue;
        }
        while (edgeCurr != NULL)
        {
            if (edgeCurr->v->data == v1)
            {
                count++;
            }
            edgeCurr = edgeCurr->next;
        }
        temp = temp->next;
    }
    return count;
}

int outDegree(int v1) // find inDegree, which means tells how many vertex initial point is this
{
    if (Graph == NULL)
    {
        cout << "No Vertice exists\n";
        return 0;
    }
    Vertex *temp = Graph;
    Edge *edgeCurr;
    bool flag = false;
    int count = 0;
    while (temp != NULL)
    {
        if (temp->data == v1)
        {
            edgeCurr = temp->edgeList;
            flag = true;
            if (edgeCurr == NULL)
            {
                return count;
            }
            break;
        }
        temp = temp->next;
    }
    if (!flag)
    {
        cout << "Vertex doesn't exists\n";
        return count;
    }
    while (edgeCurr != NULL)
    {
        count++;
        edgeCurr = edgeCurr->next;
    }
    return count;
}

int degree() // total edges it works fine for undirected
{
    Vertex *temp = Graph;
    Edge *edgeCurr;
    int count = 0;
    while (temp != NULL)
    {
        edgeCurr = temp->edgeList;
        while (edgeCurr != NULL)
        {
            count++;
            edgeCurr = edgeCurr->next;
        }
        temp = temp->next;
    }
    return count;
}

bool isAdjacent(int v1, int v2, bool flag)
{
    Vertex *curr = Graph;
    Vertex *ver1 = NULL;
    Vertex *ver2 = NULL;
    ver1 = checkVertexExistence(v1);
    ver2 = checkVertexExistence(v2);
    // count++;

    if (ver1 == NULL || ver2 == NULL)
    {
        cout << "Vertex " << v1 << " or " << v2 << " doesn't exists";
        return false;
    }

    Edge *temp = ver1->edgeList;
    while (temp != NULL)
    {
        if (temp->v->data == v2)
        {
            return true;
        }
        temp = temp->next;
    }
    if (!flag)
    {
        return isAdjacent(v2, v1, true);
    }
    return false;
}

void neighbour(int v1)
{
    if (Graph == NULL)
    {
        cout << "No Vertice exists\n";
        return;
    }
    Vertex *temp = Graph; // for inDegree neighbours / terminal / incoming edges
    Edge *edgeCurr;
    bool flag = false, flag1 = false;
    while (temp != NULL)
    {
        if (temp->data == v1)
        {
            edgeCurr = temp->edgeList;
            flag = true;
            if (edgeCurr == NULL)
            {
                // cout << "No Neighbours";
                break;
                // return;
            }
            // break;
        }
        temp = temp->next;
    }

    temp = Graph; // for outDegree Neighbours / initial / outgoing edges
    Edge *edgePointer = edgeCurr;
    cout << "Neighbours of Vertex " << v1 << " are => : ";
    while (temp != NULL)
    {
        edgePointer = temp->edgeList;
        if (edgeCurr == NULL)
        {
            temp = temp->next;
            continue;
        }
        while (edgePointer != NULL)
        {
            if (edgePointer->v->data == v1)
            {
                flag1 = true;
                cout << " v" << temp->data << ", ";
            }
            edgePointer = edgePointer->next;
        }
        temp = temp->next;
    }

    if (!flag && !flag1)
    {
        cout << "none\n";
        return;
    }

    while (edgeCurr != NULL)
    {
        cout << "v" << edgeCurr->v->data << ", ";
        edgeCurr = edgeCurr->next;
    }
    return;
}

bool depthFirst(Vertex *v1, Vertex *v2)
{
    v1->flag = true;

    path.push(v1->data);

    if (v1 == v2)
    {

        stack<int> temp = path;
        while (!temp.empty())
        {
            result.push(temp.top());
            temp.pop();
        }
        return true;
    }

    Edge *edge = v1->edgeList;

    while (edge != NULL)
    {
        if (!edge->v->flag)
        {
            if (depthFirst(edge->v, v2))
                return true;
        }
        edge = edge->next;
    }

    path.pop();

    return false;
}

void resetFlag()
{
    Vertex *temp = Graph;
    while (temp != NULL)
    {
        temp->flag = false;
        temp = temp->next;
    }
}

bool pathFinder(int v1, int v2) // ..................
{
    Vertex *curr = Graph;
    Vertex *ver1 = NULL;
    Vertex *ver2 = NULL;
    ver1 = checkVertexExistence(v1);
    ver2 = checkVertexExistence(v2);
    // count++;

    if (ver1 == NULL || ver2 == NULL)
    {
        cout << "Vertex " << v1 << " or " << v2 << " doesn't exists";
        return false;
    }

    resetFlag();
    while (!path.empty())
        path.pop();
    while (!result.empty())
        result.pop();

    if (depthFirst(ver1, ver2) && flag == false)
    {
        cout << "Path: ";

        // print correct order
        while (!result.empty())
        {
            cout << result.top() << " ";
            result.pop();
        }
        return true;
    }
    else if (flag == false)
    {
        cout << "No path exists\n";
        return false;
    }
    if (depthFirst(ver1, ver2) && flag == true)
    {
        // cout << "Path: ";

        // // print correct order
        // while (!result.empty())
        // {
        //     cout << result.top() << " ";
        //     result.pop();
        // }
        return true;
    }
    else if (flag == true)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool isConnected(Vertex *v1, Vertex *v2, int totalVertices, int count, int total)
{
    bool flag1;
    flag1 = pathFinder(v1->data, v2->data);
    if (flag1 == false)
    {
        count++;
        // Vertex *temp = v1;
        // v1 = v2;
        // v2 = temp;
        isConnected(v2, v1, totalVertices, count, total);
        if (count == 2)
        {
            return false;
        }
    }

    Vertex *temp = v1;
    v1 = v2;
    v2 = temp;
    v2 = v2->next;
    total++;
    if (total != totalVertices)
    {
        isConnected(v1, v2, totalVertices, 0, total);
    }
    else
    {
        return true;
    }
}

bool isCycle(Vertex *v1, Vertex *v2, int count, int vertice)
{
    count++;
    bool flag = false;
    flag = pathFinder(v1->data, v2->data);
    if (!flag && count < vertice)
    {
        v1 = v1->next;
        v2 = v2->next;
        return isCycle(v1, v2, count, vertice);
    }
    if (count == vertice)
    {
        return false;
    }
    return false;
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

        if (choice == 1) // done
        {
            int data;
            cout << "Enter Vertex in numbers : \n";
            cin >> data;
            addVertex(Graph, data);
        }
        else if (choice == 2) // done
        {
            int value;
            cout << "Enter Vertex Number you want to delete ";
            cin >> value;
            removeVertex(value);
        }
        else if (choice == 3) // done
        {
            int v1, v2;
            cout << "Enter Vertex 1 : ";
            cin >> v1;
            cout << "Enter Vertex 2 : ";
            cin >> v2;
            addEdge(v1, v2);
        }
        else if (choice == 4) // done
        {
            int v1, v2;
            cout << "To Delete Edge \n";
            cout << "Enter Vertex 1 : ";
            cin >> v1;
            cout << "Enter Vertex 2 : ";
            cin >> v2;
            removeEdge(v1, v2);
        }
        else if (choice == 5) // done
        {
            int sumDegree = degree();
            cout << "The Degree of the Graph is " << sumDegree;
        }
        else if (choice == 6) // done
        {
            int v1;
            cout << "Enter Vertex to find its inDegree : ";
            cin >> v1;
            int degree = inDegree(v1);
            cout << "Indegree of Vertex " << v1 << " is => " << degree << "\n";
        }
        else if (choice == 7) // done
        {
            int v1;
            cout << "Enter Vertex to find its outDegree : ";
            cin >> v1;
            int degree = outDegree(v1);
            cout << "Outdegree of Vertex " << v1 << " is => " << degree << "\n";
        }
        else if (choice == 8) // done
        {
            int v1, v2;
            flag = false; // for connection purpose
            cout << "To Find Path \n";
            cout << "Enter Vertex 1 : ";
            cin >> v1;
            cout << "Enter Vertex 2 : ";
            cin >> v2;
            pathFinder(v1, v2);
        }
        else if (choice == 9) // done
        {
            flag = false;
            int value;
            Vertex *temp = Graph;
            cout << "Enter total no. of vertices ";
            cin >> value;
            bool check = isCycle(temp, temp, 0, value);
            cout << ((check) ? "Cyclic\n" : "Not Connected\n");
        }
        else if (choice == 10) // done
        {
            flag = true;
            int value;
            Vertex *temp = Graph;
            Vertex *temp1 = Graph->next;
            cout << "Enter total no. of vertices ";
            cin >> value;
            bool yes = isConnected(temp, temp1, value, 0, 1);
            cout << ((yes) ? "Connected\n" : "Not Connected\n");
        }
        else if (choice == 11) // done
        {
            int v1, v2;
            cout << "To Find Ajacency \n";
            cout << "Enter Vertex 1 : ";
            cin >> v1;
            cout << "Enter Vertex 2 : ";
            cin >> v2;
            cout << (isAdjacent(v1, v2, false) ? "Vertices are adjacent\n" : "Not Adjacent\n");
        }
        else if (choice == 12) // done
        {
            int value;
            cout << "Enter Vertex of which you find Neighbour : ";
            cin >> value;
            neighbour(value);
        }
        else if (choice == 13)
        {
            // Search Vertex
        }
        else if (choice == 14) // done
        {
            display();
        }
        else if (choice == 0) // done
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