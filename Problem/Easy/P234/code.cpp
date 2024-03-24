/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.21.2024 20:14:07
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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* rev = NULL;
        while (fast && fast->next) {
            rev = new ListNode(slow->val, rev);
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast) {
            slow = slow->next;
        }

        while (rev && rev->val == slow->val) {
            rev = rev->next;
            slow = slow->next;
        }

        return rev == NULL;
    }
};

// ~ JustJie