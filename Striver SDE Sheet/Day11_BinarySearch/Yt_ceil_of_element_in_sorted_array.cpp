// https://www.geeksforgeeks.org/problems/ceil-in-a-sorted-array/1
// https://www.youtube.com/watch?v=uiz0IxPCUeU&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=11

class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int start = 0;
        int end = arr.size()-1;
        int res = -1;
        while(start<=end){
            int mid = start + ((end-start)/2);
            if(arr[mid] == x){
                res = mid;
                end = mid-1;
            }
            else if(arr[mid]>x){
                res = mid;
                end = mid-1;
            }
            else{ // arr[mid]<x
                start = mid+1;
            }
        }
        return res;
    }
};
