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
    Node *links[26];
    bool isEnd = false;

    bool isPresent(char ch)
    {
        return (links[ch - 'a'] != nullptr);
    }

    void makeNewNode(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
};

class Trie
{
private:
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *move = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!move->isPresent(word[i]))
            {
                move->makeNewNode(word[i], new Node);
            }
            move = move->links[word[i] - 'a'];
        }

        move->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *move = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!move->isPresent(word[i]))
            {
                return false;
            }
            move = move->links[word[i] - 'a'];
        }

        return move->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *move = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!move->isPresent(prefix[i]))
            {
                return false;
            }
            move = move->links[prefix[i] - 'a'];
        }

        return true;
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