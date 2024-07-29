// 53. Maximum Subarray- Kadane's Algorithm
// https://leetcode.com/problems/maximum-subarray/
// https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs = 0; // current sum
        int largest = nums[0]; // initialize largest to the first element
        for(int i = 0; i < nums.size(); i++) {
            cs = cs + nums[i];
            if (cs > largest) {
                largest = cs;
            }
            if (cs < 0) {
                cs = 0;
            }
        }
        return largest;
    }
    
};