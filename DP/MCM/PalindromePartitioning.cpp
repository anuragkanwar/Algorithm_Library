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
#define MOD 1e9 + 7;

class A
{
public:
    int n;
    string str;
    int dp[mxn][mxn];

    bool ispalindrome(int i, int j)
    {
        string a, b;
        a = str.substr(i, j + 1 - i);
        b = a;
        reverse(a.begin(), a.end());
        return a == b ? 1 : 0;
    }

    int calc(int i, int j)
    {
        if (i >= j)
        {
            dp[i][j] = 0;
            return 0;
        }

        if (ispalindrome(i, j))
        {
            return 0;
        }

        int ans = INT32_MAX;
        for (int k = i; k < j; k++)
        {
            int temp = (dp[i][k] != -1 ? dp[i][k] : calc(i, k)) + (dp[k + 1][j] != -1 ? dp[k + 1][j] : calc(k + 1, j)) + 1;
            ans = min(ans, temp);
            dp[i][j] = ans;
        }
        return ans;
    }

    void init()
    {
        memset(dp, -1, sizeof(dp));
        getline(cin, str);
        n = str.size();

        cout << calc(0, n - 1);
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