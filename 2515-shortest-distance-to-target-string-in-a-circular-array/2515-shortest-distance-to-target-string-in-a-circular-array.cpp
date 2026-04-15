class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIdx) {
        int n=words.size();
        for(int i=0;i<n;i++){
            //forward
            if (words[(startIdx+i)%n] == target) {
                return i;
            }
            //backward
            if (words[(startIdx-i+n)%n]==target) {
                return i;
            }
        }
        return -1;
    }
};