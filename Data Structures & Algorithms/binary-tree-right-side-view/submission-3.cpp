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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        res.reserve(100);

        if (!root) {
            return {};
        }

        while(!q.empty()) {
            int numNodeLevel = q.size();

            res.push_back(q.front()->val);
            for(int i{}; i < numNodeLevel; ++i) {
                TreeNode* curr = q.front();
                if (curr->right) {
                    q.push(curr->right);
                }
                if (curr->left) {
                    q.push(curr->left);
                }
                q.pop();
            }
        }

        return res;
    }
};
