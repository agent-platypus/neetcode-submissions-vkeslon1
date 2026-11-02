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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1_temp = l1;
        ListNode* l2_temp = l2; 

        ListNode* dummy_ptr = new ListNode();
        ListNode* temp = dummy_ptr;
        int carry = 0;
        while(l1_temp || l2_temp || carry == 1) {
            int l1_val; 
            int l2_val;
            if (l1_temp == nullptr) {
                l1_val = 0;
            }
            else {
                l1_val = l1_temp->val;
                l1_temp = l1_temp->next;
            }

            if (l2_temp == nullptr) {
                l2_val = 0;
            }
            else {
                l2_val = l2_temp->val;
                l2_temp = l2_temp->next;
            }
            int currSum = l1_val + l2_val + carry;

            int onesDigit = currSum % 10;
            carry = currSum / 10;

            ListNode* newDigit = new ListNode(onesDigit);

            temp->next = newDigit;


            temp = temp->next;
        }

        return dummy_ptr->next;
    }
};
