// 31. Next Permutation
// https://leetcode.com/problems/next-permutation/
// https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
     int n = nums.size(); // size of the array

        // Step 1: Find the break point:
        int ind = -1; // break point
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                // index i is the break point
                ind = i;
                break;
            }
        }

        // If break point does not exist:
        if (ind == -1) {
            // reverse the whole array:
            reverse(nums.begin(), nums.end());
            return; // added return statement to avoid further operations
        }

        // Step 2: Find the next greater element
        //         and swap it with arr[ind]:
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Step 3: Reverse the right half:
        reverse(nums.begin() + ind + 1, nums.end());
    }
};