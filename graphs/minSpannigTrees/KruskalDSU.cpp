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
    vi par, rank;
    vector<ar<int, 3>> edg;
    vpii ans;
    int n, m, total_cost;

    int find_set(int x)
    {
        return x ^ par[x] ? x = find_set(par[x]) : x;
    }

    void join(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);

        if (rank[a] < rank[b])
        {
            swap(a, b);
        }
        par[b] = a;

        if (rank[a] == rank[b])
        {
            a++;
        }
    }

    void init()
    {
        cin >> n >> m;

        for (int i = 0, a, b, c; i < m; i++)
        {
            cin >> a >> b >> c;
            edg.pb({c, a, b});
        }
        sort(edg.begin(), edg.end());
        rank.assign(n + 1, 0);
        par.assign(n + 1, 0);
        iota(par.begin(), par.end(), 0);
        total_cost = 0;
        for (auto x : edg)
        {
            if (find_set(x[1]) != find_set(x[2]))
            {
                total_cost += x[0];
                ans.pb(mp(x[1], x[2]));
                join(x[1], x[2]);
            }
        }
        if (ans.size() < n - 1)
        {
            cout << "IMPOSSIBLE";
        }
        else
        {
            deb(total_cost);
            for (auto x : ans)
            {
                deb2(x.first, x.second);
            }
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
5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4
*/