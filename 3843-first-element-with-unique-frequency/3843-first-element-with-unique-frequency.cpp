class Solution {
public:
    //map for both freq and freq count 
    //iterate krwaun fir arr mein and check kis ka freqcount 1 ata
    //20 -> 1
    //10 -> 1
    //30 -> 2
    //freq ka count
    //1 -> 2
    //2 -> 1
    //return 30
    int firstUniqueFreq(vector<int>& arr) {

        unordered_map<int,int>freq;
        unordered_map<int,int> count;

        for(auto it:arr){
            freq[it]++;
        } 

        for(auto& it:freq){
            count[it.second]++;
        }


        for(int i=0;i<arr.size();i++){
            if(count[freq[arr[i]]]==1){
                return arr[i];
            }
        }


        return -1;
    }
};