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
    bool op;
    int dp[mxn][mxn][2];

    int calc(int i, int j, bool opt)
    {
        if (i > j)
        {
            return 0;
        }

        if (i == j)
        {
            if (opt)
            {
                return str[i] == 'T';
            }
            else
            {
                return str[i] == 'F';
            }
        }

        if (dp[i][j][opt] != -1)
        {
            check(1);
            return dp[i][j][opt];
        }

        int ans = 0;
        for (int k = i + 1; k < j; k += 2)
        {
            int lt = calc(i, k - 1, true);
            int lf = calc(i, k - 1, false);
            int rt = calc(k + 1, j, true);
            int rf = calc(k + 1, j, false);

            if (str[k] == '^')
            {
                if (opt)
                {
                    ans += lt * rf + rt * lf;
                }
                else
                {
                    ans += lt * rt + lf * rf;
                }
            }
            else if (str[k] == '|')
            {
                if (opt)
                {
                    ans += lt * rt + lt * rf + lf * rt;
                }
                else
                {
                    ans += lf * rf;
                }
            }
            else
            {
                if (opt)
                {
                    ans += lt * rt;
                }
                else
                {
                    ans += lf * rf + lf * rt + lt * rf;
                }
            }
        }

        dp[i][j][opt] = ans;
        return ans;
    }

    void init()
    {
        op = true;
        getline(cin, str);
        n = str.size();
        memset(dp, -1, sizeof(dp));
        cout << calc(0, n - 1, op);
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
T|T&F^T
ans 4

*/