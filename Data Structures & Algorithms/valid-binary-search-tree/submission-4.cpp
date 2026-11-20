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
    bool isValidBST(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int> >> q;
        q.push( {root, {numeric_limits<int>::min(), numeric_limits<int>::max()} } );

        while(!q.empty()) {
            auto [currNode, interval] = q.front();
            
            int minRange = interval.first;
            int maxRange = interval.second;

            if (currNode->val <= minRange || currNode->val >= maxRange) {
                return false;
            }

            // condition will only be false if currNode->val > minRange && currNode->val < maxRange
            // 

            if (currNode->left) {
                q.push( {currNode->left, {minRange, currNode->val} } );
            }
            if (currNode->right) {
                q.push( {currNode->right, {currNode->val, maxRange} } );
            }
            q.pop();
        }

        return true;
    }
};
