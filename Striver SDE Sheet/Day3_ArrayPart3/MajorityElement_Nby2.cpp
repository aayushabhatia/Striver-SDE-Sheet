// 169. Majority Element - which appears more than n/2 times in the array
// https://leetcode.com/problems/majority-element/
// https://takeuforward.org/data-structure/find-the-majority-element-that-occurs-more-than-n-2-times/

#include<bits/stdc++.h>
using namespace std;

// Optimal Solution- Moore's Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //size of the given array:
    int n = nums.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = nums[i];
        }
        else if (el == nums[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
    }
};
