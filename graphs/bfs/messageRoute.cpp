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

class MessageRoute
{
public:
    int n, m, a, b, s, d;
    map<int, bool> visited;
    map<int, vi> adj;
    map<int, int> path;
    queue<int> q;
    bool flag = 0;

    void printpath()
    {

        vi ans;
        while (d ^ s)
        {
            ans.pb(d);
            d = path[d];
        }
        ans.pb(s);
        cout << ans.size() << endl;
        reverse(ans.begin(), ans.end());
        printvec(ans);
    }

    void findpath()
    {
        q.push(s);
        visited[s] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (u == d)
            {
                flag = 1;
                break;
            }
            for (auto x : adj[u])
            {
                if (!visited[x])
                {
                    q.push(x);
                    visited[x] = 1;
                    path[x] = u;
                }
            }
        }

        if (!flag)
        {
            cout << "IMPOSSIBLE";
        }
        else
        {
            printpath();
        }
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

        for (int i = 1; i <= n; i++)
        {
            visited[i] = 0;
        }

        s = 1;
        d = n;

        findpath();
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
10 20
8 9
6 7
9 10
7 9
3 4
5 8
6 8
1 2
5 7
8 10
2 3
1 4
7 8
5 6
6 9
1 3
4 5
3 6
3 5
7 10


*/