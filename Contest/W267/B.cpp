/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.10.2024 23:49:47
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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<int> a;
        while (head) {
            a.push_back(head->val);
            head = head->next;
        }

        int n = a.size();
        for (int i = 0, j = 1; i < n; j++) {
            int nex = min(i + j, n);
            int siz = nex - i;
            if (siz % 2 == 0) {
                reverse(a.begin() + i, a.begin() + nex);
            }
            i = nex;
        }

        reverse(a.begin(), a.end());
        ListNode* root = NULL;
        for (int x : a) {
            root = new ListNode(x, root);
        }
        return root;
    }
};

// ~ JustJie