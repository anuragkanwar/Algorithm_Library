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
    void simpleFact(unordered_map<int, int> &pfact, int n)
    {
        if (n < 1)
        {
            return;
        }

        int pw = 0;
        while (n % 2 == 0)
        {
            pw++;
            n /= 2;
        }
        pfact[2] = pw;
        pw = 0;
        if (n == 0)
        {
            return;
        }
        while (n % 3 == 0)
        {
            pw++;
            n /= 3;
        }
        pfact[3] = pw;
        pw = 0;
        if (n == 0)
        {
            return;
        }
        for (int i = 5; i * i <= n; i += 6)
        {
            while (n % i == 0)
            {
                pw++;
                n /= i;
            }
            pfact[i] = pw;
            pw = 0;
            if (n == 0)
            {
                return;
            }
            while (n % (i + 2) == 0)
            {
                pw++;
                n /= (i + 2);
            }
            pfact[i + 2] = pw;
            pw = 0;
            if (n == 0)
            {
                return;
            }
        }
        if (n > 3)
            pfact[n] = 1;
    }

    void seiveFact(unordered_map<int, int> &pfact, int n)
    {
        vi smallestPrime(n + 1);
        iota(smallestPrime.begin(), smallestPrime.end(), 0);

        for (int i = 4; i <= n; i += 2)
        {
            smallestPrime[i] = 2;
        }

        for (int i = 3; (long long)i * i <= n; i += 2)
        {
            if (smallestPrime[i] == i)
            {
                for (long long j = (long long )i * i; j <= n; j += (i << 1))
                {
                    smallestPrime[j] = i;
                }
            }
        }

        while (n != 1)
        {
            pfact[smallestPrime[n]]++;
            n/=smallestPrime[n];
        }
    }
    void init()
    {
        int n;
        cin >> n;
        unordered_map<int, int> m;
        seiveFact(m, n);

        for (auto x : m)
        {
            cout << x.first << " --> " << x.second << endl;
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