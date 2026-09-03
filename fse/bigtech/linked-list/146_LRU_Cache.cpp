#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>

#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

struct Node
{
    int key;
    int value;

    Node *next;
    Node *prev;

    Node(int k, int val) : key(k), value(val), next(nullptr), prev(nullptr) {}
};

class LRUCache
{
private:
    Node *head;
    Node *tail;
    int size;
    int len;
    unordered_map<int, Node *> mp;

    void removeNode(Node *node)
    {
        if (node->prev != nullptr)
        {
            node->prev->next = node->next;
        }
        else
        {
            head = node->next;
        }

        if (node->next != nullptr)
        {
            node->next->prev = node->prev;
        }
        else
        {
            tail = node->prev;
        }
    }

    void insertBeforeHead(Node *node)
    {
        node->next = head;
        node->prev = nullptr;

        if (head != nullptr)
        {
            head->prev = node;
        }

        head = node;

        if (tail == nullptr)
        {
            tail = node;
        }
    }

public:
    LRUCache(int capacity)
    {
        head = nullptr;
        tail = nullptr;
        len = capacity;
        size = 0;
    }

    int get(int key)
    {
        if (!mp.count(key))
        {
            return -1;
        }

        if (mp[key] == nullptr)
            return -1;

        Node *node = mp[key];

        removeNode(node);
        insertBeforeHead(node);

        return node->value;
    }

    void put(int key, int value)
    {
        if (mp.count(key))
        {
            Node *curr = mp[key];

            curr->value = value;

            removeNode(curr);
            insertBeforeHead(curr);

            return;
        }

        if (size == len)
        {
            Node *lru = tail;
            mp.erase(lru->key);

            removeNode(lru);
            delete lru;
            size--;
        }

        Node *newNode = new Node(key, value);
        insertBeforeHead(newNode);
        mp[key] = newNode;
        size++;
    }
};

void solve()
{
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(2, 1);
    lRUCache->put(2, 2);
    cout << lRUCache->get(2) << endl;
    lRUCache->put(1, 1);
    lRUCache->put(4, 1);
    cout << lRUCache->get(2) << endl;
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