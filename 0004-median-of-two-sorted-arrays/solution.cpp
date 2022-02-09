class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        int x = nums1.size();
        int y = x/2;
        return x%2? nums1[y] : (double) (nums1[y-1]+nums1[y])/2;
    }
};
