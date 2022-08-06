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
typedef vector<pll> vpl;
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

const int KK = 26;

struct Node
{
    Node *v[26];
    int we = 0;
    int pc = 0;

    bool isPresent(char &ch)
    {
        return (v[ch - 'a'] != nullptr);
    }

    void add(char &ch, Node *node)
    {
        v[ch - 'a'] = node;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        // Write your code here.
        root = new Node();
    }

    void insert(string &word)
    {
        // Write your code here.
        Node *mv = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!mv->isPresent(word[i]))
            {
                mv->add(word[i], new Node());
            }

            mv = mv->v[word[i] - 'a'];
            mv->pc++;
        }
        mv->we++;
    }

    int countWordsEqualTo(string &word)
    {
        // Write your code here.
        Node *mv = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!mv->isPresent(word[i]))
            {
                return 0;
            }
            mv = mv->v[word[i] - 'a'];
        }
        return (mv->we);
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        Node *mv = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!mv->isPresent(word[i]))
            {
                return 0;
            }
            mv = mv->v[word[i] - 'a'];
        }
        return (mv->pc);
    }

    void erase(string &word)
    {
        // Write your code here.
        Node *mv = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!mv->isPresent(word[i]))
            {
                return;
            }
            mv = mv->v[word[i] - 'a'];
            mv->pc--;
        }
        mv->we--;
    }
};

class A
{
public:
    void init() {}
} obj;

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    // obj.init();
}

/*


*/