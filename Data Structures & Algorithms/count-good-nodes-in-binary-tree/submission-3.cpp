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
private:
    int numGoodNodes{};
public:
    int goodNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        //++numGoodNodes;
        dfs(root, root->val);

        return numGoodNodes;
    }

    void dfs(TreeNode* root, int pathMax) {
        if (!root) {
            return;
        }

        if (root->val >= pathMax) {
            ++numGoodNodes;
            pathMax = root->val;
        }
        dfs(root->left, pathMax);
        dfs(root->right, pathMax);
    }
};
