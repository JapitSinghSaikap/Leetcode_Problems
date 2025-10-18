class Solution {
public:
//aram se ho rha easy two pointer question
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int maxx = 0;
        while(l < r){
            int area = min(height[l], height[r]) * (r - l);
            maxx = max(maxx, area);
            //height jhan km whan se pointer move kro
            if(height[l] < height[r]){
                l++;
            } else {
                r--;
            }
        }
        return maxx;
    }
};


// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int l = 0;
//         int r = height.size() - 1;
//         int area;
//         int maxx = 0;
        
//         while (l <= r) {
//             if (height[l] <= height[r]) {
//                 l++;
//                 area = height[l-1] * (r - l+1);
//                 maxx = max(maxx, area);
//             } else if (height[l] > height[r]) {
//                 r--;
//                 area = height[r] * (r - l);
//                 maxx = max(maxx, area);
//             }
//         }
//         l++;
//         r--;
        
//         return maxx;
//     }
// };