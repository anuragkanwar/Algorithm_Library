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

class ST
{
public:
    vi low, high, val, delta;

    ST(int n) : low(4 * n + 1), high(4 * n + 1), val(4 * n + 1, 0), delta(4 * n + 1, 0)
    {
        init(1, 0, n - 1);
    }

    void init(int i, int l, int h)
    {
        low[i] = l;
        high[i] = h;

        if (l == h)
            return;

        int mid = l + (h - l) / 2;

        init((i << 1), l, mid);
        init((i << 1) + 1, mid + 1, h);
    }

    void prop(int i)
    {
        delta[(i << 1)] += delta[i];
        delta[(i << 1) + 1] += delta[i];
        delta[i] = 0;
    }

    void update(int i)
    {
        int lc = (i << 1);
        int rc = (i << 1) + 1;
        int left = val[lc] + (delta[lc] * (high[lc] - low[lc] + 1));
        int right = val[rc] + (delta[rc] * (high[rc] - low[rc] + 1));
        val[i] = left + right;
    }

    void increment(int i, int l, int r, int del)
    {
        if (low[i] > r || high[i] < l)
            return;
        if (l <= low[i] && high[i] <= r)
        {
            delta[i] += del;
            return;
        }

        prop(i);
        increment((i << 1), l, r, del);
        increment((i << 1) + 1, l, r, del);
        update(i);
    }

    int query(int i, int l, int r)
    {
        if (low[i] > r || high[i] < l)
            return 0;
        if (l <= low[i] && high[i] <= r)
        {
            return (val[i] + (delta[i] * (high[i] - low[i] + 1)));
        }

        prop(i);
        int left = query((i << 1), l, r);
        int right = query((i << 1) + 1, l, r);
        update(i);

        return left + right;
    }

    void display()
    {
        for (int i = 0; i < val.size(); i++)
        {
            cout << i << " -> " << val[i] << " " << delta[i] << "\n";
        }
    }
};

class A
{
public:
    void init()
    {
        int n;
        cin >> n;
        ST st(n);
        for (int i = 0; i < n; i++)
        {
            st.increment(1, i, i, 1);
        }

        st.display();

        int q = 1000;
        while (q--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            st.increment(1, a, b, c);
            st.display();
            cin >> a >> b;
            cout << st.query(1, a, b) << "\n";
        }
    }
} obj;

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    obj.init();
}

/*


*/