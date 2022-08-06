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

        int left = ceil(pow(10, n - 1));
        int right = ceil(pow(10, n)) - 1;

        string l = to_string(left);
        string r = to_string(right);
        int dp[n + 1][2][10];
        function<int(int, bool, vb, int, string &)> rec = [&](int pos, bool tight, vb mark, int cnt, string &str) -> int
        {
            if (pos == n)
            {
                return 1;
            }

            if (dp[pos][tight][cnt] != -1)
            {
                return dp[pos][tight][cnt];
            }

            int LMT = 9;
            int st_LMT = 0;
            if (tight)
                st_LMT = (str[pos] - '0');

            int result = 0;
            for (int i = st_LMT; i <= LMT; i++)
            {
                if (mark[i])
                {
                    continue;
                }
                mark[i] = true;
                result += rec(pos + 1, false, mark, cnt + 1, str);
                mark[i] = false;
            }
            return dp[pos][tight][cnt] = result;
        };

        memset(dp, -1, sizeof(dp));
        vector<bool> mark(10, false);
        int ans = rec(0, true, mark, 0, l);

        ans = (right - left + 1 - ans);
        deb(ans);
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