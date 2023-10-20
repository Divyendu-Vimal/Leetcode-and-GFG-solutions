class Solution {
public:
const long long int mod=1e9+7;
long long int dp[301][1000];
    long long int fun(int i,long long int n1,long long int n2,int x){
        if(n1<0){
            return 0;
        }
        if(i>n2){
            if(n1==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i][n1]!=-1){
            return dp[i][n1];
        }
        long long int take=(fun(i+1,n1-pow(i,x),n2,x)%mod+fun(i+1,n1,n2,x)%mod)%mod;
        return dp[i][n1]=take;
    }
    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof(dp));
        long long int f=fun(1,n,n,x);
        return f%mod;
    }
};