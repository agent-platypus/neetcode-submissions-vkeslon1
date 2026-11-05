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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> callStack;
        TreeNode* curr = root;

        while(!callStack.empty() || curr != nullptr) {
            if (curr == nullptr) {
                TreeNode* temp = callStack.top();
                res.push_back(temp->val);
                curr = temp->right;
                callStack.pop();
                continue;
            }
            // fully explore the left and then the right subtree at a given node before popping said node from the stack 

            callStack.push(curr);
            curr = curr->left;
        }

        return res;
    }
};