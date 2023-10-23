class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0){
            return false;
        }
        double k1=log2(n);
        if(ceil(k1)==floor(k1)){
            return true;
        }
        return false;
    }
};