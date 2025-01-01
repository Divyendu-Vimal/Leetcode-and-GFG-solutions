class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        int ct1=count(s.begin(),s.end(),'1');
        int ct0=count(s.begin(),s.end(),'0');
        vector<int>v1(n,0);
        vector<int>v0(n,0);
        for(int i=0;i<n;i++){
            if(i==0){
                if(s[0]=='1'){
                    v1[0]=1;
                }
                else{
                    v0[0]=1;
                }
            }
            else{
                if(s[i]=='1'){
                    v1[i]=1+v1[i-1];
                    v0[i]=v0[i-1];
                }
                else{
                    v1[i]=v1[i-1];
                    v0[i]=1+v0[i-1];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,v0[i]+ct1-v1[i]);
        }
        return ans;
    }
};