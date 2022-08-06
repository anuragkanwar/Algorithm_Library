#include <bits/stdc++.h>

using namespace std;

bool f(int a, int b)
{
    return (a > b);
}

void vectordemo()
{
    // definin a vector:
    vector<int> a = {11, 2, 6, 3, 14};
    cout << a[1] << endl;

    // sorting of array with (ascending array) nlog(n) time;
    sort(a.begin(), a.end());

    // searching in array (BINARY SEARCH)
    bool present = binary_search(a.begin(), a.end(), 3);
    bool non = binary_search(a.begin(), a.end(), 4);

    cout << present << endl;
    cout << non << endl;

    // adding variables in array;
    a.push_back(100);
    present = binary_search(a.begin(), a.end(), 100);
    auto n = find(a.begin(), a.end(), 3);
    cout << "****************" << n - a.begin() << endl;
    cout << present << endl;
    a.push_back(100);

    //finding 1st occurance of 100 in array; // these are pointers
    vector<int>::iterator it = lower_bound(a.begin(), a.end(), 100);  // iterator which is >= 100 (100);
    vector<int>::iterator it2 = upper_bound(a.begin(), a.end(), 100); // iterator which is > 100 (123);
    /*  so instead of typing [vector<int>::iterator] we can just simply write [auto]
        c++ is smart enough to find the data type of the conserderd variable

        auto it = lower_bound(a.begin(), a.end(), 100);
        auto it2 = upper_bound(a.begin(), a.end(), 100);

    */
    cout << *it << "\t" << *it2 << endl;
    cout << (it2 - it) << endl; // 4  O(1) time [IT GIVES US THE COUNT OF NUMBER (100)]

    // sorting vetor in reverse order (descending order)
    sort(a.begin(), a.end(), f);

    //priting of vector

    vector<int>::iterator it3;
    for (it3 = a.begin(); it3 < a.end(); it3++)
    {
        cout << *it3 << endl;
    }

    sort(a.begin(), a.end());

    //but c++ helped us to print  a vector like this

    for (int x : a)
    {
        cout << x << " ";
    }
    cout << endl;
    system("pause");
}

void setdemo()
{
    //sets here;;
    // advantage is it internally manatin the sorting oreder (ascending order);

    set<int> s;

    //insertion in s;

    s.insert(1);
    s.insert(2);
    s.insert(5);
    s.insert(3);
    s.insert(100);
    s.insert(0);
    s.insert(6);
    s.insert(-1);

    //checking internal ascending

    for (int x : s)
    {
        cout << x << " ";
    }
    cout << endl;

    // because of this , set dominates over vector as it does not need to sort inputs explicitly;

    //searching a particular number
    auto it = s.find(3); // find will return iterator to the input if found else,
    //  it will return the iterator of the last element that is s.end()"
    // so element is not find :
    if (it == s.end())
    {
        cout << "element is not present" << endl;
    }
    else
    {
        cout << "element " << *it << " is present" << endl;
    }

    /*  we can also find numbers under a given conditions like 
        find the 1st number which is gretor than -1
        find the 1st number which is strictly than 0
        
        for these we can use upper and lower bound coniditons
    */

    auto it2 = s.lower_bound(-1); // remember that in vactors lower_bound() was an external function
    // therewe have to provide external parameters to that , here its is set class itself
    // it will iterator to the 1st element which { >= } -1;

    auto it3 = s.upper_bound(0); // upper bound is strict and will give only { > } 0
    auto it4 = s.upper_bound(1);
    cout << *it2 << " " << *it3 << " " << *it4 << endl;

    // now what if if we ask to find the upper bound of the last element in set
    // it will return the s.end()
    auto it5 = s.upper_bound(100);
    if (it5 == s.end())
    {
        cout << "oops we cant find the element" << endl;
    }

    // we can also erase element from set
    s.erase(5);

    for (int x : s)
    {
        cout << x << " ";
    }
    cout << endl;
}

void mapdemo()
{
    map<int, int> m;
    m[1] = 2;
    m[3] = 4;
    m[200] = 40;
    // logic to find out the frequency of paticular charachter in a string
    map<char, int> cnt;
    string x = "as you know the nails for jesus is made by gypsis";
    for(char c : x)
    {
        cnt[c]++;
    }
    cout<<cnt['a'] << " " << cnt['b'] << " " << cnt['k']<<endl;

    // we can also here can find keys 
    auto it = m.find(1);

    // we can also earse keys 
    m.erase(3);

}
int main()
{
    vectordemo();
    return (0);
}