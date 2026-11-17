/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;

        while(curr) {
            if (p->val > curr->val && q->val > curr->val) { // go into right
                curr = curr->right;
            }
            else if (p->val < curr->val && q->val < curr->val) { // go into left
                curr = curr->left;
            }
            else { // if p->val == curr->val || q->val == curr->val
                if (p->val < curr->val && q->val > curr->val || p->val > curr->val && q->val < curr->val) {
                    return curr;
                }
                if (p->val == curr->val) {
                    return p;
                }
                if (q->val == curr->val) {
                    return q;
                }
            }
        }

        return curr;
    }
};
