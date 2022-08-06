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
    int bin_pow(int a, int b)
    {
        int res = 1;
        int fact = a;
        while (b > 0)
        {
            if (b & 1)
                res *= fact;
            fact *= fact;
            b >>= 1;
        }
        return res;
    }

    unordered_map<int, int> Prime_Fact0(int n)
    {
        int nn = n;
        vi sPrime(n + 1);
        iota(sPrime.begin(), sPrime.end(), 0);

        for (int i = 2; i <= n; i += 2)
        {
            sPrime[i] = 2;
        }

        for (int i = 3; i * i <= n; i++)
        {
            if (sPrime[i] == i)
            {
                for (int j = i * i; j <= n; j += (i << 1))
                {
                    sPrime[j] = i;
                }
            }
        }

        unordered_map<int, int> m;

        while (nn > 1)
        {
            m[sPrime[nn]]++;
            nn /= sPrime[nn];
        }

        return m;
    }

    void init()
    {
        int n;
        cin >> n;

        unordered_map<int, int> m = Prime_Fact0(n);

        for (auto &x : m)
        {
            cout << x.first << "^" << x.second << "\n";
        }
        
        int ans = 1;
        for (const pair<int, int> x : m)
        {
            ans *= (bin_pow(x.first, x.second + 1) - 1) / (x.first - 1);
        }

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