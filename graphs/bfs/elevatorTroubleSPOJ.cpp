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
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    ll f, s, g, u, d, t, ans = 0;

    queue<ll> q;
    map<ll, ll> parent;
    bool visited[1000001];
    cin >> f >> s >> g >> u >> d;
    if (s <= f && s >= 1)
    {

        for (ll i = 1; i <= f; i++)
        {
            visited[i] = 0;
            parent[i] = -1;
        }

        ll dr[2] = {u, -d};
        bool flag = 0;
        q.push(s);
        visited[s] = true;
        while (!q.empty())
        {
            ll v = q.front();
            ans++;
            q.pop();
            if (v == g)
            {
                flag = 1;
                break;
            }
            int i;
            if (v < g && v + dr[0] <= f)
            {
                i = 0;
            }
            else if (v + dr[1] > 0)
            {
                i = 1;
            }
            else
            {
                continue;
            }

            if (!visited[v + dr[i]])
            {
                q.push(v + dr[i]);
                visited[v + dr[i]] = 1;
                parent[v + dr[i]] = v;
            }
        }
        if (!flag)
            cout << "use the stairs" << endl;
        else
        {
            cout << ans - 1;
        }
    }
    else
    {
        cout << "use the stairs" << endl;
    }
}

/*
10 1 10 2 1
100 2 1 1 0
10 8 3 2 1
*/