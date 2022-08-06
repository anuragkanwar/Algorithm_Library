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
        cin >> ws;
        vector<vector<char>> naksha(n, vector<char>(m));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> naksha[i][j];
            }
        }

        function<bool(int, int, char &)> e = [&](int i, int j, char &ch) -> bool
        {
            return i >= 0 && j >= 0 && i < n && j < m && naksha[i][j] == ch;
        };

        function<bool(int, int, char &, int, int)> dfs = [&](int i, int j, char &ch, int pi, int pj) -> bool
        {
            if (vis[i][j])
                return true;

            vis[i][j] = true;
            if (!(i == pi && j + 1 == pj) && e(i, j + 1, ch))
            {
                if (dfs(i, j + 1, ch, i, j))
                    return true;
            }
            if (!(i + 1 == pi && j == pj) && e(i + 1, j, ch))
            {
                if (dfs(i + 1, j, ch, i, j))
                    return true;
            }
            if (!(i == pi && j - 1 == pj) && e(i, j - 1, ch))
            {
                if (dfs(i, j - 1, ch, i, j))
                    return true;
            }
            if (!(i - 1 == pi && j == pj) && e(i - 1, j, ch))
            {
                if (dfs(i - 1, j, ch, i, j))
                    return true;
            }

            return false;
        };

        bool ok = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && !ok)
                {
                    ok = dfs(i, j, naksha[i][j], -1, -1);
                    if (ok)
                        break;
                }
            }
            if (ok)
                break;
        }

        if (ok)
            cout << "Yes\n";
        else
            cout << "No\n";
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