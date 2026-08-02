#include <bits/stdc++.h>

#define endl "\n"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> readInts() {
    string line;
    while (getline(cin, line)) {
        bool hasDigit = false;
        for (char c : line) if (isdigit((unsigned char)c)) { hasDigit = true; break; }
        if (hasDigit || line.find('[') != string::npos) break;
    }
    for (char &c : line) if (c == '[' || c == ']' || c == ',') c = ' ';
    vector<int> v;
    stringstream ss(line);
    int x;
    while (ss >> x) v.push_back(x);
    return v;
}

ListNode* readList() {
    vector<int> v = readInts();
    ListNode dummy;
    ListNode *cur = &dummy;
    for (int x : v) cur = cur->next = new ListNode(x);
    return dummy.next;
}

int readInt() {
    vector<int> v = readInts();
    return v.empty() ? 0 : v[0];
}

void printList(ListNode *head, int limit = 100) {
    cout << "[";
    for (int i = 0; head && i < limit; i++, head = head->next) {
        if (i) cout << ",";
        cout << head->val;
    }
    if (head) cout << ",...(cycle?)";
    cout << "]\n";
}

ListNode* makeCycle(ListNode *head, int pos) {
    if (!head || pos < 0) return head;
    ListNode *tail = head, *target = head;
    while (tail->next) tail = tail->next;
    for (int i = 0; i < pos && target; i++) target = target->next;
    tail->next = target;
    return head;
}

class Solution {
public:
    ListNode* solve(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // t = readInt();          // bo comment neu input.txt co nhieu test
    while (t--) {
        ListNode *head = readList();
        // ListNode *l2 = readList();   // bai 2 list (merge two lists...)
        // int k = readInt();           // bai co tham so (remove nth, rotate...)

        Solution sol;
        ListNode *res = sol.solve(head);

        printList(res);
    }
}
