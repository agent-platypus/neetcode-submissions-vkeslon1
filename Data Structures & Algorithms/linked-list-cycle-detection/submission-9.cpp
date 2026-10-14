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
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        if (!head || !head->next) {
            return false;
        }
        ListNode* fast = head->next;

        // there is no cycle if the list can be iterated through and reach nullptr

        // there is a cycle if slow and fast pointers point to the same node 

        while(slow && fast) {
            if (slow == fast) {
                return true;
            }

            if (!fast->next) {
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;


        }

        return false;
    }
};
