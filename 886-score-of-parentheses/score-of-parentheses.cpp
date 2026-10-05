class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        int score;
        for(char c : s){
            if(c == '('){
                st.push(0);
            }
            else{
                int inside = st.top();
                st.pop();
                if(inside == 0){
                    score = 1;
                }
                else{
                    score = 2*inside;
                }
                st.top() += score;
            }
        }
        return st.top();
    }
};