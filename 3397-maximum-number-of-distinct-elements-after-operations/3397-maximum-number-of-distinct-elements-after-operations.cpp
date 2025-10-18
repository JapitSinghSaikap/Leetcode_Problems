//Got tle for this brute force approach
// class Solution {
// public:
//     int maxDistinctElements(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         unordered_set<int> st;
//         //the range is x-k to x+k jhan pe x humara num hai
//         for(int num:nums){
//             for(int i=num-k;i<=num+k;i++){
//                 if(!st.count(i)){
//                     st.insert(i);
//                     break;
//                 }
//             }
//         }

//         return st.size();
//     }
// };
//used a curr, prev to track to the disticnt count
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0, prev = INT_MIN;
        for (int num : nums) {
            //prev+1 is the next distinct available num and min to ensure ki range mein hum
            int curr = min(max(num - k, prev + 1), num + k);
            if (curr > prev) {
                cnt++;
                prev = curr;
            }
        }
        return cnt;
    }
};