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

class Knight
{
public:
    int n, count = 1;
    int board[mxn][mxn];
    int di[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dj[8] = {1, -1, 1, -1, 2, -2, 2, -2};

    void init()
    {
        cin >> n;
        memset(board, -1, sizeof(board));
        board[0][0] = 0;

        bool flag = findpath(count, 0, 0);

        if (flag)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
        }
    }

    bool e(int x, int y)
    {
        return x < n && x >= 0 && y >= 0 && y < n && board[x][y] == -1;
    }

    int findpath(int fill, int x, int y)
    {
        if (fill == n * n)
        {
            return 1;
        }

        for (int i = 0; i < 8; i++)
        {
            int npx(x), npy(y);
            npx += di[i];
            npy += dj[i];

            if (e(npx, npy))
            {
                board[npx][npy] = fill;
                if (findpath(fill + 1, npx, npy) == 1)
                {
                    return 1;
                }
                else
                {
                    board[npx][npy] = -1;
                }
            }
        }
        return 0;
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