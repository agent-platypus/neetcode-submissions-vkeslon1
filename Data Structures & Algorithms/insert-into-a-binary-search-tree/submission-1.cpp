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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        
        TreeNode* newNode = new TreeNode(val);
        
        if (!root) {
            return newNode;
        }

        while(curr) {
            if (curr->val > val) {
                if (!curr->left) {
                    curr->left = newNode;
                    break;
                }
                curr = curr->left;
                
            }
            else {
                if (!curr->right) {
                    curr->right = newNode;
                    break;
                }
                curr = curr->right;
            }
        }

        return root;


    }
};