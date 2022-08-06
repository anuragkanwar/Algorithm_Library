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
    int n, m, total_weight;
    vi dist, parent;
    vb selected;
    vpii ans;
    vi adj[mxn5];
    void init()
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            adj[i].assign(n, INT32_MAX);
        }

        for (int i = 0; i < m; i++)
        {
            int from, to, w;
            cin >> from >> to >> w;
            adj[from][to] = w;
            adj[to][from] = w;
        }

        total_weight = 0;
        dist.assign(n + 1, INT32_MAX);
        dist[0] = 0;
        parent.assign(n + 1, -1);
        selected.assign(n + 1, false);

        for (int i = 0; i < n; i++)
        {
            int v = -1;
            for (int j = 0; j < n; j++)
            {

                if (!selected[j] && (v == -1 || (dist[j] < dist[v])))
                {
                    v = j;
                }
            }

            if (dist[v] == INT32_MAX)
            {
                cout << "Not Possible";
                return;
            }

            selected[v] = true;
            total_weight += dist[v];
            //adjacent relaxation
            for (int np = 0; np < n; np++)
            {
                if (v != np && !selected[np] && adj[v][np] < dist[np])
                {
                    dist[np] = adj[v][np];
                    parent[np] = v;
                }
            }
        }

        for (int i = 1; i < n; i++)
        {
            cout << i << " " << parent[i] << " " << adj[i][parent[i]] << endl;
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
6 9
0 1 4
0 2 6
1 2 6
1 3 3
1 4 4
2 3 1
3 4 2
3 5 3
4 5 7
*/