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
// brute force solution
#include <vector>

class Solution {
public:
    void reorderList(ListNode* head) {

        std::vector<ListNode*> nodes;
        ListNode* curr_head = head;
        while (curr_head) {
            nodes.push_back(curr_head);
            curr_head = curr_head->next;
        }

        int n = (int)nodes.size();
        
        int left = 0;
        int right = n - 1;
        while (left < right) {
            nodes[left]->next = nodes[right];
            left++;

            if (left == right) break;

            nodes[right]->next = nodes[left];
            right--;
        }

        nodes[left]->next = nullptr;

    }
};
