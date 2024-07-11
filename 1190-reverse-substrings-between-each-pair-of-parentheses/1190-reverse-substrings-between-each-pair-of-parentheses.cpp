class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                string s1;
                while(st.top()!='('){
                    s1.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for(auto it:s1){
                    st.push(it);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};