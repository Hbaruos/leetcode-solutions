class Solution {
    public:
        double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
            std::vector<int> arr (nums1.size()+nums2.size());
            
            for(int i=0; i<nums1.size(); ++i)
                arr[i] = nums1[i];
            
            for(int i=0; i<nums2.size(); ++i)
                arr[i+nums1.size()] = nums2[i];

            std::sort(arr.begin(), arr.end());

            int index = arr.size()/2;

            return arr.size()%2? arr[index] : (double) (arr[index] + arr[index-1])/2;
        }
};
