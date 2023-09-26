class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int>bitmask(n);
        for(int i=0;i<n;i++){
            for(char c:words[i]){
                bitmask[i]=bitmask[i]|(1<<(c-'a'));
            }
        }
        map<int,int>mp;
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(((bitmask[i]) & (bitmask[j]))==0){
                    int y=words[i].length()*words[j].length();
                    maxi=max(maxi,y);
                }
            }
        }
        return maxi;
    }
};