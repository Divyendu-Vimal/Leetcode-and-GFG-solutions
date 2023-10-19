class Solution {
public:
    string removeStars(string s) {
        int n=s.length();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
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
};