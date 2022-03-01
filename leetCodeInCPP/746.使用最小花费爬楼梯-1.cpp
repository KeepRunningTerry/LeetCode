class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int record[cost.size()+1];

        record[0] = 0;
        record[1] = 0;

        for(int i = 2; i <= cost.size(); i ++){
            record[i] = min(record[i-1]+cost[i-1],record[i-2]+cost[i-2]);
        }

        return record[cost.size()];
    }
};