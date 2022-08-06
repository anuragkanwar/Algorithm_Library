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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pll> vpl;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

struct Node
{
    int data;
    Node *p;
    Node *left;
    Node *right;
};

class BST
{
public:
    Node *root;
    BST()
    {
        root = nullptr;
    }

    Node *search(int key)
    {
        Node *move1 = root;
        while (move1 != nullptr)
        {
            if (move1->data == key)
            {
                break;
            }
            else if (move1->data > key)
            {
                move1 = move1->left;
            }
            else
            {
                move1 = move1->right;
            }
        }
        return move1;
    }

    void insert(int d)
    {
        Node *temp = new Node;
        temp->data = d;
        temp->left = nullptr;
        temp->right = nullptr;
        temp->p = nullptr;

        if (root == nullptr)
        {
            root = temp;
        }
        else
        {
            Node *move1(root), *move2(root);
            while (move1 != nullptr)
            {
                move2 = move1;
                if (move1->data > d)
                {
                    move1 = move1->left;
                }
                else
                {
                    move1 = move1->right;
                }
            }

            if (move2->data > d)
            {
                move2->left = temp;
            }
            else
            {
                move2->right = temp;
            }
            temp->p = move2;
        }
    }

    Node *minimum(Node *troot)
    {
        while (troot->left != nullptr)
        {
            troot = troot->left;
        }
        return troot;
    }

    Node *maximum(Node *troot)
    {
        while (troot->right != nullptr)
        {
            troot = troot->right;
        }
        return troot;
    }

    Node *succesor(Node *troot)
    {
        if (troot->right != nullptr)
        {
            return minimum(troot->right);
        }
        else
        {
            Node *y = troot->p;
            while (y != nullptr && troot == y->right)
            {
                troot = y;
                y = y->p;
            }
            return y;
        }
    }

    Node *predecesor(Node *troot)
    {
        if (troot->left != nullptr)
        {
            return maximum(troot->left);
        }
        else
        {
            Node *y = troot->p;
            while (y != nullptr && troot == y->left)
            {
                troot = y;
                y = y->p;
            }
            return y;
        }
    }

    Node *succesor_without_parent(Node *x)
    {
        if (x->right != nullptr)
        {
            return minimum(x->right);
        }
        else
        {
            Node *succ = nullptr;
            Node *temp = root;
            while (1)
            {
                if (x->data < temp->data)
                {
                    succ = temp;
                    temp = temp->left;
                }
                else if (x->data > temp->data)
                {
                    temp = temp->right;
                }
                else
                {
                    break;
                }
            }
            return succ;
        }
    }
    Node *predecesor_without_parent(Node *x)
    {
        if (x->left != nullptr)
        {
            return maximum(x->left);
        }
        else
        {
            Node *pre(nullptr), *temp(root);
            while (1)
            {
                if (x->data > temp->data)
                {
                    pre = temp;
                    temp = temp->right;
                }
                else if (x->data < temp->data)
                {
                    temp = temp->left;
                }
                else
                {
                    break;
                }
            }
            return pre;
        }
    }

    int height(Node *x)
    {
        int r(0), l(0);
        if (x == nullptr)
        {
            return 0;
        }
        else
        {
            return (max(height(x->right) + 1, height(x->left) + 1));
        }
    }

    int TotalNodes(Node *x)
    {
        if (x == nullptr)
        {
            return 0;
        }
        else
        {
            return TotalNodes(x->left) + TotalNodes(x->right) + 1;
        }
    }

    int deg2(Node *x)
    {
        if (x == nullptr)
        {
            return 0;
        }
        else
        {
            if (x->left != nullptr && x->right != nullptr)
            {
                return (deg2(x->left) + deg2(x->right) + 1);
            }
            else
            {
                return (deg2(x->left) + deg2(x->right));
            }
        }
    }

    int deg0(Node *x)
    {
        if (x == nullptr)
        {
            return 0;
        }
        else
        {
            if (x->left == nullptr && x->right == nullptr)
            {
                return (deg0(x->left) + deg0(x->right) + 1);
            }
            else
            {
                return (deg0(x->left) + deg0(x->right));
            }
        }
    }

    int deg1(Node *x)
    {
        if (x == nullptr)
        {
            return 0;
        }
        else
        {
            if ((x->left == nullptr) != (x->right == nullptr))
            {
                return (deg1(x->left) + deg1(x->right) + 1);
            }
            else
            {
                return (deg1(x->left) + deg1(x->right));
            }
        }
    }

    void Transplant(Node *u, Node *v)
    {
        if (u->p == nullptr)
        {
            root = v;
        }
        else if (u == u->p->right)
        {
            u->p->right = v;
        }
        else
        {
            u->p->left = v;
        }
        if (v != nullptr)
        {
            v->p = u->p;
        }
    }

    void deletion(Node *z)
    {
        if (z->left == nullptr)
        {
            Transplant(z, z->right);
        }
        else if (z->right == nullptr)
        {
            Transplant(z, z->left);
        }
        else
        {
            Node *y = minimum(z->right);
            if (y->p != z)
            {
                Transplant(y, y->right);
                y->right = z->right;
                y->right->p = y;
            }
            Transplant(z, y);
            y->left = z->left;
            y->left->p = y;
        }

        delete z;
    }

    Node *deletion_without_parent(Node *x, int key)
    {
        if (x == nullptr)
        {
            return x;
        }
        else if (x->data > key)
        {
            x->left = deletion_without_parent(x->left, key);
        }
        else if (x->data < key)
        {
            x->right = deletion_without_parent(x->right, key);
        }
        else
        {
            if (x->left == nullptr)
            {
                Node *temp = x->right;
                delete x;
                return temp;
            }
            else if (x->right == nullptr)
            {
                Node *temp = x->left;
                delete x;
                return temp;
            }

            Node *temp = minimum(x->right);
            x->data = temp->data;
            x->right = deletion_without_parent(x->right, temp->data);
        }
    }

    void inorder_rec(Node *move)
    {
        if (move == nullptr)
        {
            return;
        }
        inorder_rec(move->left);
        cout << move->data << " ";
        inorder_rec(move->right);
    }

    void inorder_ite(Node *move)
    {
        stack<Node *> s;
        while (move != nullptr || !s.empty())
        {
            if (move != nullptr)
            {
                s.push(move);
                move = move->left;
            }
            else
            {
                move = s.top();
                s.pop();
                cout << move->data << " ";
                move = move->right;
            }
        }
    }

    void preorder_rec(Node *move)
    {
        if (move == nullptr)
        {
            return;
        }
        cout << move->data << " ";
        preorder_rec(move->left);
        preorder_rec(move->right);
    }

    void preorder_ite(Node *move)
    {
        stack<Node *> s;

        if (move == nullptr)
        {
            return;
        }
        else
        {
            while (move != nullptr || !s.empty())
            {
                if (move != nullptr)
                {
                    cout << move->data << " ";
                    s.push(move);
                    move = move->left;
                }
                else
                {
                    move = s.top();
                    s.pop();
                    move = move->right;
                }
            }
        }
    }

    void postorder_rec(Node *move)
    {
        if (move == nullptr)
        {
            return;
        }
        postorder_rec(move->left);
        postorder_rec(move->right);
        cout << move->data << " ";
    }

    void preorder(Node *sroot)
    {
        
    }
};

int main()
{

    int arr[] = {50, 23, 45, 34, 78, 1, 33, 60, 80, 67, 53, 99, 65};
    BST tree1, tree2;
    for (auto x : arr)
    {
        tree1.insert(x);
        tree2.insert(x);
    }
    tree1.deletion(tree1.search(23));
    tree2.deletion_without_parent(tree2.root, 23);

    tree1.inorder_ite(tree1.root);
    cout << endl;
    tree2.inorder_rec(tree1.root);
}

/*
to be continued ...
*/
