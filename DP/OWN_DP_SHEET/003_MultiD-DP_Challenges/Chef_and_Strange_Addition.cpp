#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define check(x) cout << "--------" << x << endl

#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)
#define all(x) (x).begin(), (x).end()

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

#define printnum(x, y)               \
    for (int i = x; i <= y; i++)     \
        cout << setw(3) << i << " "; \
    cout << endl

#define debvec(v)                    \
    for (auto x : v)                 \
        cout << setw(3) << x << " "; \
    cout << endl

#define deb2dvec(v)                      \
    for (auto x : v)                     \
    {                                    \
        for (auto y : x)                 \
        {                                \
            cout << setw(3) << y << " "; \
        }                                \
        cout << endl;                    \
    }

#define print2dvec(v)         \
    for (auto x : v)          \
    {                         \
        for (auto y : x)      \
        {                     \
            cout << y << " "; \
        }                     \
        cout << endl;         \
    }

#define printarr(n, arr)                  \
    for (int i = 0; i < n; i++)           \
    {                                     \
        cout << setw(3) << arr[i] << " "; \
    }                                     \
    cout << endl;

#define print2darr(n, m, arr)                    \
    for (int i = 0; i < n; i++)                  \
    {                                            \
        for (int j = 0; j < m; j++)              \
        {                                        \
            cout << setw(3) << arr[i][j] << " "; \
        }                                        \
        cout << endl;                            \
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
    cout << *it << " = " << a << endl;
    err(++it, args...);
}

const int mxn3 = 1e3 + 1;
const int mxn5 = 1e5 + 1;
const int mxn25 = 2e5 + 1;
const ll MXN = 1e9 + 1;
const ll MOD = 1e9 + 7;

int dp[32][32][32][2];

class A
{
public:
    int solve(int pos, int ca, int cb, int c, int &t, int &ans)
    {
        if (pos == 31)
        {
            if (!c && ca == 0 && cb == 0)
                return 1;
            return 0;
        }

        if (dp[pos][ca][cb][c] != -1)
            return dp[pos][ca][cb][c];

        int temp = 0;

        if (t & (1 << pos))
        {
            if (c)
            {
                if (ca > 0 && cb > 0)
                    temp += solve(pos + 1, ca - 1, cb - 1, 1, t, ans);
                temp += solve(pos + 1, ca, cb, 0, t, ans);
            }
            else
            {
                if (ca > 0)
                    temp += solve(pos + 1, ca - 1, cb, 0, t, ans);
                if (cb > 0)
                    temp += solve(pos + 1, ca, cb - 1, 0, t, ans);
            }
        }
        else
        {
            if (c)
            {
                if (ca > 0)
                    temp += solve(pos + 1, ca - 1, cb, 1, t, ans);
                if (cb > 0)
                    temp += solve(pos + 1, ca, cb - 1, 1, t, ans);
            }
            else
            {
                if (ca > 0 && cb > 0)
                    temp += solve(pos + 1, ca - 1, cb - 1, 1, t, ans);
                temp += solve(pos + 1, ca, cb, 0, t, ans);
            }
        }

        dp[pos][ca][cb][c] = temp;
        return temp;
    }

    void init()
    {
        int a, b, c;
        cin >> a >> b >> c;
        memset(dp, 0xff, sizeof(dp));
        int ans = 0;
        ans = solve(0, __builtin_popcount(a), __builtin_popcount(b), 0, c, ans);
        cout << ans << "\n";
    }
} obj;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll _;
    cin >> _ >> ws;
    while (_--)
    {
        A obj;
        obj.init();
    }
}

/*


*/