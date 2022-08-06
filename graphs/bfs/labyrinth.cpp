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

const int MxN = 1e3;
class shortestPathBacktrack
{
public:
    int n, m;
    int ans = 0;
    string chitr[MxN];
    string path[MxN];
    int xored[MxN][MxN];
    queue<ar<int, 2>> q;
    ar<int, 2> s, d;
    int di[4] = {0, 1, 0, -1};
    int dj[4] = {1, 0, -1, 0};
    char dr[4] = {'R', 'D', 'L', 'U'};
    bool e(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m && chitr[i][j] == '.';
    }

    void findcord()
    {
        fill(path->begin(), path->end(), '0');
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (chitr[i][j] == 'A')
                {
                    chitr[i][j] = '.';
                    s = {i, j};
                }
                if (chitr[i][j] == 'B')
                {
                    chitr[i][j] = '.';
                    d = {i, j};
                }
            }

            // path[i] = string(m, '0');
        }
    }

    void backtrack()
    {
        string str = "";
        if (path[d[0]][d[1]] == '0')
        {
            cout << "NO";
        }
        else
        {
            while ((d[0]) ^ (s[0]) || (d[1]) ^ (s[1]))
            {
                str += path[d[0]][d[1]];
                int dd = xored[d[0]][d[1]] ^ 2;
                d[0] += di[dd];
                d[1] += dj[dd];
            }
            reverse(str.begin(), str.end());
            cout << "YES" << endl;
            cout << str.size() << endl;
            cout << str;
        }
    }

    void BFSPath()
    {
        q.push(s);
        chitr[s[0]][s[1]] = '#';
        while (!q.empty())
        {
            ar<int, 2> u = q.front();
            q.pop();

            if (u == d)
            {
                return;
            }

            ar<int, 2> np;
            for (int k = 0; k < 4; k++)

            {
                np[0] = u[0] + di[k];
                np[1] = u[1] + dj[k];

                if (!e(np[0], np[1]))
                    continue;

                path[np[0]][np[1]] = dr[k];
                xored[np[0]][np[1]] = k;
                chitr[np[0]][np[1]] = '#';
                q.push(np);
            }
        }
    }

} obj;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> obj.n >> obj.m;

    for (int i = 0; i < obj.n; i++)
    {
        cin >> obj.chitr[i];
    }

    obj.findcord();
    obj.BFSPath();
    obj.backtrack();
}

/*
5 8
########
#.A#...#
#.##.#B#
#......#
########
*/
