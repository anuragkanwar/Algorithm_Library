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
    ll extEuclid(ll a, ll b, ll &x, ll &y)
    {
        if (b == 0)
        {
            x = 1, y = 0;
            return a;
        }

        ll x1, y1, g;
        g = extEuclid(b, a % b, x1, y1);
        x = y1;
        y = x1 - ((a / b) * y1);
    }

    void init()
    {
        ll n;
        cin >> n;
        vl a, m;
        for (ll i = 0; i < n; i++)
        {
            inp;
            a.pb(temp);
        }
        for (ll i = 0; i < n; i++)
        {
            inp;
            m.pb(temp);
        }

        ll a1 = a[0];
        ll m1 = m[0];

        for (ll i = 1; i < n; i++)
        {
            ll a2 = a[i], m2 = m[i];
            ll g = __gcd(m1, m2);
            if (a1 % g != a2 % g)
            {
                cout << " NO solution";
                break;
            }
            ll p, q;
            extEuclid(m1 / g, m2 / g, p, q);
            int mod = (m1 / g) * m2;
            ll x = (a1 * (m2 / g) * q + a2 * (m1 / g) * p) % mod;

            a1 = x;
            if (a1 < 0)
                a1 += mod;
            m1 = mod;
        }

        deb2(a1, m1);
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