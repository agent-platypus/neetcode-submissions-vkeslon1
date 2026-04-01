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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode;
        dummy->next = head;
        ListNode* offset = head;
        ListNode* prevNodeToDelete = dummy;
        ListNode* NodeToDelete = head;

        for(int i = 0; i < n; i++) {
            offset = offset->next;
        }

        while(offset != nullptr) {
            offset = offset->next;
            prevNodeToDelete = prevNodeToDelete->next;
            NodeToDelete = NodeToDelete->next;
        }

        prevNodeToDelete->next = NodeToDelete->next;
        delete NodeToDelete;

        return dummy->next;
// 
        // return head;

    }
};
