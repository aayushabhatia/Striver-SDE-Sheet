// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// https://takeuforward.org/data-structure/search-element-in-a-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0, high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            // left half sorted
            if(nums[low]<=nums[mid]){
                if(nums[low]<= target && target <= nums[mid]){ // target lying between 
                    high = mid-1;
                }
                else{ // target not lying between so left half got eliminated
                    low = mid+1;
                }
            }
            // right half sorted
            else{
                if(nums[mid]<= target && target <= nums[high]){ // target lying between 
                    low = mid+1;
                }
                else{ // target not lying between so right half got eliminated
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};
