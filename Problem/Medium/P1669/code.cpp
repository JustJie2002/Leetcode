/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.19.2024 20:27:07
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
    ListNode* mergeInBetween(ListNode* root1, int a, int b, ListNode* root2) {
        ListNode* end = root2;
        while (end->next) {
            end = end->next;
        }

        ListNode* head = root1;
        for (int i = 0; i < b; i++, head = head->next) {
            if (i == a - 1) {
                ListNode* nex = head->next;
                head->next = root2;
                head = nex;
            }
        }

        end->next = head;
        return root1;
    }
};

// ~ JustJie