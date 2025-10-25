class Solution {
    public int totalMoney(int n) {
            int start = 0 , k = 0;
            int day = 0;
            int sum = 0;
            for(int i=1;i<=n;i++){
                start++;
                day++;
                sum+=start;
                if(day == 7){
                    day = 0;
                    k++;
                    start = k; 
                }
                
            }
            return sum;
    }
}