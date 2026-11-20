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
    
public:
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int numGoodNodes{};
        q.push({root, numeric_limits<int>::min()});

        while(!q.empty()) {
            auto [currNode, pathMax] = q.front();
            if (currNode->val >= pathMax) {
                ++numGoodNodes;
                pathMax = currNode->val;
            }

            if (currNode->left) {
                q.push({currNode->left, pathMax});
            }
            if (currNode->right) {
                q.push({currNode->right, pathMax});
            }

            q.pop();
        }

        return numGoodNodes;
    }
};
