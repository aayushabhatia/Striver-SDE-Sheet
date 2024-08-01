// Largest sunarray with 0 sum
// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// https://takeuforward.org/data-structure/length-of-the-longest-subarray-with-zero-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        int maxLen = 0;
    unordered_map<int, int> sumIndexMap;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        } else if (sumIndexMap.find(sum) != sumIndexMap.end()) {
            maxLen = max(maxLen, i - sumIndexMap[sum]);
        } else {
            sumIndexMap[sum] = i;
        }
    }

    return maxLen;
    }
};
