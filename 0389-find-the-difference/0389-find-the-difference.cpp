class Solution {
public:
    char findTheDifference(string s, string t) {
        int n=s.length();
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i=0;
        int j=0;
        int flag=0;
        while(i<n && j<n+1){
            if(s[i]!=t[j]){
                flag=1;
                return t[j];
            }
            i++;
            j++;
        }
        if(flag==0){
            return t[n];
        }
        return t[j];
    }
};