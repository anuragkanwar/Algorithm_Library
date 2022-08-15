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
#define all(x) (x).begin(), (x).end()

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
    unordered_map<int, int> m;
    int sz = 0;
    void add(int &x)
    {
        m[x]++;
        if (m[x] == 1)
        {
            sz++;
        }
    }
    void remove(int &x)
    {
        if (m[x] == 1)
        {
            sz--;
        }
        m[x]--;
    }

    int get_ans()
    {
        return sz;
    }

    void init()
    {
        int n;
        cin >> n;
        vi v(n);
        for (auto &x : v)
        {
            cin >> x;
        }

        int q;
        cin >> q;
        vector<array<int, 3>> qry(q);

        int s = sqrt((n + .0)) + 1, k = 0;
        for (auto &x : qry)
        {
            cin >> x[0] >> x[1];
            x[2] = k++;
            x[0]--;
            x[1]--;
        }

        sort(all(qry), [&](array<int, 3> a, array<int, 3> b)
             {
            if(a[0] / s == b[0] / s)
            {
                return a[1] < b[1];
            }
            return a[0] < b[0]; });

        vector<int> ans(q);

        int cur_l = 0;
        int cur_r = -1;
        for (auto &qr : qry)
        {
            while (cur_l > qr[0])
            {
                cur_l--;
                add(v[cur_l]);
            }

            while (cur_r < qr[1])
            {
                cur_r++;
                add(v[cur_r]);
            }

            while (cur_l < qr[0])
            {
                remove(v[cur_l]);
                cur_l++;
            }

            while (cur_r > qr[1])
            {
                remove(v[cur_r]);
                cur_r--;
            }
            ans[qr[2]] = get_ans();
        }

        for (auto &x : ans)
        {
            cout << x << "\n";
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