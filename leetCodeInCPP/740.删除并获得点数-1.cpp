class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = 0;
        for(int item : nums){
            maxVal = max(maxVal,item);
        }
        vector<int> sums(maxVal+1);

        for(int item : nums){
            sums[item] += item;
        }

        return rob(sums);
    }

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

/**
给你一个整数数组 nums ，你可以对它进行一些操作。

每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。

开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。

这种相邻元素之间有约束关系的，可以联想到打家劫舍
*/