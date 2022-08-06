#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl

#define deb2(x, y) cout << #x << " = " << x << "\n" \
                        << #y << " = " << y << endl

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

struct ST
{
    int m;
    vi low, high, val, delta;
    vb mark;

    void init(int i, int l, int r)
    {
        low[i] = l, high[i] = r;
        if (l == r)
            return;

        int mid = l + (r - l) / 2;
        init((i << 1), l, mid);
        init((i << 1) + 1, mid + 1, r);
    }

    ST(int n) : m((n << 2) + 1), low((n << 2) + 1), high((n << 2) + 1), delta((n << 2) + 1, 0), val((n << 2) + 1, 0), mark((n << 2) + 1, false)
    {
        init(1, 0, n - 1);
    }

    void prop(int i)
    {
        if (mark[i])
        {
            val[(i << 1)] = val[i];
            val[(i << 1) + 1] = val[i];
            delta[(i << 1)] = delta[i];
            delta[(i << 1) + 1] = delta[i];
            delta[i] = 0;
            mark[(i << 1)] = mark[(i << 1) + 1] = true;
            mark[i] = false;
        }
        else
        {
            delta[(i << 1)] += delta[i];
            delta[(i << 1) + 1] += delta[i];
            delta[i] = 0;
        }
    }

    void update(int i)
    {
        val[i] = max(val[(i << 1)] + delta[(i << 1)], val[(i << 1) + 1] + delta[(i << 1) + 1]);
    }

    void rangeUpdate(int i, int l, int r, int v)
    {
        if (r < low[i] || high[i] < l)
            return;

        if (l <= low[i] && high[i] <= r)
        {
            delta[i] += v;
            return;
        }

        prop(i);
        rangeUpdate((i << 1), l, r, v);
        rangeUpdate((i << 1) + 1, l, r, v);
        update(i);
    }

    void rangeSet(int i, int l, int r, int v)
    {
        if (r < low[i] || high[i] < l)
            return;

        if (l <= low[i] && high[i] <= r)
        {
            val[i] = v;
            mark[i] = true;
            delta[i] = 0;
            return;
        }

        prop(i);
        rangeSet((i << 1), l, r, v);
        rangeSet((i << 1) + 1, l, r, v);
        update(i);
    }

    void display()
    {
        for (int i = 1; i < 16; i++)
        {
            cout << i << " -> "
                 << "( " << low[i] << ", " << high[i] << " ) " << val[i] << " " << delta[i] << " " << mark[i] << endl;
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
        int t;
        cin >> t;
        while (t--)
        {
            char type;
            cin >> ws;
            cin >> type;
            int l, r, v;
            cin >> l >> r >> v;

            switch (type)
            {
            case 's':
                st.rangeSet(1, l, r, v);
                break;
            case 'u':
                st.rangeUpdate(1, l, r, v);
            }
            st.display();
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