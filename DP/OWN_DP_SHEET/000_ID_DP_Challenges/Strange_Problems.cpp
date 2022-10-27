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
    for (int i = x; i < y; i++)      \
        cout << setw(3) << i << " "; \
    cout << endl

#define print2dvec(v)                    \
    for (auto x : v)                     \
        for (auto y : x)                 \
            cout << setw(3) << y << " "; \
    cout << endl;

#define printarr(n, arr)                  \
    for (int i = 0; i < n; i++)           \
        cout << setw(3) << arr[i] << " "; \
    cout << endl;

#define print2darr(n, m, arr)                    \
    for (int i = 0; i < n; i++)                  \
        for (int j = 0; j < m; j++)              \
            cout << setw(3) << arr[i][j] << " "; \
    \ cout << endl;

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

void solve()
{
    ll n, k;
    cin >> n >> k;
    vl v(n);

    for (ll &x : v)
        cin >> x;

    ll t = n / k + (n % k != 0);

    vl dp(n);

    ll max_end = -1, mx_1 = -1, mx_2 = -1;

    for (ll i = 0; i < min(n, k); i++)
    {
        dp[i] = max(v[i], 0ll);
        if (dp[i] >= mx_1)
        {
            mx_2 = exchange(mx_1, dp[i]);
            max_end = i;
        }
        else if (dp[i] >= mx_2)
        {
            mx_2 = dp[i];
        }
    }

    ll _max_end = max_end, _mx_1 = mx_1, _mx_2 = mx_2;

    ll mx = LLONG_MIN;

    for (ll i = min(n, k); i < n; i++)
    {

        if (i - max_end != k)
        {
            dp[i] = max(v[i], 0ll) + mx_1;
        }
        else
        {
            dp[i] = max(max(v[i], 0ll) + mx_2, mx_1);
        }

        if (dp[i] >= _mx_1)
        {
            _mx_2 = exchange(_mx_1, dp[i]);
            _max_end = i;
        }
        else if (dp[i] >= _mx_2)
        {
            _mx_2 = dp[i];
        }

        if (i % k == k - 1)
        {
            max_end = _max_end;
            mx_1 = _mx_1;
            mx_2 = _mx_2;
        }

        mx = max<ll>(mx, dp[i]);
    }

    cout << mx << "\n";
}

int main()
{
    int _;
    cin >> _;

    while (_--)
    {
        solve();
    }
}
