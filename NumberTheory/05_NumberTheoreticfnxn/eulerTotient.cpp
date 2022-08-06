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
    cerr << *it << " = " << a << endl;
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
    /*
    Method 1 using

    ∑ ϕ(d) = n
    d|n

    ⟹ 6 = ϕ(1) + ϕ(2) + ϕ(3) + ϕ(6)
    ⟹ ϕ(6) = 6 - (ϕ(1) + ϕ(2) + ϕ(3))
    */

    vi divisorET(int n)
    {
        vi ans(n + 1);
        iota(all(ans), -1);
        ans[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = (i << 1); j <= n; j += i)
            {
                ans[j] -= ans[i];
            }
        }

        return ans;
    }

    /*
        use this for single phi calc also
        Method 2 Sieve

        1. ϕ(pᵏ) = pᵏ - pᵏ⁻¹ , p is a prime
        2. n = p1ᵏ * p2ᵏ ...

        ϕ(n) = n(1-1/p1)(1-1/p2)...
    */

    vi SieveET(int n)
    {
        vi ans(n + 1);
        iota(all(ans), 0);
        ans[1] = 1;
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

        return ans;
    }

    void init()
    {
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