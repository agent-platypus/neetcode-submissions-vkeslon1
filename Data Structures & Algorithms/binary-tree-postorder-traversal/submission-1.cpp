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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(curr || !s.empty()) {
            while(curr) {
                if (curr->right) {
                    s.push(curr->right);
                }
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            if (!s.empty() && curr->right && s.top() == curr->right) {
                s.pop();
                s.push(curr);
                curr = curr->right;
            }
            else {
                res.push_back(curr->val);
                curr = nullptr;
            }
            
        }

        return res;
    }

    void dfs(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }

        dfs(root->left, res);
        dfs(root->right, res);
        res.push_back(root->val);
    }
};