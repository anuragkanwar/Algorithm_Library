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

const int mxn = 2e5;

class Bipartite
{
public:
    int n, m, a, b;
    int ekbar = 1;
    bool bip = 1;
    map<int, vi> adj;
    map<int, bool> visited;
    vi side;
    vpii ans;
    queue<int> q;

    void connectedcomp()
    {

        for (int i = 1; i <= n; i++)
        {
            if (side[i] == -1)
            {
                side[i] = 0;
                q.push(i);
                int u;
                while (!q.empty())
                {
                    u = q.front();
                    q.pop();

                    for (auto x : adj[u])
                    {
                        if (side[x] == -1)
                        {
                            side[x] = side[u] ^ 1;
                            q.push(x);
                        }
                        else
                        {
                            bip &= side[x] ^ side[u];
                        }
                    }
                }
            }
        }

        // if (bip)
        // {
        cout << "1" << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << (side[i] ^ 1);
        }
        cout << endl;
        // }
        // else
        // {
        // cout << "IMPOSSIBLE";
        // }
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

        for (int i = 0; i <= n; i++)
        {
            side.pb(-1);
        }

        connectedcomp();
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        Bipartite obj;
        obj.init();
    }
}

/*
5 7
1 3
1 4
1 5
2 3
2 4
2 5
3 4

*/