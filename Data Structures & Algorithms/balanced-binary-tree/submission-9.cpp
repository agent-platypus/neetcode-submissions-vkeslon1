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
#include <print>

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }

    pair<bool, int> dfs(TreeNode* root) {
        if (!root) {
            return {true, 0};
        }

        auto [leftBalanced, leftDepth] = dfs(root->left);
        auto [rightBalanced, rightDepth] = dfs(root->right);

        bool isBalanced = leftBalanced && rightBalanced && abs(leftDepth - rightDepth) <= 1;

        return {isBalanced, 1 + max(leftDepth, rightDepth)};

    }
};
