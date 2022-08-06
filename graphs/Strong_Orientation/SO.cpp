#include <bits/stdc++.h>
using namespace std;

#define debvec(v)         \
    cout << #v << " : ";  \
    for (auto x : v)      \
        cout << x << " "; \
    cout << endl

#define check(x) cout << "--------" << x << endl

#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ar array
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<pll> vpll;
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

#define deb(args...)                             \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }

void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

const int mxn3 = 1e3 + 1;
const int mxn5 = 1e5 + 1;
const int mxn25 = 2e5 + 1;
const ll MXN = 1e9 + 1;
const ll MOD = 1e9 + 7;

class A
{
public:
    void init()
    {
        int n, m;
        cin >> n >> m;
        vvi adj(n + 1);
        for (int i = 0, a, b; i < m; i++)
        {
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        vi back_edge(n + 1, 0), lvl(n + 1, 0);
        vvi ans;
        int bridge_count = 0;
        function<void(int, int)> dfs = [&](int v, int p) -> void
        {
            for (int np : adj[v])
            {
                if (np == p)
                    continue;

                if (lvl[np] == 0)
                {
                    lvl[np] = lvl[v] + 1;
                    ans.pb({v, np});
                    dfs(np, v);
                    back_edge[v] += back_edge[np];
                }
                else if (lvl[np] < lvl[v])
                {
                    back_edge[v]++;
                    ans.pb({v, np});
                }
                else if (lvl[np] > lvl[v])
                {
                    back_edge[v]--;
                }
            }
            if (lvl[v] != 1 && back_edge[v] == 0)
            {
                bridge_count++;
            }
        };

        lvl[1] = 1;
        dfs(1, 0);

        if (bridge_count == 0)
        {
            print2dvec(ans);
        }
        else
        {
            cout << 0;
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


*/