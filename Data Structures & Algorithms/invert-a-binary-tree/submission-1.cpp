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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        queue<TreeNode*> q;
        
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            TreeNode* cur_right = nullptr;
            TreeNode* cur_left = nullptr;

            if (curr->left) {
                cur_left = curr->left;
                q.push(cur_left);
            }
            if (curr->right) {
                cur_right = curr->right;
                q.push(cur_right);
            }

            curr->left = cur_right;
            curr->right = cur_left;
            q.pop();
        }

        return root;
    }
};
