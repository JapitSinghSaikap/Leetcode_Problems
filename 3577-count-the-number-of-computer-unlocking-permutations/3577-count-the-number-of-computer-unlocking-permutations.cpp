class Solution {
public:
    int countPermutations(vector<int>& comp) {
        int n=comp.size();
        //impossible case
        for(int i=1;i<n;i++){
            if(comp[i]<=comp[0]) return 0;
        }

        long long ans=1;
        long long mod=1e9+7;
        for(int i=2;i<n;i++){
            ans=(ans*i)%mod;
        }

        return (int)ans;

    }
};