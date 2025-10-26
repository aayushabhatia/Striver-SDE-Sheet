// https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
// https://www.youtube.com/watch?v=5cx0xerA8XY&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=10

class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int start = 0;
        int end = arr.size()-1;
        int res = -1;
        while(start<=end){
            int mid = start + ((end-start)/2);
            if(arr[mid] == x){
                res = mid;
                start = mid+1;
            }
            else if(arr[mid]<x){
                res = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return res;
    }
};
