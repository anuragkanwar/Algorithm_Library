#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Linked_List
{
    Node *head, *tail;

public:
    Linked_List()
    {
        head = nullptr;
        tail = nullptr;
    }

    void push_start(int d)
    {
        Node *temp = new Node;
        temp->data = d;
        temp->next = nullptr;

        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }

    void push_end(int d)
    {
        Node *temp = new Node;
        temp->data = d;
        temp->next = nullptr;
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void insert(int d, int after_node)
    {
        Node *temp = new Node;
        temp->data = d;
        temp->next = nullptr;
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            Node *move = head;
            int i = after_node - 1;
            while (i--)
            {
                move = move->next;
            }
            temp->next = move->next;
            move->next = temp;
        }
    }

    void pop_end()
    {
        Node *move = head;
        while ((move->next)->next != nullptr)
        {
            move = move->next;
        }

        Node *temp = tail;
        tail = move;
    }

    void show()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverse()
    {
        Node *prev(nullptr), *current(nullptr), *ahead(nullptr);

        current = head;
        while (current != nullptr)
        {
            ahead = current->next;
            current->next = prev;
            prev = current;
            current = ahead;
        }
        tail = head;
        head = prev;
    }
};

int main()
{
    Linked_List ll;
    ll.push_start(6);
    ll.push_start(5);
    ll.push_start(4);
    ll.push_start(3);
    ll.push_start(2);
    ll.push_start(1);
    ll.insert(99, 3);

    ll.show();

    ll.reverse();
    ll.show();
}
