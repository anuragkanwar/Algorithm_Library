#include <bits/stdc++.h>

using namespace std;

int maxsum(int a, int b, int c)
{
    return (max(max(a, b), c));
}

int sum(int *arr, int low, int mid, int high)
{
    int sum = 0;
    int left = INT_MIN;

    for (int i = mid; i >= low; i--)
    {
        sum = sum + arr[i];

        if (sum > left)
        {
            left = sum;
        }
    }

    sum = 0;
    int right = INT_MIN;
    for (int i = mid + 1; i <= high; i++)
    {
        sum = sum + arr[i];

        if (sum > right)
        {
            right = sum;
        }
    }

    return (maxsum(left + right, left, right));
}

int divarr(int *arr, int low, int high)
{
    if (low == high)
    {
        return arr[low];
    }
    else
    {
        int mid = (low + high) / 2;

        int lsum = divarr(arr, low, mid);
        int rsum = divarr(arr, mid + 1, high);

        int csum = sum(arr, low, mid, high);

        return (maxsum(lsum, rsum, csum));
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n]; //-2 -1 3 -2 6 -3
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << divarr(arr, 0, n - 1);
}