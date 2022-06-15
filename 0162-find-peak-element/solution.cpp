class Solution {
public:
    int _findPeakElement(vector<int>& nums, int l, int r) {
        if (l == r) return l;
        auto m = (l + r) / 2;
        return nums[m] < nums[m + 1] ? _findPeakElement(nums, m + 1, r) : _findPeakElement(nums, l, m); 
    }
    
    int findPeakElement(vector<int>& nums) {
        return _findPeakElement(nums, 0, size(nums) - 1);
    }
};
