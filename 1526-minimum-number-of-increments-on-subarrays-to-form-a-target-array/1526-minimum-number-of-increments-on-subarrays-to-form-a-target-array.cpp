class Solution {
public:
    int minNumberOperations(vector<int>& targets) {
        int ini=targets[0];
        for(int i=1;i<targets.size();i++){
            if(targets[i]>targets[i-1]){
                ini+=targets[i]-targets[i-1];
            }
        }

        return ini;
    }
};