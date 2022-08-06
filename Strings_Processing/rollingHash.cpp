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
    vl powpow;
    int p = 31;
    ll calc_hash(string str)
    {
        int p_pow = 1;
        ll hashval = 0;
        int n = str.size();
        for (int i = n - 1; i >= 0; i--)
        {
            hashval = (hashval % MOD + ((str[i] - 'a' + 1) % MOD * (p_pow) % MOD) % MOD) % MOD;
            p_pow = (p_pow * p) % MOD;
        }
        return hashval;
    }

    void hash_push_last(ll &hashval, char ch)
    {
        check(1);
        deb(hashval);
        hashval = (hashval % MOD * p % MOD) % MOD;
        check(2);
        deb(hashval);
        hashval = (hashval % MOD + (ch - 'a' + 1)) % MOD;
        check(3);
        deb(hashval);
    }

    void hash_pull_front(int n, ll &hashval, char ch)
    {
        check(4);
        deb(hashval);
        hashval = (hashval - ((ch - 'a' + 1) * (powpow[n - 1])) % MOD) % MOD;
        check(5);
        deb(hashval);
    }

    void init()
    {
        string ptrn, txt;
        getline(cin, ptrn);
        getline(cin, txt);
        int m = ptrn.size();
        powpow.resize(m + 1);
        powpow[0] = 1;

        for (int i = 1; i < m + 1; i++)
        {
            powpow[i] = (powpow[i - 1] * p) % MOD;
        }

        ll ptrnhash = calc_hash(ptrn);
        ll rollhash = calc_hash(txt.substr(0, m));
        vi ans;
        for (int i = 0, j = m; j < txt.size() + 1; j++, i++)
        {
            deb2(ptrnhash, rollhash);
            if (rollhash == ptrnhash)
            {
                ans.pb(i);
            }
            hash_pull_front(m, rollhash, txt[i]);
            hash_push_last(rollhash, txt[j]);
        }

        printvec(ans);
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
foobarfoo
foobarfoobarfoobarfoobarfoobarfoo


*/