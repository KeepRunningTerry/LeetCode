class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if( nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }
        
        int pre = 0, maxans = nums[0];
        for(const auto &x : nums){
            pre = max(x,pre+x);
            maxans = max(pre,maxans);
        }
        return maxans;
    }
};