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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mergeList;
        ListNode* l1 = list1;
        ListNode* l2 = list2;

        if (!list1 && !list2) {
            return nullptr;
        }

        if (list1 == nullptr) {
            return list2;
        }

        if (list2 == nullptr) {
            return list1;
        }

        if (l1->val < l2->val) {
            mergeList = new ListNode(l1->val);
            l1 = l1->next;
        } else {
            mergeList = new ListNode(l2->val);
            l2 = l2->next;
        }

        ListNode* stepList = mergeList;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                stepList->next = l1;
                l1 = l1->next;
            } else {
                stepList->next = l2;
                l2 = l2->next;
            }

            stepList = stepList->next;
        }

        while (l1) {
            stepList->next = l1;
            stepList = stepList->next;
            l1 = l1->next;
        }

        while (l2) {
            stepList->next = l2;
            stepList = stepList->next;
            l2 = l2->next;
        }

        return mergeList;
    }
};