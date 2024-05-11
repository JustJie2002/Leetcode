/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.06.2024 23:07:40
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
    ListNode* reverse(ListNode* node) {
        if (node == nullptr || node->next == nullptr) {
            return node;
        }
        ListNode* root = reverse(node->next);
        node->next->next = node;
        node->next = nullptr;
        return root;
    }

    pair<int, int> divmod(int x, int mod) {
        return {x / 10, x % 10};
    }

    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        ListNode* rt = new ListNode(0);
        ListNode* ptr = rt;
        int c = 0;
        for (int x; head; head = head->next, ptr = ptr->next) {
            tie(c, x) = divmod(2 * head->val + c, 10);
            ptr->next = new ListNode(x);
        }
        if (c) {
            ptr->next = new ListNode(1);
        }
        rt = rt->next;
        return reverse(rt);
    }
};

// ~ JustJie