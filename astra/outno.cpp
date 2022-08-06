#include <bits/stdc++.h>
using namespace std;
void debug(auto x)
{
    cout << x << endl;
}

void demo(int x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

void in(int x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    in(arr, n);

    int res = 0;

    for (int x : arr)
    {
        res = res ^ x;
    }

    cout << res;
}