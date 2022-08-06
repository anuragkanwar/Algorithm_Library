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

// *************************************************************************

const int MxN = 1e3;
int n, m;
char chitr[MxN][MxN];
ar<int, 2> s, d;
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

bool e(int i, int j)
{
    return i >= 0 && i < m && j >= 0 && j < n && chitr[i][j] == '.';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {
        queue<ar<int, 2>> q;
        cin >> m >> n;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> chitr[i][j];
            }
        }

        int l = 0, h = 0, count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
                {
                    if (chitr[i][j] == '.')
                    {
                        count++;
                        q.push({i, j});
                    }
                }
            }
        }

        int flag = 0;

        if (count == 2)
        {
            s = q.front();
            q.pop();
            d = q.front();
            q.pop();
            q.push(s);
            while (!q.empty())
            {
                ar<int, 2> u = q.front();
                if (u[0] == d[0] && u[1] == d[1])
                {
                    flag = 1;
                    cout << "valid" << endl;
                    break;
                }
                q.pop();
                chitr[u[0]][u[1]] = '#';
                for (int i = 0; i < 4; i++)
                {
                    ar<int, 2> pos;
                    pos[0] = u[0] + di[i];
                    pos[1] = u[1] + dj[i];

                    if (!e(pos[0], pos[1]))
                        continue;
                    q.push(pos);
                }
            }

            if (flag == 0)
            {
                cout << "invalid" << endl;
            }
        }
        else
        {
            cout << "invalid" << endl;
        }
    }
}

/*
6
4 4
####
#...
#.##
#.##
5 5
#.###
#..##
##..#
#.#.#
###.#
1 1
.
5 1
#
#
.
.
#
2 2
#.
.#
3 4
#..#
#.##
#.##
*/