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

const int mxn = 1e3;
const ll MXN = 1e9 + 1;
#define MOD 1e9 + 7;

class A
{
public:
    void init()
    {
        int n;
        cin >> n;
        vector<pair<float, pair<int, int>>> vperw;
        for (int i = 0; i < n; i++)
        {
            // a->weight , b->value
            int a, b;
            cin >> a >> b;
            vperw.pb(mp(float(b) / float(a), mp(a, b)));
        }
        int k;
        cin >> k;

        sort(vperw.rbegin(), vperw.rend());

        float ans = 0;
        while (k && vperw.size())
        {
            for (auto it = vperw.begin(); it != vperw.end(); it++)
            {
                if (it->second.first <= k)
                {
                    k -= it->second.first;
                    ans += it->second.second;
                    vperw.erase(it);
                    break;
                }
                else
                {
                    ans += it->first * k;
                    k = 0;
                    vperw.erase(it);
                    break;
                }
            }
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
3
10 60
20 100
30 120
50

7
2 10
3 5
5 15
7 7
1 6
4 18
1 3
15

5
3 18
5 25
3 12
4 4
4 8
*/