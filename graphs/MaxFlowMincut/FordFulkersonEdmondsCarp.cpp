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

class A
{
public:
    vl adj[mxn5];
    ll cap[mxn3][mxn3], matrixadj[mxn3][mxn3];
    ll flow, n, m;

    ll bfs(ll &s, ll &t, vl &parent)
    {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = -2;

        queue<pll> q;
        q.push(mp(s, LLONG_MAX));

        while (q.size())
        {
            ll curr = q.front().first;
            ll bottleneckFlow = q.front().second;
            q.pop();

            for (auto np : adj[curr])
            {
                if (parent[np] == -1 && cap[curr][np])
                {
                    parent[np] = curr;
                    ll newflow = min(bottleneckFlow, cap[curr][np]);
                    if (np == t)
                    {
                        return newflow;
                    }

                    q.push(mp(np, newflow));
                }
            }
        }

        return 0;
    }

    void MaxFlow(ll &s, ll &t)
    {
        flow = 0;
        vl parent(mxn5, -1);
        ll newflow;
        while ((newflow = bfs(s, t, parent)))
        {
            flow += newflow;
            ll d = t;
            while (d ^ s)
            {
                cap[parent[d]][d] -= newflow;
                cap[d][parent[d]] += newflow;
                d = parent[d];
            }
        }
        cout << flow;
    }

    vb visited;
    void dfs(int v)
    {
        visited[v] = true;
        for (auto x : adj[v])
        {
            if (cap[v][x] && !visited[x])
            {
                dfs(x);
            }
        }
    }

    void Mincut(int s, int t)
    {
        visited.assign(n + 1, false);
        dfs(s);

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (visited[i] && !visited[j] && matrixadj[i][j])
                {
                    cout << i << " - " << j << endl;
                }
            }
        }
    }
    void init()
    {
        cin >> n >> m;
        memset(matrixadj, 0, sizeof(matrixadj));
        for (ll i = 0, a, b, c; i < m; i++)
        {
            cin >> a >> b >> c;
            matrixadj[a][b] = c;
            adj[a].pb(b);
            adj[b].pb(a);
            cap[a][b] += c;
            cap[b][a] = 0;
        }
        ll s, t;
        s = 1;
        t = n;

        MaxFlow(s, t);
        cout << endl;
        Mincut(s, t);
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
4 5
1 2 3
2 4 2
1 3 4
3 4 5
4 1 3


6 9
1 2 16
1 3 13
2 3 6
2 4 12
4 3 9
3 5 14
5 4 7
4 6 20
5 6 4

*/