#include <bits/stdc++.h>
using namespace std;

struct AVLNode
{
    int height, data;
    AVLNode *right;
    AVLNode *left;
};

AVLNode *insertAVL(AVLNode *curr, int value)
{
    if (curr == nullptr)
    {
        AVLNode *temp = new AVLNode;
        temp->data = value;
        temp->right = nullptr;
        temp->left = nullptr;
        temp->height = 0;
        return temp;
    }
    if (value < curr->data)
    {
        curr->left = insertAVL(curr->left, value);
        if ((curr->left->height - curr->right->height) == 2)
        {
            if (value < curr->left->data)
            {
                // rotate right
            }
            else
            {
                // rotate left
            }
        }
    }
    else if (value > curr->data)
    {
        curr->right = insertAVL(curr->right, value);
        if ((curr->right->height - curr->left->height) == 2)
        {
            if (value < curr->right->data)
            {
                // rotate left
            }
            else
            {
                // rotate right
            }
        }
    }
    else
    {
        cout << "Cant Enter Duplicate value ";
    }

    curr->height = max(curr->left->height, curr->right->height) + 1;
    return curr;
}

int main()
{
}