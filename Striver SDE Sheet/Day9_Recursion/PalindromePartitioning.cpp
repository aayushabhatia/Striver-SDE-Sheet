// https://leetcode.com/problems/palindrome-partitioning/
// https://takeuforward.org/data-structure/palindrome-partitioning/

class Solution {
public:
    void func(int ind, string s, vector<string> &ds, vector<vector<string>> &ans){
        if(ind == s.size()){ // base case
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < s.size(); ++i) {
            if(isPalindrome(s,ind,i)){
                ds.push_back(s.substr(ind, i-ind+1)); // s.substr(start, length) , i - ind + 1 is the length of the substring from ind to i
                func(i+1, s, ds, ans);
                ds.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int start, int end){
        while(start<= end){
            if(s[start++]!= s[end--]){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        func(0, s, ds, ans);
        return ans;
    }
};
