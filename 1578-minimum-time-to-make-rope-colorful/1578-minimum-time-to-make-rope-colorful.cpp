class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int count = 0;
        int n = colors.size();
        int timeNotUsed = 0;
        for(int i=0;i<n;i++){
            int maxTime = neededTime[i];
            while(i+1<n && colors[i]==colors[i+1]){//if color match (consecutive ones)
                maxTime = max(maxTime,neededTime[i]);
                i++;
            }
            maxTime = max(maxTime,neededTime[i]);
            timeNotUsed+=maxTime;
        }   
        int totalTime = accumulate(neededTime.begin(),neededTime.end(),0);//initiated with zero
        return totalTime-timeNotUsed;
    }
};