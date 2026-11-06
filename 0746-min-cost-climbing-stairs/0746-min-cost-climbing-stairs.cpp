// har stair se hokar aage jaane ka cost nikalenge, lekin har stair tak pahuchne ke liye ya to uske ek niche ya fir do niche wali stair se ayenge , aur humko minimum cost wali se aana fir ith se aage continue karna till goal stair is reached
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n); // is dp array ke har index m us stair tak pahuchne ka cost store hoga, har stair tak pahuchne ke 2 ways hain, either 1 jump or 2 , we will take that jump jiski cost minimum hoe, then add it to ith stair since humko har ith stair se hokar jaane ki cost calculate karni hai, so also us ith stair ka cost bhi include hoga
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        // since our dp array is ready , and n is our goal stair, we can either reach there via n-1 or n-2 stair , so we will return the min(dp[n-1],dp[n-2])
        return min(dp[n-1], dp[n-2]);
    }
};