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

class knapsack01
{
public:
    ll W, n;
    vl wt, val;
    ll vst[mxn][mxn];

    ll knapmemo(int cap, int ind, int ans)
    {
        if (cap == 0 || ind == 0)
        {
            return ans;
        }

        if (vst[ind][cap] != -1)
        {
            return vst[ind][cap];
        }

        if (wt[ind - 1] <= cap)
        {

            ans = max(knap(cap - wt[ind - 1], ind - 1, ans + val[ind - 1]), knap(cap, ind - 1, ans));
        }
        else
        {
            ans = knap(cap, ind - 1, ans);
        }
        vst[ind][cap] = ans;
        return ans;
    }

    ll knap(int cap, int ind, int ans)
    {
        if (cap == 0 || ind == 0)
        {
            deb(ans);
            return ans;
        }

        if (wt[ind - 1] <= cap)
        {
            ans = max(knap(cap - wt[ind - 1], ind - 1, ans + val[ind - 1]), knap(cap, ind - 1, ans));
        }
        else
        {
            ans = knap(cap, ind - 1, ans);
        }
        return ans;
    }

    void init()
    {
        cin >> n >> W;
        memset(vst, -1, sizeof(vst));
        for (int i = 0; i < n; i++)
        {
            ll temp;
            cin >> temp;
            wt.pb(temp);
        }

        for (int i = 0; i < n; i++)
        {
            ll temp;
            cin >> temp;
            val.pb(temp);
        }

        // cout << knap(W, n, 0);
        cout << knapmemo(W, n, 0);
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
4 7
1 3 4 5
1 4 5 7
*/