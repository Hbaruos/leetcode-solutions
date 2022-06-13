class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> temp;
        int startPosition = -1, endPosition = -1;
        
        if (binary_search(begin(nums), end(nums), target)) {
            startPosition = distance(begin(nums), lower_bound(begin(nums), end(nums), target));
            endPosition = distance(begin(nums), upper_bound(begin(nums), end(nums), target)) - 1;
        }
        
        temp.emplace_back(startPosition);
        temp.emplace_back(endPosition);
        
        return temp;
    }
};
