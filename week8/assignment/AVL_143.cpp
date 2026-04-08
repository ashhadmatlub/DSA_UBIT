#include <bits/stdc++.h>
using namespace std;

class AVLNode
{
    int element;
    AVLNode *Left;
    AVLNode *Right;
    int height;

public:
    int HeightCalculator(AVLNode *curr)
    {
        if (curr->Left == nullptr && curr->Right == nullptr)
            return 0;

        else if (curr->Left == nullptr)
        {
            return (curr->Right->height) + 1;
        }
        else if (curr->Right == nullptr)
        {
            return (curr->Left->height) + 1;
        }
        else
        {
            return (max(curr->Right->height, curr->Left->height)) + 1;
        }
    }
    int BalenceFactor(AVLNode *curr)
    {
        if (curr->Left == nullptr && curr->Right == nullptr)
            return 0;

        else if (curr->Right == nullptr)
            return (curr->Left->height) + 1;

        else if (curr->Left == nullptr)
            return ((curr->Right->height) + 1) * (-1);

        else
            return (curr->Left->height) - (curr->Right->height);
    }

    AVLNode *InsertAVL(AVLNode *curr, int value)
    {
        if (curr == nullptr)
        {
            AVLNode *temp = new AVLNode;
            temp->element = value;
            temp->Left = nullptr;
            temp->Right = nullptr;
            temp->height = 0;
            return temp;
        }
        else if (value < curr->element)
        {
            curr->Left = InsertAVL(curr->Left, value);

            if (BalenceFactor(curr) >= 2)
            {
                if (value < curr->Left->element)
                    curr = RotateRight(curr);

                else
                    curr = RotateLeftRight(curr);
            }
        }

        else
        {
            curr->Right = InsertAVL(curr->Right, value);

            if (BalenceFactor(curr) <= -2)
            {
                if (value > curr->Right->element)
                    curr = RotateLeft(curr);

                else
                    curr = RotateRightLeft(curr);
            }
        }
        curr->height = HeightCalculator(curr);
        return curr;
    }

    AVLNode *RotateLeft(AVLNode *curr)
    {
        AVLNode *Temp = curr;
        curr = curr->Right;
        // if(curr -> Left != nullptr)
        //{
        AVLNode *Temp2 = curr->Left;
        Temp->Right = Temp2;
        //}
        curr->Left = Temp;
        Temp->height = HeightCalculator(Temp);
        curr->height = HeightCalculator(curr);

        return curr;
    }

    AVLNode *RotateRight(AVLNode *curr)
    {
        AVLNode *Temp = curr;
        curr = curr->Left;
        // if(curr -> Right != nullptr)
        // {
        AVLNode *Temp2 = curr->Right;
        Temp->Left = Temp2;
        //}
        curr->Right = Temp;
        Temp->height = HeightCalculator(Temp);
        curr->height = HeightCalculator(curr);

        return curr;
    }

    AVLNode *RotateLeftRight(AVLNode *curr)
    {
        curr->Left = RotateLeft(curr->Left);
        curr = RotateRight(curr);

        curr->height = HeightCalculator(curr);
        return curr;
    }

    AVLNode *RotateRightLeft(AVLNode *curr)
    {
        curr->Right = RotateRight(curr->Right);
        curr = RotateLeft(curr);

        curr->height = HeightCalculator(curr);
        return curr;
    }

    AVLNode *Search(AVLNode *curr, int value)
    {
        if (curr == nullptr)
        {
            cout << "Element was not found in the tree.\n";
            return NULL;
        }
        else if (curr->element == value)
        {
            cout << "The Element was found" << endl;
            return curr;
        }
        else if (value < curr->element)
        {
            return Search(curr->Left, value);
        }
        else if (value > curr->element)
        {
            return Search(curr->Right, value);
        }
    }

    AVLNode *Delete(AVLNode *curr, int value)
    {
        AVLNode *temp = new AVLNode;
        if (curr == NULL)
        {
            cout << "Element was not found in the tree.\n";
            return NULL;
        }
        else if (value > curr->element)
        {
            curr->Right = Delete(curr->Right, value);

            curr->height = HeightCalculator(curr);
        }
        else if (value < curr->element)
        {
            curr->Left = Delete(curr->Left, value);

            curr->height = HeightCalculator(curr);
        }

        else
        {

            if (curr->Left == nullptr && curr->Right == nullptr)
            {
                delete curr;
                curr = nullptr;

                cout << "Element Deleted Successfully.\n";
                return nullptr;
            }
            else if (curr->Left == nullptr)
            {

                temp = curr->Right;
                delete curr;
                return temp;
            }
            else if (curr->Right == nullptr)
            {

                temp = curr->Left;
                delete curr;
                return temp;
            }
            else
            {
                AVLNode *Right_Child_Min = curr->Right;
                while (Right_Child_Min->Left != nullptr)
                {
                    Right_Child_Min = Right_Child_Min->Left;
                }
                curr->element = Right_Child_Min->element;
                curr->Right = Delete(curr->Right, Right_Child_Min->element);
                curr->height = HeightCalculator(curr);
            }
        }
        if (BalenceFactor(curr) == 2)
        {
            if (BalenceFactor(curr->Left) >= 0)
                curr = RotateRight(curr);

            else
                curr = RotateLeftRight(curr);
        }
        if (BalenceFactor(curr) == -2)
        {
            if (BalenceFactor(curr->Right) <= 0)
                curr = RotateLeft(curr);

            else
                curr = RotateRightLeft(curr);
        }
        return curr;
    }

    void PreOrder_Traversal(AVLNode *curr)
    {
        if (curr != NULL)
        {
            cout << " --> " << curr->element;
            PreOrder_Traversal(curr->Left);
            PreOrder_Traversal(curr->Right);
        }
    }
    void InOrder_Traversal(AVLNode *curr)
    {
        if (curr != NULL)
        {
            InOrder_Traversal(curr->Left);
            cout << " --> " << curr->element;
            InOrder_Traversal(curr->Right);
        }
    }
    void PostOrder_Traversal(AVLNode *curr)
    {
        if (curr != NULL)
        {
            PostOrder_Traversal(curr->Left);
            PostOrder_Traversal(curr->Right);
            cout << " --> " << curr->element;
        }
    }
    void printTree(AVLNode *curr, int space = 0, int indent = 5)
    {
        if (curr == nullptr)
            return;

        space += indent;
        printTree(curr->Right, space);
        cout << endl;
        for (int i = indent; i < space; i++)
            cout << " ";

        cout << curr->element << "\n";
        // Print left child
        printTree(curr->Left, space);
    }
};

int main()
{

    AVLNode tree;
    AVLNode *root = nullptr;
    int n, value, t = 0;
    bool flag = false;

    // Node node;

    cout << "Enter 1 to insert" << endl;
    cout << "Enter 2 to search" << endl;
    cout << "Enter 3 to delete" << endl;
    cout << "Enter 4 to display" << endl;
    cout << "Enter 5 to display in a tree stucture " << endl;
    cout << "Enter 6 to exit " << endl;
    while (!flag)
    {
        cout << "Enter Choice :";
        cin >> t;

        if (t == 1)
        {

            cout << "Enter Value:";
            cin >> value;
            cout << endl;

            root = tree.InsertAVL(root, value);
        }
        else if (t == 2)
        {
            int val;
            cout << "Enter what to search ";
            cin >> val;

            if (tree.Search(root, val) == NULL)
            {
                cout << "List is empty or no such value found" << endl;
                // return 0;
            }
        }
        else if (t == 3)
        {
            int val;
            cout << "Enter what to delete ";
            cin >> val;
            root = tree.Delete(root, val);
        }
        else if (t == 4)
        {
            // Display
            int choice = 0;
            cout << "Enter which traversal to use ";
            cout << "1 for Pre Order , 2 for In Order, 3 for Post Order";
            cin >> choice;
            switch (choice)
            {
            case 1:
                tree.PreOrder_Traversal(root);
                cout << endl;
                break;
            case 2:
                tree.InOrder_Traversal(root);
                cout << endl;
                break;

            case 3:
                tree.PostOrder_Traversal(root);
                cout << endl;
                break;

            default:
                cout << "Invalid input!";
                break;
            }
        }
        else if (t == 5)
        {
            cout << "Here is the data in a tree Structure.\n";
            tree.printTree(root);
        }
        else if (t == 6)
        {
            exit(flag);
        }
        else
        {
            cout << "Invalid Command check again" << endl;
        }
    }
}