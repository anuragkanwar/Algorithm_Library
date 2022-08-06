// C++ program to print all topological sorts of a graph
#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
int main()
{

    /*
        A - 1000001         a - 1100001
        .
        .
        .
    */

    int n = 155;

    string str = "AbcdeFGhiJklMnOPqrstUvWXYz";

    for (char &ch : str)
    {
        ch = ch | ' ';
    }

    cout << (str) << endl;
    str = "AbcdeFGhiJklMnOPqrstUvWXYz";

    for (char &ch : str)
    {
        ch = ch & '_';
    }
    cout << (str) << endl;

    // for flipping use (ch ^ (1<<5));
    for (char &ch : str)
    {
        // cout << (ch & ((1 << 5) - 1)-1);
        cout << ch << "->" << (ch & 31) - 1 << "\n";
    }
    cout << endl;
}
