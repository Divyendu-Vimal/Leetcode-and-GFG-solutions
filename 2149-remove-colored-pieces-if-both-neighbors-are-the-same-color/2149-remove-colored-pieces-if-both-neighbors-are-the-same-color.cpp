class Solution {
public:
    bool winnerOfGame(string s) {
        int n=s.length();
        int ct=0;
        int ct1=0;
        for(int i=0;i<n-2;i++){
            if(s[i]=='A' && s[i+1]=='A' && s[i+2]=='A'){
                ct++;
            }
            if(s[i]=='B' && s[i+1]=='B' && s[i+2]=='B'){
                ct1++;
            }
        }
        if(ct>ct1){
            return true;
        }
        else if(ct==ct1){
            return false;
        }
        else{
            return false;
        }
    }
};