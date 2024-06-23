using ll=long long;
class Solution {
public:
    ll dp[100001][2];
    long long int solve(vector<int>&v,int n,int i,int sign){
        if(i>=n){
            return 0;
        }
        if(dp[i][sign]!=-1){
            return dp[i][sign];
        }
        ll ta=0;
        ll nt=0;
        if(sign==0){
            ta=v[i]+solve(v,n,i+1,1);
            nt=v[i]+solve(v,n,i+1,0);
        }
        else{
            ta=(-1*v[i])+solve(v,n,i+1,0);
        }
        return dp[i][sign]=max<ll>(ta,nt);
    }
    long long maximumTotalCost(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        ll f=solve(nums,n,0,0);
        return f;
    }
};