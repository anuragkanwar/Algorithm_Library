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
    int seive(int n, vb &isPrime)
    {
        int ans;
        if (n < 2)
        {
            ans = 0;
            return ans;
        }
        else
        {
            ans = 1;
            isPrime[0] = false;
            isPrime[1] = false;
        }

        for (int i = 4; i <= n; i += 2)
        {
            isPrime[i] = false;
        }

        for (int i = 3; (long long)i * i <= n; i += 2)
        {
            if (isPrime[i])
            {
                ans++;
                for (int j = (long long)i * i; j <= n; j += (i << 1))
                {
                    isPrime[j] = false;
                }
            }
        }
    }

    void segmented_seive(vi &Primes, int l, int r)
    {
        vi allPrimes;
        int n = sqrt(r);
        vb isPrime(n + 1, true);

        for (int i = 4; i <= n; i += 2)
        {
            isPrime[i] = false;
        }

        for (int i = 3; (long long)i <= n; i += 2)
        {
            if (isPrime[i])
            {
                for (long long j = (long long)i * i; j <= n; j += (i << 1))
                {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= n; i++)
        {
            if (isPrime[i])
                allPrimes.pb(i);
        }

        vb isPrimen(r - l + 1, true);

        printvec(allPrimes);
        for (int x : allPrimes)
        {
            for (long long i = max((long long)x * x, (long long)((l + x - 1) / x) * x); i <= r; i += x)
            {
                isPrimen[i - l] = false;
            }
        }

        if (l == 1)
        {
            isPrimen[0] = false;
        }

        for (int i = 0; i < r - l + 1; i++)
        {
            if (isPrimen[i])
                Primes.pb(i + l);
        }

        printvec(Primes);
    }

    void init()
    {
        int l, r;
        cin >> l >> r;
        vi Primes;
        // vb isPrime(n + 1, true);
        // cout << seive(n, isPrime);
        segmented_seive(Primes, l, r);
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