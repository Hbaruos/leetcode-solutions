class Node {
    public:
    vector<Node*> child;
    
    public:
    Node() : child(vector<Node*> (2, nullptr)) {}
};

class Trie {
    private:
    Node *root;
    
    public:
    Trie() : root(new Node()) {}
    
    void insert(int num) {
        Node* temp = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!temp->child[bit]) 
                temp->child[bit] = new Node();
            temp = temp->child[bit];
        }
    }
    
    int getMax(int num) {
        int maxNum = 0;
        Node* temp = root;
        
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (temp->child[1 - bit]) {
                maxNum = maxNum | (1 << i);
                temp = temp->child[1 - bit];
            }
            else
                temp = temp->child[bit];
        }
        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(begin(nums), end(nums));
        vector<pair<int, pair<int, int>>> oQ;
        
        for (int i = 0; i < size(queries); ++i) 
            oQ.push_back({queries[i][1], {queries[i][0], i}});
        
        sort(begin(oQ), end(oQ));
        
        vector<int> ans(size(queries), 0);
        
        Trie trie;
        int idx = 0;
        for (int i = 0; i < size(queries); ++i) {
            int xi = oQ[i].second.first;
            int mi = oQ[i].first;
            int qIdx = oQ[i].second.second;
            
            while (idx < size(nums) && nums[idx] <= mi) {
                trie.insert(nums[idx]);
                ++idx;
            }
            if (idx == 0) ans[qIdx] = -1;
            else ans[qIdx] = trie.getMax(xi);
        }
        return ans;
    }
};
