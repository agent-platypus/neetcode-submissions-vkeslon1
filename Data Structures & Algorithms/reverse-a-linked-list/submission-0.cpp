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
    ListNode* reverseList(ListNode* head) {
        ListNode* left = nullptr; 
        ListNode* mid = head; 
        ListNode* right = nullptr; 

        while(mid != nullptr) {
            right = mid->next;
            mid->next = left;
            left = mid;
            mid = right;
        }   

        return left;

        //return nullptr;

    }
};
