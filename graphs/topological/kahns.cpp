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
    unordered_map<int, vi> adj;
    vi ans, indeg;
    queue<int> s;
    int n, m;
    void init()
    {
        cin >> n >> m;
        indeg.assign(n + 1, 0);

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            indeg[b]++;
            adj[a].pb(b);
        }

        for (int i = 1; i < n + 1; i++)
        {
            if (indeg[i] == 0)
            {
                s.push(i);
            }
        }

        while (s.size())
        {
            int u = s.front();
            s.pop();

            while (adj[u].size())
            {
                int np = adj[u].back();
                indeg[np]--;
                adj[u].pop_back();
                if (indeg[np] == 0)
                {
                    s.push(np);
                }
            }


            ans.pb(u);
        }

        bool ok = true;

        for (auto x : indeg)
        {
            if (x != 0)
            {
                ok = false;
            }
        }

        if (ok)
        {
            printvec(ans);
        }
        else
        {
            cout << "Impossible";
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
6 6
1 2
2 3
3 5
3 4
4 5
1 4
*/