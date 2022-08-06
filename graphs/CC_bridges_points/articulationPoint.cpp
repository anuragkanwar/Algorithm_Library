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

// template <typename... T>
// void read(T &...args)
// {
//     ((cin >> args), ...);
// }

// template <typename... T>
// void write(T &&...args)
// {
//     ((cout << args << " "), ...);
// }

const int mxn = 1e3;
const ll MXN = 1e9 + 1;
#define MOD 1e9 + 7;

class A
{
public:
    int n, m, a, b, timer, kids;
    map<int, vector<int>> adj;
    vector<bool> visited;
    vi low, disc;
    unordered_set<int> ans;

    void dfs(int v, int p)
    {
        visited[v] = true;
        low[v] = disc[v] = timer++;
        kids = 0;
        for (auto np : adj[v])
        {
            if (np == v)
                continue;
            if (visited[np])
            {
                low[v] = min(low[v], disc[np]);
            }
            else
            {
                dfs(np, v);
                low[v] = min(low[v], low[np]);

                if (low[np] >= disc[v] && p != -1)
                {
                    ans.insert(v);
                }
                kids++;
            }
        }
        if (p == -1 && kids > 1)
        {
            ans.insert(v);
        }
    }

    void init()
    {
        cin >> n >> m;
        timer = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        visited.assign(n, false);
        low.assign(n, -1);
        disc.assign(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                dfs(i, -1);
        }
        printvec(ans);
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
6 6
0 1
1 2
0 2
0 3
3 4
3 5
*/