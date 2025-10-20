class Solution {
public:
    int minAddToMakeValid(string s) {
        int valid  = 0;
        int k = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                valid++;
            }else{
               valid >0 ? valid--:k++;
            }

            // if(valid<0){
            //     // valid = -(valid);
            //     k++;
            //     valid++;
            // }
        }
        // k += valid;
        return k+valid;
    }
};