class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]);
            else {
                // stack is empty and we got closing bracket , return false
                if(st.empty()) return false;
                if(s[i]==')' && st.top()=='(' || s[i]=='}' && st.top()=='{' ||s[i]==']' && st.top()=='[') st.pop();
                // if top ka opening bracket and incoming closing bracket do not match directly return false
                else return false;
        }
        }
        return st.empty();
    }
};