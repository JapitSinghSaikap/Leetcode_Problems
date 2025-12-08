class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        //brute force method to check all the pairs
        for (int a=1;a<=n;a++) {
            for (int b=1;b<=n;b++) {
                int target=pow(a, 2)+pow(b, 2);
                int root=sqrt(target);
                if (root*root==target && root<=n) ans++;
            }
        }
        return ans;
    }
};