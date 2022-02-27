class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int j = nums.size() - 2 , jump = 1; 
        while (j >= 0){
            if (nums[j] < jump){ 
                jump++;
            } 
            else jump = 1; 
            j--;
        }
        return !(jump > 1);
    }
};
