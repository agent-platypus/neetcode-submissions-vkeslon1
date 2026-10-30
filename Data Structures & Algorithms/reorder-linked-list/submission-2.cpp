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
        


        // 1. iterate to the last node O(n)
        // 2. start reverse the list from the half point onwards O(n)
        // 3. pointers to the original head and the head of the reversed half
        // 4. next pointer assigning O
        // O(2n)

        ListNode* temp = head;
        int numNodes{};

        while(temp != nullptr) {
            temp = temp->next;
            ++numNodes;
        }

        ListNode* reversePtr = head;

        ListNode* prev = nullptr;
        ListNode* curr = nullptr;

        for(int i{}; i < (numNodes/2); ++i) {
            reversePtr = reversePtr->next;
        }

        curr = reversePtr->next;

        reversePtr->next = nullptr;
        // list reversal from halfpoint + 1

        

        while(curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // prev is at the head of the reversed half
        ListNode* ogPtr = head;
        ListNode* ogNext = nullptr;

        ListNode* rvrsePtr = prev;
        ListNode* rvrseNext = nullptr;

        while(ogPtr != nullptr && rvrsePtr != nullptr) {
            ogNext = ogPtr->next;
            rvrseNext = rvrsePtr->next;

            ogPtr->next = rvrsePtr;
            rvrsePtr->next = ogNext;

            ogPtr = ogNext;
            rvrsePtr = rvrseNext;
        }

    }


};
