// 88. Merge Sorted Array (w/o taking extra space)
// https://leetcode.com/problems/merge-sorted-array/
// https://takeuforward.org/data-structure/merge-two-sorted-arrays-without-extra-space/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    void swapIfGreater(vector<int>& nums1, vector<int>& nums2, int ind1, int ind2) {
        if (nums1[ind1] > nums2[ind2]) {
            swap(nums1[ind1], nums2[ind2]);
        }
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Initial gap: (n+m+1)/2
        int len = m + n;
        int gap = (len / 2) + (len % 2);

        while (gap > 0) {
            int left = 0;
            int right = left + gap;

            while (right < len) {
                // case 1: left in nums1 and right in nums2
                if (left < m && right >= m) {
                    swapIfGreater(nums1, nums2, left, right - m);
                }
                // case 2: both pointers in nums2
                else if (left >= m) {
                    swapIfGreater(nums2, nums2, left - m, right - m);
                }
                // case 3: both pointers in nums1
                else {
                    swapIfGreater(nums1, nums1, left, right);
                }
                left++;
                right++;
            }

            // Reduce gap
            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }

        // Copy remaining elements from nums2 to nums1
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};
