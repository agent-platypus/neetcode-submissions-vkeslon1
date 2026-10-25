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

        if (!head->next) {
            return nullptr;
        }
        ListNode dummy(0, head);
        ListNode* beforeNodeToRemove = &dummy;
        ListNode* offset = head;

        // dummy -> 1 -> 2 -> 3 -> 4

        // ^            ^
        //               ^         ^

        for(int i{}; i < n; ++i) {
            offset = offset->next;
        }

        while(offset != nullptr) {
            offset = offset->next;
            beforeNodeToRemove = beforeNodeToRemove->next;
        }

        ListNode* nodeToRemove = beforeNodeToRemove->next;
        ListNode* afterNodeToRemove;

        if(nodeToRemove->next == nullptr) {
            afterNodeToRemove = nullptr;
        }
        else {
            afterNodeToRemove = nodeToRemove->next;
        } 

        beforeNodeToRemove->next = afterNodeToRemove;

        delete nodeToRemove;

        return dummy.next;


    }
};
