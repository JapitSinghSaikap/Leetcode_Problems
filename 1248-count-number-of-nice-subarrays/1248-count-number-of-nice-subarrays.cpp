class Solution {
public:
    //similar to binary sum arr (goal)
    int numberOfSubarrays(vector<int>& nums, int k) {
        //arr convert krlo to 0 and 1 then do the same
        unordered_map<int,int>mpp;
        int sum=0,count=0;
        // int maxK=0;
        int l=0,r=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0) nums[i]=1;
            else nums[i]=0;
        }

        while(r<nums.size()){
            sum+=nums[r];
            if(sum==k) count++;
            //check if map mein koi previous to nhi rhe gya
            if(mpp.find(sum-k)!=mpp.end()){
               count+=mpp[sum-k];
                // l++;
            }
            mpp[sum]++;
            r++;
        }

        return count;

    }
};