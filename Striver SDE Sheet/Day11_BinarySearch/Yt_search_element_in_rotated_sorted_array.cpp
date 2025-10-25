// https://leetcode.com/problems/search-in-rotated-sorted-array/
// https://www.youtube.com/watch?v=Id-DdcWb5AU&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=8

class Solution {
public:
    int findMinElement(vector<int> &arr) {
        int n = arr.size();
        int start = 0;
        int end = n - 1;

        while (start <= end) {
            // if subarray is already sorted, start is minimum
            if (arr[start] <= arr[end])
                return start;

            int mid = start + (end - start) / 2;
            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;

            if (arr[mid] <= arr[next] && arr[mid] <= arr[prev]) {
                return mid;
            }
            if (arr[start] <= arr[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return 0;
    }

    int binarysearch(const vector<int>& nums, int start, int end, int target) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) return nums[0] == target ? 0 : -1;

        int index = findMinElement(nums);

        // if target equals pivot element
        if (nums[index] == target) return index;

        // search left half [0 .. index-1]
        int ans = binarysearch(nums, 0, index - 1, target);
        if (ans != -1) return ans;

        // search right half [index .. n-1]
        return binarysearch(nums, index, n - 1, target);
    }
};
