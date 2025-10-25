// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
// https://www.youtube.com/watch?v=zr_AoTxzn0Y&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=5

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        vector<int> res = {-1,-1};
        while(start<=end){
            int mid = start + ((end-start)/2);
            if(target == nums[mid]){
                res[0] = mid;
                end = mid-1;
            }
            else if(target < nums[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        start = 0;
        end = nums.size()-1;
        while(start<=end){
            int mid = start + ((end-start)/2);
            if(target == nums[mid]){
                res[1] = mid;
                start = mid+1;
            }
            else if(target < nums[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return res;
    }
};
