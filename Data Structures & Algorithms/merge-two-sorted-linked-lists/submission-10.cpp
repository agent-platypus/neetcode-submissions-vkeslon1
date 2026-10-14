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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // ListNode dummy(0);
        // ListNode* curr = &dummy;

        ListNode* l1_ptr = list1;
        ListNode* l2_ptr = list2;

        if (!list1 && !list2) {
            return nullptr;
        }

        if (!list1 && list2) {
            return list2;
        }

        if (list1 && !list2) {
            return list1;
        }

        ListNode* curr;

        if (list1->val <= list2->val) {
            curr = l1_ptr;
            l1_ptr = l1_ptr->next;
        }

        else {
            curr = l2_ptr;
            l2_ptr = l2_ptr->next;
        }

        while(l1_ptr && l2_ptr) {
            if (l1_ptr->val <= l2_ptr->val) {
                curr->next = l1_ptr;
                l1_ptr = l1_ptr->next;
                curr = curr->next;
            }

            else {
                curr->next = l2_ptr;
                
                l2_ptr = l2_ptr->next;
                curr = curr->next;
            }
        }

        if (l1_ptr) {
            curr->next = l1_ptr;
        }

        if (l2_ptr) {
            curr->next = l2_ptr;
        }



        // return dummy.next;
        
        return (list1->val <= list2->val) ? list1 : list2;
        
    }
};
