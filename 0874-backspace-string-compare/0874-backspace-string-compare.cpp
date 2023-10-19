class Solution {
public:
    string fnc(string &s,int n){
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]!='#'){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    continue;
                }
                else{
                    st.pop();
                }
            }
        }
        if(st.empty()){
            return "";
        }
        string p;
        while(!st.empty()){
            p.push_back(st.top());
            st.pop();
        }
        reverse(p.begin(),p.end());
        return p;
    }
    bool backspaceCompare(string s, string t) {
        int n=s.length();
        int m=t.length();
        string s2=fnc(s,n);
        string s1=fnc(t,m);
        if(s2==s1){
            return true;
        }
        return false;
    }
};