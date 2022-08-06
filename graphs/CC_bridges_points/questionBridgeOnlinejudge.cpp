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
    int n, a, temp, timer;
    unordered_map<int, vector<int>> adj;
    vpii ans;
    vi low, disc;
    vector<bool> visited;

    void dfs(int v, int p)
    {
        visited[v] = true;
        low[v] = disc[v] = timer++;

        for (auto np : adj[v])
        {
            if (np == p)
            {
                continue;
            }
            if (visited[np])
            {
                low[v] = min(low[v], disc[np]);
            }
            else
            {
                dfs(np, v);
                low[v] = min(low[v], low[np]);

                if (low[np] > disc[v])
                {
                    ans.push_back(make_pair((min(np, v)), max(np, v)));
                }
            }
        }
    }

    void init()
    {
        ans.clear();
        adj.clear();
        cin >> n;
        timer = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            cin >> ws;
            char ch1, ch3;
            int m;
            cin >> ch1 >> m >> ch3;
            for (int j = 0; j < m; j++)
            {
                cin >> temp;
                adj[a].push_back(temp);
            }
        }
        visited.assign(n, false);
        low.assign(n, -1);
        disc.assign(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, -1);
            }
        }

        cout << ans.size() << " critical links" << endl;
        sort(ans.begin(), ans.end());
        for (pii x : ans)
        {
            cout << x.first << " - " << x.second << endl;
        }
        cout << endl;
    }

} obj;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        obj.init();
    }
}

/*
4

2
0 (1) 1
1 (1) 0

20
0 (1) 1
1 (4) 0 2 4 5
2 (4) 1 5 6 10
3 (1) 4
4 (4) 1 3 5 8
5 (6) 1 2 4 8 9 10
6 (3) 2 10 13
7 (1) 8
8 (4) 4 5 7 9
9 (3) 5 8 10
10 (4) 2 5 9 6
11 (3) 12 13 17
12 (3) 11 14 15
13 (5) 6 11 14 17 18
14 (4) 12 13 15 18
15 (4) 12 14 16 18
16 (1) 15
17 (3) 11 13 19
18 (3) 13 14 15
19 (1) 17

19
0 (2) 1 2
1 (2) 0 3
2 (2) 0 3
3 (3) 1 2 4
4 (6) 5 6 3 10 7 8
5 (2) 4 6
6 (2) 5 4
7 (3) 9 8 4
8 (2) 4 7
9 (1) 7
10 (3) 11 12 4
11 (2) 10 13
12 (2) 10 13
13 (3) 11 12 14
14 (3) 13 15 16
15 (2) 14 16
16 (4) 14 15 17 18
17 (2) 16 18
18 (2) 16 17

7
0 (4) 1 2 3 4
1 (3) 0 2 3
2 (3) 1 0 3
3 (4) 0 1 2 4
4 (4) 0 3 6 5
5 (1) 4
6 (1) 4
*/