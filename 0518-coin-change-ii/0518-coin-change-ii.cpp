class Solution {
public:
int dp[301][5001];
    int fun(vector<int>&v,int i,int t){
        if(i>=v.size()){
            if(t==0){
                return 1;
            }
            return 0;
        }
        if(t<0){
            return 0;
        }
        if(dp[i][t]!=-1){
            return dp[i][t];
        }
        int ta=fun(v,i,t-v[i]);
        int nt=fun(v,i+1,t);
        return dp[i][t]=ta+nt;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        int f=fun(coins,0,amount);
        return f;
    }
};