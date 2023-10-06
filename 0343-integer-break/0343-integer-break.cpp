class Solution {
public:
    int integerBreak(int n) {
        if(n==2){
            return 1;
        }
        if(n==3){
            return 2;
        }
        vector<int>v(59,0);
        v[4]=4;
        v[5]=6;
        v[6]=9;
        for(int i=7;i<=n;i++){
            v[i]=v[i-3]*3;
        }
        return v[n];
    }
};