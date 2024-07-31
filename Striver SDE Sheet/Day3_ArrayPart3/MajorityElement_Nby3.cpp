// 229. Majority Element II - occurs more than n/3 times
// https://leetcode.com/problems/majority-element-ii/
// https://takeuforward.org/data-structure/majority-elementsn-3-times-find-the-elements-that-appears-more-than-n-3-times-in-the-array/

#include<bits/stdc++.h>
using namespace std;

// Brute Force
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(); //size of the array
    vector<int> ls; // list of answers

    for (int i = 0; i < n; i++) {
        //selected element is v[i]:
        // Checking if v[i] is not already a part of the answer:
        if (ls.size() == 0 || ls[0] != nums[i]) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                // counting the frequency of v[i]
                if (nums[j] == nums[i]) {
                    cnt++;
                }
            }

            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                ls.push_back(nums[i]);
        }

        if (ls.size() == 2) break;
    }

    return ls;
    }
};


// Optimal Solution - Exten Boyer Moore's Voting Algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(); //size of the array

    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN; // element 1
    int el2 = INT_MIN; // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != nums[i]) { // check if el1 is already in nums
            cnt1 = 1;
            el1 = nums[i];
        }
        else if (cnt2 == 0 && el1 != nums[i]) { // check if el2 is already in nums
            cnt2 = 1;
            el2 = nums[i];
        }
        else if (nums[i] == el1) cnt1++;
        else if (nums[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }
      
    vector<int> ls; // list of answers
      
    // Manually check if the stored elements in el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == el1) cnt1++;
        if (nums[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);

    return ls;
    }
};
