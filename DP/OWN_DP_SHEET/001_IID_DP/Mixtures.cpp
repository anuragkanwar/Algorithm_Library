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

class A
{
public:
    void init()
    {
        int n;
        // cin >> n;
        while (cin >> n)
        {
            vi v(n);
            for (int &x : v)
                cin >> x;

            vector<vector<array<ll, 2>>> dp(n, vector<array<ll, 2>>(n, {INT32_MAX, INT32_MAX}));

            for (int len = 0; len < n; len++)
            {
                for (int i = 0; i + len < n; i++)
                {
                    int j = i + len;

                    if (len == 0)
                    {
                        dp[i][j][0] = (((v[i]) % 100) + 100) % 100;
                        dp[i][j][1] = 0;
                        continue;
                    }

                    if (len == 1)
                    {
                        dp[i][j][0] = (((v[i] + v[j]) % 100) + 100) % 100;
                        dp[i][j][1] = v[i] * v[j];
                        continue;
                    }

                    for (int k = i; k < j; k++)
                    {
                        if (dp[i][j][1] > dp[i][k][1] + dp[k + 1][j][1] + (dp[i][k][0] * dp[k + 1][j][0]))
                        {
                            dp[i][j][1] = dp[i][k][1] + dp[k + 1][j][1] + (dp[i][k][0] * dp[k + 1][j][0]);
                            dp[i][j][0] = (((dp[i][k][0] + dp[k + 1][j][0]) % 100) + 100) % 100;
                        }
                    }
                }
            }

            cout << dp[0][n - 1][1] << "\n";
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


*/