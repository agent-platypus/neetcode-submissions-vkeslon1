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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> pq;
        pq.push({p, q});

        while(!pq.empty()) {
            pair<TreeNode*, TreeNode*> curr_pair = pq.top();
            pq.pop();
            if(!curr_pair.first && !curr_pair.second) {
                continue;
            }

            if(!curr_pair.first || !curr_pair.second || curr_pair.first->val != curr_pair.second->val) {
                return false;
            }
            pq.push({curr_pair.first->right, curr_pair.second->right});
            pq.push({curr_pair.first->left, curr_pair.second->left});
        }

        return true;
        
    }
};
