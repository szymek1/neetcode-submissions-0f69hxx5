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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode r;
        ListNode* r_tail = &r;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                r_tail->next = l1;
                l1 = l1->next;
            } else {
                r_tail->next = l2;
                l2 = l2->next;
            }
            r_tail = r_tail->next;
        }

        if (l1 && !l2) {
            r_tail->next = l1;
        } else if (!l1 && l2) {
            r_tail->next = l2;
        }

        return r.next;
    }
};
