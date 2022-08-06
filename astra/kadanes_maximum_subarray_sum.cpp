#include <bits/stdc++.h>
using namespace std;

int kadensAlgo(int arr[], int n)
{

    //-2 -3 4 -1 -2 1 5 -3

    int max_so_far = INT_MIN;
    int new_max = 0;
    for (int i = 0; i < n; i++)
    {
        new_max = new_max + arr[i];

        if (max_so_far < new_max)
        {
            max_so_far = new_max;
        }

        if (new_max < 0)
        {
            new_max = 0;
        }
    }
    cout << max_so_far;
}

int maxsum(int a, int b, int c)
{
    return (max(max(a, b), c));
}

int sum(int *a, int low, int mid, int high)
{
    int sum = 0;
    int left = INT_MIN;

    for (int i = mid; i >= low; i--)
    {
        sum = sum + a[i];

        if (sum > left)
        {
            left = sum;
        }
    }

    sum = 0;
    int right = INT_MIN;
    for (int i = mid + 1; i <= high; i++)
    {
        sum = sum + a[i];

        if (sum > right)
        {
            right = sum;
        }
    }
    return (maxsum(right + left, left, right));
}

int divide_array(int *a, int low, int high)
{
    if (low == high)
    {
        return a[low];
    }
    else
    {
        int mid = (low + high) / 2;

        int lsum = divide_array(a, low, mid);
        int rsum = divide_array(a, mid + 1, high);
        int csum = sum(a, low, mid, high);

        return (maxsum(lsum, rsum, csum));
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << divide_array(arr, 0, n - 1);
    cout << endl;
    cout << "kadens;s algo " << endl;
    kadensAlgo(arr, n);
}