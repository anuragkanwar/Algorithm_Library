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

const int mxn = 1e3;
const ll MXN = 1e9 + 1;
const ll MOD = 1e9 + 7;

class A
{
public:
    ll n, x;
    vi v;
    int dp[1000001];

    void cacl()
    {
        dp[0] = 1;
        sort(v.begin(), v.end());
        for (int i = 1; i <= x; i++)
        {
            for (int k = 0; k < n; k++)
            {
                if (v[k] <= i)
                {
                    dp[i] = (dp[i] + dp[i - v[k]]) % MOD;
                }
                printarr(x + 1, dp);
            }
        }

        cout << dp[x];
    }

    void init()
    {
        cin >> n >> x;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            v.pb(temp);
        }

        cacl();
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
2 4
1 2
*/