class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum = 0;
        for(int it : nums) sum+=it;
        int rightSum = sum;
        int leftSum = 0;
        int cnt = 0;
        for(int it : nums){
            if(it==0){
                if(leftSum >= rightSum && leftSum-rightSum<=1) cnt++;
                if(rightSum >= leftSum && rightSum-leftSum<=1) cnt++;
            }
            leftSum+=it;
            rightSum-=it;
        }   
        return cnt;
    }
};