class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0){
            return false;
        }
        double k1=log(n)/log(4);
        if(ceil(k1)==floor(k1)){
            return true;
        }
        return false;
    }
};