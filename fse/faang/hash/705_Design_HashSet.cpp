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
    Node *prev;

    Node(int val) : value(val), next(nullptr), prev(nullptr) {}
};

class MyHashSet
{
private:
    vector<Node *> buckets;
    int numberBucket;

    int hashing(int key)
    {
        return key % numberBucket;
    }

public:
    MyHashSet()
    {
        numberBucket = 10007;
        buckets.resize(numberBucket);
    }

    void add(int key)
    {
        int index = hashing(key);
        Node *curr = buckets[index];
        Node *newNode = new Node(key);

        if (curr == nullptr)
        {
            buckets[index] = newNode;

            return;
        }

        Node *tail = nullptr;
        while (curr != nullptr)
        {
            if (curr->value == key)
                return; // Key already exists

            tail = curr;
            curr = curr->next;
        }

        tail->next = newNode;
        newNode->prev = tail;
    }

    void remove(int key)
    {
        int index = hashing(key);
        Node *curr = buckets[index];

        if (curr == nullptr)
            return;

        while (curr != nullptr)
        {
            if (curr->value == key)
            {
                Node *prevNode = curr->prev;
                Node *nextNode = curr->next;

                if (prevNode != nullptr)
                {
                    prevNode->next = nextNode;
                }
                else
                {
                    buckets[index] = nextNode;
                }

                if (nextNode != nullptr)
                {
                    nextNode->prev = prevNode;
                }

                delete curr;
                return;
            }

            curr = curr->next;
        }
    }

    bool contains(int key)
    {
        int index = hashing(key);
        Node *curr = buckets[index];

        if (curr == nullptr)
        {
            return false;
        }

        while (curr != nullptr)
        {
            if (curr->value == key)
            {
                return true;
            }

            curr = curr->next;
        }

        return false;
    }
};

void solve()
{
    MyHashSet *myHashSet = new MyHashSet();
    myHashSet->add(1);                      // set = [1]
    myHashSet->add(2);                      // set = [1, 2]
    cout << myHashSet->contains(1) << endl; // return True
    cout << myHashSet->contains(3) << endl; // return False, (not found)
    myHashSet->add(2);                      // set = [1, 2]
    cout << myHashSet->contains(2) << endl; // return True
    myHashSet->remove(2);                   // set = [1]
    cout << myHashSet->contains(2) << endl;
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