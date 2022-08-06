#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        cin >> arr[i];
    }

    int i = 0, tp, max_area = 0, area_with_top;

    while (i < n)
    {
        if (s.empty() || arr[s.top()] <= arr[i])
        {
            s.push(i);
            i++;
        }
        else
        {
            tp = s.top();
            s.pop();
            if (s.empty())
            {
                area_with_top = arr[tp] * i;
            }
            else
            {
                area_with_top = arr[tp] * (i - s.top() - 1);
            }

            if (max_area < area_with_top)
            {
                max_area = area_with_top;
            }
        }
    }

    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        if (s.empty())
        {
            area_with_top = arr[tp] * i;
        }
        else
        {
            area_with_top = arr[tp] * (i - s.top() - 1);
        }

        if (max_area < area_with_top)
        {
            max_area = area_with_top;
        }
    }

    cout << max_area;
}