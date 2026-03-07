class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();

        if(n == 1)
        return 0;

        unordered_map<int,int>hmap1;
        unordered_map<int,int>hmap2;

        for(int i=0;i<n;i++){
            if(i%2 == 0)
            hmap1[nums[i]]++;
            else
            hmap2[nums[i]]++;
        }

        pair<int,int> e1 = {0,-1}, e2 = {0,-1};
        pair<int,int> o1 = {0,-1}, o2 = {0,-1};

        for(auto &it : hmap1){
            if(it.second > e1.first){
            e2=e1;
            e1={it.second,it.first};
            }
            else if(it.second > e2.first)
            e2={it.second,it.first};
        }

        for(auto &it : hmap2){
            if(it.second > o1.first){
            o2=o1;
            o1={it.second,it.first};
            }
            else if(it.second > o2.first)
            o2={it.second,it.first};
        }

        if(e1.second != o1.second)
        return (((n+1)/2)-e1.first)+((n/2)-o1.first);

        return min(((n+1)/2 - e1.first) + ((n/2) - o2.first),
        ((n+1)/2 - e2.first) + ((n/2) - o1.first));

    }
};