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
        cout << i << " ";       \
    }                           \
    cout << endl;               \
    for (int i = 0; i < n; i++) \
    {                           \
        cout << arr[i] << " ";  \
    }                           \
    cout << endl;

#define print2darr(n, m, arr)         \
    for (int i = 0; i < n; i++)       \
    {                                 \
        cout << i << " -> ";          \
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

struct Tries
{
    int links[mxn3][26];
    int fail[mxn3];
    int e[mxn3];
    int count;
    bool vis[mxn3];

    Tries()
    {
        memset(links, 0, sizeof(links));
        memset(fail, 0, sizeof(fail));
        memset(e, 0, sizeof(e));
        memset(vis, false, sizeof(vis));
        count = 0;
    }

    void debug()
    {
        cout << "     ";
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
        print2darr(count + 1, 26, links);
        cout << endl;
        printarr(count + 1, fail);
        cout << endl;
        printarr(count + 1, e);
    }

    void query(string &str)
    {
        memset(vis, false, sizeof(vis));
        int u = 0;
        int res = 0;
        for (int i = 0; str[i]; i++)
        {
            u = links[u][str[i] - 'a'];
            for (int j = u; j && !vis[j]; j = fail[j])
            {
                vis[j] = true;
                res += e[j];
            }
        }

        cout << res;
    }

    void insert(string &str)
    {
        int root = 0;
        for (int i = 0; str[i]; i++)
        {
            if (!links[root][str[i] - 'a'])
                links[root][str[i] - 'a'] = ++count;

            root = links[root][str[i] - 'a'];
        }
        e[root] = e[root] + 1;
    }

    void build()
    {
        queue<int> q;
        for (int i = 0; i < 26; i++)
        {
            if (links[0][i])
                q.push(links[0][i]);
        }

        while (q.size())
        {
            int u = q.front();
            q.pop();

            for (int i = 0; i < 26; i++)
            {
                if (links[u][i])
                {
                    fail[links[u][i]] = links[fail[u]][i];
                    q.push(links[u][i]);
                }
                else
                {
                    links[u][i] = links[fail[u]][i];
                }
            }
        }
    }
};

class A
{
public:
    void init()
    {
        // vector<string> v = {
        //     "hers",
        //     "he",
        //     "his",
        //     "she",
        //     "i",
        // };

        vector<string> v = {
            "a",
            "cab",
            "abca"};

        Tries trie;

        for (string &s : v)
        {
            trie.insert(s);
        }

        trie.build();
        // trie.debug();

        string str;
        // str = "she";
        // trie.query(str);
        str = "abcab";
        trie.query(str);
    }
} obj;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    obj.init();
}

/*


*/