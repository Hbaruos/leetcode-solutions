class Node {
    private:
    vector<Node*> child;
    
    public:
    Node() : child(vector<Node*> (2, nullptr)) {}
    
    void setNode(int bit, Node* temp) {
        child[bit] = temp;
    }
    
    Node* getNode(int bit) {
        return child[bit];
    }
    
    bool searchNode(int bit) {
        return child[bit] != nullptr;
    }
};

class Trie {
    private:
    Node* root;
    
    public:
    Trie() : root(new Node()) {}
    
    void insert(int num) {
        Node *temp = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!temp->searchNode(bit))
                temp->setNode(bit, new Node());
            temp = temp->getNode(bit);
        }
    }
    
    int getMax(int num) {
        int maxNum = 0;
        Node *temp = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (temp->searchNode(1 - bit)) {
                maxNum = maxNum | (1 << i); 
                temp = temp->getNode(1 - bit);
            }
            else 
                temp = temp->getNode(bit);
        }
        return maxNum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int maxNum = 0;
        
        for (auto &it : nums) 
            trie.insert(it);
        
        for (auto &it : nums)
            maxNum = max(maxNum, trie.getMax(it));
        
        return maxNum;
    }
};
