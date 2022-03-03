class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        Arrays.sort(nums);
        func(0, nums, res, temp);
        return res;
    }
    
    public void func(int i, int[] nums, List<List<Integer>> res, List<Integer> temp) {
        res.add(new ArrayList(temp));
        for (int j = i; j < nums.length; ++j) {
            if (j > i && nums[j] == nums[j - 1]) continue;
            temp.add(nums[j]);
            func(j + 1, nums, res, temp);
            temp.remove(temp.size() - 1);
        }
    }
    
}
