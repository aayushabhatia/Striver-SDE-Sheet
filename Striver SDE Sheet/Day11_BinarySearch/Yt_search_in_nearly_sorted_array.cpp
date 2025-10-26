// https://www.geeksforgeeks.org/problems/search-in-an-almost-sorted-array/1
// https://www.youtube.com/watch?v=W3-KgsCVH1U&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=9

class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        int n = arr.size();
        int start = 0;
        int end = n-1;
        while(start<=end){
            int mid = start + ((end-start)/2);
            if(target == arr[mid]){
                return mid;
            }
            if(mid-1>=start && target == arr[mid-1]){
                return mid-1;
            }
            if(mid+1 <= end && target == arr[mid+1]){
                return mid+1;
            }
            else if(target < arr[mid]){
                end = mid-2;
            }
            else{
                start = mid+2;
            }
        }
        return -1;
    }

};
