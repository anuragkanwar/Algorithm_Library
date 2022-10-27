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
    int dp[10000][10000];
    int solve(int l, int r, vl &psum)
    {
        if (l >= r || l < 0 || r < 0)
        {
            return 0;
        }

        if (l < 1e4 && r < 1e4 && dp[l][r] != -1)
        {
            return dp[l][r];
        }

        int ans = 0;
        int ind = -1;
        int i = l, j = r;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            int left_sum = psum[mid] - (l - 1 >= 0 ? psum[l - 1] : 0);
            int right_sum = psum[r] - (mid >= 0 ? psum[mid] : 0);
            if (left_sum == right_sum)
            {
                ind = mid;
                j = mid - 1;
            }
            else if (left_sum < right_sum)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }

        if (ind != -1)
        {
            ans = max(ans, max(solve(l, ind, psum), solve(ind + 1, r, psum)) + 1);
            if (l < 1e4 && r < 1e4)
            {
                dp[l][r] = ans;
            }
        }
        return ans;
    }

    void init()
    {
        int n, sum = 0;
        cin >> n;

        vl psum, v(n);
        for (ll &x : v)
        {
            cin >> x;
            sum += x;
            psum.pb(sum);
        }
        memset(dp, -1, sizeof(dp));
        cout << solve(0, n - 1, psum) << "\n";
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