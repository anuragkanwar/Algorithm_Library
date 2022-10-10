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

#define print2darr(n, m, arr)             \
    for (int i = 0; i < n; i++)           \
    {                                     \
        for (int len = 0; len < m; len++) \
        {                                 \
            cout << arr[i][len] << " ";   \
        }                                 \
        cout << endl;                     \
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
        string s;
        cin >> s;
        int n = s.size();
        vvi dp(n + 1, vi(n + 1, 0));

        // first we will calculate all small len problems so that we can cal large len prob.
        for (int len = 0; len <= n; len++)
        {
            for (int i = 0; i < n - len; i++)
            {

                int j = i + len;

                // Base case: We just duplicate s[i]
                dp[i][j] = dp[i + 1][j] + 1;

                for (int k = i + 1; k <= j; k++)
                {

                    deb(i, len, k);
                    if (s[k] == s[i])
                    {
                        // We try match s[i] and s[k]
                        dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
                    }
                }
                print2dvec(dp);
                cout << "\n";
            }
        }
        cout << dp[0][s.size() - 1] << '\n';
    }
} oblen;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    oblen.init();
}

/*


*/