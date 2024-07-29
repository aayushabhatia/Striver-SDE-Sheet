// 75. Sort Colors - Dutch National Flag Algorithm
// https://leetcode.com/problems/sort-colors/
// https://takeuforward.org/data-structure/sort-an-array-of-0s-1s-and-2s/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1; // 3 pointers

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
    }
};