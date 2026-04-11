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
