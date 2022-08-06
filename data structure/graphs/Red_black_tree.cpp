#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    char color;
    Node *left;
    Node *right;
    Node *parent;
};

class rb_tree
{
public:
    Node *root;
    Node *nil;
    rb_tree()
    {
        root == nullptr;
        nil == nullptr;
    }

    void right_rotate(Node *x)
    {
        Node *y = x->left;
        Node *b = y->right;
        if (x->parent->left == x)
        {
            x->parent->left = y;
            y->parent = x->parent;
            x->left = b;
            b->parent = x;
            y->right = x;
            x->parent = y;
        }
        else
        {
            x->parent->right = y;
            y->parent = x->parent;
            x->left = b;
            b->parent = x;
            y->right = x;
            x->parent = y;
        }
    }

    void left_rotate(Node *x)
    {
        Node *y = x->right;
        Node *b = y->left;

        if (x->parent->left == x)
        {
            x->parent->left = y;
            y->parent = x->parent;
            x->right = b;
            b->parent = x;
            y->left = x;
            x->parent = y;
        }
        else
        {
            x->parent->right = y;
            y->parent = x->parent;
            x->right = b;
            b->parent = x;
            y->left = x;
            x->parent = y;
        }
    }
};
