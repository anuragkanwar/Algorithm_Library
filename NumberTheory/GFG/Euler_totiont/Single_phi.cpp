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
    int phi(int n)
    {
        int ans = n;

        bool ok = false;
        while (n % 2 == 0)
        {
            ok = true;
            n >>= 1;
        }
        if (ok)
            ans = ans - (ans / 2);

        ok = false;
        while (n % 3 == 0)
        {
            ok = true;
            n /= 3;
        }
        if (ok)
            ans = ans - (ans / 3);

        for (ll i = 5; (ll)i * i <= n; i += 6)
        {
            ok = false;
            while (n % i == 0)
            {
                ok = true;
                n /= i;
            }
            if (ok)
                ans = ans - (ans / i);

            ok = false;
            while (n % (i + 2) == 0)
            {
                ok = true;
                n /= (i + 2);
            }
            if (ok)
                ans = ans - (ans / (i + 2));
        }
        if (n > 3)
        {
            ans = ans - (ans / n);
        }
        return ans;
    }

    void init()
    {
        int n;
        cin >> n;
        int ans = phi(n);
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