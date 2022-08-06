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

#define print2dvec(v)         \
    for (auto x : v)          \
    {                         \
        for (auto y : x)      \
        {                     \
            cout << y << " "; \
        }                     \
        cout << endl;         \
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

const int mxn = 2e5;

class CycleDetection
{
public:
    int n, m, a, b, cs, ce;
    map<int, vi> adj;
    map<int, bool> visited;
    map<int, int> parent;
    bool cycle = 0;

    void init()
    {
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        for (int i = 1; i <= n; i++)
        {
            visited[i] = 0;
            parent[i] = -1;
        }

        cs = -1;
        ce = -1;
        findCycle();
    }

    bool dfs(int v, int p)
    {
        visited[v] = 1;
        for (auto u : adj[v])
        {
            if (u == p)
                continue;

            if (visited[u] == 1)
            {
                cycle = 1;
                cs = u;
                ce = v;
                return true;
            }
            else
            {
                parent[u] = v;
                if (dfs(u, parent[u]))
                {
                    return true;
                }
            }
        }
        return false;
    }

    void findCycle()
    {
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && dfs(i, parent[i]))
            {
                break;
            }
        }

        if (cs == -1)
        {
            cout << "IMPOSSIBLE";
        }
        else
        {
            vi ans;
            ans.pb(cs);
            while (cs ^ ce)
            {
                ans.pb(ce);
                ce = parent[ce];
            }

            ans.pb(cs);

            reverse(ans.begin(), ans.end());
            cout << ans.size() << endl;
            printvec(ans);
        }
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
########
#M..A..#
#.#.M#.#
#M#..#..
#.######

*/