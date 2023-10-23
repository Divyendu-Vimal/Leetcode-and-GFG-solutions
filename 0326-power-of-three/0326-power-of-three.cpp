class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0){
            return false;
        }
        double k1=log10(n)/log10(3);
        if(ceil(k1)==floor(k1)){
            return true;
        }
        return false;
    }
};