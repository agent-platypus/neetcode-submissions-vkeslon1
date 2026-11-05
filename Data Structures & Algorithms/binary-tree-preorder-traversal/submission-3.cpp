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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        stack<TreeNode*> callStack;


        // stack 1 2 4 
        if (!curr) {
            return {};
        }
        // res   1 2 4 
        while(curr || !callStack.empty()) {
            if (!curr) {
                TreeNode* temp = callStack.top();
                curr = temp->right;
                callStack.pop();
                continue;
            }
            //cout << "curr val = " << curr->val << endl;
            callStack.push(curr);
            res.push_back(curr->val);
            curr = curr->left;
        }

        return res;
    }

    // dfs(node) { if (!node) return; res.push_back(val) dfs(node->left); dfs(node->right);}
};