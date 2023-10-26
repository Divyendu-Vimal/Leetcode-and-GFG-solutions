class Solution {
public:
int dp[1000][1000];
    int fun(vector<int>&nums,int t,int n,int i,int prev){
        if(i==n-1){
            if(abs(nums[i]-nums[prev])<=t){
                return 1;
            }
            else{
                return -1e9;
            }
        }
        if(i>=n){
            return -1e9;
        }
        if(dp[i][prev]!=-1){
            return dp[i][prev];
        }
        int a=-1e9;
        if(abs(nums[i]-nums[prev])<=t){
            a=1+fun(nums,t,n,i+1,i);
        }
        int b=fun(nums,t,n,i+1,prev);
        return dp[i][prev]=max(a,b);
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int f=fun(nums,target,n,1,0);
        if(f<=0){
            return -1;
        }
        return f;
    }
};