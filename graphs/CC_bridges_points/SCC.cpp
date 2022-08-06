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
    int n, m, a, b, count;
    vector<bool> visited;
    stack<int> order;
    map<int, vector<int>> adj, adjr;

    void dfs1(int v)
    {
        visited[v] = true;
        for (auto np : adj[v])
        {
            if (!visited[np])
            {
                dfs1(np);
            }
        }
        order.push(v);
    }

    void dfs2(int v)
    {
        visited[v] = true;
        for (auto np : adjr[v])
        {
            if (!visited[np])
            {
                dfs2(np);
            }
        }
    }

    void init()
    {
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].pb(b);
            adjr[b].pb(a);
        }

        visited.assign(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                dfs1(i);
        }
        visited.assign(n, false);
        count = 0;
        while (order.size())
        {
            int t = order.top();
            order.pop();

            if (visited[t])
                continue;
            dfs2(t);
            count++;
        }
        cout << count;
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
8 10
0 1
1 2
2 0
2 3
3 4
4 5
5 6
6 4
4 7
6 7
*/