#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

struct AVLNode
{
    int height, data;
    AVLNode *right;
    AVLNode *left;
} *treeHead = nullptr;

int nodeHeight(AVLNode *node)
{
    if (node == nullptr)
        return -1;
    return node->height;
}

int heightCalculator(AVLNode *curr)
{
    if (curr == nullptr)
        return -1;

    return max(nodeHeight(curr->left), nodeHeight(curr->right)) + 1;
}

AVLNode *rotateLeft(AVLNode *curr) // means tree is growing from the right side so we rotate it to the left
{
    AVLNode *temp = curr;
    curr = curr->right;

    AVLNode *temp2 = curr->left;
    temp->right = temp2;

    curr->left = temp;

    temp->height = heightCalculator(temp);
    curr->height = heightCalculator(curr);
    return curr;
}

AVLNode *rotateRight(AVLNode *curr) // means tree is growing from the left side, so we rotate it to the right.
{
    AVLNode *temp = curr;
    curr = curr->left;

    AVLNode *temp2 = curr->right;
    temp->left = temp2;
    curr->right = temp;

    temp->height = heightCalculator(temp);
    curr->height = heightCalculator(curr);

    return curr;
}

AVLNode *rotateLeftRight(AVLNode *curr)
{
    curr->left = rotateLeft(curr->left);
    curr = rotateRight(curr);

    curr->height = heightCalculator(curr);
    return curr;
}

AVLNode *rotateRightLeft(AVLNode *curr)
{
    curr->right = rotateRight(curr->right);
    curr = rotateLeft(curr);

    curr->height = heightCalculator(curr);
    return curr;
}

AVLNode *insertAVL(AVLNode *curr, int value)
{
    if (curr == nullptr)
    {
        AVLNode *temp = new AVLNode;
        temp->data = value;
        temp->right = nullptr;
        temp->left = nullptr;
        temp->height = 0;
        if (treeHead == nullptr)
        {
            treeHead = temp;
        }
        return temp;
    }
    if (value > curr->data)
    {
        curr->right = insertAVL(curr->right, value);
        curr->height = heightCalculator(curr);
        if ((nodeHeight(curr->right) - nodeHeight(curr->left)) > 1)
        {
            if (value > curr->right->data)
            {
                curr = rotateLeft(curr);
            }
            else
            {
                curr = rotateRightLeft(curr);
            }
        }
    }
    else if (value < curr->data)
    {
        curr->left = insertAVL(curr->left, value);
        curr->height = heightCalculator(curr);
        if ((nodeHeight(curr->left) - nodeHeight(curr->right)) > 1)
        {
            if (value < curr->left->data)
            {
                curr = rotateRight(curr);
            }
            else
            {
                curr = rotateLeftRight(curr);
            }
        }
    }
    else
    {
        cout << "Can't insert Duplicate Value ";
    }

    curr->height = heightCalculator(curr);
    return curr;
}

int getHeight(AVLNode *node)
{
    if (node == nullptr)
        return 0;
    return max(getHeight(node->left), getHeight(node->right)) + 1;
}

void printLevel(AVLNode *root, int level)
{
    if (level == 1)
    {
        if (root)
            cout << setw(4) << root->data;
        else
            cout << setw(4) << " ";
    }
    else
    {
        if (root)
        {
            printLevel(root->left, level - 1);
            printLevel(root->right, level - 1);
        }
        else
        {
            printLevel(nullptr, level - 1);
            printLevel(nullptr, level - 1);
        }
    }
}

void displayTree(AVLNode *root)
{
    int h = getHeight(root);

    for (int i = 1; i <= h; i++)
    {
        int space = (1 << (h - i + 1));

        for (int j = 0; j < space / 2; j++)
            cout << " ";

        printLevel(root, i);

        cout << "\n\n";
    }
}

void PreOrder_Traversal(AVLNode *curr)
{
    if (curr != NULL)
    {
        cout << " --> " << curr->data;
        PreOrder_Traversal(curr->left);
        PreOrder_Traversal(curr->right);
        cout << "\n";
    }
}
void InOrder_Traversal(AVLNode *curr)
{
    if (curr != NULL)
    {
        InOrder_Traversal(curr->left);
        cout << " --> " << curr->data;
        InOrder_Traversal(curr->right);
        cout << "\n";
    }
}
void PostOrder_Traversal(AVLNode *curr)
{
    if (curr != NULL)
    {
        PostOrder_Traversal(curr->left);
        PostOrder_Traversal(curr->right);
        cout << " --> " << curr->data;
        cout << "\n";
    }
}

AVLNode *search(AVLNode *curr, int value)
{
    if (curr == nullptr)
    {
        cout << "Value not Found \n";
        return curr;
    }
    if (value > curr->data)
    {
        curr->right = search(curr->right, value);
        return curr;
    }
    if (value < curr->data)
    {
        curr->left = search(curr->left, value);
        return curr;
    }
    else
    {
        cout << "Value found " << curr->data << "\n";
        return curr;
    }
}

AVLNode *del(AVLNode *curr, int value) // left
{
    if (curr == nullptr)
    {
        cout << "Not Found \n";
        return curr;
    }

    if (value > curr->data)
    {
        curr->right = del(curr->right, value);
        return curr;
    }
    if (value < curr->data)
    {
        curr->left = del(curr->left, value);
        return curr;
    }
    else
    {
        if (curr->left == nullptr && curr->right == nullptr)
        {
            delete (curr);
            cout << "Value Deleted successfully \n";
        }
        else if (curr->right == nullptr)
        {
            AVLNode *temp = curr;
            curr = curr->left;
            delete (temp);
            cout << "Value Deleted successfully \n";
        }
        else
        {
            AVLNode *temp = curr;
            curr = curr->right;
            AVLNode *temp3 = curr;
            while (curr->left != nullptr)
            {
                curr = curr->left;
            }
            if (curr->right != nullptr)
            {
                AVLNode *temp2 = curr->right;
                temp = temp2;
                curr = temp;
                while (curr->right != nullptr)
                {
                    curr = curr->right;
                }
                curr->right = temp3;
                cout << "Value Deleted successfully \n";
                return curr;
            }
            else
            {
                temp = curr;
                curr->right = temp3;
                cout << "Value Deleted successfully \n";
                return curr;
            }
        }
        return curr;
    }
}

int main()
{
    int choice;
    bool flag = true;
    while (flag)
    {
        cout << "Enter =>  1 to Insert , 2 to Display Tree Structure , 3 To Display, 4 To Search , 5 To Delete, 6 to Exit : \n";
        cin >> choice;

        if (choice == 1)
        {
            int value;
            cout << "Enter value to insert \n";
            cin >> value;

            treeHead = insertAVL(treeHead, value);
        }
        else if (choice == 2)
        {
            displayTree(treeHead);
        }
        else if (choice == 3)
        {
            int value;
            cout << "Which Traversal you want ";
            cout << "Enter 1 For PreOrder, 2 For InOrder, 3 For PostOrder \n";
            cin >> value;

            if (value == 1)
            {
                PreOrder_Traversal(treeHead);
            }
            else if (value == 2)
            {
                InOrder_Traversal(treeHead);
            }
            else if (value == 3)
            {
                PostOrder_Traversal(treeHead);
            }
            else
            {
                cout << "Invalid Command \n";
            }
        }
        else if (choice == 4)
        {
            int value;
            cout << "Search => ";
            cin >> value;
            search(treeHead, value);
        }
        else if (choice == 5)
        {
            int value;
            cout << "Enter value to Delete \n";
            cin >> value;
            del(treeHead, value);
        }
        else if (choice == 6)
        {
            flag = false;
            cout << "Program Exits ... ! ";
        }
        else
        {
            cout << "Invalid command ";
        }
    }
}