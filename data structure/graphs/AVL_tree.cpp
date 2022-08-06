#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl

#define deb2(x, y) cout << #x << " = " << x << "\n" \
                        << #y << "=" << y << endl

#define debwe(x) cout << #x << " = " << x
#define check(x) cout << "--------" << x << endl

#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)

#define pb push_back
#define mp make_pair

struct Node
{
    int data;
    int height;
    Node *p;
    Node *left;
    Node *right;
};

class AVL
{
public:
    Node *root;

    AVL()
    {
        root = nullptr;
    }

    int node_height(Node *p)
    {
        int hl = (p != nullptr && p->left != nullptr) ? p->left->height : 0;
        int hr = (p != nullptr && p->right != nullptr) ? p->right->height : 0;

        return (max(hl + 1, hr + 1));
    }

    int bfactor(Node *p)
    {
        int hl = (p != nullptr && p->left != nullptr) ? p->left->height : 0;
        int hr = (p != nullptr && p->right != nullptr) ? p->right->height : 0;

        return (hl - hr);
    }

    Node *LLRotation(Node *t)
    {
        Node *tl = t->left;
        Node *tlr = t->left->right;

        tl->p = t->p;
        t->p = tl;
        tlr->p = t;

        tl->right = t;
        t->right = tlr;

        t->height = node_height(t);
        tl->height = node_height(tl);

        if (root == t)
        {
            root = tl;
        }
        return tl;
    }

    Node *RRRotation(Node *t)
    {
        Node *tr = t->right;
        Node *trl = t->right->left;

        tr->p = t->p;
        t->p = tr;
        trl->p = t;

        tr->left = t;
        t->left = trl;

        t->height = node_height(t);
        tr->height = node_height(tr);

        if (root == t)
        {
            root = tr;
        }
        return tr;
    }

    Node *LRRotation(Node *t)
    {
        Node *tl = t->left;
        Node *tlr = t->left->right;

        tlr->p = t->p;
        t->p = tlr;
        tl->p = tlr;
        tlr->left->p = tl;
        tlr->right->p = t;

        t->left = tlr->right;
        tl->right = tlr->left;
        tlr->right = t;
        tlr->left = tl;

        t->height = node_height(t);
        tl->height = node_height(tl);
        tlr->height = node_height(tlr);

        if (root == t)
        {
            root = tlr;
        }
        return tlr;
    }

    Node *RLRotation(Node *t)
    {
        Node *tr = t->right;
        Node *trl = t->right->left;

        trl->p = t->p;
        t->p = trl;
        tr->p = trl;
        trl->left->p = t;
        trl->right->p = tr;

        tr->left = trl->right;
        t->right = trl->left;
        trl->right = tr;
        trl->left = t;

        t->height = node_height(t);
        tr->height = node_height(tr);
        trl->height = node_height(trl);

        if (root == t)
        {
            root = trl;
        }
        return trl;
    }

    Node *insertion_rec(Node *t, int key)
    {
        Node *temp = new Node;
        temp->data = key;
        temp->height = 1;
        temp->left = nullptr;
        temp->right = nullptr;
        temp->p = nullptr;

        if (t == nullptr)
        {
            return temp;
        }
        if (key < t->data)
        {
            t->left = insertion_rec(t->left, key);
        }
        else if (key > t->data)
        {
            t->right = insertion_rec(t->right, key);
        }

        t->height = node_height(t);

        if (bfactor(t) == 2 && bfactor(t->left) == 1)
        {
            LLRotation(t);
        }
        else if (bfactor(t) == 2 && bfactor(t->left) == -1)
        {
            LRRotation(t);
        }
        else if (bfactor(t) == -2 && bfactor(t->left) == 1)
        {
            RLRotation(t);
        }
        else if (bfactor(t) == -2 && bfactor(t->left) == -1)
        {
            RRRotation(t);
        }
        return t;
    }

    // Node *deletion(Node *t, int key)
    // {
    //     if (t == nullptr)
    //     {
    //         return t;
    //     }

    //     if()
    // }
};

int main()
{
}