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
    vi low, high, seg, height, first, nodes;
    vb visited;
    vi adj[mxn5];
    int n;

    void dfs(int v, int h = 0)
    {
        visited[v] = true;
        first[v] = nodes.size();
        height[v] = h;
        nodes.pb(v);
        for (auto x : adj[v])
        {
            if (!visited[x])
            {
                dfs(x, h + 1);
                nodes.pb(v);
            }
        }
    }

    void prepro(int i, int l, int r)
    {
        low[i] = l;
        high[i] = r;
        if (l == r)
        {
            seg[i] = nodes[l];
            return;
        }

        int mid = l + (r - l) / 2;
        prepro(i << 1, l, mid);
        prepro(i << 1 | 1, mid + 1, r);
        int left = seg[i << 1], right = seg[i << 1 | 1];
        seg[i] = (height[left] < height[right] ? left : right);
    }

    int LCA(int i, int l, int r)
    {
        if (r < low[i] || l > high[i])
        {
            return -1;
        }
        if (l <= low[i] && high[i] <= r)
        {
            return seg[i];
        }

        int left = LCA(i << 1, l, r);
        int right = LCA(i << 1 | 1, l, r);
        if (left == -1)
            return right;
        if (right == -1)
            return left;

        return height[left] < height[right] ? left : right;
    }

    void query(int l, int r)
    {
        l = first[l];
        r = first[r];
        if (l > r)
        {
            swap(l, r);
        }
        int ans = LCA(1, l, r);
        deb(ans);
    }

    void init()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int s;
            cin >> s;
            while (s--)
            {
                inp;
                adj[i].pb(temp);
            }
        }
        height.assign(n + 1, 0);
        first.assign(n + 1, 0);
        visited.assign(n + 1, false);
        dfs(0);
        debvec(height);
        debvec(first);
        debvec(nodes);
        seg.assign(4 * (nodes.size()) + 1, 0);
        low.assign(4 * (nodes.size()) + 1, 0);
        high.assign(4 * (nodes.size()) + 1, 0);
        prepro(1, 0, nodes.size() - 1);
        query(3, 4);
        query(4, 5);
        query(6, 3);
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
7
3 1 2 3
2 4 5
0
1 6
0
0
0
*/