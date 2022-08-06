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

const int mxn = 1e3;
const int mxm = 2e5;
const ll MXN = 1e9 + 1;
#define MOD 1e9 + 7;

class A
{
public:
    unordered_map<int, vi> adj;
    stack<int> s;
    vi ans;
    int eu[mxm + 1], ev[mxm + 1];
    bool used[mxm + 1];
    int n, m, src;

    void eulercycleDFS(int u = 1)
    {
        while (adj[u].size())
        {
            int e = adj[u].back();
            adj[u].pop_back();

            if (!used[e])
            {
                used[e] = true;
                eulercycleDFS(ev[e] ^ eu[e] ^ u);
                ans.pb(u);
            }
        }
    }

    void init()
    {
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> eu[i] >> ev[i];
            adj[eu[i]].pb(i);
            adj[ev[i]].pb(i);
        }
        memset(used, false, sizeof(used));

        src = 1;
        ans.pb(src);
        bool flag = false;
        for (auto x : adj)
        {
            if (x.second.size() & 1)
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else
        {
            s.push(src);
            eulercycleDFS();
            bool flag = false;

            if (ans.size() ^ (m + 1))
            {
                cout << "IMPOSSIBLE" << endl;
            }
            else
            {
                printvec(ans);
            }
        }
    }
}

obj;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    obj.init();
}

/*
6 8
1 2
1 3
2 3
2 4
2 6
3 5
3 6
4 5
*/