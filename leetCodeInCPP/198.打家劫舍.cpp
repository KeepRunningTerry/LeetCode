class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 2){
            return max(nums[0],nums[1]);
        }

        int a = nums[0],b = max(nums[0],nums[1]), c = 0;
        for(int i = 2; i < nums.size(); i ++){
            c = max(b,a+nums[i]);
            a = b;
            b = c;
        }
        return c;
    }
};