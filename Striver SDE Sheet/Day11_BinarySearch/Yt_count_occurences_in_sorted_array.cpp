// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
// https://www.youtube.com/watch?v=Ru_HhBFV3Xo&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=6

class Solution {
  public:
    int countFreq(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int res1 = -1, res2 = -1;
        while(start<=end){
            int mid = start + ((end-start)/2);
            if(target == nums[mid]){
                res1 = mid;
                end = mid-1;
            }
            else if(target < nums[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        
        if(res1 == -1){
            return 0;
        }
        
        start = 0;
        end = nums.size()-1;
        while(start<=end){
            int mid = start + ((end-start)/2);
            if(target == nums[mid]){
                res2 = mid;
                start = mid+1;
            }
            else if(target < nums[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        int len = res2-res1+1;
        return len;
    }
};
