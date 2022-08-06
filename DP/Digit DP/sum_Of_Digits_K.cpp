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
        int a, b, k;
        cin >> a >> b >> k;

        int dp[18][2][(18 * 9) + 1];
        function<int(int, bool, int, string &)> rec = [&](int pos, bool tight, int sum, string &str) -> int
        {
            if (sum > k)
                return 0;

            if (pos == str.size())
                return (sum == k);

            if (dp[pos][tight][sum] != -1)
                return dp[pos][tight][sum];

            int LMT = 9;
            if (tight)
                LMT = (str[pos] - '0');

            int result = 0;
            for (int i = 0; i <= LMT; i++)
            {
                int t = tight;
                if (tight == 1 && i < LMT)
                {
                    t = 0;
                }

                if (sum + i <= k)
                    result += rec(pos + 1, t, sum + i, str);
            }

            return dp[pos][tight][sum] = result;
        };

        function<int(int, bool, int, int)> solve = [&](int pos, bool tight, int sum, int num) -> int
        {
            memset(dp, -1, sizeof(dp));
            string str = to_string(num);
            return rec(pos, tight, sum, str);
        };

        deb(solve(0, 1, 0, b));
        deb(solve(0, 1, 0, a - 1));
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