#include <bits/stdc++.h>

using namespace std;

class heaps
{

public:
    int arr[10000];
    int size;
    int cur = 1;
    heaps(int p)
    {
        size = p;
    }

    int parent(int i)
    {
        return floor(i / 2);
    }

    int l_child(int i)
    {
        return (2 * i);
    }
    int r_child(int i)
    {
        return (2 * i + 1);
    }

    void siftup(int i)
    {
        while (i > 1 && arr[parent(i)] < arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void siftdown(int i, int temp2)
    {
        int maxindex = i;
        int left = l_child(i);
        int right = r_child(i);
        if (left <= temp2 && arr[left] > arr[maxindex])
        {
            maxindex = left;
        }
        if (right <= temp2 && arr[right] > arr[maxindex])
        {
            maxindex = right;
        }

        if (i != maxindex)
        {
            swap(arr[i], arr[maxindex]);
            siftdown(maxindex, temp2);
        }
    }
    void insert(int p)
    {
        arr[cur] = p;
        siftup(cur);
        cur++;
    }

    int extract_max()
    {
        int result = arr[1];
        arr[1] = arr[size];
        size--;
        siftdown(1, size);
        return result;
    }

    void remove(int i)
    {
        arr[i] = INT32_MAX;
        siftup(i);
        extract_max();
    }

    int change_priority(int i, int p)
    {
        int oldp = arr[i];
        arr[i] = p;
        if (p > oldp)
        {
            siftup(i);
        }
        else
        {
            siftdown(i, size);
        }
    }

    void build_heap()
    {
        for (size_t i = floor(size / 2); i > 0; i--)
        {
            siftdown(i, size);
        }
    }

    void heap_sort()
    {
        build_heap();
        int temp = size;
        int n = size;
        for (size_t i = 1; i <= n; i++)
        {
            this->show();
            swap(arr[1], arr[temp]);
            temp = temp - 1;
            siftdown(1, temp);
        }
    }

    void show()
    {
        for (size_t i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    heaps obj(n);
    for (size_t i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        obj.insert(temp);
    }

    obj.show();
    obj.heap_sort();
    // obj.show();
}

/*
15
4 5 11 1 10 13 40 15 18 17 35 9 16 30 12
*/