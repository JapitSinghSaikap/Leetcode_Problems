class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       
        if(k<=1) return 0;

        int n = nums.size();
        int product = 1;
        int count =0;

        for( int l=0,r=0;r<n;r++){
            product=product*nums[r];
            while(product>=k){
                product=product/nums[l];
                l++;
            }
            count+=r-l+1;//the window size
        }

        return count;
        
    }
};