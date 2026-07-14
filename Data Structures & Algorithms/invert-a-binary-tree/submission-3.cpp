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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        queue <TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()){
            TreeNode *tmp = queue.front();
            queue.pop();
            swap(tmp->left, tmp->right);
            if (tmp->left) queue.push(tmp->left);
            if (tmp->right) queue.push(tmp->right);
        }
        return root;
    }
};
