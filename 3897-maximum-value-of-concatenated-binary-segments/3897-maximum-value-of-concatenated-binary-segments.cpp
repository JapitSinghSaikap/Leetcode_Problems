class Solution {
public:
    const int mod=1e9+7;
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
         //nums1 1,1
         //nums0 0,0
        //binary string concatentate then return to int
        //for each i i make string using nums1 and nums0 then sort(using lamdba) and concatentate them 
        int n=nums1.size();
        vector<string> arr;
        //string bna li using nums1 and nums0
        for(int i=0;i<n;i++){
            string temp="";
            temp.append(nums1[i],'1');
            temp.append(nums0[i],'0');
            arr.push_back(temp);
        }
        sort(arr.begin(),arr.end(),[&](string &a,string &b){
            return a+b>b+a;
        });
        string str="";
        for(auto& it:arr){
            str+=it;
        }

        long long ans=0;
        for(auto it:str){
            ans=(ans*2+(it-'0'))%mod;
        }

        return ans;
    }
};