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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        while(!q.empty()) {
            int numNodeLevel = q.size();
            vector<int> currLevel;
            for(int i{}; i < numNodeLevel; ++i) {
                TreeNode* curr = q.front();
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
                currLevel.push_back(curr->val);
                q.pop();
            }
            res.push_back(currLevel);
        }

        return res;
    }
};
