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

const int mxn = 1e5;

class Dijkstra
{
public:
    ll n, m, a, b, c;
    map<ll, vpl> adj;
    map<ll, ll> d;
    priority_queue<pll, vector<pll>, greater<pll>> hp;

    void init()
    {
        cin >> n >> m;
        for (ll i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            adj[a].pb(mp(b, c));
        }

        for (ll i = 1; i <= n; i++)
        {
            if (i == 1)
            {
                d[i] = 0;
                continue;
            }
            d[i] = LLONG_MAX;
        }

        hp.push(mp(d[1], 1));
        findPaths();
    }

    void findPaths()
    {
        while (!hp.empty())
        {
            pll u = hp.top();
            hp.pop();
            if (d[u.second] < u.first)
            {
                continue;
            }
            for (auto x : adj[u.second])
            {
                if (d[x.first] > d[u.second] + x.second)
                {
                    d[x.first] = d[u.second] + x.second;

                    hp.push(mp(d[x.first], x.first));
                }
            }
        }

        for (auto x : d)
        {
            cout << x.second << " ";
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


*/