class Solution {
public:
    //prefix sum se kiya hai yeh
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mpp;
        int sum=0;
        int finalSum=0;
        for(auto it:nums){
            //yhan pe hum prefix sum hi bna rhe 
            sum+=it;
            if(sum==goal){
                finalSum++;
            }
            //and if part mil gya mpp mein 
            if(mpp.find(sum-goal)!=mpp.end()){
                //yeh prefix sum wala part hai
               finalSum+=mpp[sum-goal];
            }
            //mpp mein us sum ko add bhi kr rhe taki aage wale occurneces mein uska count le ske
            mpp[sum]++;
        }
        return finalSum;
    }
};