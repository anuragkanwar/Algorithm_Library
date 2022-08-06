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
    /*
        Method :- 1
        formulae - sum(phi(d)) = n
        where d | n

        for n  = 6
    =>  6 = phi(1) + phi(2) + phi(3) + phi(6)
    => phi(6) = n - (phi(1) + phi(2) + phi(3))


    **IMPORTENT**
        preProcessing time - o(nlogn)
        query time - o(1)
    */

    void dp_sol(vi &dp, int n)
    {
        for (int i = 2; i <= n; i++)
        {
            for (int j = (i << 1); j <= n; j += i)
            {
                dp[j] -= dp[i];
            }
        }
    }

    /*
        Method :- 2
        formulae -> phi(n) = n . (1-1/p1) . (1-1/p2) ... (1-1/pk)

        **IMPORTENT**
        preProcessing time - o(nloglogn) ~ o(n)
        query time - o(1)

    */

    void seive_sol(vi &ans, int n)
    {
        for (int i = 2; i <= n; i++)
        {
            if (ans[i] == i)
            {
                ans[i]--;
                for (int j = (i << 1); j <= n; j += i)
                {
                    ans[j] -= (ans[j] / i);
                }
            }
        }
    }

    void init()
    {
        int n;
        cin >> n;

        vi ans1(n + 1), ans2(n + 1);
        iota(ans1.begin(), ans1.end(), -1);
        iota(ans2.begin(), ans2.end(), 0);
        ans1[0] = 0;
        ans1[1] = 1;
        dp_sol(ans1, n);
        seive_sol(ans2, n);
        printvec(ans1);
        cout << endl;
        printvec(ans2);

        // cout << (ans1 == ans2) << endl;
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