// Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// https://takeuforward.org/data-structure/length-of-longest-substring-without-any-repeating-character/

#include<bits/stdc++.h>
using namespace std;
// Optimal solution using hashmap 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // creates a vector of size 256 (to cover all possible ASCII characters) and initializes all values to -1. This vector will be used to store the last occurrence index of each character.
        vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      // loop continues until the right pointer has processed all characters in the string
      while (right < n) {
        // checks if the current character s[right] has been seen before and is within the current window
        if (mpp[s[right]] != -1) 
          // If it has been seen, we need to update the left pointer to ensure the substring does not have repeating characters
          left = max(mpp[s[right]] + 1, left);
        //  updates the last occurrence of the current character s[right] to the current right index
        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
};
