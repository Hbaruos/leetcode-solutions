class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for (auto it : nums)
            m[it]++;
        nums.clear();
        for (auto it : m)
            if (it.second > n / 3)
                nums.push_back(it.first);

        return nums;
    }
};
