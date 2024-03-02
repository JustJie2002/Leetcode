/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.02.2024 17:41:11
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
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        int carry = 0;
        ListNode* head = new ListNode();
        ListNode* ptr = head;
        while (a || b || carry) {
            int x = (a == NULL ? 0 : a->val);
            int y = (b == NULL ? 0 : b->val);
            int sum = x + y + carry;
            carry = sum / 10;
            sum %= 10;
            ptr->next = new ListNode(sum);
            ptr = ptr->next;
            if (a) a = a->next;
            if (b) b = b->next;
        }
        return head->next;
    }
};

// ~ JustJie