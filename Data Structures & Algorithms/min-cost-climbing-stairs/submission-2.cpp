class Solution {
   public:
    map<int, int> storage;

    int minCostClimbingStairs(vector<int>& cost, int i = 0) {
        int ans = 0;
        if (i >= cost.size()) {
            return ans;
        }
        if (storage.find(i) != storage.end()) {
            return storage[i];
        }

        if (i == 0) {
            storage[i] = ans = min(cost[i] + min(minCostClimbingStairs(cost, i + 1),
                                                 minCostClimbingStairs(cost, i + 2)),
                                   minCostClimbingStairs(cost, i + 1));

            return ans;
        }
        storage[i] = ans =
            cost[i] + min(minCostClimbingStairs(cost, i + 1), minCostClimbingStairs(cost, i + 2));
        return ans;
    }
};
