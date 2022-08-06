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

const int mxn = 1e3;

class FLoyads
{
public:
    ll n, m, a, b, c, q;
    ll adj[mxn][mxn];
    vpl qr;

    void init()
    {
        memset(adj, 0x3F, sizeof(adj));
        cin >> n >> m >> q;
        for (ll k = 0; k < m; k++)
        {
            cin >> a >> b >> c;
            adj[a][b] = min(adj[b][a], c);
            adj[b][a] = min(adj[a][b], c);
        }

        for (ll i = 1; i <= n; i++)
        {
            adj[i][i] = 0;
        }

        for (ll i = 0; i < q; i++)
        {
            cin >> a >> b;
            qr.pb(mp(a, b));
        }

        algo();
    }

    void algo()
    {
        for (ll k = 1; k <= n; k++)
        {
            for (ll i = 1; i <= n; i++)
            {
                for (ll j = 1; j <= n; j++)
                {
                    if (adj[i][k] < LLONG_MAX && adj[k][j] < LLONG_MAX)
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }

        for (auto x : qr)
        {
            cout << (adj[x.first][x.second] >= 1e18 ? -1 : adj[x.first][x.second]) << endl;
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
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2

*/