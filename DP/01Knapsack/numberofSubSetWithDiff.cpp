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

// template <typename... T>
// void read(T &...args)
// {
//     ((cin >> args), ...);
// }

// template <typename... T>
// void write(T &&...args)
// {
//     ((cout << args << " "), ...);
// }

#define MOD 1e9 + 7;
const int mxn = 1e3;
const ll MXN = 1e9 + 1;

class Subset
{
public:
    int n, sum = 0, diff;
    int dp[mxn][mxn];
    vi v;

    void calculate()
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (i == 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 1;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (v[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - v[i - 1]] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        print2darr(n + 1, sum + 1, dp);
    }

    void init()
    {
        cin >> n >> diff;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            sum += temp;
            v.pb(temp);
        }

        sum += diff;
        if (sum & 1)
        {
            cout << "0";
        }
        else
        {
            sum = sum >> 1;
            calculate();
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