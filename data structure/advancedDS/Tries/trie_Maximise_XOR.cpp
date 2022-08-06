#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl

#define deb2(x, y) cout << #x << " = " << x << "\n" \
                        << #y << "=" << y << endl

#define debvec(v)         \
    cout << #v << " : ";  \
    for (auto x : v)      \
        cout << x << " "; \
    cout << endl

#define debwe(x) cout << #x << " = " << x
#define check(x) cout << "--------" << x << endl

#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ar array

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define inp  \
    ll temp; \
    cin >> temp;

#define printvec(v)       \
    for (auto x : v)      \
        cout << x << " "; \
    cout << endl

#define print2dvec(v)         \
    for (auto x : v)          \
    {                         \
        for (auto y : x)      \
        {                     \
            cout << y << " "; \
        }                     \
        cout << endl;         \
    }

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

const int mxn3 = 1e3 + 1;
const int mxn5 = 1e5 + 1;
const int mxn25 = 2e5 + 1;
const ll MXN = 1e9 + 1;
const ll MOD = 1e9 + 7;

struct Node
{
    static const int n = 31;
    Node *links[2] = {nullptr};

    bool isPresent(int bit)
    {
        return (this->links[bit] != nullptr);
    }

    void makeNewNode(int bit, Node *node)
    {
        this->links[bit] = node;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node;
    }

    void Insert(int n)
    {
        Node *move = root;

        for (int i = move->n; i >= 0; i--)
        {
            int bit = ((n >> i) & 1);
            if (!move->isPresent(bit))
            {
                move->makeNewNode(bit, new Node);
            }
            move = move->links[bit];
        }
    }

    int maxOR(int num)
    {
        int ans = 0;
        Node *move = root;
        for (int i = move->n; i >= 0; i--)
        {
            int tomove = (((num >> i) & 1) ^ 1);
            if (move->isPresent(tomove))
            {
                ans |= (1 << i);
                move = move->links[tomove];
            }
            else
            {
                move = move->links[(tomove ^ 1)];
            }
        }
        return ans;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    // Write your code here.
    Trie trie;
    for (int &x : arr1)
    {
        trie.Insert(x);
    }

    int ans = INT32_MIN;

    for (int &x : arr2)
    {
        ans = max(ans, trie.maxOR(x));
    }

    return ans;
}

// class A{public:void init(){}} obj;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // obj.init();

    int n, m;
    cin >> n >> m;
    vi v1, v2;
    for (int i = 0; i < n; i++)
    {
        inp;
        v1.pb(temp);
    }
    for (int i = 0; i < m; i++)
    {
        inp;
        v2.pb(temp);
    }

    cout << maxXOR(n, m, v1, v2);
}

/*

7 7
6 6 0 6 8 5 6
1 7 1 7 8 0 2

*/