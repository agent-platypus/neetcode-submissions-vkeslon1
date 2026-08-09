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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if (left == right) {
            return head;
        }
        
        ListNode* curr = head;
        ListNode* start = nullptr;
        ListNode* end = nullptr;

        int i;
        for(i = 1; i < right + 1; i++) {
            if (i == left - 1) {
                start = curr;
            }

            if (i == right) {
                end = curr->next;
            }
            curr = curr->next;
        }
        
        if (left == 1) {
            head = reverseSubList(head, end, right - left + 1);
        }
        else {
            start->next = reverseSubList(start->next, end, right - left + 1);
        }
    
        return head;
    }

    ListNode* reverseSubList(ListNode* start, ListNode* end, int numNodes) {
        ListNode* prev = end;
        ListNode* curr = start;
        ListNode* next;

        int i = 0;
        while(curr != nullptr && i < numNodes) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }


        return prev;
    }
};