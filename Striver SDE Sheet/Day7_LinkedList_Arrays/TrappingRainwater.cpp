// Trapping Rainwater
// https://leetcode.com/problems/trapping-rain-water/description/
// https://takeuforward.org/data-structure/trapping-rainwater/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int waterTrapped = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            int leftMax = 0, rightMax = 0;
            while (j >= 0) {
                leftMax = max(leftMax, arr[j]);
                j--;
            }
            j = i;
            while (j < n) {
                rightMax = max(rightMax, arr[j]);
                j++;
            }
            waterTrapped += min(leftMax, rightMax) - arr[i];
        }
        return waterTrapped;
    }
};
