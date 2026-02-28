class Solution {
public:
    int minMoves(int target, int maxDouble) {
        //greedy approach reverse se start kiya because breaking it from 1 would be complex
        int cnt=0;
        while(target>0 && maxDouble!=0){
            if(target%2==1){
                cnt++;
                target--;
            }
            else{
                target/=2;
                maxDouble--;
                cnt++;
            }
        }
        return cnt+target-1;
    }
};