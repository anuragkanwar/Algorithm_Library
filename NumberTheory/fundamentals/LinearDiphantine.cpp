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
    ll exteuc(ll a, ll b, ll &x, ll &y)
    {
        if (b == 0)
        {
            x = 1;
            y = 0;
            return a;
        }

        ll x1, y1;
        ll d = exteuc(b, a % b, x1, y1);
        x = y1;
        y = x1 - y1 * (a / b);
        return d;
    }

    bool find_any_solution(ll a, ll b, ll c, ll &x, ll &y, ll &g)
    {
        g = exteuc(a, b, x, y);
        deb(g);
        if (c % g)
            return false;

        x *= (c / g);
        y *= (c / g);

        x *= (a < 0 ? -1 : 1);
        y *= (b < 0 ? -1 : 1);
        return true;
    }

    void shift_solution(ll a, ll b, ll &x, ll &y, ll cnt)
    {
        x += (cnt * b);
        y -= (cnt * a);
    }

    int find_all_solution(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy)
    {
        ll x, y, g;
        if (!find_any_solution(a, b, c, x, y, g))
        {
            return -1;
        }

        a /= g;
        b /= g;

        int sign_a = (a < 0 ? -1 : 1);
        int sign_b = (b < 0 ? -1 : 1);

        shift_solution(a, b, x, y, (minx - x) / b);
        if (x < minx)
            shift_solution(a, b, x, y, sign_b);
        if (x > maxx)
            return 0;
        ll lx1 = x;

        shift_solution(a, b, x, y, (maxx - x) / b);
        if (x > maxx)
            shift_solution(a, b, x, y, -sign_b);
        ll rx1 = x;

        shift_solution(a, b, x, y, -((miny - y) / a));
        if (y < miny)
            shift_solution(a, b, x, y, -sign_a);
        if (y > maxy)
            return 0;
        ll lx2 = x;

        shift_solution(a, b, x, y, -((maxy - y) / a));
        if (y > maxy)
            shift_solution(a, b, x, y, sign_a);
        ll rx2 = x;

        if (lx2 > rx2)
        {
            swap(lx2, rx2);
        }

        ll lx = max(lx1, lx2);
        ll rx = min(rx1, rx2);
 vb
        if (lx > rx)
            return 0;
        return (((rx - lx) / abs(b)) + 1);
    }
    void init()
    {
        ll t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
            ll a, b, c;
            ll minx, maxx, miny, maxy;
            cin >> a >> b >> c;
            cin >> minx >> maxx >> miny >> maxy;
            c *= -1;
            ll ans = find_all_solution(a, b, c, minx, maxx, miny, maxy);
            if (ans == -1)
            {
                cout << "IMPOSSIBLE";
            }
            else
            {
                cout << "Case " << i << ": " << ans << endl;
            }
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
5
1 1 -5 -5 10 2 4
-10 -8 80 -100 100 -90 90
2 3 -4 1 7 0 8
-2 -3 6 -2 5 -10 5
1 8 -32 0 0 1 10
*/