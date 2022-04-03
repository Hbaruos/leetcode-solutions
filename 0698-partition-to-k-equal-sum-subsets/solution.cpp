class Solution {
public:
    bool canPartitionKSubsets(vector<int>& a, int k) {
        int sum = 0;
        sum = accumulate(a.begin(), a.end(), 0);
        
        if (sum % k || k > a.size()) return false;
        
        vector<bool> visited(a.size(), false);
        int unvisited = a.size();
        // sort(begin(a),end(a),greater<int>());
        return f(a, visited, sum/k, 0, 0, k, unvisited);
    }
    
    int f(vector<int> &a, vector<bool> &v, int tar, int i, int cur_sum, int k, int &unv) {
        if (k == 1) return true;
        if (unv == 0 || i >= a.size()) return false;
        if (cur_sum == tar) return f(a, v, tar, 0, 0, k - 1, unv);
        
        for (int j = i; j < a.size(); ++j) {
            if (v[j] || cur_sum + a[j] > tar) continue;
            
            v[j] = true;
            unv--;
            if (f(a, v, tar, j + 1, cur_sum + a[j], k, unv)) return true;
            v[j] = false;
            unv++;
        }
        return false;
    }
    
};
