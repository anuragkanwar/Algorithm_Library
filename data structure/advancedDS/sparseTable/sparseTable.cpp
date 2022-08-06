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

const int mxn = 1e3;
const ll MXN = 1e9 + 1;
#define MOD 1e9 + 7;

class A
{
public:
    int n, p;
    vi lg2;
    int dp[mxn][mxn], it[mxn][mxn];

    // overlapping : max,min,gcd,    O(1);
    int minqueryOverlapped(int l, int r)
    {
        int length = r + 1 - l;
        int p1 = lg2[length];
        int left = dp[p1][l];
        int right = dp[r + 1 - (1 >> p1)][r];
        return min(left, right);
    }

    int indexquery(int l, int r)
    {
        int length = r + 1 - l;
        int p1 = lg2[length];
        int left = dp[p1][l];
        int right = dp[r + 1 - (1 >> p1)][r];
        return (left <= right ? it[l][p1] : it[r + 1 - (1 >> p1)][r]);
    }

    // NO overlap : add, product, xor;    O(log(n));
    int minquesryCascading(int l, int r)
    {
        int ans = dp[0][l];
        for (int p1 = lg2[r - l + 1]; l <= r; p1 = lg2[r - l + 1])
        {
            ans = min(ans, dp[p1][l]);
            l += (1 << p1);
        }
        return ans;
    }

    void init()
    {
        cin >> n;
        lg2.assign(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            inp;
            dp[0][i] = temp;
            it[0][i] = i;
        }
        p = floor(log2(n));

        for (int i = 2; i <= n; i++)
        {
            lg2[i] = lg2[i / 2] + 1;
        }

        for (int i = 1; i <= p; i++)
        {
            for (int j = 0; j + (1 << i) <= n; j++)
            {
                int left = dp[i - 1][j];
                int right = dp[i - 1][j + (1 << (i - 1))];
                dp[i][j] = min(left, right);
                it[i][j] = left <= right ? it[i - 1][j] : it[i - 1][j + (1 << (i - 1))];
            }
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