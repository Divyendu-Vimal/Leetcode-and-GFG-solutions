class Solution {
public:
    int numSteps(string s) {
        int n=s.length();
        int ct=0;
        while(s!="1"){
            if(s[s.length()-1]=='0'){
                s.pop_back();
            }
            else{
                int f=0;
                for(int i=s.length()-1;i>=0;i--){
                    if(s[i]=='1'){
                        s[i]='0';
                    }
                    else{
                        s[i]='1';
                        f=1;
                        break;
                    }
                }
                if(f==0){
                    s='1'+s;
                }
            }
            ct++;
        }
        return ct;
    }
};