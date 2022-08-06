#include <bits/stdc++.h>
using namespace std;

#define debvec(v)         \
    cout << #v << " : ";  \
    for (auto x : v)      \
        cout << x << " "; \
    cout << endl

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

#define deb(args...)                             \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }

void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

const int mxn3 = 1e3 + 1;
const int mxn5 = 1e5 + 1;
const int mxn25 = 2e5 + 1;
const ll MXN = 1e9 + 1;
const ll MOD = 1e9 + 7;

class A
{
public:
    void init()
    {
        int n;
        cin >> n;
        vvi adj(n);
        for (int i = 0; i < n; i++)
        {
            int m;
            cin >> m;
            for (int j = 0; j < m; j++)
            {
                int a;
                cin >> a;
                adj[i].pb(a);
            }
        }

        int t;
        cin >> t;
        vector<ar<int, 2>> qry;
        for (int i = 0; i < t; i++)
        {
            int a, b;
            cin >> a >> b;
            qry.pb({a, b});
        }

        int lg = ceil(log2(n) + 1);
        vb vis(n + 1, false);
        vvi up(n + 1, vi(lg));
        vi depth(n + 1, -1);
        vi sz(n + 1, -1);

        function<void(int, int)> dfs = [&](int v, int p)
        {
            vis[v] = true;
            up[v][0] = p;
            depth[v] = depth[p] + 1;
            sz[v] = 1;
            for (int i = 1; i <= lg; i++)
            {
                up[v][i] = up[up[v][i - 1]][i - 1];
            }

            for (int &np : adj[v])
            {
                if (!vis[np])
                {
                    dfs(np, v);
                    sz[v] += sz[np];
                }
            }
        };

        function<int(int, int)> lca = [&](int u, int v) -> int
        {
            if (depth[u] < depth[v])
                swap(u, v);

            int k = depth[u] - depth[v];
            while (k)
            {
                int t = log2(k & -k);
                u = up[u][t];
                k &= (k - 1);
            }

            if (u == v)
                return u;

            for (int i = lg - 1; i >= 0; i--)
            {
                if (up[u][i] != up[v][i])
                {
                    u = up[u][i], v = up[v][i];
                }
            }
            return up[u][0];
        };

        dfs(0, 0);
        for (auto &x : qry)
        {
            cout << lca(x[0], x[1]) << "\n";
        }
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