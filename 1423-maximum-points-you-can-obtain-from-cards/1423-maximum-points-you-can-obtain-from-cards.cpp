// class Solution {
// public:
//     int maxScore(vector<int>& nums, int k) {
//         int sum=0;
//         int n=nums.size();
//         //k cards left se le liye
//         for(int i=0;i<k;i++){
//             sum+=nums[i];
//         }

//         int maxSum=sum;
//         for(int i=0;i<k;i++){
//             sum =sum-nums[k-i-1]+nums[n-i-1];
//             maxSum=max(maxSum,sum);
//         }

//         return maxSum;
//     }
// };


class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int sizeN = n - k;

        int totalSum = 0;
        for(int x : nums) totalSum += x;

        
        if(sizeN == 0) return totalSum;

        int windowSum = 0;
        // First window
        for(int i = 0; i < sizeN; i++) {
            windowSum += nums[i];
        }

        int minSum = windowSum;
        // Slide the window
        for(int i = sizeN; i < n; i++) {
            windowSum += nums[i];                
            windowSum -= nums[i - sizeN]; 
            minSum = min(minSum, windowSum);
        }

        return totalSum - minSum;
    }
};