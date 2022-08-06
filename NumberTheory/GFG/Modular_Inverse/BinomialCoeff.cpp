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
    int c_simp(int n, int k)
    {
        k = min(k, n - k);
        float res = 1;
        for (float i = 1; i <= k; i++)
        {
            res = res * (n - k + i) / i;
        }
        return (int)(res + 0.001);
    }

    void pascal(int n, int k, vvi &pas)
    {
        pas[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            pas[i][0] = 1, pas[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                pas[i][j] = pas[i - 1][j] + pas[i - 1][j - 1];
            }
        }
    }

    void factorial(int n, int m, vi &fact)
    {
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            fact[i] = (fact[i - 1] * i) % m;
        }
    }

    void InvModulus(int n, int m, vi &invmod)
    {
        invmod[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            invmod[i] = m - ((m / i) * invmod[m % i]) % m;
        }
    }

    void Invfactoral(int n, int m, vi &invfact, vi &invmod)
    {
        invfact[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            invfact[i] = (invfact[i - 1] * invmod[i]) % m;
        }
    }

    void init()
    {
        int n, k, m;
        cin >> n >> k >> m;
        int ans = c_simp(n, k);
        deb(ans);
        vvi pas(n + 1, vi(n + 1));
        pascal(n, k, pas);
        print2dvec(pas);

        vi fact(n + 1), invmod(n + 1), invfact(n + 1);
        factorial(n, m, fact);
        InvModulus(n, m, invmod);
        Invfactoral(n, m, invfact, invmod);
        cout << (fact[n] * invfact[n - k] * invfact[k]) % m;
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