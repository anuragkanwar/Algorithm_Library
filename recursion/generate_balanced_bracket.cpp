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

const int mxn = 1e5;
const ll MXN = 1e9 + 1;

void balanced(int n1, int n2, string op)
{
    if (n1 == 0 && n2 == 0)
    {
        cout << op << endl;
        return;
    }
    string op1, op2;
    op1 = op;
    op2 = op;
    if (n1)
    {
        if (n1 < n2)
        {
            op1 += "(";
            op2 += ")";
            balanced(n1 - 1, n2, op1);
            balanced(n1, n2 - 1, op2);
        }
        else
        {
            op1 += "(";
            balanced(n1 - 1, n2, op1);
        }
    }
    else
    {
        op2 += ")";
        balanced(n1, n2 - 1, op2);
    }
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int n;
    cin >> n;

    balanced(n - 1, n, "(");
}

/*


*/