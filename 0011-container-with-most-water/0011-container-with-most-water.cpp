class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int maxi=INT_MIN;
        while(i<j){
            if(height[i]<height[j]){
                maxi=max(maxi,min(height[i],height[j])*(j-i));
                i++;
            }
            else{
                maxi=max(maxi,min(height[i],height[j])*(j-i));
                j--;
            }
        }
        return maxi;
    }
};