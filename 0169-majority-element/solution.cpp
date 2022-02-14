class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, num;
        for (auto it : nums) {
            if (cnt == 0)
                num = it;
            if (it == num)
                cnt++;
            else 
                cnt--;
        }
        return num;
    }
};
