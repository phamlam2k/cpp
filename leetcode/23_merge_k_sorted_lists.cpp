#include <iostream>
#include <algorithm>
#include <map>
#include <string>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>arr;
        ListNode* head;
        for (ListNode* i : lists){
            head = i;
            while(head){
                arr.push_back(head->val);
                head = head ->next;
            }
        }
        sort(arr.begin(),arr.end());
        ListNode* dummy = new ListNode();
        ListNode* helpr ;
        helpr = dummy;
        for (int i : arr){
            helpr -> next = new ListNode(i);
            helpr = helpr->next;
        }
        return dummy->next;
    }
};