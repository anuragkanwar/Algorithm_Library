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
const ll MXN = 1e9 + 1;
#define MOD 1e9 + 7;

class A
{
public:
    unordered_map<int, vi> adj;
    vector<bool> visited;
    vi lg2, height, nodes, first;
    int dp[10][mxn + 1], it[10][mxn + 1];
    int p, n, timer;

    void dfs(int v, int h)
    {
        timer++;
        visited[v] = true;
        if (first[v] == -1)
        {
            first[v] = timer;
        }
        nodes.pb(v);
        height.pb(h);
        for (auto np : adj[v])
        {
            if (!visited[np])
                dfs(np, h + 1);
            timer++;
            nodes.pb(v);
            height.pb(h);
        }
    }

    int indMin(int l, int r)
    {
        int len = r - l + 1;
        int p1 = lg2[len];
        int left = dp[p1][l];
        int right = dp[p1][r + 1 - len];
        int ans = (left <= right ? it[p1][l] : it[p1][r + 1 - len]);

        return nodes[ans];
    }

    void init(int cse)
    {
        cin >> n;
        timer = 0;
        adj.clear();
        visited.clear();
        lg2.clear();
        height.clear();
        nodes.clear();
        first.clear();

        for (int i = 1; i <= n; i++)
        {
            int tmp;
            cin >> tmp;
            if (!tmp)
                continue;
            while (tmp--)
            {
                inp;
                adj[i].pb(temp);
            }
        }
        visited.assign(n + 1, false);
        first.assign(n + 1, -1);
        dfs(1, 1);
        // for (auto x : adj)
        // {
        //     cout << x.first << "->  ";
        //     printvec(x.second);
        // }
        // printvec(first);
        // printvec(nodes);
        // printvec(height);
        n = nodes.size();
        lg2.assign(n + 1, 0);
        for (int i = 2; i <= n; i++)
        {
            lg2[i] = lg2[i / 2] + 1;
        }
        p = lg2[n];

        for (int i = 0; i < n; i++)
        {
            dp[0][i] = height[i];
            it[0][i] = i;
        }

        for (int i = 1; i <= p; i++)
        {
            for (int j = 0; j + (1 << i) <= n; j++)
            {
                int left = dp[i - 1][j];
                int right = dp[i - 1][j + (1 << (i - 1))];
                dp[i][j] = min(left, right);
                it[i][j] = (left <= right ? it[i - 1][j] : it[i - 1][j + (1 << (i - 1))]);
            }
        }

        int q;
        cin >> q;
        cout << "Case " << cse << ":" << endl;
        for (int i = 0; i < q; i++)
        {
            int a, b;
            cin >> a >> b;
            a = first[a];
            b = first[b];
            if (a > b)
            {
                swap(a, b);
            }
            // deb2(a, b);
            cout << indMin(a, b) << endl;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        A obj;
        obj.init(i);
    }
}

/*
1
7
3 2 3 4
0
3 5 6 7
0
0
0
0
2
5 7
2 7


2
7
3 2 3 4
0
3 5 6 7
0
0
0
0
7
1 7
2 7
3 3
3 6
3 7
5 6
5 7
13
3 2 3 4
0
3 5 6 7
0
0
2 8 9
2 10 11
0
0
2 12 13
0
0
0
4
9 12
8 9
2 11
11 13


1
1
0
1
1 1



*/