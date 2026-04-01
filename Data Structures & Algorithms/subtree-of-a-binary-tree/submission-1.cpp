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
        // search for a node in the first tree that matches the subRoot val and go from there

        // stop traversing the subTree once the last node has been traversed, checking the node values with the 
        // tree node values along the way 
        

        if(root == nullptr)
            return false;
        
        if(isSameTree(root, subRoot)){
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
    }

    // function to find starting point in the tree
    bool isSameTree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr) {
            return true;
        }
        if(root == nullptr || subRoot == nullptr) {
            return false;
        }

        return (root->val == subRoot->val) && isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
    }
};
