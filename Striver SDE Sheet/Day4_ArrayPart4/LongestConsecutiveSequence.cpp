// 128. Longest Consecutive Sequence of numbers
// https://leetcode.com/problems/longest-consecutive-sequence/
// https://takeuforward.org/data-structure/longest-consecutive-sequence-in-an-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
    if (n == 0) return 0;
    sort(nums.begin(), nums.end());
    // Initializing
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    //find longest sequence:
    for (int i = 0; i < n; i++) {
        if (nums[i] - 1 == lastSmaller) { // lastSmaller is the previous element and if current element value -1 is equal to lastsmaller then inc the cnt ie the length
            //a[i] is the next element of the current sequence.
            cnt += 1;
            lastSmaller = nums[i];
        }
        else if (nums[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = nums[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
    }
};
