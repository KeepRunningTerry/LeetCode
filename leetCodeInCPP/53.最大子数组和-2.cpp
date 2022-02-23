class Solution {
public:
//超时，未知对错
    int maxSubArray(vector<int>& nums) {
        if( nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }
        
        int sums[nums.size()];
        sums[0] = nums[0];
        for(int i = 1; i < nums.size(); i ++){
            sums[i] = sums[i-1]+nums[i];
        }

        int ret = nums[0];
        for(int i = 0; i < nums.size(); i ++){
            ret = max(ret,sums[i]);
            for( int j = i+1; j < nums.size(); j ++){
                ret = max(ret,sums[j]-sums[i]);
            }
        }

        return ret;
    }
};