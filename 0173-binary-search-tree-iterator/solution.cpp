class BSTIterator {
public:
     stack<TreeNode*> s;
    BSTIterator(TreeNode *root) {
        f(root);
    }
    
    bool hasNext() {
    return s.empty() ? false : true;
    }
    
    int next() {
        TreeNode* temp = s.top();
        s.pop();
        if (temp->right)
            f(temp->right);  
     return temp->val;
    }
    
    void f(TreeNode* root)
    {
        TreeNode* temp = root;
        while (temp)
        {
            s.push(temp);
            temp = temp->left;
        }
    }
};
