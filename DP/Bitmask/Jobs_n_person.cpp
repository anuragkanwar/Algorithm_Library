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
        int n;
        cin >> n;
        vvi cost(n, vi(n));
        fo(i, n)
        {
            fo(j, n)
            {
                cin >> cost[i][j];
            }
        }

        // dp[i][j] represents --- min ans if `ith`job assign is assign to `jth` set of people
        vvi dp(n, vi((1 << n) + 1, INT32_MAX));
        for (int j = 0; j < n; j++)
        {
            dp[0][(1 << j)] = cost[j][0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < (1 << n); j++)
            {
                int temp = j;
                while (temp)
                {
                    int mask = (temp & -temp);
                    dp[i][j] = min(dp[i][j], cost[(int)log2(mask)][i] + dp[i - 1][(j & ~(mask))]);
                    temp &= (temp - 1);
                }
            }
        }

        deb(dp[n - 1][(1 << n) - 1]);
    }
} obj;

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    obj.init();
}

/*
4
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4

*/