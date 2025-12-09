class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int mod =1e9+7;
        unordered_map<int,long long> left,right;
        long long ans=0;
        for(int it:nums) right[it]++;
        //right is to check after the index(future wale elements ke liye) and left is for before the index (past elements ke liye) 
        for(auto it:nums){
            right[it]--;

            long long target = 2LL*it;
            if(left.count(target) && right.count(target)){
                ans=(ans+left[target]*right[target])%mod;
            }
            left[it]++;
        }

        return (int)ans;

    }
};