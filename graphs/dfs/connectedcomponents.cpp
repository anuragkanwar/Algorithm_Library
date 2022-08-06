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

const int MxN = 1e5;
class ConnectedDFS
{
public:
    int n, m;
    int ans = 0;
    string chitr[MxN];

    bool e(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m && chitr[i][j] == '.';
    }

    void dfs(int i, int j)
    {
        chitr[i][j] = '#';

        if (e(i - 1, j))
            dfs(i - 1, j);
        if (e(i + 1, j))
            dfs(i + 1, j);
        if (e(i, j - 1))
            dfs(i, j - 1);
        if (e(i, j + 1))
            dfs(i, j + 1);
    }
    int connectedcomp()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (e(i, j))
                {
                    dfs(i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
} obj;

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    cin >> obj.n >> obj.m;

    for (int i = 0; i < obj.n; i++)
    {
        cin >> obj.chitr[i];
    }

    cout << obj.connectedcomp();
}

/*
5 8
########
#..#...#
####.#.#
#..#...#
########
*/