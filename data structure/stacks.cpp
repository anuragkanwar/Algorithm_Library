#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
public:
    Node *top = nullptr;

    void push(int data)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->next = nullptr;

        if (top == nullptr)
        {
            top = temp;
        }
        else
        {
            temp->next = top;
            top = temp;
        }
    }

    int pop()
    {
        if (top == nullptr)
        {
            cout << "underflow condition" << endl;
            return INT_MIN;
        }
        Node *temp = top;
        top = top->next;
        int x = temp->data;
        delete temp;
        return x;
    }

    void peek()
    {
        cout << top->data << endl;
    }

    void display()
    {
        cout << "current stack is : \n";
        Node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int driverptr()
{
    char ch;
    int choice;
    Stack obj;
    do
    {
        cout << "1. push \n2. pop \n3. traversal \n4. peek";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "enter data" << endl;
            cin >> choice;
            obj.push(choice);
        }
        break;
        case 2:
            cout << " curently removed object is " << obj.pop() << endl;
            break;
        case 3:
            obj.display();
            break;

        case 4:
            obj.peek();
            break;
        }

        cout << "want to enter more \n";
        cin >> ws;
        cin >> ch;
    } while (ch == 'y');
    return 0;
}

class TwoStack
{

public:
    int *arr;
    int top1;
    int top2;
    int size;

    TwoStack(int len)
    {
        size = len;
        arr = new int[len];
        top1 = -1;
        top2 = size;
    }

    bool isfull()
    {
        if (top1 < top2 - 1)
        {
            return false;
        }
        return true;
    }

    bool isempty(int who)
    {
        if (who == 1)
        {
            if (top1 >= 0)
            {
                return false;
            }
            return true;
        }

        else
        {
            if (top2 < size)
            {
                return false;
            }
            return true;
        }
    }

    void push1(int data)
    {
        if (isfull())
        {
            cout << "Overflow";
        }
        else
        {
            top1++;
            arr[top1] = data;
        }
    }
    void push2(int data)
    {
        if (isfull())
        {
            cout << "Overflow";
        }
        else
        {
            top2--;
            arr[top2] = data;
        }
    }
    int pop1()
    {
        if (isempty(1) == false)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        else
        {
            cout << "underflow" << endl;
            return INT_MIN;
        }
    }
    int pop2()
    {
        if (isempty(2) == false)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        else
        {
            cout << "underflow" << endl;
            return INT_MIN;
        }
    }

    void display1()
    {

        for (int i = 0; i <= top1; i++)
        {
            cout << arr[top1] << endl;
        }
    }
    void display2()
    {

        for (int i = size - 1; i >= top2; i--)
        {
            cout << arr[top2] << endl;
        }
    }
};

int driverarr()
{
    int n;
    cin >> n;
    TwoStack obj(n);
    char ch;
    int choice;
    do
    {
        cout << "1. push1 \n2. push2 \n3. pop1 \n4. pop2 \n5. display1 \n6.display2" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "enter data" << endl;
            cin >> choice;
            obj.push1(choice);
        }
        break;
        case 2:
        {
            cout << "enter data" << endl;
            cin >> choice;
            obj.push2(choice);
        }
        break;
        case 3:
            cout << " curently removed object is " << obj.pop1() << endl;
            break;
        case 4:
            cout << " curently removed object is " << obj.pop2() << endl;
            break;
        case 5:
            obj.display1();
            break;
        case 6:
            obj.display2();
            break;
        }

        cout << "want to enter more \n";
        cin >> ws;
        cin >> ch;
    } while (ch == 'y');
    return 0;
}

int main()
{
    driverptr();
    // driverarr();
}