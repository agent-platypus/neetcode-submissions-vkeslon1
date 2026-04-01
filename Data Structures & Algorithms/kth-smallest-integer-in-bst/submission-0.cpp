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
    int kthSmallest(TreeNode* root, int k) {
        int count = k;
        int nodeVal;

        dfs(root, count, nodeVal);

        return nodeVal;
    }

    void dfs(TreeNode* root, int &cnt, int &nodeVal) {
        if(root == nullptr) {
            return;
        }

        dfs(root->left, cnt, nodeVal);
        cnt--;
        if (cnt == 0) {
            nodeVal = root->val;
            return;
        }
        dfs(root->right, cnt, nodeVal);
    }
    
};
