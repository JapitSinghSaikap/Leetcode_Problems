class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> set;
        if (nums.size() < 3)  
            return {};

        sort(nums.begin(), nums.end()); 

        for (int i = 0; i < nums.size() - 2; ++i) {
            int target = -nums[i];
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int sum = nums[j] + nums[k];
                if (sum == target) {
                    set.insert({nums[i], nums[j], nums[k]}); 
                    ++j;
                    --k;
                } else if (sum < target) {
                    ++j;
                } else {
                    --k;
                }
            }
        }

        
        return vector<vector<int>>(set.begin(), set.end());
    }
};