class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counta = 0, countb = 0, countc = 0;

        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) counta++;
            else if(nums[i] == 1) countb++;
            else countc++;
        }

        
        for(int i = 0; i < counta; i++) {
            nums[i] = 0;
        }
        for(int i = counta; i < counta + countb; i++) {
            nums[i] = 1;
        }
        for(int i = counta + countb; i < nums.size(); i++) {
            nums[i] = 2;
        }
    }
};
