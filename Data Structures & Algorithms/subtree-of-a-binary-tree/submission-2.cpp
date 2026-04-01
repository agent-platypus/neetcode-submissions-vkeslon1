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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
                TreeNode* curr = q.front();

                cout << "curr node val = " << curr->val << endl;
                cout << "subroot node val = " << subRoot->val << endl << endl;
                if(isSameTree(curr, subRoot)) {
                    return true;
                }
                if(curr->left) {
                    q.push(curr->left);
                }
                
                if(curr->right) {
                    q.push(curr->right);
                }
                q.pop();
        }
            
        return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) {
            return true;
        }
        if(p && q && p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else {
            return false; 
        }
    }
};
