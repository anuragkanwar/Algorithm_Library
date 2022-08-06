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
    void init()
    {
        string str;
        getline(cin, str);

        int n = str.size();
        vi d1(n, 0), d2(n, 0);

        int mx_odd_length = 0;
        for (int i = 0, l = 0, r = -1; i < n; i++)
        {

            int k = (i > r) ? 0 : min(r - i, d1[l + r - i]);

            while (i - k >= 0 && i + k < n && (str[i - k] == str[i + k]))
                k++;

            d1[i] = k--;

            if (i + k > r)
            {
                l = i - k;
                r = i + k;
            }

            mx_odd_length = max(mx_odd_length, (d1[i] << 1) - 1);
        }
        int mx_even_length = 0;
        for (int i = 0, l = 0, r = -1; i < n; i++)
        {
            int k = (i > r) ? 0 : min(r - i, d2[l + r - i + 1]);

            while (i - k - 1 >= 0 && i + k < n && (str[i - k - 1] == str[i + k]))
                k++;

            d2[i] = k--;
            if (i + k > r)
            {
                l = i - k - 1;
                r = i + k;
            }

            mx_even_length = max(mx_even_length, (d2[i] << 1));
        }

        ll count_odd = 0;
        ll count_even = 0;
        ll count_total = 0;

        for (int i = 0; i < n; i++)
        {
            count_odd += d1[i];
            count_even += d2[i];
            count_total += (d1[i] + d2[i]);
        }

        deb(count_odd);
        deb(count_even);
        deb(count_total);
        deb(mx_odd_length);
        deb(mx_even_length);
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