class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }else{
                if(st.empty()) return false;
                char top=st.top();
                st.pop();
                if((s[i]==')' && top!='(') || (s[i]==']' && top!='[') || (s[i]=='}' && top!='{')) return false;
            }
        }

        return st.empty();
    }
};


































// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> st;
//         for(int i=0; i<s.size(); i++){
//             if(s[i]=='(' || s[i]=='{' || s[i]=='['){//agr opening aayegi tbhi push krdo stack mein
//                 st.push(s[i]);
//             }
//             else{
//                 if(st.empty()) return false; // because uski opening bracket ho nhi skti as stk its empty
//                 char ch = st.top(); // get the opening bracket to compare with the closing bracket
//                 st.pop();//fir usko nikal bhi dena ke liye consider krdiya hai
//                 if((s[i] == ')' and ch != '(') or  (s[i] == ']' and ch != '[') or (s[i] == '}' and ch != '{')) {
//                     return false;
//                 }
//             }
//         }
//         return st.empty(); 
//     }
// };