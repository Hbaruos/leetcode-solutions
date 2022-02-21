class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> v;
        for (auto it : nums1) 
            m[it]++;
        
        for (auto it : nums2) {
            if (m[it]) {
                v.push_back(it);
                m.erase(it);
            }
        }
        return v;
    }
};
