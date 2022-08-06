#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl

#define deb2(x, y) cout << #x << " = " << x << "\n" \
                        << #y << "=" << y << endl

#define debwe(x) cout << #x << " = " << x
#define check(x) cout << "--------" << x << endl

#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)

#define pb push_back
#define mp make_pair
#define ar array

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pll> vpl;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define inp  \
    ll temp; \
    cin >> temp;

#define LSB(n) (n & -n)

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

// template <typename... T>
// void read(T &...args)
// {
//     ((cin >> args), ...);
// }

// template <typename... T>
// void write(T &&...args)
// {
//     ((cout << args << " "), ...);
// }

const int mxn = 1e3;
const ll MXN = 1e9 + 1;
#define MOD 1e9 + 7;

class BIT
{
public:
    int n;
    vector<int> bit;
    BIT(int s)
    {
        this->n = s + 1;
        bit.assign(n, 0);
    }

    void update(int i, int delta)
    {
        // delta = delta - bit[i];
        i++;
        while (i < n)
        {
            bit[i] += delta;
            i += LSB(i);
        }
    }
    int prefixSum(int i)
    {
        int sum = 0;
        i++;
        while (i > 0)
        {
            sum += bit[i];
            i -= LSB(i);
        }

        return sum;
    }

    int range_sum(int l, int r)
    {
        return (prefixSum(r) - prefixSum(l - 1));
    }

    void init()
    {
        vi v;
        for (int i = 0; i < n - 1; i++)
        {
            inp;
            v.pb(temp);
        }

        for (int i = 0; i < n - 1; i++)
        {
            this->update(i, v[i]);
        }

        int t;
        cin >> t;
        while (t--)
        {
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    BIT obj(n);
}

/*


*/
