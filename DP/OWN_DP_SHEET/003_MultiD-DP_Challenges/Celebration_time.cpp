#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define debvec(v)         \
    cout << #v << " : ";  \
    for (auto x : v)      \
        cout << x << " "; \
    cout << endl

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

#define printvec(v)                  \
    for (auto x : v)                 \
        cout << setw(3) << x << " "; \
    cout << endl

#define printnum(x, y)               \
    for (int i = x; i <= y; i++)     \
        cout << setw(3) << i << " "; \
    cout << endl

#define print2dvec(v)                    \
    for (auto x : v)                     \
    {                                    \
        for (auto y : x)                 \
        {                                \
            cout << setw(3) << y << " "; \
        }                                \
        cout << endl;                    \
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

int dp[101][101][101];
class A
{
public:
    int solve(int n, int k, int prv)
    {
        if (n == 0)
        {
            return (k == 0);
        }

        if (dp[n][k][prv] != -1)
            return dp[n][k][prv];
        int c1 = solve(n - 1, k, 0) % (int)(1e6 + 3);
        int c2 = solve(n - 1, k - (prv == 1), 1) % (int)(1e6 + 3);

        dp[n][k][prv] = (c1 + c2) % (int)(1e6 + 3);
        return dp[n][k][prv];
    }

    void init()
    {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k, 0) << "\n";
    }
} obj;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll _;
    cin >> _ >> ws;
    memset(dp, -1, sizeof(dp));
    while (_--)
    {
        A obj;
        obj.init();
    }
}

/*


*/