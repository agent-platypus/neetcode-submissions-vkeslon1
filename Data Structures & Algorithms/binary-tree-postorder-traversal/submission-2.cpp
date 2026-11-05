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
    vector<int> res;

    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int> res;
        // stack<TreeNode*> nodeStack;
        // TreeNode* curr = root;

        // while(curr || !nodeStack.empty()) {
        //     if (curr == nullptr) {
        //         TreeNode* temp = nodeStack.top();
        //         if ()
        //         curr = temp->right;
        //         nodeStack.pop();
        //         continue;
        //     }
        //     nodeStack.push(curr);
        //     curr = curr->left;
        // }

        // return res;
        dfs(root);
        return res;
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        dfs(root->left);
        dfs(root->right);
        res.push_back(root->val);
    }
};