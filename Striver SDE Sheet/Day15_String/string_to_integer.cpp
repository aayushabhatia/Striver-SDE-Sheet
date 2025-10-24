// https://leetcode.com/problems/string-to-integer-atoi/description/?envType=problem-list-v2&envId=eeudwo2i

class Solution {
public:
    int myAtoi(string s) {
        long long result = 0;
        int n = s.size();
        int i = 0;
        const long long MAX_INT = INT_MAX;
        const long long MIN_INT = INT_MIN;
        if(s.empty()){
            return 0;
        }
        // skip leading whitespace
        while(i<n && s[i]==' '){
            i++;
        }
        if (i == n) {
            return 0;
        }

        // check sign
        int sign = 1;
        if(s[i]=='+'){
            i++;
        }
        else if(s[i]=='-'){
            sign = -1;
            i++;
        }

        // read digits and convert
        while(i<n && isdigit(s[i])){
            int digit = s[i] - '0';
            result = result*10 + digit;
            if (sign * result <= INT_MIN) {
                return INT_MIN;
            }
            if (sign * result >= INT_MAX) {
                return INT_MAX;
            }
            i++;
        }

        // apply sign and return
        return static_cast<int>(result * sign); 
    }
};
