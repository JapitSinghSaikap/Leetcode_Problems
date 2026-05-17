class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int low = -1;
        int high = n;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(x(mid, nums) > x(mid + 1, nums) &&
               x(mid, nums) > x(mid - 1, nums)) {
                return mid;
            }

            int a = x(mid - 1, nums);
            int b = x(mid + 1, nums);

            if(a > b) high = mid - 1;
            else low = mid + 1;
        }

        return 0;
    }

    int x(int idx, vector<int>& nums) {
        if(idx < 0 || idx >= nums.size()) {
            return INT_MIN;
        }

        return nums[idx];
    }
};