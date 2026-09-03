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
    pair<int, int> obj;
    Node *next;

    Node() : obj(), next(nullptr) {};
    Node(pair<int, int> p) : obj(p), next(nullptr) {};
    Node(pair<int, int> p, Node *n) : obj(p), next(n) {};
};

class MyHashMap
{
private:
    int numberBucket;
    vector<Node *> buckets;

    int hash(int key)
    {
        return key % numberBucket;
    }

public:
    MyHashMap()
    {
        numberBucket = 10000;
        buckets.resize(numberBucket);
    }

    void put(int key, int value)
    {
        int keyHash = hash(key);

        Node *curr = buckets[keyHash];

        while (curr != nullptr)
        {
            if (curr->obj.first == key)
            {
                curr->obj.second = value;
                return;
            }
            curr = curr->next;
        }

        Node *newNode = new Node({key, value});
        newNode->next = buckets[keyHash];
        buckets[keyHash] = newNode;
    }

    int get(int key)
    {
        int keyHash = hash(key);

        Node *curr = buckets[keyHash];

        if (curr != nullptr)
        {
            while (curr != nullptr)
            {
                if (curr->obj.first == key)
                {
                    return curr->obj.second;
                }

                curr = curr->next;
            }

            return -1;
        }
        else
        {
            return -1;
        }
    }

    void remove(int key)
    {
        int keyHash = hash(key);

        Node *curr = buckets[keyHash];
        Node *prev = nullptr;

        while (curr != nullptr)
        {
            if (curr->obj.first == key)
            {
                if (prev == nullptr)
                {
                    buckets[keyHash] = curr->next;
                }
                else
                {
                    prev->next = curr->next;
                }

                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};

void solve()
{
    MyHashMap *hashmap = new MyHashMap();

    hashmap->put(1, 2);
    hashmap->put(2, 2);
    cout << hashmap->get(1) << endl;
    hashmap->put(1, 1);
    cout << hashmap->get(1) << endl;
    hashmap->put(10001, 3);
    hashmap->remove(1);
    cout << hashmap->get(1) << endl;
    cout << hashmap->get(10001) << endl;
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