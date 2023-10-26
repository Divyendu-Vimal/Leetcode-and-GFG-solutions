class Solution {
public:
int dp[13][10005];
    int fun(vector<int>&v,int i,int t){
        if(i>=v.size()){
            if(t==0){
                return 0;
            }
            return 1e9;
        }
        int ta=1e9;
        if(dp[i][t]!=-1){
            return dp[i][t];
        }
        if(v[i]<=t){
            ta=1+fun(v,i,t-v[i]);
        }
        int nt=fun(v,i+1,t);
        return dp[i][t]=min(ta,nt);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int f=fun(coins,0,amount);
        if(f>=1e9){
            return -1;
        }
        return f;
    }
};