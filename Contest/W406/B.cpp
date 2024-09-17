/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.13.2024 22:55:55
*********************************************/

using i64 = long long;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& a, ListNode* head) {
        unordered_set<int> bad(a.begin(), a.end());

        ListNode* root = new ListNode(0, head);
        ListNode* dum = root;
        while (dum->next != nullptr) {
            int x = dum->next->val;
            if (bad.contains(x)) {
                dum->next = dum->next->next;
            } else {
                dum = dum->next;
            }
        }
        return root->next;
    }
};

// ~ JustJie