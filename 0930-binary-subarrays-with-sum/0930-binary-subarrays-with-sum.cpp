class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mpp;
        int sum=0;
        int finalSum=0;
        for(auto it:nums){
            sum+=it;
            if(sum==goal){
                finalSum++;
            }
            if(mpp.find(sum-goal)!=mpp.end()){
                //yeh prefix sum wala part hai
               finalSum+=mpp[sum-goal];
            }
            mpp[sum]++;
        }
        return finalSum;
    }
};