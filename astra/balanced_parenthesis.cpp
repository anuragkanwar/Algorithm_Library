#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    char *arr;

    Stack(int len)
    {
        size = len;
        arr = new char[len];
        top = -1;
    }

    void push(char data)
    {
        top++;
        arr[top] = data;
    }

    bool pop(char check)
    {
        if (check == ')')
        {
            if (arr[top] == '(')
            {
                top--;
                return true;
            }
            return false;
        }
        if (check == ']')
        {
            if (arr[top] == '[')
            {
                top--;
                return true;
            }
            return false;
        }
        if (check == '}')
        {
            if (arr[top] == '{')
            {
                top--;
                return true;
            }
            return false;
        }
    }

    int size1()
    {
        return (top + 1);
    }
};

int main()
{
    string str;
    getline(cin, str);
    bool flag = 1;
    Stack obj(str.length());
    for (char x : str)
    {
        if (x == '(' || x == '[' || x == '{')
        {
            obj.push(x);
        }
        else
        {
            flag = obj.pop(x);
        }
        if (flag)
        {
            continue;
        }
        else
        {
            cout << "Not Balanced";
            exit(0);
        }
    }

    if (obj.size1() == 0)
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not Balanced";
    }
}