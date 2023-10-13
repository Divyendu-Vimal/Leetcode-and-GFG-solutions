class Solution {
public:
    int fun(vector<int>&cost,int n,vector<int>&dp){
        if(n<=1){
            return cost[n];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=min((cost[n]+fun(cost,n-1,dp)),(cost[n]+fun(cost,n-2,dp)));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        int f=fun(cost,n-1,dp);
        int p=fun(cost,n-2,dp);
        return min(f,p);
    }
};