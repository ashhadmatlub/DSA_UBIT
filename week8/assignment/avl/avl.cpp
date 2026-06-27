#include <bits/stdc++.h>
using namespace std;

struct AVLNode
{
    int height, data;
    AVLNode *right;
    AVLNode *left;
} *treeHead = nullptr;

int heightCalculator(AVLNode *curr)
{
    if (curr->right == nullptr && curr->left == nullptr)
    {
        return 0;
    }
    if (curr->right == nullptr)
    {
        return (curr->left->height) + 1;
    }
    if (curr->left == nullptr)
    {
        return (curr->right->height) + 1;
    }

    return (max(curr->right->height, curr->left->height) + 1);
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
    temp2->height = heightCalculator(temp2);
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
    temp2->height = heightCalculator(temp2);
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
        if ((curr->right->height - curr->left->height) > 1)
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
        if ((curr->left->height - curr->right->height) < 1)
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

int main()
{
}