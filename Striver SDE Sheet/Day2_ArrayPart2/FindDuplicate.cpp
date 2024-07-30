// 287. Find the duplicate number in array
// https://leetcode.com/problems/find-the-duplicate-number/
// https://takeuforward.org/data-structure/find-the-duplicate-in-an-array-of-n1-integers/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans=-1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                ans= nums[i];
            }
        }
        return ans;
    }
};
