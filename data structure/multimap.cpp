#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int x : arr)
    {
        m[x]++;
    }

    // auto it = m.begin();
    // int max = it->second;
    // for (it; it != m.end(); it++)
    // {
    //     cout << it->first << " " << it->second << endl;
    // }
    // cout << endl
    //      << endl;
    // //  multimap concept

    multimap<int, int> mm;
    for (auto pair : m)
    {
        mm.insert(make_pair(pair.second, pair.first));
    }

    // for (auto x = mm.begin(); x != mm.end(); x++)
    // {
    //     cout << x->first << " " << x->second << endl;
    // }

    int max2 = mm.rbegin()->first;
    auto point = mm.lower_bound(max2);
    int min = point->second;

    if (point == mm.end())
    {
        cout << max2;
    }
    else
    {
        for (point; point != mm.end(); point++)
        {
            if (point->second < min)
            {
                min = point->second;
            }
        }
        cout << min << endl;
    }
}