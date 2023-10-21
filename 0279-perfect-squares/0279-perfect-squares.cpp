class Solution {
public:
    int dp[10001][1000];
    int fun(int n,int i,int sum){
        if(sum==0){
            return 0;
        }
        if(i*i>n || sum<0){
            return 1e8;
        }
        if(dp[sum][i]!=-1){
            return dp[sum][i];
        }
        int take=1e8;
        if(i*i<=sum){
            take=1+fun(n,i,sum-pow(i,2));
        }
        int ntake=fun(n,i+1,sum);
        return dp[sum][i]=min(take,ntake);
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        int f=fun(n,1,n);
        return f;
    }
};