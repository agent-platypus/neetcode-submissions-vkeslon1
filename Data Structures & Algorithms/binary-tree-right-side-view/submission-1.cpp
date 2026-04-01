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
    vector<int> rightSideView(TreeNode* root) {
        //bfs 

        // store each node in bst
        // start with q.front() -> right and then ->left 
        // store q.front() for each iteration in the while (q.empty() loop) 
        if(!root) {
            return {};        
        }

        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        int numNodes;

        while(!q.empty()) {
            numNodes = q.size();
            TreeNode* curr = q.front();
            res.push_back(curr->val);
            for(int i = 0; i < numNodes; i++) {
                curr = q.front();
                if(curr->right) {
                    q.push(curr->right);

                }
                if(curr->left) {
                    q.push(curr->left);
                }
                q.pop();
            }
        }

        return res; 
    } 
};
