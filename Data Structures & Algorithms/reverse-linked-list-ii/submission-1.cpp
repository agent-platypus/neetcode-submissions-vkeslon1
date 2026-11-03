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
        ListNode* reverseStart = head;
        ListNode* reverseStartPrev = nullptr;

        ListNode* reverseEnd = head;
        ListNode* reverseEndNext;

        int i;
        for(i = 1; i < left; ++i) {
            reverseStartPrev = reverseStart;
            reverseStart = reverseStart->next;

            reverseEnd = reverseEnd->next;
        }
        // disconnect the sublist to be reversed from the original list
        for(;i < right; ++i) {
            reverseEnd = reverseEnd->next;
        }
        reverseEndNext = reverseEnd->next;
        
        if (reverseStartPrev) {
            reverseStartPrev->next = nullptr;
        }
        reverseEnd->next = nullptr;

        
        ListNode* newHead = reverseList(reverseStart);

        if (reverseStartPrev) {
            reverseStartPrev->next = newHead;
        }

        reverseStart->next = reverseEndNext;

        // if the left = 1, then newHead is the head of the list now
        // otherwise, the original head is the head
        return (left == 1) ? newHead : head;

    }


    // returns the new head of the reversed list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev{nullptr};
        ListNode* curr = head;

        while(curr != nullptr) {
            ListNode* next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};