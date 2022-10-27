#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int main()
{

    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<int> dp(n + 1, INT32_MAX);

    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (i & 1)
        {
            dp[i] = min(dp[(i + 1) >> 1] + x + z, dp[i - 1] + y);
        }
        else
        {
            dp[i] = min(dp[i / 2] + x, dp[i - 1] + y);
        }
    }

    cout << dp[n];

    return 0;
}