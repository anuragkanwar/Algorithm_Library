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

const int mxn3 = 1e3 + 1;
const int mxn5 = 1e5 + 1;
const int mxn25 = 2e5 + 1;
const ll MXN = 1e9 + 1;
const ll MOD = 1e9 + 7;

void sieve_of_erat(ll n, vb &is_prime)
{
    is_prime[0] = false;
    is_prime[1] = false;
    for (ll i = 4; i <= n; i += 2)
    {
        is_prime[i] = false;
    }

    for (ll i = 3; i * i <= n; i += 2)
    {
        if (is_prime[i])
        {
            for (ll j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}

vl primes;
void segmented_sieve(ll l, ll r, vb &is_prime)
{

    // just running a simple seive here to get all the primes untill sqrt(r)
    // --------------------------------------------------------------------------------
    ll lim = sqrt(r);
    vb is_primetemp(lim + 1, true);
    primes.eb(2);
    is_primetemp[0] = false;
    is_primetemp[1] = false;

    for (ll i = 4; i <= lim; i += 2)
    {
        is_primetemp[i] = false;
    }

    for (ll i = 3; i <= lim; i += 2)
    {
        if (is_primetemp[i])
        {
            primes.eb(i);
            for (ll j = i * i; j <= lim; j += i)
            {
                is_primetemp[j] = false;
            }
        }
    }
    // --------------------------------------------------------------------------------

    for (ll x : primes)
    {
        for (ll i = max(x * x, (l + x - 1) / x * x); i <= r; i += x)
        {
            is_prime[i - l] = false;
        }

        if (l == 1)
        {
            is_prime[0] = false;
        }
    }
}

// class A{public:void init(){}} obj;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // obj.init();
    ll n, l, r;
    cin >> n;
    vb v(n + 1, true);
    sieve_of_erat(n, v);
    for (int i = 0; i < 50; i++)
    {
        cout << i + 101 << " -> " << v[i] << endl;
    }
    cin >> l >> r;
    vb v1(l - r + 1, true);
    segmented_sieve(l, r, v1);
    for (int i = 0; i < l - r + 1; i++)
    {
        cout << i + l << " -> " << v1[i] << endl;
    }
}

/*


*/