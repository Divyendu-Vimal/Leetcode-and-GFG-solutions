class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char>st;
        stack<char>st1;
        int n=s.length();
        int ct=0;
        int ct1=0;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(s[i]=='b'){
                    if(st.top()=='a'){
                        ct=ct+x;
                        st.pop();
                    }
                    else{
                        st.push(s[i]);
                    }
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        string a;
        while(!st.empty()){
            a.push_back(st.top());
            st.pop();
        }
        reverse(a.begin(),a.end());
        for(int i=0;i<a.length();i++){
            if(st.empty()){
                st.push(a[i]);
            }
            else{
                if(a[i]=='a'){
                    if(st.top()=='b'){
                        ct=ct+y;
                        st.pop();
                    }
                    else{
                        st.push(a[i]);
                    }
                }
                else{
                    st.push(a[i]);
                }
            }
        }


        // 2nd condition

        for(int i=0;i<s.length();i++){
            if(st1.empty()){
                st1.push(s[i]);
            }
            else{
                if(s[i]=='a'){
                    if(st1.top()=='b'){
                        ct1=ct1+y;
                        st1.pop();
                    }
                    else{
                        st1.push(s[i]);
                    }
                }
                else{
                    st1.push(s[i]);
                }
            }
        }
        string b;
        while(!st1.empty()){
            b.push_back(st1.top());
            st1.pop();
        }
        reverse(b.begin(),b.end());
        for(int i=0;i<b.length();i++){
            if(st1.empty()){
                st1.push(b[i]);
            }
            else{
                if(b[i]=='b'){
                    if(st1.top()=='a'){
                        ct1=ct1+x;
                        st1.pop();
                    }
                    else{
                        st1.push(b[i]);
                    }
                }
                else{
                    st1.push(b[i]);
                }
            }
        }
        return max(ct,ct1);
    }
};