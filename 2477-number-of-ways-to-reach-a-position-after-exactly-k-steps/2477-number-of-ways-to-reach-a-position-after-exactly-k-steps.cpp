class Solution {
public:
    const int mod=1e9+7;
    int dp[3001][1001];
    int fun(int s,int e,int k){
        if(k==0){
            if(s==e){
                return 1;
            }
            return 0;
        }
        if(dp[s+1000][k]!=-1){
            return dp[s+1000][k];
        }
        long long int a=0;
        a=(a%mod+fun(s+1,e,k-1)%mod)%mod;
        a=((a%mod)+(fun(s-1,e,k-1)%mod))%mod;
        return dp[s+1000][k]=a%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
        int f=fun(startPos,endPos,k);
        return f%mod;
    }
};