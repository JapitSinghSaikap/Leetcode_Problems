class Solution {
public:
    int maxDistance(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        while(nums[j]==nums[i]){
            j--;
        }
        int sum1 = abs(i-j);
        j = n-1;
        while(nums[i]==nums[j]){
            i++;
        }
        int sum2 = abs(i-j);
        return max(sum1,sum2);
    }
};