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
const int MXN = 1e9 + 1;

class MaxBFS
{
public:
    ll n, m, a, b, w;
    ll s, d;
    ll cs, ce;
    map<ll, vpl> adj;
    ll dist[5010], marked[5010], parent[5010];
    queue<ll> q;
    bool flag = 1;

    void init()
    {
        memset(dist, -0x3F, sizeof(dist));
        memset(marked, 0, sizeof(marked));
        cin >> n >> m;
        for (ll i = 0; i < m; i++)
        {
            cin >> a >> b >> w;
            adj[a].pb(mp(w, b));
        }
        s = 1;
        d = n;
        dist[s] = 0;
        calcMAX();
    }

    void calcMAX()
    {
        q.push(s);
        while (!q.empty())
        {
            ll u = q.front();
            q.pop();
            marked[u] = 1;
            
            for (auto x : adj[u])
            {
                if (marked[x.second])
                {
                    cs = x.second;
                    if (dist[x.second] < dist[u] + x.first)
                    {
                        flag = 1;
                        continue;
                    }
                    else
                    {
                        continue;
                    }
                }
                if (dist[x.second] < dist[u] + x.first)
                {
                    dist[x.second] = dist[u] + x.first;
                    parent[x.second] = u;
                }
                q.push(x.second);
            }
        }

        vl path;
        d = n;
        while (d ^ s)
        {
            if (flag && d == cs)
            {
                cout << "-1";
                return;
            }

            d = parent[d];
        }
        if (flag && d == cs)
        {
            cout << "-1";
            return;
        }

        cout << dist[n];
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
4 5
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4

*/