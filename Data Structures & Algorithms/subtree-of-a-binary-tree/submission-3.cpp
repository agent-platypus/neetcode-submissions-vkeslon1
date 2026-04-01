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
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while(!q.empty()) {
    //             TreeNode* curr = q.front();

    //             cout << "curr node val = " << curr->val << endl;
    //             cout << "subroot node val = " << subRoot->val << endl << endl;
    //             if(isSameTree(curr, subRoot)) {
    //                 return true;
    //             }
    //             if(curr->left) {
    //                 q.push(curr->left);
    //             }
                
    //             if(curr->right) {
    //                 q.push(curr->right);
    //             }
    //             q.pop();
    //     }
            
    //     return false;
    // }

    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //     if(!p && !q) {
    //         return true;
    //     }
    //     if(p && q && p->val == q->val) {
    //         return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    //     }
    //     else {
    //         return false; 
    //     }
    // }
    if (!subRoot) {
            return true;
        }
        if (!root) {
            return false;
        }

        if (sameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }

    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) {
            return true;
        }
        if (root && subRoot && root->val == subRoot->val) {
            return sameTree(root->left, subRoot->left) &&
                   sameTree(root->right, subRoot->right);
        }
        return false;
    }
};
