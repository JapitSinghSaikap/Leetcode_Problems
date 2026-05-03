class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int> parity;
        for(int i=0;i<nums.size();i++){
            int k=0;
            int what=nums[i]%2;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]%2!=what){
                        k++;
                }
            }
            parity.push_back(k);
        }
        return parity;
    }
};