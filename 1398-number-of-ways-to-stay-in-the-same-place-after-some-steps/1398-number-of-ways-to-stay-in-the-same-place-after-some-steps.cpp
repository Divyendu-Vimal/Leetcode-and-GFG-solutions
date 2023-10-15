class Solution {
public:
    int mod=1e9+7;
    int dp[501][501];
    int fun(int ind,int steps,int n){
        if(ind<0 || ind>=n){
            return 0;
        }
        if(steps==0){
            if(ind==0){
                return 1;
            }
            return 0;
        }
        if(dp[ind][steps]!=-1){
            return dp[ind][steps];
        }
        int a=fun(ind+1,steps-1,n)%mod;
        a=(a%mod+fun(ind-1,steps-1,n)%mod)%mod;
        a=(a%mod+fun(ind,steps-1,n)%mod)%mod;
        return dp[ind][steps]=a%mod;
    }
    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof(dp));
        int f=fun(0,steps,min(steps,arrLen));
        return f;
    }
};