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
        bitset<mxn5> bs[26], oc;
        string hay;
        getline(cin, hay);
        for (int i = 0; hay[i]; i++)
            bs[hay[i] - 'a'][i] = 1;

        int q;
        cin >> q;
        while (q--)
        {
            int type, l, r;
            cin >> type;
            switch (type)
            {
            case 1:
                cin >> l, l--;
                cin >> ws;
                char ch;
                cin >> ch;
                bs[hay[l] - 'a'][l] = 0;
                bs[ch - 'a'][l] = 1;
                hay[l] = ch;
                break;

            case 2:
                cin >> l >> r, l--, r--;
                cin >> ws;
                string patt;
                getline(cin, patt);
                oc.set();
                for (int i = 0; patt[i]; i++)
                    oc &= ((bs[patt[i] - 'a']) >> i);

                if (patt.size() > (r - l + 1))
                {
                    cout << 0 << "\n";
                }
                else
                {
                    cout << (((oc >> l).count()) - (oc >> (r - patt.size() + 2)).count()) << "\n";
                }
                break;
            }
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