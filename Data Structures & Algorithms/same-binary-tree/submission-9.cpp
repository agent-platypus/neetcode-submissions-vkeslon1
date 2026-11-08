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

        if (p == nullptr && q == nullptr) {
            return true;
        }

        else if (!p && q || p && !q) {
            return false;
        }
        queue<TreeNode*> pQueue;
        queue<TreeNode*> qQueue;

        TreeNode* pCurr = p;
        TreeNode* qCurr = q;

        pQueue.push(pCurr);
        qQueue.push(qCurr);

        while(!pQueue.empty() && !qQueue.empty()) {
            TreeNode* pTemp = pQueue.front();
            TreeNode* qTemp = qQueue.front();

            if (pTemp->val != qTemp->val || (!pTemp->left && qTemp->left) || (!pTemp->right && qTemp->right)) {
                return false;
            }

            if (pTemp->left) {
                pQueue.push(pTemp->left);
            }

            if (pTemp->right) {
                pQueue.push(pTemp->right);
            }

            if (qTemp->left) {
                qQueue.push(qTemp->left);
            }

            if (qTemp->right) {
                qQueue.push(qTemp->right);
            }

            pQueue.pop();
            qQueue.pop();
        }

        return true;
    }

     
};
