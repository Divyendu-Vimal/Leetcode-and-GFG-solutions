class Solution {
public:
    int dp[501][501];
    int findlcs(string word1,string word2,int n1,int n2){
        if(n1<0 || n2<0){
            return 0;
        }
        if(dp[n1][n2]!=-1){
            return dp[n1][n2];
        }
        if(word1[n1]==word2[n2]){
            return dp[n1][n2]=1+findlcs(word1,word2,n1-1,n2-1);
        }
        else{
            return dp[n1][n2]=max(findlcs(word1,word2,n1-1,n2),findlcs(word1,word2,n1,n2-1));
        }
    } 
    int minDistance(string word1, string word2) {
        int n1=word1.length();
        int n2=word2.length();
        memset(dp,-1,sizeof(dp));
        int y=findlcs(word1,word2,n1-1,n2-1);
        return n1-y+n2-y;
    }
};