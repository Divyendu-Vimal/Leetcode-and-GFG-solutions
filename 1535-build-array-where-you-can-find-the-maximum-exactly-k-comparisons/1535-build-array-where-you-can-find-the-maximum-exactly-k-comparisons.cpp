class Solution {
public:
    int dp[51][101][51]; 
    int mod=1e9+7;
    int findway(int ind,int n,int m,int k,int maxi,int search_length){
        if(ind>=n){
            if(search_length==k){
                return 1;
            }
            return 0;
        }
        if(dp[ind][maxi][search_length]!=-1){
            return dp[ind][maxi][search_length];
        }
        int result=0;
        for(int i=1;i<=m;i++){
            if(i>maxi){
                result=((result%mod)+(findway(ind+1,n,m,k,i,search_length+1))%mod)%mod;
            }
            else{
                result=((result%mod)+(findway(ind+1,n,m,k,maxi,search_length))%mod)%mod;
            }
        }
        return dp[ind][maxi][search_length]=result%mod;
    }
    int numOfArrays(int n, int m, int k) {
        if(k>m){
            return 0;
        }
        else{
            memset(dp,-1,sizeof(dp));
            int s=findway(0,n,m,k,0,0);
            return s%mod;
        }
    }
};