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
    ll n, m;
    vector<ll> dist, parent;
    vector<pair<ll, pair<ll, ll>>> edges;
    ll s, d;
    void init()
    {
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            edges.pb(mp(c, mp(a, b)));
        }

        // cin >> s >> d;
        s = 1;
        d = n;

        dist.assign(n + 1, INT32_MAX);
        parent.assign(n + 1, -1);

        dist[s] = 0;
        ll indicator = -1;
        for (ll i = 0; i < n; i++)
        {
            indicator = -1;
            for (auto x : edges)
            {
                if (dist[x.second.first] != LLONG_MAX)
                {
                    if (dist[x.second.first] + x.first < dist[x.second.second])
                    {
                        dist[x.second.second] = max(LLONG_MIN, dist[x.second.first] + x.first);
                        parent[x.second.second] = x.second.first;
                        indicator = x.second.second;
                    }
                }
            }
        }

        vector<ll> ans;

        if (indicator == -1)
        {

            cout << "NO" << endl;
            // cout << "No -ve cut edge cycles present"
            //      << " " << dist[d];

            // while (d ^ s)
            // {
            //     ans.pb(d);
            //     d = parent[d];
            // }
            // printvec(ans);
        }
        else
        {
            cout << "YES" << endl;
            int y = indicator;
            for (int i = 0; i < n; i++)
            {
                y = parent[y];
            }
            for (int cur = y;; cur = parent[cur])
            {
                if (cur == y && ans.size() > 0)
                {
                    break;
                }
                ans.push_back(cur);
            }
            ans.pb(y);
        }
        reverse(ans.begin(), ans.end());
        printvec(ans);
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
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2


25 50
17 22 68
12 3 93
20 23 92
13 9 -34
25 3 -13
9 8 54
21 2 -8
15 4 26
13 15 8
6 24 39
6 17 -9
21 4 -46
12 6 16
13 22 75
23 5 -49
2 21 33
18 20 -38
4 7 45
21 14 96
5 3 63
9 11 49
1 10 95
8 5 -34
1 23 4
24 7 51
9 18 -6
8 19 46
16 11 6
21 6 71
23 7 6
4 23 44
23 14 38
4 9 0
14 4 -13
13 4 -41
5 13 14
22 25 51
13 21 14
16 4 80
18 5 -38
4 2 22
18 7 75
2 18 -46
6 18 32
6 9 -12
12 5 55
23 24 72
22 3 85
3 2 -14
17 9 55
*/