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
    int maxDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while(!q.empty()) {
            int len = q.size();
            for(int i = 0; i < len; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
                if(curr->left != nullptr) {
                    q.push(curr->left);
                }
            }
            depth++;
        }
        return depth;
    }
};
