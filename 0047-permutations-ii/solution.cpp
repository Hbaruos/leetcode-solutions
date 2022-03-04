class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> freq(nums.size(), 0);
        sort(nums.begin(), nums.end());
        func(nums, res, temp, freq);
        return res;
    }
    
    void func(vector<int> &nums, vector<vector<int>> &res, vector<int> &temp, vector<bool> &freq) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i && !freq[i-1] && nums[i] == nums[i - 1]) continue;
            if (!freq[i]) {
                freq[i] = 1;
                temp.push_back(nums[i]);
                func(nums, res, temp, freq);
                temp.pop_back();
                freq[i] = 0;
            }
        }
    }
    
};
