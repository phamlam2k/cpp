#include <iostream>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD                                                                \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void solve() {
  int n, k;

  cin >> n >> k;

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  ListNode *head = new ListNode(arr[0]);
  ListNode *dump = head;

  for (int i = 1; i < n; i++) {
    dump->next = new ListNode(arr[i]);
    dump = dump->next;
  }

  ListNode *dummy = new ListNode(0);
  dummy->next = head;

  ListNode *fast = head;
  ListNode *slow = dummy;

  for (int i = 0; i < k; i++) {
    fast = fast->next;
  }

  while (fast != nullptr) {
    slow = slow->next;
    fast = fast->next;
  }

  ListNode *nodeToDelete = slow->next;
  slow->next = slow->next->next;
  delete nodeToDelete;

  while (head != nullptr) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

signed main() {
  CODEGOD;
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
