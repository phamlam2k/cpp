#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

struct Node
{
    int value;

    Node *next;

    Node() : value(0), next(nullptr) {}
    Node(int val) : value(val), next(nullptr) {}
    Node(int val, Node *nxt) : value(val), next(nxt) {}
};

class MyLinkedList
{
private:
    Node *head;
    Node *tail;
    int size = 0;

public:
    MyLinkedList()
    {
        head = nullptr;
    }

    int get(int index)
    {
        if (head == nullptr || index >= size)
        {
            return -1;
        }

        Node *curr = head;

        while (index)
        {
            curr = curr->next;
            index--;
        }

        return curr->value;
    }

    void addAtHead(int val)
    {
        size++;

        if (head == nullptr)
        {
            head = new Node(val);
            tail = head;

            return;
        }

        Node *newNode = new Node(val, head);
        head = newNode;
    }

    void addAtTail(int val)
    {
        size++;

        if (head == nullptr)
        {
            head = new Node(val);
            tail = head;

            return;
        }

        Node *newNode = new Node(val);
        tail->next = newNode;
        tail = newNode;
    }

    void addAtIndex(int index, int val)
    {

        if (index > size)
        {
            return;
        }

        if (index == size)
        {
            addAtTail(val);
            return;
        }

        if (index == 0)
        {
            addAtHead(val);

            return;
        }

        Node *curr = head;
        Node *prev = nullptr;

        while (index)
        {

            prev = curr;
            curr = curr->next;
            index--;
        }

        Node *newNode = new Node(val);

        prev->next = newNode;
        newNode->next = curr;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size)
        {
            return;
        }

        Node *curr = head;

        if (index == 0)
        {
            head = curr->next;
            if (size == 1)
                tail = head;
            delete curr;
            size--;
            return;
        }

        Node *prev;

        while (index)
        {

            prev = curr;
            curr = curr->next;
            index--;
        }

        prev->next = curr->next;

        size--;

        delete curr;
    }
};

void solve()
{
    MyLinkedList myLinkedList = MyLinkedList();
    myLinkedList.addAtHead(1); // return 2
    myLinkedList.deleteAtIndex(0);
    myLinkedList.addAtTail(2);
    cout << myLinkedList.get(0) << endl; // return 2
}

signed main()
{
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}