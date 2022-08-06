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
#define ar array

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pll> vpl;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define printvec(v)       \
    for (auto x : v)      \
        cout << x << " "; \
    cout << endl

#define printarr(n, arr)        \
    for (int i = 0; i < n; i++) \
    {                           \
        cout << arr[i] << " ";  \
    }                           \
    cout << endl;

#define print2darr(n, m, arr)         \
    for (int i = 0; i < n; i++)       \
    {                                 \
        for (int j = 0; j < m; j++)   \
        {                             \
            cout << arr[i][j] << " "; \
        }                             \
        cout << endl;                 \
    }

// template <typename... T>
// void read(T &... args)
// {
//     ((cin >> args), ...);
// }

// template <typename... T>
// void write(T &&... args)
// {
//     ((cout << args << " "), ...);
// }

const ll MxN = 1e9 + 1;
const int mxn = 1e3;
#define MOD 1e9 + 7;

struct Node
{
public:
    int data;
    Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;

    return (node);
};

class A
{
public:
    Node *root;

    int find_diameter(Node *sroot, int &res)
    {
        if (sroot == nullptr)
        {
            return 0;
        }

        int l = find_diameter(sroot->left, res);
        int r = find_diameter(sroot->right, res);

        int temp = max(l, r) + 1;
        int ans = max(temp, 1 + l + r);
        res = max(res, ans);

        return temp;
    }

    void init()
    {
        check(2);
        root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(4);
        root->left->right = newNode(5);
        check(2);

        int res = INT32_MIN;
        int faltu = find_diameter(root, res);
        cout << res << endl;
    }
} obj;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // ll t;cin >> t;while(t--){}

    obj.init();
}
/*

*/
