class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int target = original;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                target = 2*target;
            }
        }

        return target;
    }
};