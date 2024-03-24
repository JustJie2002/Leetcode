/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.22.2024 23:58:32
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
    void reorderList(ListNode* head) {
        vector<int> a;
        for (ListNode* root = head; root; root = root->next) {
            a.push_back(root->val);
        }

        int n = a.size();
        bool on = true;
        ListNode* sentinel = new ListNode(0, head);
        ListNode* mover = sentinel;
        for (int i = 0, j = n - 1; i <= j; on = !on) {
            if (on) {
                mover->next = new ListNode(a[i++]);
            } else {
                mover->next = new ListNode(a[j--]);
            }
            mover = mover->next
        }
    }
};

// ~ JustJie