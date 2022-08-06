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

const int mxn = 1e4;
const ll MXN = 1e9 + 10;

class MultiBFS
{
public:
    char naksha[mxn][mxn], parent[mxn][mxn];
    ll dist[mxn][mxn];
    ll di[4] = {0, 1, 0, -1};
    ll dj[4] = {1, 0, -1, 0};
    char dr[4] = {'R', 'D', 'L', 'U'};
    // int d[4]  = {}
    queue<ar<ll, 2>> q1, q2;
    vector<ar<ll, 2>> monster;
    ar<ll, 2> s, d;
    ll n, m;
    bool flag = 0;

    bool e(ll i, ll j)
    {
        return i >= 0 && j >= 0 && i < n && j < m && naksha[i][j] == '.';
    }

    void movebfs()
    {
        q1.push(s);
        while (!q1.empty())
        {

            // check(1);

            // for (ll i = 0; i < n; i++)
            // {
            //     for (ll j = 0; j < m; j++)
            //     {
            //         cout << naksha[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl
            //      << endl;
            // check(1);

            ar<ll, 2> u = q1.front();
            q1.pop();

            queue<ar<ll, 2>> q3;
            while (!q2.empty())
            {
                ar<ll, 2> v = q2.front();
                q2.pop();

                for (ll i = 0; i < 4; i++)
                {
                    ar<ll, 2> np;
                    np[0] = v[0] + di[i];
                    np[1] = v[1] + dj[i];
                    if (!e(np[0], np[1]))
                        continue;
                    naksha[np[0]][np[1]] = 'M';
                    q3.push({np[0], np[1]});
                }
            }
            q2.swap(q3);

            if (u[0] == 0 || u[0] == n - 1 || u[1] == 0 || u[1] == m - 1)
            {
                d = {u[0], u[1]};
                flag = 1;
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                ar<int, 2> np;
                np[0] = u[0] + di[i];
                np[1] = u[1] + dj[i];
                if (!e(np[0], np[1]))
                    continue;
                naksha[np[0]][np[1]] = 'A';
                q1.push({np[0], np[1]});
                parent[np[0]][np[1]] = dr[i];
                dist[np[0]][np[1]] = i;
            }
        }

        if (!flag)
        {
            cout << "NO";
        }
        else
        {
            cout << "YES" << endl;
            string ans = "";

            while (s[0] ^ d[0] || s[1] ^ d[1])
            {
                ans += parent[d[0]][d[1]];
                ll dd = dist[d[0]][d[1]] ^ 2;
                d[0] += di[dd];
                d[1] += dj[dd];
            }

            reverse(ans.begin(), ans.end());
            cout << ans.size() << endl
                 << ans;
        }
    }

    void init()
    {
        memset(parent, 'N', sizeof(parent));
        cin >> n >> m;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> naksha[i][j];
                if (naksha[i][j] == 'M')
                {
                    // monster.pb({i, j});
                    q2.push({i, j});
                }
                else if (naksha[i][j] == 'A')
                {
                    s[0] = i;
                    s[1] = j;
                }
            }
        }

        movebfs();
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
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######

*/