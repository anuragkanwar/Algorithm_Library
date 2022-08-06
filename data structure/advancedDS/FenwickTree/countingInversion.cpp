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

class A
{
public:
    int n, mx, ans;
    vi v, bit;

    int LSB(int i)
    {
        return (i & -i);
    }

    void update(int i)
    {
        while (i <= mx)
        {
            bit[i]++;
            i += LSB(i);
        }
    }

    int prefix_cnt(int i)
    {
        int sum = 0;
        while (i > 0)
        {
            sum += bit[i];
            i -= LSB(i);
        }
        return sum;
    }

    int count_query(int i)
    {
        if (i >= mx)
        {
            return 0;
        }
        return (prefix_cnt(mx) - prefix_cnt(i));
    }

    void init()
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            inp;
            v.pb(temp);
        }
        mx = *max_element(v.begin(), v.end());

        bit.assign(mx + 1, 0);
        ans = 0;
        for (auto x : v)
        {
            update(x);
            int temp = count_query(x);
            ans += temp;
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
7
7 6 2 3 1 4 5
*/