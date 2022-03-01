class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 2){
            return max(nums[0],nums[1]);
        }

        return max(
            robWithRange(nums, 0, nums.size()-1),
            robWithRange(nums, 1, nums.size()));
    }

    int robWithRange(vector<int>& nums, int start, int endWithout){
        int size = endWithout-start;
         if(size == 1){
            return nums[start];
        }
        if(size == 2){
            return max(nums[start],nums[start+1]);
        }

        int a = nums[start],b = max(nums[start],nums[start+1]), c = 0;
        for(int i = start+2; i < endWithout; i ++){
            c = max(b,a+nums[i]);
            a = b;
            b = c;
        }
        return c;
    }
};