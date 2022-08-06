#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<char, int> m;
    string x;
    getline(cin, x);
    for (char c : x)
    {
        m[c]++;
    }
    auto it = m.begin();
    for (it; it != m.end(); it++)
    {
        cout<< it->first << " : " << it->second <<endl;
    }
}