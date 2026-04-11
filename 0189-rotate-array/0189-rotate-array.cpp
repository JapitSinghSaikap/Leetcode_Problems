class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Ensure k is within the bounds of the array size
        vector<int> temp;

        for (int i = n-k; i <n; i++) {
            temp.push_back(nums[i]);
        }

       
        for (int i =0; i<n-k; i++) {
            // nums[i + k] = nums[i];
            temp.push_back(nums[i]);
        }

        nums = temp;

        
        // for (int i = 0; i < k; i++) {
        //     nums[i] = temp[i];
        // }
    }
};