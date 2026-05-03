class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int,int>axis;
        for(char c : moves){
            if(c=='R') axis.first++;
            else if(c=='L') axis.first--;
            else if(c=='U') axis.second++;
            //down ke liye hai
            else axis.second--;
        }
        return axis.first==0 && axis.second ==0;

    }
};