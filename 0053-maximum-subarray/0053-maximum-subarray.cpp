class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int sum=0;
        //use of kadane's algorithm
        for(auto it:nums){
            sum +=it;
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
        }
        return maxi;   
    }
};