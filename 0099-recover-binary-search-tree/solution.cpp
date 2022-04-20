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
    void recoverTree(TreeNode* root) {
        TreeNode *prev(nullptr), *start(nullptr), *end(nullptr);
        f(root, prev, start, end);
        swap(start->val, end->val);
    }
    
    void f(TreeNode *root, TreeNode *&prev, TreeNode *&start, TreeNode *&end) {
        if (!root) return;
        f(root->left, prev, start, end);
        if (prev && prev->val > root->val) { 
            if (!start) start = prev;
            end = root;
        }
        prev = root;
        f(root->right, prev, start, end);
    }
    
};
