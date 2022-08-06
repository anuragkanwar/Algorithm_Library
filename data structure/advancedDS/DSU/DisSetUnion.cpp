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

struct DSU
{
    unordered_map<int, int> par, rank, sz;
    int cc;

    DSU(int n, vector<int> &arr) : cc(n)
    {
        for (int i = 0; i < (int)arr.size(); i++)
        {
            par[arr[i]] = arr[i];
            rank[arr[i]] = 0;
            sz[arr[i]] = 1;
        }
    }

    int find(int x)
    {
        return (x ^ par[x] ? par[x] = find(par[x]) : x);
    }

    int same(int i, int j)
    {
        return (find(i) == find(j));
    }

    int get_size(int i)
    {
        return sz[find(i)];
    }

    int countCC()
    {
        return cc;
    }

    int merge(int a, int b)
    {
        if ((a = find(a)) == (b = find(b)))
            return -1;

        cc--;

        if (rank[a] < rank[b])
            swap(a, b);

        par[b] = a;
        sz[a] += sz[b];
        if (rank[a] == rank[b])
            rank[a]++;
        return a;
    }
};

class A
{
public:
    void init()
    {
        int n;
        cin >> n;
        vector<int> v = {1,2,3,4,5,6};
        DSU dsu(n, v);
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


*/