class Solution {
public:
    bool isValid(string s) {
        // int n = s.length();
        stack<char> st;
        bool result = true;

        for (char x : s) {
            if (x == '(' || x == '{' || x == '[') {
                st.push(x);
            } else {
                if(st.empty()) return false;

                if ((x == ')' && st.top() != '(') ||
                    (x == '}' && st.top() != '{') ||
                    (x == ']' && st.top() != '[')) {
                    return false;
                } else {
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};