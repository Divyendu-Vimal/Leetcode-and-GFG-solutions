class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string k="";
        string t="";
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]!=32){
                t=t+s[i];
            }
            else{
                reverse(t.begin(),t.end());
                k=k+t;
                k=k+" ";
                t="";
            }
        }
        reverse(t.begin(),t.end());
        k=k+t;
        
        return k;
    }
};