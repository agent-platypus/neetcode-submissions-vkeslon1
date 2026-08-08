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
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     inoTraversal(root, res);
    //     return res;
    // }

    // void inoTraversal(TreeNode* root, vector<int>& res) {
    //     if(root == nullptr) {
    //         return;
    //     }
        
    //     inoTraversal(root->left, res);
    //     res.push_back(root->val);
    //     inoTraversal(root->right, res);
    // }

    vector<int> inorderTraversal(TreeNode* root) { 
        vector<int> res;

        stack<TreeNode*> s;
        TreeNode* curr = root;

        while(!s.empty() || curr) {
            while(curr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }

        return res;
    }
};