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

#define inp   \
    int temp; \
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

class A
{
public:
    int n, key;
    vi v;

    int solve(int l, int r)
    {
        int mid;
        int ind;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (v[mid] <= v[((mid + 1) < n ? mid + 1 : mid)] && v[mid] <= v[((mid - 1) >= 0)])
            {
                ind = mid;
                break;
            }
            else
            {
                if (v[l] > v[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }

        r = n - 1;
        l = 0;
        if (key <= v[r])
        {
            l = ind;
        }
        else
        {
            r = ind - 1;
        }

        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (v[mid] == key)
            {
                return mid;
            }
            else
            {
                if (key > v[mid])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
    void init()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            inp;
            v.pb(temp);
        }
        cin >> key;

        cout << solve(0, n - 1);
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
4 6 8 10 12 14 2
10

*/