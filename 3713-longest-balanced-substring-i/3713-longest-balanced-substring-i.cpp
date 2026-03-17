class Solution {
public:
    int longestBalanced(string s) {
        // unordered_map<char,int>counting;
        int mxsize=1;
        for(int i=0;i<s.size();i++){
            vector<int>alpha(26,0);
            alpha[s[i]-'a']++;
            for(int j=i+1;j<s.size();j++){
                alpha[s[j]-'a']++;
                int val=alpha[s[j]-'a'];
                bool check=true;
                for(int k=0;k<26;k++){
                    if(alpha[k]!=0&&alpha[k]!=val){
                        check=false;
                        break;
                    }
                }
                if(check){
                    mxsize=max(mxsize,(j-i)+1);
                }
            }
        }
        return mxsize;
    }
};