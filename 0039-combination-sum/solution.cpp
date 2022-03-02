class Solution {
public:
    
    void findCombo(int i, int x, vector<int> &arr, vector<vector<int>> &res, vector<int> &temp) {
        if (i == arr.size()) {
            if (x == 0) {
                res.push_back(temp);
            }
            return;
        }
        if (arr[i] <= x) {
            temp.push_back(arr[i]);
            findCombo(i, x - arr[i], arr, res, temp);
            temp.pop_back();
        }
        findCombo(i + 1, x, arr, res, temp);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        findCombo(0, target, candidates, res, temp);
        return res;
    }
};
