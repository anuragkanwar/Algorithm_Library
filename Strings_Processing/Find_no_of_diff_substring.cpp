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

// every substring can be represented as a prefix of a suffix;
// 1st also with tries, couting non empty substring(add 1 if want to count empty substring also)

struct Node
{
    Node *links[26];

    bool isPresent(char ch)
    {
        return (links[ch - 'a'] != nullptr);
    }

    void addNode(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
};

struct Trie
{
    Node *root;
    int nc;

    Trie()
    {
        root = new Node();
        nc = 0;
    }

    void insert(string word)
    {
        Node *move = root;
        for (int i = 0; word[i]; i++)
        {
            if (!move->isPresent(word[i]))
            {
                move->addNode(word[i], new Node());
                nc++;
            }
            move = move->links[word[i] - 'a'];
        }
    }
};

class A
{
public:
    int z_mx(string str)
    {
        int n = str.size(), l = 0, r = 0, mx = 0;
        vector<int> z(n, 0);
        for (int i = 1; i < n; i++)
        {
            if (i > r)
            {
                l = r = i;
                while (r < n && str[r] == str[r - l])
                    r++;
                r--;
                z[i] = r - l + 1;
            }
            else
            {
                if (z[i - l] + i > r)
                {
                    l = i;
                    while (r < n && str[r] == str[r - l])
                        r++;
                    r--;
                    z[i] = r - l + 1;
                }
                else
                {
                    z[i] = z[i - l];
                }
            }
            mx = max(mx, z[i]);
        }

        return mx;
    }

    void init()
    {
        string str;
        getline(cin, str);

        // 1. with trie
        Trie t;
        int n = str.size();
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < (n - i); j++)
            {
                t.insert(str.substr(i, j + 1));
            }
        }
        deb(t.nc);

        // 2.
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            string s = str.substr(0, i + 1);
            reverse(s.begin(), s.end());
            ans += (i + 1) - z_mx(s);
        }

        deb(ans);
    }
} obj;

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    obj.init();
}

/*


*/