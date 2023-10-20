class Solution {
public:
    int dp[21][3001];
    int fun(int i,vector<int>&nums,int t){
        if(i>=nums.size()){
            if(t==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][t+1001]!=-1){
            return dp[i][t+1001];
        }
        int take=fun(i+1,nums,t-nums[i]);
        int nt=fun(i+1,nums,t+nums[i]);
        return dp[i][t+1001]=take+nt;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int f=fun(0,nums,target);
        return f;
    }
};