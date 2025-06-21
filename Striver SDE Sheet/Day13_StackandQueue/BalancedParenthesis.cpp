// https://takeuforward.org/data-structure/check-for-balanced-parentheses/
// https://leetcode.com/problems/valid-parentheses/submissions/1671963578/

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> stack;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push(s[i]); // keep pushing when opening brackets come
            } else {
                if (stack.empty()) {
                    return false; // this occurs when there is no opening bracket for a closing bracket
                }
                char top = stack.top();
                if ((s[i] == ')' && top != '(') ||
                    (s[i] == '}' && top != '{') ||
                    (s[i] == ']' && top != '[')) {
                    return false; // when closing bracket in string and opening bracket from top of stack are not matching
                }
                stack.pop();
            }
        }
        return stack.empty(); // in the end finally stack should be empty for ans to be true
    }
};
