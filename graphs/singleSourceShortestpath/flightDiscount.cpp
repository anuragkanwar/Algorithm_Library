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

const int mxn = 1e5;
const ll MXN = 1e9 + 1;

class Flight
{
public:
    ll n, m, a, b, w, s, d;
    map<ll, vpl> adj;
    map<pll, ll> wght;
    ll dist[200010];
    ll parent[200010];
    priority_queue<pll, vpl, greater<pll>> pq;

    void init()
    {
        cin >> n >> m;
        for (ll i = 0; i < m; i++)
        {
            cin >> a >> b >> w;
            adj[a].pb(mp(w, b));
            wght[mp(a, b)] = w;
        }

        memset(dist, 0x3F, sizeof(dist));
        memset(parent, -1LL, sizeof(parent));

        s = 1;
        d = n;
        dist[s] = 0;
        pq.push(mp(dist[s], s));
        dijkstra();
    }

    void dijkstra()
    {
        while (!pq.empty())
        {
            pll u = pq.top();
            pq.pop();
            if (dist[u.second] < u.first)
                continue;
            for (auto x : adj[u.second])
            {
                if (dist[x.second] > dist[u.second] + x.first)
                {
                    dist[x.second] = dist[u.second] + x.first;
                    pq.push(mp(dist[x.second], x.second));
                    parent[x.second] = u.second;
                }
            }
        }

        backtrack();
    }

    void backtrack()
    {
        ll maxi = LLONG_MIN;
        ll temp = d;
        vl nodes;
        while (s ^ d)
        {
            nodes.pb(wght[mp(parent[d], d)]);
            deb(*nodes.rbegin());
            d = parent[d];
        }

        maxi = *max_element(nodes.begin(), nodes.end());
        ll total = 0;
        int ekbar = 1;

        for (auto x : nodes)
        {
            if (ekbar && x == maxi)
            {
                ekbar--;
                total += floor(double(maxi) / double(2));
            }
            else
            {
                total += x;
            }
        }

        cout << total;
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
3 4
1 2 3
2 3 1
1 3 7
2 1 5


4 4
1 2 100
2 4 100
1 3 10
3 4 200

6 6
1 2 1
2 3 12
3 6 1
1 4 4
4 5 4
5 6 4
*/