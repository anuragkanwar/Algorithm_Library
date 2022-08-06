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

class n_raani
{
public:
    int n;
    int board[mxn][mxn];

    bool e(int row, int col)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[row][j])
                return false;
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j])
                return false;
        }

        for (int i = row, j = col; i < n && j >= 0; i++, j--)
        {
            if (board[i][j])
                return false;
        }
        return true;
    }

    bool find_rani_pos(int q)
    {
        if (n == q)
        {
            return 1;
        }

        for (int i = 0; i < n; i++)
        {
            if (e(i, q))
            {
                board[i][q] = 1;
                if (find_rani_pos(q + 1))
                {
                    return 1;
                }
                else
                {
                    board[i][q] = 0;
                }
            }
        }
        return 0;
    }

    void init()
    {
        cin >> n;
        memset(board, 0, sizeof(board));
        bool flag = find_rani_pos(0);

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