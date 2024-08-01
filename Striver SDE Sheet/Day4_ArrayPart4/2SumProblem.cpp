// 1. Two Sum
// https://leetcode.com/problems/two-sum/
// https://takeuforward.org/data-structure/two-sum-check-if-a-pair-with-given-sum-exists-in-array/

#include<bits/stdc++.h>
using namespace std;

// Brute Force 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j}; // Return the indices
            }
        }
    }
    return {}; // Return an empty vector if no pair is found
    }
};

// Optimal Solution - Using Two Pointer Approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> num_indices; // To store values and their original indices

        for (int i = 0; i < n; ++i) {
            num_indices.push_back({nums[i], i});
        }

        sort(num_indices.begin(), num_indices.end());

        int left = 0;
        int right = n - 1;

        while (left < right) {
            int sum = num_indices[left].first + num_indices[right].first;
            if (sum == target) {
                return {num_indices[left].second, num_indices[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};
