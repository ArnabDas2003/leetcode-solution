class Solution {
public:
    string removeOuterParentheses(string s) {
        string result="";
        int depth=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='('){
                if(depth>0){
                    result+=ch;
                }
                depth++;

            }else{
                depth--;
                if(depth>0){
                    result+=ch;
                }
            }
        }
        return result;
    }
};