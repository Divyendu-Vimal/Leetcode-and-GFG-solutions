class Solution {
public:
    static bool cmp(string &words1,string &words2){
        return words1.length()<words2.length();
    }
    int findseg(string &w1,string &w2){
        int n=w1.size();
        int m=w2.size();
        int i=0;
        int j=0;
        if(m-n!=1){
            return 0;
        }
        while(i<n && j<m){
            if(w1[i]==w2[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i==n){
            return 1;
        }
        return 0;
    }
    int lis(vector<string>&words,int prev,int curr,vector<vector<int>>&dp){
        if(curr==words.size()){
            return 0;
        }
        if(prev!=-1 && dp[prev][curr]!=-1){
            return dp[prev][curr];
        }
        int take=0,ntake=0;
        if(prev==-1 || findseg(words[prev],words[curr])){
            take=1+lis(words,curr,curr+1,dp);
        }
        ntake=lis(words,prev,curr+1,dp);
        if(prev!=-1){
            dp[prev][curr]=max(take,ntake);
        }
        return max(take,ntake);
    }
    int longestStrChain(vector<string>& words) {
        vector<vector<int>>dp(1001,vector<int>(1001,-1));
        int n=words.size();
        sort(words.begin(),words.end(),cmp);
        int k=lis(words,-1,0,dp);
        return k;
    }
};