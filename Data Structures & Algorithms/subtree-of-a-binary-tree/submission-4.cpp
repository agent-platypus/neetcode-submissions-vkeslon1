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

        TreeNode* curr = root;
        q.push(curr);

        while(!q.empty()) {
            TreeNode* temp = q.front();

            if (temp->val == subRoot->val) {
                if (isSame(temp, subRoot)) {
                    return true;
                }
            }
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }

            q.pop();
        }

        return false;
    }

    bool isSame(TreeNode* a, TreeNode* b) {
        queue<TreeNode*> a_Queue;
        queue<TreeNode*> b_Queue;

        TreeNode* currA = a;
        TreeNode* currB = b;

        a_Queue.push(currA);
        b_Queue.push(currB);

        while(!a_Queue.empty() && !b_Queue.empty()) {
            TreeNode* curr_a = a_Queue.front();
            TreeNode* curr_b = b_Queue.front();
            if (curr_a->val != curr_b->val || (!curr_a->left && curr_b->left) || (!curr_a->right && curr_b->right)) {
                return false; 
            }
            if (curr_a->left) {
                a_Queue.push(curr_a->left);
            }

            if (curr_a->right) {
                a_Queue.push(curr_a->right);
            }

            if (curr_b->left) {
                b_Queue.push(curr_b->left);
            }

            if (curr_b->right) {
                b_Queue.push(curr_b->right);
            }

            a_Queue.pop();
            b_Queue.pop();
        }

        if (!a_Queue.empty() || !b_Queue.empty()) {
            return false;
        }
        return true;
        
    }
};
