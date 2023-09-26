class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.length();
        stack<char>st;
        vector<int>freq(26,0);
        vector<int>vis(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            if(vis[s[i]-'a']==1){
                freq[s[i]-'a']--;
            }
            else if(vis[s[i]-'a']==0){
                while(!st.empty() && st.top()>s[i] && freq[st.top()-'a']>0){
                    vis[st.top()-'a']=0;
                    st.pop();
                }
                st.push(s[i]);
                freq[s[i]-'a']--;
                vis[s[i]-'a']=1;
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