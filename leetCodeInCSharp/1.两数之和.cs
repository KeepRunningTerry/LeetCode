public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        int[] ret = new int[2];
        for(int i = 0; i < nums.Length; i ++){
            for(int j = i+1; j < nums.Length; j++){
                if(nums[i]+nums[j] == target){
                    return new int[]{i,j};
                }
            }
        }
        return ret;
    }

    int[] TwoSum2(int[] nums, int target)
    {
        Dictionary<int, int> kvs = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; i++)
        {
            if (kvs.ContainsKey(target-nums[i])){
                return new int[] {i,kvs[target-nums[i]]};
            }else{
                kvs.Add(nums[i],i);
            }
        }
    
        return new int[] { 0, 0 };
    }
}