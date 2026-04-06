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
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // once this loop terminates slow_ptr points to the middle node
        // of the head, effectively giving us an access to the second half of it
        // now this second half of the list needs to be reversed

        ListNode* second_half = slow->next;
        slow->next = nullptr;

        ListNode* reversed_2nd_half = reverseList(second_half);
        ListNode* curr_head = head;

        while (reversed_2nd_half) {
            ListNode* tmp_curr_nxt = curr_head->next;
            ListNode* tmp_rev_nxt = reversed_2nd_half->next;

            curr_head->next = reversed_2nd_half;
            reversed_2nd_half->next = tmp_curr_nxt;
            curr_head = tmp_curr_nxt;
            reversed_2nd_half = tmp_rev_nxt;
        } 


    }
private:
    ListNode* reverseList(ListNode* head) {
        if(!head) {
            return nullptr;
        } else {
            ListNode* new_head = head;
            if (new_head->next) {
                new_head = reverseList(new_head->next);
                head->next->next = head;
            }
            head->next = nullptr;

            return new_head;
        }
    }
};
