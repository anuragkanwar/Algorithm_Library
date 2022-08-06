#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    for (auto x : arr)
    {
        cout << x << " "; // printf("%d ", x);
    }
    cout << endl;

    sort(arr.begin(), arr.end());
    for (auto x : arr)
    {
        cout << x << " "; // printf("%d ", x);
    }
}