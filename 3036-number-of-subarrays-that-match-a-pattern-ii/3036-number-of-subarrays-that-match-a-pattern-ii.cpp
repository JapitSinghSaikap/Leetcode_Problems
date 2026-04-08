// class Solution {
// public:
//     int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
//         int n = nums.size();
//         int m = pattern.size();
//         int ans = 0;

//         for(int i = 0; i < n; i++){
//             int cnt = 0;
//             for(int j = 0; j < m; j++){
//                 if(i+j+1 < n){
//                     if(pattern[j] == 1 && nums[i+j+1] > nums[i+j]) cnt++;
//                     else if(pattern[j] == 0 && nums[i+j+1] == nums[i+j]) cnt++;
//                     else if(pattern[j] == -1 && nums[i+j+1] < nums[i+j]) cnt++;
//                 }
//             }
//             if(cnt == m) ans++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> buildLPS(vector<int>& pattern) {
        int m = pattern.size();
        vector<int> lps(m, 0);

        int len = 0;
        for (int i = 1; i < m; ) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) len = lps[len - 1];
                else i++;
            }
        }
        return lps;
    }

    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();

        // Step 1: build rel array
        vector<int> rel;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i+1] > nums[i]) rel.push_back(1);
            else if (nums[i+1] == nums[i]) rel.push_back(0);
            else rel.push_back(-1);
        }

        // Step 2: KMP
        vector<int> lps = buildLPS(pattern);

        int i = 0, j = 0, ans = 0;
        while (i < rel.size()) {
            if (rel[i] == pattern[j]) {
                i++; j++;
            }

            if (j == pattern.size()) {
                ans++;
                j = lps[j - 1];
            } 
            else if (i < rel.size() && rel[i] != pattern[j]) {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }

        return ans;
    }
};