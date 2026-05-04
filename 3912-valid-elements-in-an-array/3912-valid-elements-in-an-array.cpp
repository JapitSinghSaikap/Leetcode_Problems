class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> validElements;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            bool greaterThanLeft = true;

            // Check if nums[i] is greater than all elements to its left
            for (int j = 0; j < i; j++) {
                if (nums[i] <= nums[j]) {
                    greaterThanLeft = false;
                    break;
                }
            }

            bool greaterThanRight = true;

            // Only check the right side if it wasn't already valid from the left
            if (!greaterThanLeft) {
                for (int j = i + 1; j < n; j++) {
                    if (nums[i] <= nums[j]) {
                        greaterThanRight = false;
                        break;
                    }
                }
            }

            // If it satisfies either condition, it's a valid element
            if (greaterThanLeft || greaterThanRight) {
                validElements.push_back(nums[i]);
            }
        }

        return validElements;
    }
};