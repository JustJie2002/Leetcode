/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.05.2024 20:43:16
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
    ListNode* reverse(ListNode* node, ListNode* pre) {
        if (!node) {
            return pre;
        }
        auto nex = node->next;
        node->next = pre;
        return reverse(nex, node);
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverse(head, nullptr);

        int x = -1;
        for (ListNode* root = head; root; root = root->next) {
            if (x > root->val) {
                root->val = -root->val;
            } else {
                x = root->val;
            }
        }

        head = reverse(head, nullptr);

        ListNode* root = new ListNode(0);
        ListNode* ptr = root;
        for (; head; head = head->next) {
            if (head->val > 0) {
                ptr->next = head;
                ptr = ptr->next;
            }
        }

        ptr->next = nullptr;
        return root->next;
    }
};

// ~ JustJie