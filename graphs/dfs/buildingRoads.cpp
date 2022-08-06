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

const int mxn = 1e5;

class BuildingRoads
{
public:
    int n, m, a, b;
    vi ans;
    set<int> cities;
    map<int, vi> adj;
    map<int, bool> visited;

    void dfs(int y)
    {
        visited[y] = 1;
        for (auto x : adj[y])
        {
            if (!visited[x])
            {
                dfs(x);
            }
        }
    }

    void connected()
    {
        for (auto x : cities)
        {
            if (!visited[x])
            {
                ans.pb(x);
                dfs(x);
            }
        }

        cout << ans.size() - 1 << endl;

        for (int i = 1; i < ans.size(); i++)
        {
            cout << ans[0] << " " << ans[i] << endl;
        }
    }

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
            cities.insert(i);
        }

        // for (auto x : adj)
        // {
        //     for (auto y : x.second)
        //     {
        //         cout << x.first << "->" << y << endl;
        //     }
        //     cout << endl;
        // }
        for (auto x : cities)
        {
            visited[x] = 0;
        }

        connected();
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
10 10
2 5
5 6
1 4
6 8
2 6
3 6
1 10
8 9
2 3
5 8
*/