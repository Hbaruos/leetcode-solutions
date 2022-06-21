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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> order;
        queue<TreeNode*> q;
        q.emplace(root);
        TreeNode *temp;
        int h;
        
        while (!q.empty()) {
            h = size(q);
            vector<int> v;
            
            for (int i = 0; i < h; ++i) {
                temp = q.front();
                q.pop();
                v.emplace_back(temp->val);
                
                if (temp->left) q.emplace(temp->left);
                if (temp->right) q.emplace(temp->right);
            }
            order.emplace_back(v);
        }
        return order;
    }
};
