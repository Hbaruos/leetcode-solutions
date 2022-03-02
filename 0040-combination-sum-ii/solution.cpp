#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void findCombo(int i, int x, vector<int>& v, vector<vector<int>>& res, vector<int>& temp) {
        if (x == 0) {
            res.push_back(temp);
            return;
        }
        for (int j = i; j < v.size(); j++) {
            if (j > i && v[j] == v[j - 1]) continue;
            if (v[j] > x) break;
            
            temp.push_back(v[j]);
            findCombo(j + 1, x - v[j], v, res, temp);
            temp.pop_back();
        }
    }
        
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        
        findCombo(0, target, candidates, res, temp);
        
        return res;
    }
};
