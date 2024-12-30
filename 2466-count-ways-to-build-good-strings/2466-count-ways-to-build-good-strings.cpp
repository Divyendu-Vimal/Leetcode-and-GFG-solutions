class Solution {
public:
    const int mod=1e9+7;
    int dp[100005];
    int solve(int l,int h,int i,int z,int o){
        if(i>h){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int t1=0;
        if(i>=l){
            t1=(t1%mod+1%mod)%mod;
        }
        t1=(t1%mod+solve(l,h,i+z,z,o)%mod)%mod;
        t1=(t1%mod+solve(l,h,i+o,z,o)%mod)%mod;
        return dp[i]=t1; 
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        int f=solve(low,high,0,zero,one);
        return f;
    }
};